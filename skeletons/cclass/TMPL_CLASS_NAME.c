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

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

struct TMPL_CLASS_NAME {
   void       *x;
};

struct TMPL_CLASS_NAME *
TMPL_CLASS_TAG_new(void)
{
   struct TMPL_CLASS_NAME *tp;

   tp = (struct TMPL_CLASS_NAME *) malloc(sizeof(struct TMPL_CLASS_NAME));
   if (_IS_NULL(tp))
      return NULL;

   /* Do some magic here ... */

   return tp;
}

void
TMPL_CLASS_TAG_free(struct TMPL_CLASS_NAME **pp)
{

   /* Do some magic here ... */

   _FREE(*pp);
   *pp = NULL;
}

int
TMPL_CLASS_TAG_init(struct TMPL_CLASS_NAME *p, void *x)
{

   /* Do some magic here ... */
   p->x = x;                                     /* FIXME */

   return 0;
}

const char *
TMPL_CLASS_TAG_version(void)
{
   return "0.0.0";
}

#undef  _IS_NULL
#undef  _FREE
