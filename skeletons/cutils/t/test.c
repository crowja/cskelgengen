#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TMPL_CLASS_NAME.h"
#include "tinytest.h"


#ifdef _COLOR_CODE
#undef _COLOR_CODE
#endif
#define _COLOR_CODE      0x1B
#ifdef _COLOR_RED
#undef _COLOR_RED
#endif
#define _COLOR_RED       "[1;31m"
#ifdef _COLOR_GREEN
#undef _COLOR_GREEN
#endif
#define _COLOR_GREEN     "[1;32m"
#ifdef _COLOR_YELLOW
#undef _COLOR_YELLOW
#endif
#define _COLOR_YELLOW    "[1;33m"
#ifdef _COLOR_RESET
#undef _COLOR_RESET
#endif
#define _COLOR_RESET     "[0m"

static void
_printf_test_name(char *name, char *info)
{
   printf("%c%s%s%c%s", _COLOR_CODE, _COLOR_YELLOW, name, _COLOR_CODE, _COLOR_RESET);

   if (NULL != info)
      printf(" [%s]\n", info);
   else
      printf("\n");
}

void        test_func1(void);

void
test_func1(void)
{
   char       *cp = malloc(10000);

   _printf_test_name("test_func1()", NULL);
   memset(cp, 'a', 10000);
   ASSERT_EQUALS(0, TMPL_CLASS_TAG_func1(cp));
   free(cp);
}

#if 0                                            /* 6 yy */
void
test_stub(void)
{
   _printf_test_name("test_stub()", NULL);
   ASSERT_EQUALS(0, 0);
}
#endif

int
main(int argc, char *argv[])
{
   printf("%s\n", TMPL_CLASS_TAG_version());

   RUN(test_func1);

   return TEST_REPORT();
}
