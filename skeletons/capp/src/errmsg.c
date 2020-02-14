/**
 *  @file errmsg.c
 *  @version 0.1.0-dev0
 *  @date Sun Jan 19 23:12:14 CST 2020
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 *  @see https://github.com/crowja/hodgepodge
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errmsg.h"

#ifdef  COLOR_RED_
#undef  COLOR_RED_
#endif
#define COLOR_RED_        "\x1B[31m"

#ifdef  COLOR_GREEN_
#undef  COLOR_GREEN_
#endif
#define COLOR_GREEN_      "\x1B[32m"

#ifdef  COLOR_YELLOW_
#undef  COLOR_YELLOW_
#endif
#define COLOR_YELLOW_     "\x1B[33m"

#ifdef  COLOR_BLUE_
#undef  COLOR_BLUE_
#endif
#define COLOR_BLUE_       "\x1B[34m"

#ifdef  COLOR_RESET_
#undef  COLOR_RESET_
#endif
#define COLOR_RESET_      "\x1B[0m"

void
errmsg_error(FILE *out, const char *info)
{
   fprintf(out, COLOR_RED_ "[ERROR]" COLOR_RESET_);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}

void
errmsg_success(FILE *out, const char *info)
{
   fprintf(out, COLOR_GREEN_ "[SUCCESS]" COLOR_RESET_);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}

void
errmsg_warning(FILE *out, const char *info)
{
   fprintf(out, COLOR_YELLOW_ "[WARNING]" COLOR_RESET_);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}
