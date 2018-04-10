.. default-domain:: chpl

.. module:: BlockDim

BlockDim
========
**Usage**

.. code-block:: chapel

   use BlockDim;

.. class:: BlockDim

   
   This Block dimension specifier is for use with the
   :class:`DimensionalDist2D` distribution.
   
   It specifies the mapping of indices in its dimension
   that would be produced by a 1D :class:`~BlockDist.Block` distribution.
   
   **Constructor Arguments**
   
   The following ``BlockDim`` class constructors are available:
   
     .. code-block:: chapel
   
       proc BlockDim.BlockDim(
         numLocales,
         boundingBoxLow,
         boundingBoxHigh,
         type idxType = boundingBoxLow.type)
   
       proc BlockDim.BlockDim(
         numLocales: int,
         boundingBox: range(?),
         type idxType = boundingBox.idxType)
   
   .. Is there also the compiler-generated constructor:
      proc BlockDim.BlockDim(type idxType, numLocales: int, bbStart, bbLength)
      If so, do we want to list it here?
      Ideally, the compiler will not generate that constructor
      since user-defined constructors are provided
   
   The ``numLocales`` argument specifies the number of locales
   that this dimension's bounding box is to be distributed over.
   
   The ``boundingBoxLow`` and ``boundingBoxHigh`` arguments are
   a convenient replacement for the ``boundingBox`` argument,
   which specifies the bounding box in this dimension.
   
   The ``idxType``, whether provided or inferred, must match
   the index type of the domains "dmapped" using the corresponding
   ``DimensionalDist2D`` distribution.


