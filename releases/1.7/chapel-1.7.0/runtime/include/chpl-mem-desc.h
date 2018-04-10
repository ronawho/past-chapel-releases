/**************************************************************************
  Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)
**************************************************************************/


#ifndef _chpl_mem_desc_H_
#define _chpl_mem_desc_H_

//
// When defining a new allocation type (for new instances of chpl_mem_allocMany
// or chpl_mem_realloc in the runtime), define both a new enumeration constant
// below and the corresponding descriptive string in the table defined in
// chpl-mem.c:chpl_mem_descString().  Then you can use your enumeration in
// a call to chpl_mem_allocMany(), chpl_mem_realloc(), or chpl_mem_descString().
//
typedef enum {
  CHPL_RT_MD_UNKNOWN = 0,
  CHPL_RT_MD_CHAPEL_CODE,
  CHPL_RT_EXECUTION_COMMAND,
  CHPL_RT_MD_ARRAY_ELEMENTS,
  CHPL_RT_MD_SET_WIDE_STRING,
  CHPL_RT_MD_GET_WIDE_STRING,
  CHPL_RT_MD_COMMAND_BUFFER,
  CHPL_RT_MD_COMM_XMIT_RECV_BUF,
  CHPL_RT_MD_COMM_XMIT_RECV_STATUS,
  CHPL_RT_MD_COMM_FORK_SEND_INFO,
  CHPL_RT_MD_COMM_FORK_SEND_NB_INFO,
  CHPL_RT_MD_COMM_FORK_SEND_LARGE_ARG,
  CHPL_RT_MD_COMM_FORK_SEND_NB_LARGE_ARG,
  CHPL_RT_MD_COMM_FORK_SEND_RESPONSE_DATA,
  CHPL_RT_MD_COMM_FORK_RECV_INFO,
  CHPL_RT_MD_COMM_FORK_RECV_LARGE_INFO,
  CHPL_RT_MD_COMM_FORK_RECV_NB_INFO,
  CHPL_RT_MD_COMM_FORK_RECV_NB_LARGE_INFO,
  CHPL_RT_MD_COMM_FORK_RECV_LARGE_ARG,
  CHPL_RT_MD_COMM_FORK_RECV_NB_LARGE_ARG,
  CHPL_RT_MD_COMM_FORK_DONE_FLAG,
  CHPL_RT_MD_COMM_PER_LOCALE_INFO,
  CHPL_RT_MD_COMM_PRIVATE_OBJECTS_ARRAY,
  CHPL_RT_MD_COMM_PRIVATE_BROADCAST_DATA,
  CHPL_RT_MD_GC_HEAP,
  CHPL_RT_MD_GC_SPACE_POINTER,
  CHPL_RT_MD_GLOM_STRINGS_DATA,
  CHPL_RT_MD_STRING_COPY_DATA,
  CHPL_RT_MD_STRING_CONCAT_DATA,
  CHPL_RT_MD_STRING_STRIDED_SELECT_DATA,
  CHPL_RT_MD_CONFIG_ARG_COPY_DATA,
  CHPL_RT_MD_CONFIG_TABLE_DATA,
  CHPL_RT_MD_LOCALE_NAME_BUFFER,
  CHPL_RT_MD_SERIAL_FLAG,
  CHPL_RT_MD_TASK_DESCRIPTOR,
  CHPL_RT_MD_TASK_DESCRIPTOR_LINK,      // reserved for future use
  CHPL_RT_MD_TASK_STACK,                // reserved for future use
  CHPL_RT_MD_MUTEX,
  CHPL_RT_MD_LOCK_REPORT_DATA,
  CHPL_RT_MD_TASK_POOL_DESCRIPTOR,
  CHPL_RT_MD_TASK_LIST_DESCRIPTOR,
  CHPL_RT_MD_THREAD_PRIVATE_DATA,
  CHPL_RT_MD_THREAD_LIST_DESCRIPTOR,
  CHPL_RT_MD_IO_BUFFER,
  CHPL_RT_MD_GMP,
  CHPL_RT_MD_GETS_PUTS_STRIDES,
  CHPL_RT_MD_GETS_PUTS_COUNTS,
  CHPL_RT_MD_NUM                        // this must be the last entry
} chpl_mem_rtMemDesc_t;


typedef int16_t chpl_mem_descInt_t;

#endif

