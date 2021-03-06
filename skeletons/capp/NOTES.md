# Dev notes on TMPL_CLASS_NAME.

## To get started

Run autoconf to generate the configure script, then run the configure script to
generate the Makefile from Makefile.in. This will help you understand what to
change in configure.ac and Makefile.in.

Clean up configure.ac. It includes, for example, using

     m4_include([m4/ax_lib_sqlite3.m4])
     AX_LIB_SQLITE3

in order to show how to incorporate local Autoconf macros. If this macro ends up
being used, it can be updated as shown below.

Makefile.in will need substantial cleaning since it contains many examples of
variables set by Autoconf templating.

## FYI

The Makefile in src is simply a convenience for the dev; it's not called by the
top-level Makefile as part of the build.

## Updating external dependencies:

     wget -Psrc \
        https://raw.githubusercontent.com/skeeto/optparse/master/optparse.h
     wget -Psrc \
        https://raw.githubusercontent.com/crowja/linewrapper/master/linewrapper.c
     wget -Psrc \
        https://raw.githubusercontent.com/crowja/linewrapper/master/linewrapper.h
     wget -Psrc \
        https://raw.githubusercontent.com/crowja/varstr/master/varstr.c
     wget -Psrc \
        https://raw.githubusercontent.com/crowja/varstr/master/varstr.h

     http://git.savannah.gnu.org/gitweb/?p=autoconf-archive.git;a=blob_plain;f=m4/ax_lib_sqlite3.m4

