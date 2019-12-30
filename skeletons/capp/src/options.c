#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "options.h"
#include "linewrapper.h"
#define OPTPARSE_IMPLEMENTATION
#define OPTPARSE_API static
#include "optparse.h"

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

struct options *
options_new(void)
{
   struct options *tp;

   tp = (struct options *) malloc(sizeof(struct options));
   if (_IS_NULL(tp))
      return NULL;

   tp->appname = "MY NAME GOES HERE";
   tp->appvers = "0.1.0-dev0";
   tp->fname = NULL;
   tp->help_flag = 0;
   tp->quiet_flag = 0;
   tp->verbosity = 0;
   tp->version_flag = 0;
   tp->extras = NULL;

   return tp;
}

void
options_free(struct options *p)
{
   if (_IS_NULL(p))
      return;

   /* p->extras has pointers from optparse, no need to free them */
   _FREE(p->extras);
   _FREE(p->fname);
   _FREE(p);
}

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

   fprintf(out, "%s\n", "-pPREFIX, --prefix=PREFIX");
   fprintf(out, "%s\n", lwrap_format(w, indent, width, "Set PREFIX as the prefix."));

   fprintf(out, "%s\n", "-q, --quiet");
   fprintf(out, "%s\n", lwrap_format(w, indent, width, "Run quietly."));

   fprintf(out, "%s\n", "-v, --verbosity");
   fprintf(out, "%s\n",
           lwrap_format(w, indent, width,
                        "Increase the level of reporting, multiples accumulate."));

   fprintf(out, "%s\n", "-V, --version");
   fprintf(out, "%s\n",
           lwrap_format(w, indent, width, "Print the version information and exit."));

   lwrap_free(w);
}

void
options_parse(struct options *p, int argc, char *argv[])
{
   char       *arg;
   int         option;
   unsigned    nextras = 0;
   static struct optparse_long longopts[] = {
      {"help", 'h', OPTPARSE_NONE},
      {"prefix", 'p', OPTPARSE_REQUIRED},
      {"quiet", 'q', OPTPARSE_NONE},
      {"verbose", 'v', OPTPARSE_NONE},
      {"version", 'V', OPTPARSE_NONE},
      {"xyzzy", 'x', OPTPARSE_OPTIONAL},
      {0}
   };
   struct optparse options;
   int         fake_x;                      /* FIXME */

   optparse_init(&options, argv);
   options.permute = 0;                          /* set = 1 to allow argv to be permuted */

   while ((option = optparse_long(&options, longopts, NULL)) != -1) {
      switch (option) {
         case 'h':
            printf("looks like you want help\n");
            p->help_flag = 1;
            break;

         case 'p':
            printf("prefix set as %s\n", options.optarg);
            break;

         case 'q':
            printf("looks like you want me to be quiet\n");
            p->verbosity = 0;
            break;

         case 'v':
            printf("looks like you want me to be chatty\n");
            printf(" --verbose\n");
            p->verbosity += 1;
            break;

         case 'V':
            printf("my version is %s\n", p->appvers);
            p->version_flag = 1;
            break;

         case 'x':
            printf("the x option has an optional argument\n");
            fake_x = options.optarg ? atoi(options.optarg) : -1;
            if (fake_x < 0)
               printf("... and none provided\n");
            else
               printf("... and %d is provided\n", fake_x);
            break;

         case '?':
            fprintf(stderr, "Bad option \n");
            break;

         default:
            abort();
      }
   }

#if 0
   if (optind < argc) {                          /* remains NULL otherwise */
      p->fname = (char *) realloc(p->fname, (1 + strlen(argv[optind])) * sizeof(char));
      strcpy(p->fname, argv[optind]);
   }
#endif
   while ((arg = optparse_arg(&options))) {
      p->extras = realloc(p->extras, (2 + nextras) * sizeof(char *));
      (p->extras)[nextras] = arg;
      printf("Extra: %s\n", (p->extras)[nextras]);
      nextras += 1;
      (p->extras)[nextras] = NULL;               /* overwritten next time */
   }
}

#undef _IS_NULL
#undef _FREE
