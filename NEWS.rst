News for nalu
=============

This file lists the major changes between versions. For a more detailed list of
every change, see the Git log.

Latest
------
* tbd

4.2.0
-----
* Minor: Added install step to CMake.

4.1.0
-----
* Minor: Added CMake build file.
* Minor: Added inspect example.

4.0.0
-----
* Major: Renamed ``nalu_type_from_header.hpp`` -> ``type_from_header.hpp``.
* Major: Renamed ``nalu_type_from_header`` -> ``type_from_header``.
* Major: Renamed ``nalu_type_to_string.hpp`` -> ``type_to_string.hpp``.
* Major: Renamed ``nalu_type_to_string`` -> ``type_to_string``.
* Major: Renamed ``nalu_type.hpp`` -> ``type.hpp``.
* Major: Renamed ``nalu_type`` -> ``type``.
* Major: ``annex_b_nalu`` now has a two constructors, one for constructing
  valid nalus and one for constructing invalid nalus. The validity of a nalu
  can be checked with the ``is_valid`` member function and
  the ``operator bool()``.
* Major: Renamed ``annex_b_nalu::startcode_size`` ->
  ``annex_b_nalu::start_code_size``.

3.0.0
-----
* Major: Upgrade to waf-tools 4
* Minor: Upgrade to gtest 4
* Major: Removed sak dependency.

2.1.0
-----
* Minor: Improve nalu tags.

2.0.0
-----
* Major: Rename from n4lu to nalu.

1.0.0
-----
* Initial release.
