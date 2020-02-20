#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "TMPL_CLASS_NAME.h"
#include "t/tinytest.h"
#include "t/tinyhelp.h"

static void
test_constr(void)
{
   struct TMPL_CLASS_NAME *z;

   fprintf_test_info(stdout, "test_constr", "TMPL_CLASS_TAG_new, TMPL_CLASS_TAG_free");
   z = TMPL_CLASS_TAG_new();
   ASSERT("Constructor test", z);
   TMPL_CLASS_TAG_free(&z);
   ASSERT_EQUALS(NULL, z);
}

#if 0                                            /* 12 yy */
static void
test_stub(void)
{
   struct TMPL_CLASS_NAME *z;

   fprintf_test_info(stdout, "test_stub", NULL);
   z = TMPL_CLASS_TAG_new();
   ASSERT("Constructor test, pt 1", z);
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
