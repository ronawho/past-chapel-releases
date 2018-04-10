.. default-domain:: chpl

.. module:: ReplicatedDim

ReplicatedDim
=============
**Usage**

.. code-block:: chapel

   use ReplicatedDim;

.. class:: ReplicatedDim

   
   This Replicated dimension specifier is for use with the
   :class:`DimensionalDist2D` distribution.
   
   The dimension of a domain or array for which this specifier is used
   has a *replicand* for each element of ``targetLocales``
   in the same dimension. This is similar to the Replicated distribution
   (:class:`Replicated`). The dimension specifies differs
   in that it always accesses the local replicand, whereas the Replicated
   distribution accesses all replicands in certain cases, as specified there.
   
   **Constructor Arguments**
   
   The ``ReplicatedDim`` class constructor is available as follows:
   
     .. code-block:: chapel
   
       proc ReplicatedDim.ReplicatedDim(numLocales:int)
   
   It creates a dimension specifier for replication over ``numLocales`` locales.


