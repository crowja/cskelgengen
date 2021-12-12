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

struct TMPL_CLASS_TAG {
   void       *x;
};

struct TMPL_CLASS_TAG *
TMPL_CLASS_TAG_new(void)
{
   struct TMPL_CLASS_TAG *tp;

   tp = (struct TMPL_CLASS_TAG *) malloc(sizeof(struct TMPL_CLASS_TAG));
   if (IS_NULL(tp))
      return NULL;

   /* Do some magic here ... */

   return tp;
}

void
TMPL_CLASS_TAG_free(struct TMPL_CLASS_TAG **pp)
{

   /* Do some magic here ... */

   FREE(*pp);
   *pp = NULL;
}

int
TMPL_CLASS_TAG_init(struct TMPL_CLASS_TAG *p, void *x)
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

#undef  IS_NULL
#undef  FREE
