#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "TMPL_CLASS_NAME.h"
#include "t/tinytest.h"

#ifdef  COLOR_CODE_
#undef  COLOR_CODE_
#endif
#define COLOR_CODE_       0x1B

#ifdef  COLOR_RED_
#undef  COLOR_RED_
#endif
#define COLOR_RED_        "[1;31m"

#ifdef  COLOR_GREEN_
#undef  COLOR_GREEN_
#endif
#define COLOR_GREEN_      "[1;32m"

#ifdef  COLOR_YELLOW_
#undef  COLOR_YELLOW_
#endif
#define COLOR_YELLOW_     "[1;33m"

#ifdef  COLOR_RESET_
#undef  COLOR_RESET_
#endif
#define COLOR_RESET_      "[0m"

static void
_printf_test_name(char *name, char *info)
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
test_constr(void)
{
   struct TMPL_CLASS_NAME *z;

   _printf_test_name("test_constr", "TMPL_CLASS_TAG_new, TMPL_CLASS_TAG_free");

   z = TMPL_CLASS_TAG_new();
   ASSERT("Constructor test", z);
   TMPL_CLASS_TAG_free(&z);
   ASSERT_EQUALS(NULL, z);
}

#if 0                                            /* 16 yy */
static void
test_stub(void)
{
   struct TMPL_CLASS_NAME *z;
   double      x = 1.23;                    /* TODO */

   _printf_test_name("test_stub", NULL);

   z = TMPL_CLASS_TAG_new();
   ASSERT("Constructor test, pt 1", z);
   ASSERT("Here's a test ...", two_doubles_equal(x, 1.23));
   ASSERT_EQUALS(10, 10);

   TMPL_CLASS_TAG_free(&z);
   ASSERT_EQUALS(NULL, z);
}
#endif

int
main(void)
{
   printf("%s\n", TMPL_CLASS_TAG_version());

   RUN(test_constr);

   return TEST_REPORT();
}
