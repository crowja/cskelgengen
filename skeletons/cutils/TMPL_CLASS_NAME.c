/**
 *  @file TMPL_CLASS_NAME.c
 *  @version TMPL_CLASS_VERSION
 *  @date %TODAY%
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <string.h>                              /* FIXME */
#include "TMPL_CLASS_NAME.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

static const char version[] = "TMPL_CLASS_VERSION";

/*** TMPL_CLASS_TAG_func1() ***/

int
TMPL_CLASS_TAG_func1(const char *cp)
{
   /* Do some magic here ... */

   return 0;
}

/*** TMPL_CLASS_TAG_version() ***/

const char *
TMPL_CLASS_TAG_version(void)
{
   return version;
}

#undef _IS_NULL
#undef _FREE
