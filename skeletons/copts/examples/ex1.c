#include <stdlib.h>
#include <stdio.h>
#include "TMPL_CLASS_NAME.h"

int
main(int argc, char *argv[])
{
   struct TMPL_CLASS_NAME *op = TMPL_CLASS_TAG_new();
   TMPL_CLASS_TAG_parse(op, argc, argv);
   TMPL_CLASS_TAG_free(op);
   return 0;
}
