#include <stdlib.h>
#include <stdio.h>
#include "options.h"

int
main(int argc, char *argv[])
{
   struct options *z = options_new();
   int         err = 0;

   options_cmdline(z, argc, argv);

   err += (NULL == z ? 1 : 0);

   printf("%s\t%s\t%s\n", "options", "t/test02", (err > 0 ? "failed" : "passed"));

   options_free(z);

   return 0;
}
