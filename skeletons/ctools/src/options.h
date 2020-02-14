#ifndef OPTIONS_H_
#define OPTIONS_H_

struct options {
   char       *appname;
   char       *appvers;
   char       *fname;                       /* input file name, if any */
   unsigned    help_flag;
   char       *prefix;
   unsigned    quiet_flag;
   unsigned    verbosity;
   unsigned    version_flag;
   char      **extras;
};

struct options *options_new(void);
void        options_free(struct options **pp);
void        options_help_msg(struct options *p, FILE *out);
void        options_parse(struct options *p, int argc, char *argv[]);

#endif
