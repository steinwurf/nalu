#! /usr/bin/env python
# encoding: utf-8

APPNAME = 'nalu'
VERSION = '4.2.0'


def build(bld):

    bld.env.append_unique(
        'DEFINES_STEINWURF_VERSION',
        'STEINWURF_NALU_VERSION="{}"'.format(
            VERSION))

    # Export nalu includes
    bld(name='nalu_includes',
        includes='./src',
        export_includes='./src')

    if bld.is_toplevel():

        # Only build tests when executed from the top-level wscript,
        # i.e. not when included as a dependency
        bld.recurse('test')
        bld.recurse('examples')
