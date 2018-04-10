.. default-domain:: chpl

.. module:: LinearAlgebra
   :synopsis: Linear Algebra Module

LinearAlgebra
=============
**Usage**

.. code-block:: chapel

   use LinearAlgebra;

**Submodules**

.. toctree::
   :maxdepth: 1
   :glob:

   LinearAlgebra/*

Linear Algebra Module

A high-level interface to linear algebra operations and procedures.

.. note::
  This is an early prototype package module. As a result, interfaces may change
  over the next release.

Compiling with Linear Algebra
-----------------------------

The linear algebra module uses the :mod:`BLAS` module.
In order to compile a Chapel program with this module, be sure
to have a BLAS implementation available on your system. See the :mod:`BLAS`
documentation for further details.

.. _LinearAlgebraInterface:

Linear Algebra Interface
------------------------

**Matrix and Vector representation**

Matrices and vectors are represented as Chapel arrays, which means the
convenience constructors provided in this module are not necessary to use this
module's functions. This also means that matrices (2D arrays) and vectors (1D
arrays) will work with any other Chapel library that works with arrays.

.. note::

  This documentation uses the terms `matrix` to refer to `2D arrays`, and
  `vector` to refer to `1D arrays`.

**Indexing**

All functions that return new arrays will return arrays over 1-based indices,
unless otherwise specified.

**Matrix multiplication**

:proc:`dot` is the general matrix multiplication function provided in this module.
This function supports any combination of scalars, vectors (1D arrays), and
matrices (2D arrays). See the :proc:`dot` documentation for more information.

The :proc:`dot` function, along with others may be given a matrix-specific
operator in future releases.

**Row vs Column vectors**

Row and column vectors are both represented as 1D arrays and are
indistinguishable in Chapel. In the :proc:`dot` function, matrix-vector
multiplication assumes a column vector, vector-matrix multiplication assumes a
row vector, vector-vector multiplication is always treated as an inner-product,
as the function name implies.
An outer product can be computed with the :proc:`outer` function.

**Domain maps**

All of the functions in this module only support
``DefaultRectangular`` arrays (the default domain map), unless explicitly
specified in the function's documentation. Other domain maps
are supported through submodules, such ``LinearAlgebra.Sparse`` for the
``CS`` layout.

**Promotion flattening**

Promotion flattening is an unintended consequence of Chapel's
:ref:`promotion feature <ug-promotion>`, when a multi-dimensional array assignment
gets type-inferred as a 1-dimensional array of the same size, effectively
flattening the array dimensionality. This can result in unexpected behavior in
programs such as this:

.. code-block:: chapel

  var A = Matrix(4, 4),
      B = Matrix(4, 4);
  // A + B is a promoted operation, and C becomes a 1D array
  var C = A + B;
  // This code would then result in an error due to rank mismatch:
  C += A;

To avoid this, you can avoid relying on inferred-types for new arrays:

.. code-block:: chapel

  var A = Matrix(4, 4),
      B = Matrix(4, 4);
  // C's type is not inferred and promotion flattening is not a problem
  var C: [A.domain] A.eltType = A + B;
  // Works as expected
  C += A;

Alternatively, you can use the LinearAlgebra helper routines, which create
and return a new array:

.. code-block:: chapel

  var A = Matrix(4, 4),
      B = Matrix(4, 4);
  // matPlus will create a new array with an explicit type
  var C = matPlus(A, B);
  // Works as expected
  C += A;

Promotion flattening is not expected to be an issue in future releases.


.. function:: proc Vector(length, type eltType = real)

   Return a vector (1D array) over domain ``{1..length}``

.. function:: proc Vector(space: range, type eltType = real)

   Return a vector (1D array) over domain ``{space}`` 

.. function:: proc Vector(Dom: domain(1), type eltType = real)

   Return a vector (1D array) over domain ``Dom`` 

.. function:: proc Vector(A: [?Dom] ?Atype, type eltType = Atype)

   Return a vector (1D array) with domain and values of ``A`` 

.. function:: proc Vector(x: ?t, Scalars ...?n, type eltType)

   Return a vector (1D array), given 2 or more numeric values
   
   If `type` is omitted, it will be inferred from the first argument

.. function:: proc Matrix(rows, type eltType = real)

   Return a square matrix (2D array) over domain ``{1..rows, 1..rows}``

.. function:: proc Matrix(rows, cols, type eltType = real)

   Return a matrix (2D array) over domain ``{1..rows, 1..cols}``

.. function:: proc Matrix(space: range, type eltType = real)

   Return a square matrix (2D array) over domain ``{space, space}`` 

.. function:: proc Matrix(rowSpace: range, colSpace: range, type eltType = real)

   Return a matrix (2D array) over domain ``{rowSpace, colSpace}`` 

.. function:: proc Matrix(Dom: domain, type eltType = real)

   Return a matrix (2D array) over domain ``Dom`` 

.. function:: proc Matrix(A: [?Dom] ?Atype, type eltType = Atype)

   Return a matrix (2D array) with domain and values of ``A``.
   
   ``A`` can be sparse (CS) or dense.

.. function:: proc Matrix(const Arrays ...?n, type eltType)

   
   Return a matrix (2D array), given 2 or more vectors, such that the vectors
   form the rows of the matrix. In other words, the vectors are
   concatenated such that the ``ith`` vector corresponds to the matrix slice:
   ``A[i, ..]``
   
   If `type` is omitted, it will be inferred from the first array.
   
   For example:
   
   .. code-block:: chapel
   
       var A = Matrix([1, 2, 3],
                      [4, 5, 6],
                      [7, 8, 9]);
       /* Produces the 3x3 matrix of integers:
            1 2 3
            4 5 6
            7 8 9
        */
   

.. function:: proc eye(m, type eltType = real)

   Return a square identity matrix over domain ``{1..m, 1..m}`` 

.. function:: proc eye(m, n, type eltType = real)

   Return an identity matrix over domain ``{1..m, 1..n}`` 

.. function:: proc eye(Dom: domain(2), type eltType = real)

   Return an identity matrix over domain ``Dom`` 

.. function:: proc transpose(A: [?Dom] ?eltType)

   Transpose vector, matrix, or domain.
   
   .. note::
   
      Since row vectors and columns vectors are indistinguishable, passing
      a vector to this function will return that vector unchanged
   

.. method:: proc _array.T

   Transpose vector or matrix 

.. function:: proc matPlus(A: [?Adom] ?eltType, B: [?Bdom] eltType)

   Add matrices, maintaining dimensions, deprecated for ``_array.plus`` 

.. method:: proc _array.plus(A: [?Adom])

   Add matrices, maintaining dimensions 

.. function:: proc matMinus(A: [?Adom] ?eltType, B: [?Bdom] eltType)

   Subtract matrices, maintaining dimensions, deprecated for ``_array.minus``

.. method:: proc _array.minus(A: [?Adom])

   Subtract matrices, maintaining dimensions 

.. method:: proc _array.times(A: [?Adom])

   Element-wise multiplication, maintaining dimensions 

.. method:: proc _array.elementDiv(A: [?Adom])

   Element-wise division, maintaining dimensions 

.. function:: proc dot(A: [?Adom] ?eltType, B: [?Bdom] eltType)

   
   Generic matrix multiplication, ``A`` and ``B`` can be a matrix, vector, or
   scalar.
   
   When ``A`` is a vector and ``B`` is a matrix, this function implicitly
   computes ``dot(transpose(A), B)``, which may not be as efficient as
   passing ``A`` and ``B`` in the reverse order.

.. method:: proc _array.dot(A: [])

   Compute the dot-product 

.. function:: proc inner(A: [?Adom], B: [?Bdom])

   Inner product of 2 vectors 

.. function:: proc outer(A: [?Adom] ?eltType, B: [?Bdom] eltType)

   Outer product of 2 vectors 

.. function:: proc matPow(A: [], b)

   Return the matrix ``A`` to the ``bth`` power, where ``b`` is a positive
   integral type. 

.. function:: proc cross(A: [?Adom] ?eltType, B: [?Bdom] eltType)

   Return cross-product of 3-element vectors ``A`` and ``B`` with domain of
   ``A`` 

.. function:: proc diag(A: [?Adom] ?eltType, k = 0)

   
   Return a Vector containing the diagonal elements of ``A`` if the argument ``A`` is of rank 2.
   Return a diagonal Matrix whose diagonal contains elements of ``A`` if argument ``A`` is of rank 1.
   

.. function:: proc tril(A: [?D] ?eltType, k = 0)

   
   Return lower triangular part of matrix, above the diagonal + ``k``,
   where ``k = 0`` includes the diagonal, and ``k = -1`` does *not* include
   the diagonal. For example:
   
   .. code-block:: chapel
   
    var A = Matrix(4, 4, eltType=int);
    A = 1;
   
    tril(A);
    /* Returns:
   
        1    0    0    0
        1    1    0    0
        1    1    1    0
        1    1    1    1
    */
   
    tril(A, 1);
    /* Returns:
   
        1    1    0    0
        1    1    1    0
        1    1    1    1
        1    1    1    1
    */
   
    tril(A, -1);
    /* Returns:
   
        0    0    0    0
        1    0    0    0
        1    1    0    0
        1    1    1    0
    */
   

.. function:: proc triu(A: [?D] ?eltType, k = 0)

   
   Return upper triangular part of matrix, above the diagonal + ``k``,
   where ``k = 0`` includes the diagonal, and ``k = 1`` does *not* include
   the diagonal. For example:
   
   .. code-block:: chapel
   
      var A = Matrix(4, 4, eltType=int);
      A = 1;
   
      triu(A);
      /* Returns:
   
          1    1    1    1
          0    1    1    1
          0    0    1    1
          0    0    0    1
      */
   
      triu(A, 1);
      /* Returns:
   
          0    1    1    1
          0    0    1    1
          0    0    0    1
          0    0    0    0
      */
   
      triu(A, -1);
      /* Returns:
   
          1    1    1    1
          1    1    1    1
          0    1    1    1
          0    0    1    1
      */
   

.. function:: proc isDiag(A: [?D] ?eltType)

   Return `true` if matrix is diagonal 

.. function:: proc isHermitian(A: [?D])

   Return `true` if matrix is Hermitian 

.. function:: proc isSymmetric(A: [?D]): bool

   Return `true` if matrix is symmetric 

.. function:: proc isTril(A: [?D] ?eltType, k = 0): bool

   
   Return `true` if matrix is lower triangular below the diagonal + ``k``,
   where ``k = 0`` does *not* include the diagonal, and ``k = 1`` includes the
   diagonal
   

.. function:: proc isTriu(A: [?D] ?eltType, k = 0): bool

   Return `true` if matrix is upper triangular above the diagonal + ``k``,
   where ``k = 0`` does *not* include the diagonal, and ``k = -1`` includes the
   diagonal
   

.. function:: proc isSquare(A: [?D])

   Return `true` if matrix is square 

.. function:: proc trace(A: [?D] ?eltType)

   Return the trace (sum of diagonal elements) of ``A`` 

.. function:: proc cholesky(A: [] ?t, lower = true)

   Perform a Cholesky factorization on matrix ``A``.  ``A`` must be square.
   Argument ``lower`` indicates whether to return the lower or upper
   triangular factor.  Matrix ``A`` is not modified.  Returns an array with
   the same shape as argument ``A`` with the lower or upper triangular
   Cholesky factorization of ``A``.
   

.. function:: proc eigvals(A: [] ?t, param left = false, param right = false)

   Find the eigenvalues and eigenvectors of matrix ``A``. ``A`` must be square.
   
   * If ``left`` is ``true`` then the "left" eigenvectors are computed. The
     return value is a tuple with two elements:
     ``(eigenvalues, leftEigenvectors)``
   
   * If ``right`` is ``true`` then the "right" eigenvectors are computed. The
     return value is a tuple with two elements:
     ``(eigenvalues, rightEigenvectors)``
   
   * If ``left`` and ``right`` are both ``true`` then both eigenvectors are
     computed.  The return value is a tuple with three elements:
     ``(eigenvalues, leftEigenvectors, rightEigenvectors)``
   
   * If ``left`` and ``right`` are both ``false`` only the eigenvalues are
     computed, and returned as a single array.
   
   

.. function:: proc kron(A: [?ADom] ?eltType, B: [?BDom] eltType)

   Return the Kronecker Product of matrix ``A`` and matrix ``B``.
   If the size of A is ``x * y`` and of B is ``a * b`` then size of the resulting
   matrix will be ``(x * a) * (y * b)`` 

