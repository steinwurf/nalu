====
nalu
====

|Linux make-specs| |Windows make-specs| |MacOS make-specs| |Linux CMake| |Windows CMake| |MacOS CMake| |Valgrind| |No Assertions| |Clang Format| |Cppcheck|

.. |Linux make-specs| image:: https://github.com/steinwurf/nalu/actions/workflows/linux_mkspecs.yml/badge.svg
   :target: https://github.com/steinwurf/nalu/actions/workflows/linux_mkspecs.yml
   
.. |Windows make-specs| image:: https://github.com/steinwurf/nalu/actions/workflows/windows_mkspecs.yml/badge.svg
   :target: https://github.com/steinwurf/nalu/actions/workflows/windows_mkspecs.yml

.. |MacOS make-specs| image:: https://github.com/steinwurf/nalu/actions/workflows/macos_mkspecs.yml/badge.svg
   :target: https://github.com/steinwurf/nalu/actions/workflows/macos_mkspecs.yml
   
.. |Linux CMake| image:: https://github.com/steinwurf/nalu/actions/workflows/linux_cmake.yml/badge.svg
   :target: https://github.com/steinwurf/nalu/actions/workflows/linux_cmake.yml

.. |Windows CMake| image:: https://github.com/steinwurf/nalu/actions/workflows/windows_cmake.yml/badge.svg
   :target: https://github.com/steinwurf/nalu/actions/workflows/windows_cmake.yml
   
.. |MacOS CMake| image:: https://github.com/steinwurf/nalu/actions/workflows/macos_cmake.yml/badge.svg
   :target: https://github.com/steinwurf/nalu/actions/workflows/macos_cmake.yml

.. |Clang Format| image:: https://github.com/steinwurf/nalu/actions/workflows/clang-format.yml/badge.svg
   :target: https://github.com/steinwurf/nalu/actions/workflows/clang-format.yml

.. |No Assertions| image:: https://github.com/steinwurf/nalu/actions/workflows/nodebug.yml/badge.svg
   :target: https://github.com/steinwurf/nalu/actions/workflows/nodebug.yml

.. |Valgrind| image:: https://github.com/steinwurf/nalu/actions/workflows/valgrind.yml/badge.svg
   :target: https://github.com/steinwurf/nalu/actions/workflows/valgrind.yml

.. |Cppcheck| image:: https://github.com/steinwurf/nalu/actions/workflows/cppcheck.yml/badge.svg
   :target: https://github.com/steinwurf/nalu/actions/workflows/cppcheck.yml

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
