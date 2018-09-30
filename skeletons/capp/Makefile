SHELL = /bin/bash

.PHONY: clean

# Example of how to template for variables set by configure
howdy:
	echo "The OPENMP_CFLAGS ARE: -fopenmp"

clean:
	$(RM) *.o *~

# PACKAGE_NAME      is My new package
# PACKAGE_TARNAME   is my_new_pkg
# PACKAGE_VERSION   is 0.0-alpha
# PACKAGE_STRING    is My new package 0.0-alpha
# PACKAGE_BUGREPORT is crowja@gmail.com
# PACKAGE_URL       is http://example.com
#
# builddir          is .
# abs_builddir      is /home/jac/Projects/cskelgengen/skeletons/capp
# top_builddir      is .
# abs_top_builddir  is /home/jac/Projects/cskelgengen/skeletons/capp
# 
# srcdir            is .
# abs_srcdir        is /home/jac/Projects/cskelgengen/skeletons/capp
# top_srcdir        is .
# abs_top_srcdir    is /home/jac/Projects/cskelgengen/skeletons/capp
#
# CFLAGS            is -g -O2
# DEFS              is -DPACKAGE_NAME=\"My\ new\ package\" -DPACKAGE_TARNAME=\"my_new_pkg\" -DPACKAGE_VERSION=\"0.0-alpha\" -DPACKAGE_STRING=\"My\ new\ package\ 0.0-alpha\" -DPACKAGE_BUGREPORT=\"crowja@gmail.com\" -DPACKAGE_URL=\"http://example.com\"
# LDFLAGS           is 
# LIBS              is 
#
# prefix            is /tmp/junk
# exec_prefix       is ${prefix}

distclean:
	$(MAKE) clean
	$(RM) -r autom4te.cache  config.status config.log

