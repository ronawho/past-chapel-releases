.. default-domain:: chpl

.. module:: BLAS
   :synopsis: Support for Basic Linear Algebra Subprograms (BLAS) kernel routines.

BLAS
====
**Usage**

.. code-block:: chapel

   use BLAS;

**Submodules**

.. toctree::
   :maxdepth: 1
   :glob:

   BLAS/*



Support for Basic Linear Algebra Subprograms (BLAS) kernel routines.

BLAS (Basic Linear Algebra Subprograms) are the de facto standard routines for
low-level matrix, vector, and scalar operations. While `netlib
<http://www.netlib.org/blas/#_documentation>`_ provides the official
reference version of BLAS, this documentation refers to the
`MKL BLAS <https://software.intel.com/en-us/node/520725>`_ documentation, due
to interface similarities.

This module is intended to work with non-distributed dense rectangular arrays.


Compiling with BLAS
-------------------

In order to compile a Chapel program that uses this module, the
BLAS and C_BLAS (C wrappers to BLAS) libraries must be installed on the system.
The paths to both the ``cblas.h`` header file and BLAS library
must be passed to the ``-I`` and ``-L`` compiler arguments. The library name,
typically ``blas``, must be passed to the ``-l`` argument as well.

The compilation command should look something like this:

.. code-block:: sh

    chpl -I$PATH_TO_CBLAS_DIR \
         -L$PATH_TO_BLAS_LIBS -lblas source.chpl

BLAS Implementations:
  There is a wide range of
  `BLAS implementations <https://en.wikipedia.org/wiki/Basic_Linear_Algebra_Subprograms#Implementations>`_
  available.
  This module was built and tested with `netlib's C_BLAS
  <http://www.netlib.org/blas/#_cblas>`_, but many other implementations are
  compatible as well.
  Using a version of BLAS optimized for the user's system will yield the best
  performance.

  There are a few known caveats with some popular implementations:

  * **ATLAS**

    * The compilation command above likely requires the additional flag: ``-latlas``

  * **MKL**

    * Compile with :param:`isBLAS_MKL` if using MKL BLAS.

  * **OpenBLAS**

    * The header files that are included with OpenBLAS differ from the reference
      C_BLAS prototypes for complex arguments by using ``float*`` and ``double*``
      pointers, instead of ``void*`` pointers.  Using this will likely result in
      warnings about incompatible pointer types. These may be ignored.

Cray Systems:
  No compiler flags should be necessary when compiling BLAS programs on
  Crays. The **CrayBLAS** implementation is made available through Cray's libsci,
  which comes installed on all Cray systems. This is typically loaded by
  default, but can be manually loaded with ``module load cray-libsci`` as well.
  Chapel programs compiled on Crays utilize the ``cc`` wrapper as the backend
  compiler, which implicitly links against the libsci library. Therefore, no
  additional steps are required of the user.

Chapel BLAS API
---------------

This module provides higher-level wrappers around the BLAS functions. These
provide reasonable default values for many less commonly used arguments and
determine the appropriate functions to call, based on the array element types,
as well as the array dimensions. The other functionality is identical to the
corresponding BLAS functions.

The names of these routines are identical to the corresponding BLAS functions,
except that the type prefix is dropped. For instance, ``gemm`` is the
wrapper for the ``[sdcz]gemm`` routines.

The native BLAS interface can still be accessed by calling routines from the
``C_BLAS`` submodule.

The ``ldA`` argument is omitted from the Chapel BLAS API. Chapel determines the
dimensions of the matrices from the arrays that are passed in, even when one is
passing in a sub-array such that the array elements are not contiguously stored
in memory.

.. warning::

  The ``CHPL_LOCALE_MODEL=numa`` configuration is currently not supported by
  this module.

.. MKL Documentation References

.. _GEMM:   https://software.intel.com/en-us/node/ae8380b9-cac8-4c57-9af3-2eaac6acfc1b
.. _HEMM:   https://software.intel.com/en-us/node/ecdcb863-3cb8-40ce-84f6-4cbc66cfc659
.. _HERK:   https://software.intel.com/en-us/node/4ee4425c-42b6-4cc0-b2f0-6cfaa2117cb8
.. _HER2K:  https://software.intel.com/en-us/node/5c17da7b-d8f9-44ec-921e-d6285238d48e
.. _SYMM:   https://software.intel.com/en-us/node/8273eec0-2663-4843-90cd-12fd7a1baa6c
.. _SYRK:   https://software.intel.com/en-us/node/04ca14b7-ec46-4836-8693-c4c7de26048e
.. _SYR2K:  https://software.intel.com/en-us/node/d2a17c66-4265-4c56-84b9-2817ded7ee29
.. _TRMM:   https://software.intel.com/en-us/node/60775edf-9a2b-4ad4-a627-dabbd24dcc80
.. _TRSM:   https://software.intel.com/en-us/node/fc848297-8a33-42e6-826f-f4ae361c1800
.. _GBMV:   https://software.intel.com/en-us/node/181e3c0c-e04a-4464-b87c-7e5d085f38a8
.. _GEMV:   https://software.intel.com/en-us/node/78589c78-9c40-4846-b698-2c36e04b8869
.. _GER:    https://software.intel.com/en-us/node/94156ede-4add-4830-940e-1ca5688abe88
.. _GERC:   https://software.intel.com/en-us/node/f0469e83-40cc-40a0-9cd7-eeb8ea718aae
.. _GERU:   https://software.intel.com/en-us/node/e62ae6d4-ba79-4034-96cc-46753ad0ec63
.. _HBMV:   https://software.intel.com/en-us/node/02ca78c6-cad1-4c31-a6eb-5c645e862a52
.. _HEMV:   https://software.intel.com/en-us/node/5c5972fb-d88f-4e32-8c4c-66f004945097
.. _HER:    https://software.intel.com/en-us/node/c47a886b-8816-4cb6-be84-124b7ac70259
.. _HER2:   https://software.intel.com/en-us/node/e2ddc00b-d8a5-4cc7-96f7-d08882151431
.. _HPMV:   https://software.intel.com/en-us/node/fc602a99-7cb3-44f7-a22e-a89de255181a
.. _HPR:    https://software.intel.com/en-us/node/60392a82-4400-4c9c-9c14-7a2e0cea4025
.. _HPR2:   https://software.intel.com/en-us/node/163c6278-762f-40d7-8214-788d46ca4ea9
.. _SBMV:   https://software.intel.com/en-us/node/9a02d0da-7aa4-4c5d-be91-78d4ce4a42e9
.. _SPMV:   https://software.intel.com/en-us/node/fcd03a47-3896-4ad9-b0f9-1600c67deaa8
.. _SPR:    https://software.intel.com/en-us/node/3a77ea66-38a4-42cd-ac6b-68c34c9f7e13
.. _SPR2:   https://software.intel.com/en-us/node/9e17a098-ccbb-4cd4-9695-72c60a69904b
.. _SYMV:   https://software.intel.com/en-us/node/687edc3e-fe76-4635-a425-40aab089cefc
.. _SYR:    https://software.intel.com/en-us/node/08ab04b6-7aa7-4ce0-a69c-d4a4bc326ebe
.. _SYR2:   https://software.intel.com/en-us/node/c2c54a2e-98d0-466a-a6b3-ae5f8cada666
.. _TBMV:   https://software.intel.com/en-us/node/ae4b8c9d-8af2-4c5c-9e30-a8075cfef635
.. _TBSV:   https://software.intel.com/en-us/node/f66b8633-aa82-4a54-ba5f-7aeaa40fc4f0
.. _TPMV:   https://software.intel.com/en-us/node/00b446f2-5adb-4c7d-a4f5-3a63fee8f20d
.. _TPSV:   https://software.intel.com/en-us/node/daea8c6c-7e29-461a-86d9-1ad01ae82cd6
.. _TRMV:   https://software.intel.com/en-us/node/ce930002-ce05-4c38-a613-62931e024078
.. _TRSV:   https://software.intel.com/en-us/node/4a450630-f24a-442e-94e2-e8f4e4ae4819
.. _ASUM:   https://software.intel.com/en-us/node/ae455054-52b2-460a-8887-12192e01d899
.. _AXPY:   https://software.intel.com/en-us/node/c8cbb256-eab7-4629-80ff-14029038e6b7
.. _COPY:   https://software.intel.com/en-us/node/7e841640-7c31-4cd1-bc44-34f7d2343215
.. _DOT:    https://software.intel.com/en-us/node/961a869b-14d9-4e4e-98fd-9ca13802c671
.. _SDOT:   https://software.intel.com/en-us/node/7eaa9448-1ef0-404d-b8fb-c233a6b0142f
.. _DOTC:   https://software.intel.com/en-us/node/a2c46a8c-343b-401d-88b6-9a6b88a4fa47
.. _DOTU:   https://software.intel.com/en-us/node/e81ff20a-c401-4a15-a64f-cc0daa2bd65d
.. _NRM2:   https://software.intel.com/en-us/node/aca1a6dc-60a0-4689-becc-2e0f4662c093
.. _ROT:    https://software.intel.com/en-us/node/d8e66614-3ad9-4a37-90e8-3ef59e559ad6
.. _ROTG:   https://software.intel.com/en-us/node/1a7e7c3a-e209-4c7a-b8ea-00c60e103e1f
.. _ROTM:   https://software.intel.com/en-us/node/104aa6a5-5eef-4a3b-badf-78534ee1dee4
.. _ROTMG:  https://software.intel.com/en-us/node/9ea3f8dd-fe3f-4a8a-ba12-ec25fabda6e6
.. _SCAL:   https://software.intel.com/en-us/node/54f97254-4ed4-46ce-90f9-aa3c745ad840
.. _SWAP:   https://software.intel.com/en-us/node/54a2904f-b8ed-4a5f-a0f2-a2be10d61495
.. _AMAX:   https://software.intel.com/en-us/node/acb0d496-e032-4cf3-82f9-92b2e0bfc6d1
.. _AMIN:   https://software.intel.com/en-us/node/50dceaa5-3463-402f-8065-a48bc68e0888
.. _CABS1:  https://software.intel.com/en-us/node/64961e94-92d0-4671-90e6-86995e259a85

.. BLAS Module TODO:
  - Clearer compiler errors instead of using where-clauses
  - Support more implementations using config param-wrapped require statements
    - related: general RequireMKL module
  - More consistent documentation
  - Support banded/packed matrix routines


.. data:: config param isBLAS_MKL = false

   
   Tells the BLAS module to look for ``mkl_cblas.h`` instead of ``cblas.h``.
   Set this to `true` if you are using the Intel MKL BLAS implementation.
   

.. function:: proc isBLASType(type t) param: bool

   Return `true` if type is supported by BLAS 

.. enum:: enum Order { Row = 101: c_int, Col }

   Define row or column order 


.. enum:: enum Op { N = 111: c_int, T, H }

   Operation of matrix : none, transpose, or adjoint 


.. enum:: enum Uplo { Upper = 121: c_int, Lower }

   Storage for symmetric matrices 


.. enum:: enum Diag { NonUnit = 131: c_int, Unit }

   Assume a unit or non-unit diagonal 


.. enum:: enum Side { Left = 141: c_int, Right }

   Operate on the left or right side 


.. function:: proc gemm(A: [?Adom], B: [?Bdom], C: [?Cdom], alpha, beta, opA: Op = Op.N, opB: Op = Op.N, order: Order = Order.Row)

   
   Wrapper for the `GEMM`_ routines::
   
     C := alpha * op(A) * op(B) + beta * C
   
   

.. function:: proc symm(A: [?Adom], B: [?Bdom], C: [?Cdom], alpha, beta, uplo: Uplo = Uplo.Upper, side: Side = Side.Left, order: Order = Order.Row)

   
   Wrapper for the `SYMM`_ routines::
   
     C := alpha * A * B + beta * C
   
   or::
   
     C := alpha * B * A + beta * C
   
   where ``A`` is a symmetric matrix.
   

.. function:: proc hemm(A: [?Adom], B: [?Bdom], C: [?Cdom], alpha, beta, uplo: Uplo = Uplo.Upper, side: Side = Side.Left, order: Order = Order.Row)

   
   Wrapper for the `HEMM`_ routines::
   
     C := alpha * A * B + beta * C
   
   or::
   
     C := alpha * B * A + beta * C
   
   where ``A`` is an hermitian matrix.
   

.. function:: proc syrk(A: [?Adom], C: [?Cdom], alpha, beta, uplo: Uplo = Uplo.Upper, trans: Op = Op.N, order: Order = Order.Row)

   
   Wrapper for the `SYRK`_ routines::
   
     C := alpha * A * A**T + beta * C
   
   or::
   
     C := alpha * A**T * A + beta * C
   
   
   where ``C`` is a symmetric matrix, and ``A**T`` is the transpose of ``A``.
   

.. function:: proc herk(A: [?Adom], C: [?Cdom], alpha, beta, uplo: Uplo = Uplo.Upper, trans: Op = Op.N, order: Order = Order.Row)

   
   Wrapper for the `HERK`_ routines::
   
     C := alpha * A * A**H + beta * C
   
   or::
   
     C := alpha * A**H * A + beta * C
   
   where ``C`` is an hermitian matrix, and ``A**H`` is the conjugate transpose
   of ``A``.
   

.. function:: proc syr2k(A: [?Adom], B: [?Bdom], C: [?Cdom], alpha, beta, uplo: Uplo = Uplo.Upper, trans: Op = Op.N, order: Order = Order.Row)

   
   Wrapper for the `SYR2K`_ routines::
   
     C := alpha * A * B**T + alpha * B * A**T +  beta * C
   
   or::
   
     C := alpha * A**T * B + alpha * B**T * A +  beta * C
   
   where ``C`` is a symmetric matrix, and ``A**T`` and ``B**T`` are the
   transpose of ``A`` and ``B`` , respectively.
   

.. function:: proc her2k(A: [?Adom], B: [?Bdom], C: [?Cdom], alpha, beta, uplo: Uplo = Uplo.Upper, trans: Op = Op.N, order: Order = Order.Row)

   
   Wrapper for the `HER2K`_ routines::
   
     C := alpha * A * B**H + conjg(alpha) * B * A**H +  beta * C
   
   or::
   
     C := alpha * A**H * B + conjg(alpha) * B**H * A +  beta * C
   
   where ``C`` is an hermitian matrix, ``B**H`` is the conjugate transpose of
   ``B`` , ``conjg(alpha)`` is the complex conjugate of ``alpha``.
   

.. function:: proc trmm(A: [?Adom] ?eltType, B: [?Bdom] eltType, alpha, uplo: Uplo = Uplo.Upper, trans: Op = Op.N, side: Side = Side.Left, diag: Diag = Diag.NonUnit, order: Order = Order.Row) throws

   
   Wrapper for the `TRMM`_ routines::
   
     B := alpha * op(A) * B
   
   or::
   
     B := alpha * B * op(A)
   
   where ``A`` is a triangular matrix.
   

.. function:: proc trsm(A: [?Adom], B: [?Bdom], alpha, uplo: Uplo = Uplo.Upper, trans: Op = Op.N, side: Side = Side.Left, diag: Diag = Diag.NonUnit, order: Order = Order.Row) throws

   
   Wrapper for the `TRSM`_ routines::
   
     op(A) * X = alpha * B
   
   or::
   
     X * op(A) = alpha * B
   
   where ``A`` is a triangular matrix.
   

.. function:: proc gemv(A: [?Adom] ?eltType, x: [?xdom] eltType, y: [?ydom] eltType, alpha, beta, opA: Op = Op.N, order: Order = Order.Row, incx: c_int = 1, incy: c_int = 1)

   
   Wrapper for the `GEMV`_ routines::
   
     y := alpha*op(A)*x + beta*y,
   
   where ``A`` is an ``m``x``n`` matrix.
   

.. function:: proc ger(A: [?Adom] ?eltType, X: [?Xdom] eltType, Y: [?Ydom] eltType, alpha, order: Order = Order.Row, incx: c_int = 1, incy: c_int = 1)

   
   Wrapper for `GER`_ routines::
   
     A := alpha*x*y'+ A
   
   

.. function:: proc gerc(A: [?Adom] ?eltType, X: [?Xdom] eltType, Y: [?Ydom] eltType, ref alpha: eltType, order: Order = Order.Row, incx: c_int = 1, incy: c_int = 1)

   
   Wrapper for `GERC`_ routines::
   
     A := alpha*x*conjg(y') + A
   
   

.. function:: proc geru(A: [?Adom] ?eltType, X: [?Xdom] eltType, Y: [?Ydom] eltType, ref alpha: eltType, order: Order = Order.Row, incx: c_int = 1, incy: c_int = 1)

   
   Wrapper for the `GERU`_ routines::
   
     A := alpha*x*y' + A
   
   

.. function:: proc hemv(A: [?Adom] ?eltType, X: [?vDom] eltType, Y: [vDom] eltType, ref alpha: eltType, ref beta: eltType, order: Order = Order.Row, uplo: Uplo = Uplo.Upper, incx: c_int = 1, incy: c_int = 1) throws

   
   Wrapper for the `HEMV`_ routines::
   
     y := alpha*A*x + beta*y
   
   

.. function:: proc her(A: [?Adom] ?eltType, X: [?vDom] eltType, alpha, order: Order = Order.Row, uplo: Uplo = Uplo.Upper, incx: c_int = 1) throws

   
   Wrapper for the `HER`_ routines::
   
     A := alpha*x*conjg(x') + A
   
   

.. function:: proc her2(A: [?Adom] ?eltType, X: [?vDom] eltType, Y: [vDom] eltType, ref alpha: eltType, order: Order = Order.Row, uplo: Uplo = Uplo.Upper, incx: c_int = 1, incy: c_int = 1) throws

   
   Wrapper for `HER2`_ routines::
   
     A := alpha *x*conjg(y') + conjg(alpha)*y *conjg(x') + A
   
   

.. function:: proc symv(A: [?Adom] ?eltType, X: [?vDom] eltType, Y: [vDom] eltType, alpha, beta, order: Order = Order.Row, uplo: Uplo = Uplo.Upper, incx: c_int = 1, incy: c_int = 1) throws

   
   Wrapper for the `SYMV`_ routines::
   
     y := alpha*A*x + beta*y
   
   

.. function:: proc syr(A: [?Adom] ?eltType, X: [?vDom] eltType, alpha, order: Order = Order.Row, uplo: Uplo = Uplo.Upper, incx: c_int = 1) throws

   
   Wrapper for `SYR`_ routines::
   
     A := alpha*x*x' + A
   
   

.. function:: proc syr2(A: [?Adom] ?eltType, X: [?vDom] eltType, Y: [vDom] eltType, alpha, order: Order = Order.Row, uplo: Uplo = Uplo.Upper, incx: c_int = 1, incy: c_int = 1) throws

   
   Wrapper for `SYR2`_ routines::
   
     A := alpha*x*y'+ alpha*y*x' + A
   
   

.. function:: proc trmv(A: [?Adom] ?eltType, X: [?vDom] eltType, trans: Op = Op.N, order: Order = Order.Row, uplo: Uplo = Uplo.Upper, diag: Diag = Diag.NonUnit, incx: c_int = 1) throws

   
   Wrapper for `TRMV`_ routines::
   
     x := op(A)*x
   
   

.. function:: proc trsv(A: [?Adom] ?eltType, B: [?vDom] eltType, trans: Op = Op.N, order: Order = Order.Row, uplo: Uplo = Uplo.Upper, diag: Diag = Diag.NonUnit, incx: c_int = 1) throws

   
   Wrapper for the `TRSV`_ routines::
   
     A*op(x) = b
   
   

.. function:: proc rotg(ref a: ?eltType, ref b: eltType, ref c: eltType, ref s: eltType)

   
   Wrapper for the `ROTG`_ routines
   
   Construct `Givens plane rotation <https://en.wikipedia.org/wiki/Givens_rotation>`_
   of point ``p`` defined by Cartesian coordinates ``(a, b)``::
   
     | c  s |   |a|   |r|
     |      | . | | = | |
     |-s  c |   |b|   |0|
   
   **Input:**
   
   - ``a``: x-coordinate of point ``p``
   - ``b``: y-coordinate of point ``p``
   
   **Output:**
   
   - ``a``: stores length vector (``r``) of inputs ``(a, b)``
   - ``b``: stores ``z`` parameter that is defined below
   - ``c``: stores value of ``c`` element defined above
   - ``s``: stores value of ``s`` element defined above
   
   The ``z`` parameter (stored in ``b``) is defined such that::
   
     if |a| > |b| then z = s;
     else if c != 0 then z = 1/c;
     else z = 1
   
   

.. function:: proc rotmg(ref d1: ?eltType, ref d2: eltType, ref b1: eltType, b2: eltType, P: [] eltType) throws

   
   Wrapper for the `ROTMG`_ routines
   
   Generate Givens rotation of points::
   
      |b1|     |b1*sqrt(d1)|
      |  | = H.|           |
      |0 |     |b2*sqrt(d2)|
   
   **Input:**
   
   - ``d1``: Scaling factor for ``b1`` (x-axis)
   - ``d2``: Scaling factor for ``b2`` (y-axis)
   - ``b1``: x-coordinate of input vector
   - ``b2``: y-coordinate of input vector
   
   **Output:**
   
   - ``d1``: Provides the first element the diagonal matrix
   - ``d2``: Provides the second element the diagonal matrix
   - ``b1``: Provides the ``b1`` rotated (rotated x coordination) of the vector
   - ``P``: Parameter array of 5 elements, detailed below::
   
   
                              |P[1] P[3]|
      if P[0] == -1 then  H = |         |
                              |P[2] P[4]|
   
                              |1.0  P[3]|
      if P[0] ==  0 then  H = |         |
                              |P[2]  1.0|
   
                              |P[1]  1.0|
      if P[0] == 1 then   H = |         |
                              |-1.0 P[4]|
   
                              |1   0|
      if P[0] == -2 then  H = |     |
                              |0   1|
   
   
   
   

.. function:: proc rot(X: [?D] ?eltType, Y: [D] eltType, c: eltType, s: eltType, incY: c_int = 1, incX: c_int = 1)

   
   Wrapper for the `ROT`_ routines
   
   Replaces the value elements of two vectors ``X`` and ``Y`` using the equation::
   
     X[i] = c*X[i] + s*X[i]
     Y[i] = c*Y[i] - s*X[i]
   
   **Input:**
   
   - ``X``: Input vector
   - ``Y``: Input vector
   - ``c``: Scalar parameter
   - ``s``: Scalar parameter
   - ``incY``: Defines the increment for the vector ``Y``
   - ``incX``: Defines the increment for the vector ``X``
   
   **Output:**
   
   - ``X``: Vector with updated elements
   - ``Y``: Vector with updated elements
   
   
   

.. function:: proc rotm(X: [?D] ?eltType, Y: [D] eltType, P: [] eltType, incY: c_int = 1, incX: c_int = 1) throws

   
   Wrapper for the `ROTM`_ routines
   
   Executes the modified `Givens rotations <https://en.wikipedia.org/wiki/Givens_rotation>`_ with element wise  substitution::
   
      |X[i]|     |X[i]|
      |    | = H.|    |
      |Y[i]|     |Y[i]|
   
   **Input:**
   
   - ``X``: Input vector
   - ``Y``: Input vector
   - ``incY``: Defines the increment for the vector ``Y``
   - ``incX``: Defines the increment for the vector ``X``
   - ``P``: Parameter array of 5 elements, detailed below::
   
   
                              |P[1] P[3]|
      if P[0] == -1 then  H = |         |
                              |P[2] P[4]|
   
                              |1.0  P[3]|
      if P[0] ==  0 then  H = |         |
                              |P[2]  1.0|
   
                              |P[1]  1.0|
      if P[0] == 1 then   H = |         |
                              |-1.0 P[4]|
   
                              |1   0|
      if P[0] == -2 then  H = |     |
                              |0   1|
   
   **Output:**
   
   - ``X``: Vector with updated elements
   - ``Y``: Vector with updated elements
   
   

.. function:: proc swap(X: [?D] ?eltType, Y: [D] eltType, incY: c_int = 1, incX: c_int = 1)

   
   Wrapper for the `SWAP`_ routines
   
   Exchanges elements of two vectors.
   
   **Input:**
   
   - ``X``: Input vector
   - ``Y``: Input vector
   - ``incY``: Defines the increment for the vector ``Y``
   - ``incX``: Defines the increment for the vector ``X``
   
   **Output:**
   
   - ``X``: Contains input ``Y`` elements
   - ``Y``: Contains input ``X`` elements
   
   

.. function:: proc scal(X: [?D] ?eltType, ref alpha: eltType, incX: c_int = 1)

   
   Wrapper for the `SCAL`_ routines
   
   Calculates the product of a vector ``X`` with scalar alpha::
   
     X' = alpha*X
   
   **Input:**
   
   - ``X``: Input vector
   - ``alpha``: Scalar parameter
   
   **Output:**
   
   - ``X``: Vector updated by the equation: ``X[i] = alpha*X[i]``
   
   

.. function:: proc copy(X: [?D] ?eltType, Y: [D] eltType, incY: c_int = 1, incX: c_int = 1)

   
   Wrapper for the `COPY`_ routines
   
   Copies one vector (``X`` the source) to another (``Y`` the destination)::
   
     Y = X
   
   **Input:**
   
   - ``X``: Input vector
   - ``Y``: Input vector
   - ``incX``: Defines the increment for the vector ``X``
   - ``incY``: Defines the increment for the vector ``Y``
   
   **Output:**
   
   ``Y``: Contains the values copied from ``X`` vector
   
   

.. function:: proc axpy(X: [?D] ?eltType, Y: [D] eltType, ref alpha: eltType, incY: c_int = 1, incX: c_int = 1)

   
   Wrapper for the `AXPY`_ routines
   
   Computes the vector-scalar product of apha and ``X`` and adds the result to
   ``Y``::
   
     Y = alpha*X + Y
   
   **Input:**
   
   - ``X``: Input vector
   - ``alpha``: Scalar parameter
   - ``incX``: Defines the increment for the vector ``X``
   - ``incY``: Defines the increment for the vector ``Y``
   
   **Output:**
   
   - ``Y``: Vector updated by the equation: ``Y[i] = alpha*X[i]+Y[i]``
   
   

.. function:: proc dot(X: [?xD] ?eltType, Y: [?yD] eltType, incY: c_int = 1, incX: c_int = 1): eltType

   
   Wrapper for `DOT`_ routines
   
   Returns  the dot product of two vectors::
   
      X*Y
   
   **Input:**
   
   - ``X``: Input vector
   - ``Y``: Input vector
   - ``incX``: Defines the increment for the vector ``X``
   - ``incY``: Defines the increment for the vector ``Y``
   
   :returns: Scalar value of dot product
   

.. function:: proc dotu(X: [?D] ?eltType, Y: [D] eltType, incY: c_int = 1, incX: c_int = 1)

   
     Wrapper for  `DOTU`_ routines (``DOTU_SUB``)
   
     Obtains the dot product of two complex vectors::
   
        X*Y
   
     **Input:**
   
     - ``X``: Input vector
     - ``Y``: Input vector
     - ``incX``: Defines the increment for the vector ``X``
     - ``incY``: Defines the increment for the vector ``Y``
   
   :returns: The complex dot product
   
   
   

.. function:: proc dotc(X: [?D] ?eltType, Y: [D] eltType, incY: c_int = 1, incX: c_int = 1)

   
   Wrapper for `DOTC`_ routines (``DOTC_SUB``)
   
   Obtains the dot product of conjugated X vector with Y vector::
   
      conj(X)*Y
   
   **Input:**
   
   - ``X``: Conjugated input vector
   - ``Y``: Input vector
   - ``incX``: Defines the increment for the vector ``X``
   - ``incY``: Defines the increment for the vector ``Y``
   
   :returns: The complex dot product
   
   
   

.. function:: proc dsdot(X: [?D] real(32), Y: [D] real(32), incY: c_int = 1, incX: c_int = 1): real(64)

   
   Wrapper for `SDOT`_ routines (``DSDOT`` variant)
   
   Returns the dot product of two ``real(32)`` vectors as a ``real(64)``,
   using ``real(64)`` precision internally::
   
      X*Y
   
   **Input:**
   
   - ``X``: Input vector
   - ``Y``: Input vector
   - ``incX``: Defines the increment for the vector ``X``
   - ``incY``: Defines the increment for the vector ``Y``
   
   :returns: Scalar value of dot product
   
   
   

.. function:: proc sdsdot(X: [?D] real(32), Y: [D] real(32), incY: c_int = 1, incX: c_int = 1): real(32)

   
   Wrapper for `SDOT`_ routines (``SDSDOT`` variant)
   
   Returns the dot product of two ``real(32)`` vectors as a ``real(32)``,
   using ``real(64)`` precision internally::
   
      X*Y
   
   **Input:**
   
   - ``X``: Input vector
   - ``Y``: Input vector
   - ``incX``: Defines the increment for the vector ``X``
   - ``incY``: Defines the increment for the vector ``Y``
   
   :returns: Scalar value of dot product
   
   
   

.. function:: proc nrm2(X: [?D] ?eltType, incX: c_int = 1)

   
   Wrapper for `NRM2`_ routines
   
   Returns the  Euclidean norm of vector ``X``::
   
     ||X||
   
   **Input:**
   
   - ``X``: Input vector
   - ``incX``: Defines the increment for the vector ``X``
   
   :returns: The 2-norm of ``X`` vector
   
   

.. function:: proc asum(X: [?D] ?eltType, incX: c_int = 1)

   
   Wrapper for the `ASUM`_ routines
   
   Returns the sum of the magnitude values of X elements::
   
     |Re X[1]| + |Im X[1]| + |Re  X[2]| + |Im  X[2]|+ ... + |Re  X[N]| + |Im X[N]|.
   
   **Input:**
   
   - ``X``: Input vector
   - ``incX``: Defines the increment for the vector ``X``
   
   :returns: The 1-norm of ``X`` vector
   
   

.. function:: proc amax(X: [?D] ?eltType, incX: c_int = 1)

   
   Wrapper for `AMAX`_ routines
   
   Returns the index of element in the vector with maximum absolute value.
   
   **Input:**
   
   - ``X``: Input vector
   - ``incX``: Defines the increment for the vector ``X``
   
   :returns: The index of maximum absolute value
   
   

