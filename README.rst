====
nalu
====

The nalu project contains helper functionality for parsing Annex B H264
streams.

The main functionality is located in these header files:

* ``src/nalu/to_annex_b_nalu.hpp``
* ``src/nalu/to_annex_b_nalus.hpp``
* ``src/nalu/annex_b_nalu.hpp``

Usage
=====

The library is header-only, so you just need to set the include path to use it.

See the unit tests in ``test/src/`` for usage/API examples.

Use as Dependency in CMake
--------------------------

To depend on this project when using the CMake build system, add the following
in your CMake build script::

   add_subdirectory("/path/to/nalu" nalu)
   target_link_libraries(<my_target> steinwurf::nalu)

Where ``<my_target>`` is replaced by your target.
