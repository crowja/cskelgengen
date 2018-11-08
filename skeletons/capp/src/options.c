#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "options.h"
#include "fgetopt.h"
#include "linewrapper.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)             ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)                ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

#define QUOTE(name) #name
#define STR(macro) QUOTE(macro)
#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION dev
#endif
#define PACKAGE_VERSION_STR STR(PACKAGE_VERSION)

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

   tp->appname = "My name here";
   tp->appvers = PACKAGE_VERSION_STR;
   tp->fname = NULL;
   tp->help_flag = 0;
   tp->quiet_flag = 0;
   tp->verbosity = 0;
   tp->version_flag = 0;

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

/*** options_help_msg() ***/

void
options_help_msg(struct options *p, FILE *out)
{
   unsigned    indent = 5;
   unsigned    width = 75;
   struct linewrapper *w = lwrap_new();

   fprintf(out, "Usage: %s [options] infile1 [infile2 ...]\n", p->appname);
   fprintf(out, "Options:\n");

   fprintf(out, "%s\n", "-h, --help");
   fprintf(out, "%s\n",
           lwrap_format(w, indent, width, "Print this help message and exit."));

   fprintf(out, "%s\n", "-q, --quiet");
   fprintf(out, "%s\n", lwrap_format(w, indent, width, "Run quietly."));

   fprintf(out, "%s\n", "-V, --verbosity");
   fprintf(out, "%s\n",
           lwrap_format(w, indent, width,
                        "Increase the level of reporting, multiples accumulate."));

   fprintf(out, "%s\n", "-v, --version");
   fprintf(out, "%s\n",
           lwrap_format(w, indent, width, "Print the version information and exit."));

   lwrap_free(w);
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
            p->help_flag = 1;
            break;

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
            p->version_flag = 1;
            break;

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
