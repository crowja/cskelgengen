#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "options.h"
#include "fgetopt.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)             ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)                ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

/**
 *  Structure is defined in options.h since it needs to be visible.
 */


/*** options_new() ***/

struct options *
options_new(void)
{
   struct options *tp;

   tp = (struct options *) malloc(sizeof(struct options));
   if (_IS_NULL(tp))
      return NULL;

   tp->fname = NULL;
   tp->quiet_flag = 0;
   tp->verbosity = 0;

   return tp;
}

/*** options_free() ***/

void
options_free(struct options *p)
{
   if (_IS_NULL(p))
      return;

   _FREE(p->fname);
   _FREE(p);
}

/*** options_helpmsg() ***/

void
options_helpmsg(FILE *out)
{
   char        indent[] = "    ";
   fprintf(out, "Usage: MYNAME [options] infile1 [infile2 ...]\n");
   fprintf(out, "Options:\n");

   fprintf(out, "%s\n", "-h, --help");
   fprintf(out, "%s%s\n", indent, "Print this help message and exit.");

   fprintf(out, "%s\n", "-q, --quiet");
   fprintf(out, "%s%s\n", indent, "Run quietly.");

   fprintf(out, "%s\n", "-V, --verbosity");
   fprintf(out, "%s%s\n", indent,
           "Increase the level of reporting, multiples accumulate.");

   fprintf(out, "%s\n", "-v, --version");
   fprintf(out, "%s%s\n", indent, "Print the version information and exit.");
}


/*** options_parse() ***/

void
options_parse(struct options *p, int argc, char *argv[])
{
   int         c;
   int         oindex = 0;
   char        opts[] = "hp:qvV";
   static struct option long_options[] = {
      {"help", no_argument, NULL, 'h'},
      {"prefix", required_argument, NULL, 'p'},
      {"quiet", no_argument, NULL, 'q'},
      {"version", no_argument, NULL, 'v'},
      {"verbose", no_argument, NULL, 'V'},
      {NULL, 0, NULL, 0}
   };

   optarg = NULL;                                /* initialized */
   opterr = 0;                                   /* suppress fgetopt error messages */
   optopt = '\0';                                /* initialized */

   for (;;) {

      c = fgetopt_long(argc, argv, opts, long_options, &oindex);

      if (c == -1)                               /* end of the options */
         break;

      switch (c) {

         case 'h':
            options_helpmsg(stdout);
            exit(0);

         case 'p':
            printf("prefix set as %s\n", optarg);
            break;

         case 'q':
            p->verbosity = 0;
            break;

         case 'V':
            printf(" --verbose\n");
            p->verbosity += 1;
            break;

         case 'v':
            /* printf("%s-%s\n", _PACKAGE_NAME, _PACKAGE_VERSION); */
            /* TODO Need to figure out what to do here ... */
            exit(0);

         case '?':
            fprintf(stderr, "Bad option \n");
            break;

         default:
            abort();
      }
   }

   if (optind < argc) {                          /* remains NULL otherwise */
      p->fname = (char *) realloc(p->fname, (1 + strlen(argv[optind])) * sizeof(char));
      strcpy(p->fname, argv[optind]);
   }
}

#undef _IS_NULL
#undef _FREE
