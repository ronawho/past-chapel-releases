/*
 * Copyright (c)  2012, Mellanox Technologies LTD. All rights reserved.
 */

#include <stdio.h>

#include <dlfcn.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include "gasnet_fca.h"
#include <gasnet_coll_internal.h>
/*
 * Instantiate the public struct with all of our public information
 * and pointers to our public functions in it
 */
int gasnet_fca_open(int my_rank);
int gasnet_fca_close(void);
static int fca_register(void);
int gasnet_fca_verbose_level = 25;
gasnet_fca_component_t gasnet_fca_component={0};


#define FCA_API_CLEAR_MICRO(__x) ((__x>>FCA_MINOR_BIT)<<FCA_MINOR_BIT)
#define FCA_API_VER(__major,__minor) (__major<<FCA_MAJOR_BIT | __minor<<FCA_MINOR_BIT)

#define GET_FCA_SYM(__name) \
{ \
    dlsym_quiet((void **)&gasnet_fca_component.fca_ops.__name, "fca_" #__name);\
    if (!gasnet_fca_component.fca_ops.__name) { \
        FCA_ERROR("Symbol %s not found", "fca_" #__name); \
        return GASNET_FCA_ERROR; \
    } \
}

static void dlsym_quiet(void **p, const char *name)
{
    *p = dlsym(gasnet_fca_component.fca_lib_handle, name);
}

static void gasnet_fca_progress_fn(void *arg)
{
    gasneti_AMPoll();
}
int gasnet_fca_get_fca_lib(int my_rank)
{
    struct fca_init_spec *spec;
    int ret;
    unsigned long fca_ver, major, minor, detected_ver;
    char x[3];
    if (gasnet_fca_component.fca_lib_handle)
        return GASNET_FCA_SUCCESS;

    gasnet_fca_component.fca_lib_handle = dlopen(gasnet_fca_component.fca_lib_path, RTLD_LAZY);
    if (!gasnet_fca_component.fca_lib_handle) {
        FCA_ERROR("Failed to load FCA from %s: %s", gasnet_fca_component.fca_lib_path, strerror(errno));
        return GASNET_FCA_ERROR;
    }

    memset(&gasnet_fca_component.fca_ops, 0, sizeof(gasnet_fca_component.fca_ops));

    FCA_VERBOSE(30, "FCA Loaded from: %s", gasnet_fca_component.fca_lib_path);
    GET_FCA_SYM(get_version);
    GET_FCA_SYM(get_version_string);
    fca_ver = FCA_API_CLEAR_MICRO(gasnet_fca_component.fca_ops.get_version());
    major = (fca_ver>>FCA_MAJOR_BIT);
    minor = (fca_ver>>FCA_MINOR_BIT) & 0xf;
    sprintf(x, "%ld%ld", major, minor);
    detected_ver = atol(x);
    FCA_VERBOSE(30, "FCA ABI version: %ld supported: %d", detected_ver, GASNET_FCA_VERSION);

    if (detected_ver != GASNET_FCA_VERSION) {
        FCA_ERROR("Unsupported FCA version: %s, please update FCA to v%d, now v%ld",
                gasnet_fca_component.fca_ops.get_version_string(),
                GASNET_FCA_VERSION, fca_ver);
        return GASNET_FCA_ERROR;
    }
    GET_FCA_SYM(init);
    GET_FCA_SYM(cleanup);
    GET_FCA_SYM(comm_new);
    GET_FCA_SYM(comm_end);
    GET_FCA_SYM(get_rank_info);
    GET_FCA_SYM(free_rank_info);
    GET_FCA_SYM(comm_init);
    GET_FCA_SYM(comm_destroy);
    GET_FCA_SYM(comm_get_caps);
    GET_FCA_SYM(do_all_reduce);
    GET_FCA_SYM(do_reduce);
    GET_FCA_SYM(do_bcast);
    GET_FCA_SYM(do_barrier);
#if GASNET_FCA_ALLGATHER == 1
    GET_FCA_SYM(do_allgather);
    GET_FCA_SYM(do_allgatherv);
#endif
    GET_FCA_SYM(parse_spec_file);
    GET_FCA_SYM(free_init_spec);
    GET_FCA_SYM(strerror);
    spec = gasnet_fca_component.fca_ops.parse_spec_file(gasnet_fca_component.fca_spec_file);
    if (!spec) {
        FCA_ERROR("Failed to parse FCA spec file `%s'", gasnet_fca_component.fca_spec_file);
        return GASNET_FCA_ERROR;
    }
    spec->job_id = 0;
    spec->rank_id = my_rank;
    spec->progress.func = gasnet_fca_progress_fn;
    spec->progress.arg = NULL;

    ret = gasnet_fca_component.fca_ops.init(spec, &gasnet_fca_component.fca_context);
    /* FCA library uses random numbers internally and specifies rand seed with it's 
     * specific value. As a result the seed is different for different processes.
     * Howevere, if GASNet client relies on the default value of seed, that implies all
     * the processes have the same random numbers, he would fail. So, restore seed
     * to the fixed value.
     */
    srand(1);
    if (ret < 0) {
        FCA_ERROR("Failed to initialize FCA: %s", gasnet_fca_component.fca_ops.strerror(ret));
        return GASNET_FCA_ERROR;
    }
    gasnet_fca_component.fca_ops.free_init_spec(spec);

    return GASNET_FCA_SUCCESS;
}

static int operation_enabled(gasnet_fca_coll_t coll){
    switch(coll){
        case _FCA_BARRIER:
            return gasnet_fca_component.fca_enable_barrier;
        case _FCA_BCAST:
            return gasnet_fca_component.fca_enable_bcast;
        case _FCA_REDUCE:
            return gasnet_fca_component.fca_enable_reduce;
        case _FCA_ALLREDUCE:
            return gasnet_fca_component.fca_enable_allreduce;
        case _FCA_ALLGATHER:
            return gasnet_fca_component.fca_enable_allgather;
        default:
            /*Unknown operation - disable it*/
            return -1;
    }
}
int gasnet_team_fca_is_active(gasnet_team_handle_t team, gasnet_fca_coll_t coll){

    return team->use_fca && operation_enabled(coll);
}

static void gasnet_fca_close_fca_lib(void)
{
    gasnet_fca_component.fca_ops.cleanup(gasnet_fca_component.fca_context);
    gasnet_fca_component.fca_context = NULL;
    dlclose(gasnet_fca_component.fca_lib_handle);
    gasnet_fca_component.fca_lib_handle = NULL;
}

static int is_appropriate_value(char *var)
{
    int len = strlen(var);
    int i;
    for (i=0; i<len; i++)
    {
        if (!isdigit(var[i])){
            return 0;
        }
    }
    return 1;
}

static int get_from_environment(const char *name, int *dest)
{
    char *var = gasnet_getenv(name);
    if (var == NULL){
        FCA_VERBOSE(5,"%s environment variable is not set; using default value %i",name,*dest);
    }
    else
    {
        if (is_appropriate_value(var)){
            *dest = atoi(var);
        }
        else{
            FCA_ERROR("Wrong value of environment variable %s: FCA is disabled!",name);
            return GASNET_FCA_ERROR;
        }
    }
    return GASNET_FCA_SUCCESS;
}

static uint64_t primes[] = {
    0xfdc0d83e0bba66c5ULL,
    0xe70f3669d6c4910bULL,
    0x833ec4bb6c52ba61ULL,
    0x8150068ca6884b23ULL,
    0xb20b78617a55da61ULL
};

static uint64_t hostname_hash(const char *name){
    int i;
    uint64_t h = 0;
    int size = strlen(name) / 8;
    int left = strlen(name) % 8;
    uint64_t *value = (uint64_t*)name;
    for (i = 0; i < size; i++) {
        h = primes[i%5]*h + *value;
        value++;
    }
    if (left){
        memcpy(value,name+size*8,left);
        h = primes[i%5]*h + *value;
    }
    return h;
}
static int construct_node_map(int proc_count)
{
    const char *myname = gasneti_gethostname();
    uint64_t myid = hostname_hash(myname);
    FCA_VERBOSE(30,"host=%s: rank=%i: id=%lu",myname,gasnet_mynode(),myid);
    gasnet_fca_component.node_map = (uint64_t *)gasneti_calloc(proc_count,sizeof(uint64_t));
    gasnet_coll_gather_all(gasnete_coll_team_all, (void *)gasnet_fca_component.node_map,
            (void *)&myid, sizeof(uint64_t), GASNET_COLL_LOCAL | GASNET_COLL_IN_ALLSYNC | GASNET_COLL_OUT_ALLSYNC);
    return GASNET_FCA_SUCCESS;
}

static int register_gasnet_fca_params(void){
    /*default values of control parameters*/
    gasnet_fca_component.fca_enable = 1;
    gasnet_fca_component.fca_np = 64;
    gasnet_fca_verbose_level = 0;
    gasnet_fca_component.fca_enable_barrier = 1;
    gasnet_fca_component.fca_enable_bcast = 1;
    gasnet_fca_component.fca_enable_reduce = 1;
    gasnet_fca_component.fca_enable_allreduce = 1;
    gasnet_fca_component.fca_enable_allgather = 1;

    if (GASNET_FCA_SUCCESS != 
            get_from_environment("GASNET_FCA_ENABLE_CMD_LINE",&gasnet_fca_component.fca_enable))
        return GASNET_FCA_ERROR;

    if (GASNET_FCA_SUCCESS != 
            get_from_environment("GASNET_FCA_NP_CMD_LINE",&gasnet_fca_component.fca_np))
        return GASNET_FCA_ERROR;

    if (GASNET_FCA_SUCCESS != 
            get_from_environment("GASNET_FCA_VERBOSE_CMD_LINE",&gasnet_fca_verbose_level))
        return GASNET_FCA_ERROR;

    if (GASNET_FCA_SUCCESS != 
            get_from_environment("GASNET_FCA_ENABLE_BARRIER",&gasnet_fca_component.fca_enable_barrier))
        return GASNET_FCA_ERROR;

    if (GASNET_FCA_SUCCESS != 
            get_from_environment("GASNET_FCA_ENABLE_BCAST",&gasnet_fca_component.fca_enable_bcast))
        return GASNET_FCA_ERROR;
    
    if (GASNET_FCA_SUCCESS != 
            get_from_environment("GASNET_FCA_ENABLE_REDUCE",&gasnet_fca_component.fca_enable_reduce))
        return GASNET_FCA_ERROR;
    
    if (GASNET_FCA_SUCCESS != 
            get_from_environment("GASNET_FCA_ENABLE_ALLREDUCE",&gasnet_fca_component.fca_enable_allreduce))
        return GASNET_FCA_ERROR;
    
    if (GASNET_FCA_SUCCESS != 
            get_from_environment("GASNET_FCA_ENABLE_ALLGATHER",&gasnet_fca_component.fca_enable_allgather))
        return GASNET_FCA_ERROR;
    return GASNET_FCA_SUCCESS;
}
int gasnet_fca_open(int my_rank)
{
    gasnet_fca_component.fca_lib_handle = NULL;
    gasnet_fca_component.fca_context = NULL;
    gasnet_fca_component.fca_lib_path = (char *)GASNET_FCA_HOME "/lib/libfca.so";
    gasnet_fca_component.fca_spec_file = (char *)GASNET_FCA_HOME "/etc/fca_mpi_spec.ini";

    if (GASNET_FCA_SUCCESS != register_gasnet_fca_params()){
        FCA_ERROR("error: register_gasnet_fca_params failed!");
        return GASNET_FCA_ERROR;
    }
    if (gasnet_fca_component.fca_enable){
        if (GASNET_FCA_SUCCESS != construct_node_map(gasnet_nodes())){
            FCA_ERROR("Can not construct node map");
            return GASNET_FCA_ERROR;
        }
        if (GASNET_FCA_SUCCESS != gasnet_fca_get_fca_lib(my_rank)){
            FCA_ERROR("error: gasnet_fca_get_fca_lib failed!");
            return GASNET_FCA_ERROR;
        }
    }
    return GASNET_FCA_SUCCESS;
}

int gasnet_fca_close(void)
{

    if (!gasnet_fca_component.fca_lib_handle || !gasnet_fca_component.fca_context)
        return GASNET_FCA_SUCCESS;

    gasnet_fca_close_fca_lib();
    return GASNET_FCA_SUCCESS;
}

static int __fca_comm_new(gasnet_team_handle_t team)
{
     int ret;
     fca_comm_new_spec_t spec;
     int info_size = 0, all_info_size = 0;
     void *all_info = NULL, *my_info = NULL;
     int *rcounts = NULL, *disps = NULL;
     int i,j;
     const int team_root_id = 0;
     int max_info_size = 0;
     void *max_info;
     gasnet_image_t team_root_image = (gasnet_image_t)team_root_id;
     fca_comm_data_t *fca_comm_data = &team->fca_comm_data;
     /* call fca_get_rank_info() on node managers only*/
     if (fca_comm_data->local_proc_idx == 0)
     {
         my_info = gasnet_fca_component.fca_ops.get_rank_info(gasnet_fca_component.fca_context,
                 &info_size);
         if (!my_info) {
             FCA_ERROR("fca_get_rank_info returned NULL");
             return GASNET_FCA_ERROR;
         }
      } else {
         info_size = 0;
     }
 
     FCA_VERBOSE(1, "Info size: %d", info_size);
     /* Allocate gather buffer on the root rank */
     if (team_root_id == fca_comm_data->my_rank){
        rcounts = gasneti_calloc(fca_comm_data->proc_count, sizeof *rcounts);
     }
     gasnet_coll_gather(team, team_root_image, (void *)rcounts, (void *)&info_size, sizeof(int), GASNET_COLL_LOCAL | GASNET_COLL_IN_ALLSYNC | GASNET_COLL_OUT_ALLSYNC);
     
     /* We need to gather all the node managers' infos at team_root node. In general those infos can be of different size on different nodes, thus
        we cannot use gasnet_coll_gather. Moreover, we don't have smth like MPI_Gatherv in gasnet. So the way round is:
        1. Find maximum info size on team_root node. Allocate max_info_size*proc_count memory there.
        2. Broadcast max_info_size, and allocate max_info_size of memory on all other nodes.
        3. Copy my_info into max_info and gather it on the team_root node with const size of max_info_size
        4. Extract the non zero my_infos from max_info on team_root node
        */
     /* Root rank defines the maximum info size and prepare memory for further gathering */
     if (team_root_id == fca_comm_data->my_rank) {
         for (i=0; i<fca_comm_data->proc_count; i++)
             if (rcounts[i] > max_info_size)
                 max_info_size = rcounts[i];
         max_info = gasneti_calloc(fca_comm_data->proc_count,max_info_size);
         memcpy(max_info,my_info,info_size);
     }
     /*broadcasting max_info_size*/
     gasnet_coll_broadcast(team,(void *)&max_info_size,team_root_id,(void *)&max_info_size, sizeof(int), GASNET_COLL_LOCAL | GASNET_COLL_IN_ALLSYNC | GASNET_COLL_OUT_ALLSYNC);
 
     /*prepare memory on not team_root nodes*/
     if (team_root_id != fca_comm_data->my_rank){
         max_info = gasneti_calloc(1,max_info_size);
         if (info_size > 0)
             memcpy(max_info,my_info,info_size);
     }
 
     /*gather my_infos on team_root node: NOTO, all nodes that are not node managers will pass zero max_info to the gasnet_coll_gather*/
     gasnet_coll_gather(team, team_root_image, max_info, max_info, max_info_size, GASNET_COLL_LOCAL | GASNET_COLL_IN_ALLSYNC | GASNET_COLL_OUT_ALLSYNC);
 
     
     if (team_root_id == fca_comm_data->my_rank) {
         all_info_size = 0;
         disps = gasneti_calloc(fca_comm_data->proc_count, sizeof *disps);
         for (i = 0; i<fca_comm_data->proc_count; ++i) {
             disps[i] = all_info_size;
             all_info_size += rcounts[i];
         }
         FCA_VERBOSE(3, "Total rank_info size: %d", all_info_size);
         /*team_root allocates as much memory as necessary to store node_managers info only*/
         all_info = gasneti_calloc(all_info_size,1);
 
         /*copy out non zero infos (those that came from node managers) to the all_info array*/
         for (i=0; i<fca_comm_data->proc_count; i++){
             memcpy((void *)((char *)all_info+disps[i]),(void *)((char *)max_info+max_info_size*i),rcounts[i]);
         }
      }
 
 
        /* team_root calls fca_comm_new() and fills fca_comm_spec filed */
        if (team_root_id == fca_comm_data->my_rank) {
            spec.rank_info  = all_info;
            /*at the moment we support gasnete_coll_team_all only*/
            spec.is_comm_world = team == gasnete_coll_team_all;
            spec.rank_count = 0;
            for (i = 0; i < fca_comm_data->proc_count; ++i) {
                FCA_VERBOSE(1, "rcounts[%d]=%d disps[%d]=%d",
                        i, rcounts[i], i, disps[i]);
                if (rcounts[i] > 0)
                    ++spec.rank_count;
            }
                 
            FCA_VERBOSE(5, "starting fca_comm_new(), rank_count: %d",
                    spec.rank_count);
     
            ret = gasnet_fca_component.fca_ops.comm_new(gasnet_fca_component.fca_context,
                    &spec, &fca_comm_data->fca_comm_desc);
            gasneti_free(all_info);
            gasneti_free(rcounts);
            gasneti_free(disps);
        }
        gasneti_free(max_info);
 
        
        gasnet_coll_broadcast(team,(void *)&ret,team_root_id,(void *)&ret, sizeof(int), GASNET_COLL_LOCAL | GASNET_COLL_IN_ALLSYNC | GASNET_COLL_OUT_ALLSYNC);
          
        /* Examine comm_new return value */
        if (ret < 0)
        {
           FCA_ERROR("rank %i: COMM_NEW failed: %s", fca_comm_data->my_rank, gasnet_fca_component.fca_ops.strerror(ret));
           return GASNET_FCA_ERROR;
        }
     
        /* Release allocate rank_info on node managers */
        if (fca_comm_data->local_proc_idx == 0) {
            gasnet_fca_component.fca_ops.free_rank_info(my_info);
        }
     
        
        gasnet_coll_broadcast(team,(void *)&fca_comm_data->fca_comm_desc,team_root_id,(void *)&fca_comm_data->fca_comm_desc,
                sizeof(fca_comm_data->fca_comm_desc), GASNET_COLL_LOCAL | GASNET_COLL_IN_ALLSYNC | GASNET_COLL_OUT_ALLSYNC);         
     
        FCA_VERBOSE(5,"Received FCA communicator spec, comm_id %d",
                fca_comm_data->fca_comm_desc.comm_id);
    return GASNET_FCA_SUCCESS;
}

static int __create_fca_comm(gasnet_team_handle_t team)
{
     int rc, ret;
     int comm_size;
     fca_comm_data_t *fca_comm_data = &team->fca_comm_data;
     rc = __fca_comm_new(team);
     if (rc != GASNET_FCA_SUCCESS)
         return rc;
 
     /* allocate comm_init_spec */
     FCA_VERBOSE(1, "Starting COMM_INIT comm_id %d proc_idx %d num_procs %d",
             fca_comm_data->fca_comm_desc.comm_id, fca_comm_data->local_proc_idx,
             fca_comm_data->num_local_procs);
 
     comm_size = fca_comm_data->proc_count;
     ret = gasnet_fca_comm_init(&gasnet_fca_component.fca_ops,
                     gasnet_fca_component.fca_context,
                     /*this is a global id of the process in job*/fca_comm_data->my_rank, comm_size,
                     fca_comm_data->local_proc_idx, fca_comm_data->num_local_procs,
                     &fca_comm_data->fca_comm_desc, &fca_comm_data->fca_comm);
     if (ret < 0) {
         FCA_ERROR("COMM_INIT failed: %s", gasnet_fca_component.fca_ops.strerror(ret));
         return GASNET_FCA_ERROR;
     }
     /* get communicator capabilities */
     ret = gasnet_fca_component.fca_ops.comm_get_caps(fca_comm_data->fca_comm,
             &fca_comm_data->fca_comm_caps);
     if (ret < 0) {
         FCA_ERROR("GET_COMM_CAPS failed: %s", gasnet_fca_component.fca_ops.strerror(ret));
         return GASNET_FCA_ERROR;
     }

     /* by this point every rank in the communicator is set up */
     FCA_VERBOSE(1, "Initialized FCA communicator, comm_id %d",
             fca_comm_data->fca_comm_desc.comm_id);
     return GASNET_FCA_SUCCESS;
}

static int __rank_is_local(int rank, int my_rank)
{
    return gasnet_fca_component.node_map[rank] == gasnet_fca_component.node_map[my_rank];
}
static int __get_local_ranks(gasnet_team_handle_t team)
{
    int i, rank;
    /* Count the local ranks */
    team->fca_comm_data.num_local_procs = 0;
    for (rank = 0; rank < team->total_ranks; ++rank) {
        if (__rank_is_local(gasnete_coll_team_rank2node(team,rank),gasnet_mynode())) {
            if (rank == team->myrank) {
                team->fca_comm_data.local_proc_idx = team->fca_comm_data.num_local_procs;
            }
            ++team->fca_comm_data.num_local_procs;
        }
    }
    /* Make a list of local ranks */
    team->fca_comm_data.local_ranks = gasneti_calloc(team->fca_comm_data.num_local_procs,
            sizeof *team->fca_comm_data.local_ranks);
    if (!team->fca_comm_data.local_ranks) {
        FCA_ERROR("Failed to allocate memory for %d local ranks",
                team->fca_comm_data.num_local_procs);
        return GASNET_FCA_ERROR;
    }

    i = 0;
    for (rank = 0; rank < team->total_ranks; ++rank) {
        if (__rank_is_local(gasnete_coll_team_rank2node(team,rank),gasnet_mynode())) {
            team->fca_comm_data.local_ranks[i++] = rank;
        }
    }

    FCA_VERBOSE(3, "i am %d/%d", team->fca_comm_data.local_proc_idx,
            team->fca_comm_data.num_local_procs);

    return GASNET_FCA_SUCCESS;
}

static int have_remote_peers(gasnet_team_handle_t team)
{
    size_t i;
    int ret;

    ret = 0;
    for (i = 0; i < team->total_ranks; ++i) {
        if (!__rank_is_local(gasnete_coll_team_rank2node(team,i),gasnet_mynode())) {
            ret = 1;
        }
    }
    return ret;
}

int gasnet_team_fca_enable(gasnet_team_handle_t team)
{
   
    if (!gasnet_fca_component.is_initialized){
        gasnet_fca_open(gasnet_mynode());
        gasnet_fca_component.is_initialized = 1;
    }
    if (!gasnet_fca_component.fca_enable)
    {
        FCA_VERBOSE(20,"FCA is disabled from command line");
        return GASNET_FCA_SUCCESS;
    }

    if (gasnet_fca_component.fca_np > team->total_ranks) {
        FCA_VERBOSE(20,"FCA is disabled: -fca_np=%i > total_ranks=%i",
                gasnet_fca_component.fca_np, team->total_ranks);
        return GASNET_FCA_ERROR;
    }

    team->fca_comm_data.my_rank = team->myrank;
    team->fca_comm_data.proc_count = team->total_ranks;
    if (!have_remote_peers(team)){
        FCA_VERBOSE(20,"All ranks are local");
        return GASNET_FCA_ERROR;
    }
    
    if (team->total_ranks < 2){
        FCA_VERBOSE(20,"team size (%d) < 2",team->total_ranks);
    }
    __get_local_ranks(team);
    if (GASNET_FCA_SUCCESS != __create_fca_comm(team)){
        FCA_ERROR("Can not create fca communicator");
        return GASNET_FCA_ERROR;
    }
    team->use_fca = 1;
    return GASNET_FCA_SUCCESS;
}
