/**
 *  @file main.c
 *  @version 0.0.0
 *  @date
 *  @copyright
 *  @license Unlicense <http://unlicense.org/>
 *  @brief FIXME
 *  @details FIXME
 */

#ifdef  HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <string.h>                              /* FIXME */
#include "main.h"
#include "options.h"
#include "XXX_main.h"

#ifdef  IS_NULL
#undef  IS_NULL
#endif
#define IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  FREE
#undef  FREE
#endif
#define FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

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
      printf("*** SOME OPTIONS DELIVERED TO main.c ***\n");
      printf("appname         %s\n", o->appname);
      printf("appvers         %s\n", o->appvers);
      printf("--help          %d\n", o->help_flag);
      printf("--prefix        %s\n", o->prefix);
      printf("--quiet         %d\n", o->quiet_flag);
      printf("--verbosity     %d\n", o->verbosity);
      printf("--version_flag  %d\n", o->version_flag);
   }

   /* o->extras will be NULL or a NULL-terminated list */
   if (!IS_NULL(o->extras)) {
      unsigned    count = 0;
      char      **tp = o->extras;
      while (!IS_NULL(*tp)) {
         printf("Also %s\n", *(tp++));           /* *tp++, clarified */
         count++;
      }
      printf("HOW MANY EXTRAS? ... %d\n", count);

      if (0 == strcmp(o->extras[0], "XXX")) {
         XXX_main(count, o->extras, o);
      }
   }

   options_free(&o);
   return 0;
}

#undef IS_NULL
#undef FREE
