/**
 *  @file main.c
 *  @version 0.0-alpha
 *  @date %TODAY%
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <string.h>                              /* FIXME */
#include "main.h"
#include "options.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

#define QUOTE(name) #name
#define STR(macro) QUOTE(macro)
#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION dev
#endif
#define PACKAGE_VERSION_STR STR(PACKAGE_VERSION)

int
main(int argc, char *argv[])
{
   struct options *o = options_new();

   options_parse(o, argc, argv);

   /** options_parse() needs to deliver a few things, particularly:
    *     the name of the numerical features file, if any
    *     the name of the categorical features
    */

   if (o->version_flag) {
       printf("prog_name %s\n", PACKAGE_VERSION_STR);
       exit(0);
   }

   options_free(o);
   return 0;
}

#undef _IS_NULL
#undef _FREE
