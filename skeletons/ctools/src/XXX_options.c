#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "XXX_options.h"
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
 *  Structure is defined in XXX_options.h since it needs to be visible.
 */

struct XXX_options XXX_options_default = {
   .appname = "MY NAME GOES HERE",
   .appvers = "0.0.0",
   .fname = NULL,
   .help_flag = 0,
   .prefix = "XXX_FOO",
   .quiet_flag = 0,
   .verbosity = 0,
   .version_flag = 0,
   .extras = NULL
};

struct XXX_options *
XXX_options_new(void)
{
   struct XXX_options *tp;

   tp = (struct XXX_options *) malloc(sizeof(struct XXX_options));
   if (_IS_NULL(tp))
      return NULL;

   *tp = XXX_options_default;

   return tp;
}

void
XXX_options_free(struct XXX_options **pp)
{
   if (_IS_NULL(*pp))
      return;

   /* p->extras has pointers from optparse, no need to free them */
   _FREE((*pp)->extras);
   _FREE((*pp)->fname);
   _FREE(*pp);
   *pp = NULL;
}

void
XXX_options_help_msg(struct XXX_options *p, FILE *out)
{
   unsigned    indent = 5;
   unsigned    width = 70;
   struct linewrapper *w = lwrap_new();
#ifdef  _BUFSIZE
#undef  _BUFSIZE
#endif
#define _BUFSIZE                1000
   char        buffer[_BUFSIZE];

   fprintf(out, "Usage: %s [options] infile1 [infile2 ...]\n", p->appname);
   fprintf(out, "Options:\n");

   fprintf(out, "%s\n", "-h, --help");
   snprintf(buffer, _BUFSIZE, "Print this help message and exit.");
   fprintf(out, "%s\n", lwrap_format(w, indent, width, buffer));

   fprintf(out, "%s\n", "-p PREFIX, --prefix=PREFIX");
   snprintf(buffer, _BUFSIZE,
            "Set PREFIX as the prefix. This is just to provide an example of "
            "how to incorporate the default value of PREFIX (which is %s) in "
            "a message.", XXX_options_default.prefix);
   fprintf(out, "%s\n", lwrap_format(w, indent, width, buffer));

   fprintf(out, "%s\n", "-q, --quiet");
   snprintf(buffer, _BUFSIZE, "Run quietly.");
   fprintf(out, "%s\n", lwrap_format(w, indent, width, buffer));

   fprintf(out, "%s\n", "-v, --verbosity");
   snprintf(buffer, _BUFSIZE, "Increase the level of reporting, multiples accumulate.");
   fprintf(out, "%s\n", lwrap_format(w, indent, width, buffer));

   fprintf(out, "%s\n", "-V, --version");
   snprintf(buffer, _BUFSIZE, "Print the version information and exit.");
   fprintf(out, "%s\n", lwrap_format(w, indent, width, buffer));

   lwrap_free(&w);
}

void
XXX_options_parse(struct XXX_options *p, int argc, char *argv[])
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
   struct optparse opts;
   int         fake_x;                      /* FIXME */

   optparse_init(&opts, argv);
   opts.permute = 0;                             /* set = 1 to allow argv to be permuted */

   while ((option = optparse_long(&opts, longopts, NULL)) != -1) {
      switch (option) {
         case 'h':
            printf("looks like you want help\n");
            p->help_flag = 1;
            break;

         case 'p':
            printf("prefix set as %s\n", opts.optarg);
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
            fake_x = opts.optarg ? atoi(opts.optarg) : -1;
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
   while ((arg = optparse_arg(&opts))) {
      p->extras = realloc(p->extras, (2 + nextras) * sizeof(char *));
      (p->extras)[nextras] = arg;
      printf("Extra: %s\n", (p->extras)[nextras]);
      nextras += 1;
      (p->extras)[nextras] = NULL;               /* overwritten next time */
   }
}

#undef _IS_NULL
#undef _FREE
