#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errmsg.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _COLOR_CODE
#undef  _COLOR_CODE
#endif
#define _COLOR_CODE       0x1B

#ifdef  _COLOR_RED
#undef  _COLOR_RED
#endif
#define _COLOR_RED        "[1;31m"

#ifdef  _COLOR_GREEN
#undef  _COLOR_GREEN
#endif
#define _COLOR_GREEN      "[1;32m"

#ifdef  _COLOR_YELLOW
#undef  _COLOR_YELLOW
#endif
#define _COLOR_YELLOW     "[1;33m"

#ifdef  _COLOR_BLUE
#undef  _COLOR_BLUE
#endif
#define _COLOR_BLUE       "[1;34m"

#ifdef  _COLOR_RESET
#undef  _COLOR_RESET
#endif
#define _COLOR_RESET      "[0m"

void
errmsg_error(FILE *out, const char *info)
{
   fprintf(out, "%c%s%s%c%s", _COLOR_CODE, _COLOR_RED, "[ERROR]", _COLOR_CODE,
           _COLOR_RESET);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}

void
errmsg_success(FILE *out, const char *info)
{
   fprintf(out, "%c%s%s%c%s", _COLOR_CODE, _COLOR_GREEN, "[SUCCESS]", _COLOR_CODE,
           _COLOR_RESET);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}

void
errmsg_warning(FILE *out, const char *info)
{
   fprintf(out, "%c%s%s%c%s", _COLOR_CODE, _COLOR_YELLOW, "[WARNING]", _COLOR_CODE,
           _COLOR_RESET);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}

#undef _IS_NULL
#undef _FREE
