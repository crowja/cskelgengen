#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errmsg.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _COLOR_RED
#undef  _COLOR_RED
#endif
#define _COLOR_RED        "\x1B[31m"

#ifdef  _COLOR_GREEN
#undef  _COLOR_GREEN
#endif
#define _COLOR_GREEN      "\x1B[32m"

#ifdef  _COLOR_YELLOW
#undef  _COLOR_YELLOW
#endif
#define _COLOR_YELLOW     "\x1B[33m"

#ifdef  _COLOR_BLUE
#undef  _COLOR_BLUE
#endif
#define _COLOR_BLUE       "\x1B[34m"

#ifdef  _COLOR_RESET
#undef  _COLOR_RESET
#endif
#define _COLOR_RESET      "\x1B[0m"

void
errmsg_error(FILE *out, const char *info)
{
   fprintf(out, _COLOR_RED "[ERROR]" _COLOR_RESET);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}

void
errmsg_success(FILE *out, const char *info)
{
   fprintf(out, _COLOR_GREEN "[SUCCESS]" _COLOR_RESET);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}

void
errmsg_warning(FILE *out, const char *info)
{
   fprintf(out, _COLOR_YELLOW "[WARNING]" _COLOR_RESET);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}

#undef _IS_NULL
#undef _FREE
