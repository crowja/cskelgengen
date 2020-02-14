#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "TMPL_CLASS_NAME.h"
#include "tinytest.h"

#ifdef  COLOR_CODE_
#undef  COLOR_CODE_
#endif
#define COLOR_CODE_      0x1B
#ifdef  COLOR_RED_
#undef  COLOR_RED_
#endif
#define COLOR_RED_       "[1;31m"
#ifdef  COLOR_GREEN_
#undef  COLOR_GREEN_
#endif
#define COLOR_GREEN_     "[1;32m"
#ifdef  COLOR_YELLOW_
#undef  COLOR_YELLOW_
#endif
#define COLOR_YELLOW_    "[1;33m"
#ifdef  COLOR_RESET_
#undef  COLOR_RESET_
#endif
#define COLOR_RESET_     "[0m"

static void
printf_test_name(char *name, char *info)
{
   printf("%c%s%s%c%s", COLOR_CODE_, COLOR_YELLOW_, name, COLOR_CODE_, COLOR_RESET_);

   if (NULL != info)
      printf(" [%s]\n", info);
   else
      printf("\n");
}

static int
two_doubles_equal(double x, double y)
{
   double      t = fabs(x) + fabs(y);
   return fabs(x - y) < 4 * DBL_EPSILON * t ? 1 : 0;
}

static void
test_func1(void)
{
   char       *cp = malloc(10000);

   printf_test_name("test_func1", "TMPL_CLASS_TAG_func1");
   memset(cp, 'a', 10000);
   ASSERT_EQUALS(0, TMPL_CLASS_TAG_func1(cp));
   free(cp);
}

/* 7 yy */
static void
test_stub(void)
{
   ASSERT("test 1 in test_stub", two_doubles_equal(0.0, 0.0));
   printf_test_name("test_stub", NULL);
   ASSERT_EQUALS(0, 0);
}

int
main(void)
{
   printf("%s\n", TMPL_CLASS_TAG_version());
   test_stub();                                  /* only to quiet compiler warnings */
   RUN(test_func1);

   return TEST_REPORT();
}
