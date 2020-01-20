/**
 *  @file main.c
 *  @version 0.0.0
 *  @date
 *  @copyright 2020
 *  @license Unlicense <http://unlicense.org/>
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

int
main(int argc, char *argv[])
{
   struct options *o = options_new();

   options_parse(o, argc, argv);

   if (o->help_flag) {
      options_help_msg(o, stdout);
      options_free(&o);
      exit(0);
   }

   if (o->version_flag) {
      printf("%s version %s\n", o->appname, o->appvers);
      options_free(&o);
      exit(0);
   }

   if (o->quiet_flag)
      o->verbosity = 0;

   if (o->verbosity > 0) {
      printf("*** SOME OPTIONS DELIVERED TO MAIN.C ***\n");
      printf("appname         %s\n", o->appname);
      printf("appvers         %s\n", o->appvers);
      printf("--help          %d\n", o->help_flag);
      printf("--prefix        %s\n", o->prefix);
      printf("--quiet         %d\n", o->quiet_flag);
      printf("--verbosity     %d\n", o->verbosity);
      printf("--version_flag  %d\n", o->version_flag);
   }

   /* o->extras will be NULL or a NULL-terminated list */
   if (!_IS_NULL(o->extras)) {
      char      **tp = o->extras;
      while (!_IS_NULL(*tp))
         printf("Also %s\n", *(tp++));           /* *tp++, clarified */
   }

   options_free(&o);
   return 0;
}

#undef _IS_NULL
#undef _FREE
