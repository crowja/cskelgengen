#include <stdlib.h>
#include <stdio.h>
#include "options.h"

int
main(int argc, char *argv[])
{
   struct options *z = options_new();
   int         err = 0;

   err += (NULL == z ? 1 : 0);

   printf("%s\t%s\t%s\n", "options", "t/test01", (err > 0 ? "failed" : "passed"));

   options_free(z);

   return 0;
}
