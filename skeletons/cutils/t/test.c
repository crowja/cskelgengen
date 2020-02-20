#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "TMPL_CLASS_NAME.h"
#include "tinytest.h"
#include "tinyhelp.h"

static void
test_func1(void)
{
   char       *cp = malloc(10000);

   fprintf_test_info(stdout, "test_func1", "TMPL_CLASS_TAG_func1");
   memset(cp, 'a', 10000);
   ASSERT_EQUALS(0, TMPL_CLASS_TAG_func1(cp));
   free(cp);
}

/* 6 yy */
static void
test_stub(void)
{
   fprintf_test_info(stdout, "test_stub", NULL);
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
