// Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)


// ChapelStandard.chpl
//
pragma "no use ChapelStandard"
module ChapelStandard {
  // Internal modules.
  use ChapelBase;
  use Atomics;
  use NetworkAtomics;
  use NetworkAtomicTypes;
  use ChapelNumLocales;
  use ChapelThreads;
  use ChapelThreadsInternal;
  use ChapelTasksInternal;
  use ChapelTuple;
  use ChapelRange;
  use ChapelReduce;
  use ChapelSyncvar;
  use ChapelLocale;
  use DefaultArchitecture;
  use RootLocale;
  use ChapelArray;
  use ChapelDistribution;
  use ChapelIO;
  use LocaleTree;
  use DefaultRectangular; // Must precede ChapelTaskTable.
  use DefaultAssociative;
  use DefaultSparse;
  use DefaultOpaque;
  use ChapelTaskTable;
  use MemTracking;
  use ChapelUtil;

  // Standard modules.
  use Types;
  use Math;
}
