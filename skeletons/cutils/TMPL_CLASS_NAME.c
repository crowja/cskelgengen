/**
 *  @file TMPL_CLASS_NAME.c
 *  @version 0.0.0
 *  @date
 *  @copyright
 *  @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <string.h>                              /* FIXME */
#include "TMPL_CLASS_NAME.h"

#ifdef  IS_NULL
#undef  IS_NULL
#endif
#define IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  FREE
#undef  FREE
#endif
#define FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

int
TMPL_CLASS_TAG_func1(const char *cp)
{
   /* Do some magic here ... */

   return 0;
}

const char *
TMPL_CLASS_TAG_version(void)
{
   return "0.0.0";
}

#undef IS_NULL
#undef FREE
