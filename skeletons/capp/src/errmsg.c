/**
 *  @file errmsg.c
 *  @version 0.1.0-dev0
 *  @date Sun Feb 16, 2020 07:41:25 PM CST
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 *  @see https://github.com/crowja/hodgepodge
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errmsg.h"

#ifdef  COLOR_RED
#undef  COLOR_RED
#endif
#define COLOR_RED        "\x1B[31m"

#ifdef  COLOR_GREEN
#undef  COLOR_GREEN
#endif
#define COLOR_GREEN      "\x1B[32m"

#ifdef  COLOR_YELLOW
#undef  COLOR_YELLOW
#endif
#define COLOR_YELLOW     "\x1B[33m"

#ifdef  COLOR_BLUE
#undef  COLOR_BLUE
#endif
#define COLOR_BLUE       "\x1B[34m"

#ifdef  COLOR_RESET
#undef  COLOR_RESET
#endif
#define COLOR_RESET      "\x1B[0m"

void
errmsg_error(FILE *out, const char *info)
{
   fprintf(out, COLOR_RED "[ERROR]" COLOR_RESET);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}

void
errmsg_success(FILE *out, const char *info)
{
   fprintf(out, COLOR_GREEN "[SUCCESS]" COLOR_RESET);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}

void
errmsg_warning(FILE *out, const char *info)
{
   fprintf(out, COLOR_YELLOW "[WARNING]" COLOR_RESET);

   if (NULL != info)
      printf(" %s", info);

   printf("\n");
}
