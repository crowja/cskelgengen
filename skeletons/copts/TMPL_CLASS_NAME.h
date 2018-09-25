struct TMPL_CLASS_NAME {
   char       *fname;                       /* input file name, if any */
   unsigned    quiet_flag;
   unsigned    verbosity;
};

struct TMPL_CLASS_NAME *TMPL_CLASS_TAG_new(void);
void        TMPL_CLASS_TAG_free(struct TMPL_CLASS_NAME *p);
void        TMPL_CLASS_TAG_helpmsg(FILE *out);
void        TMPL_CLASS_TAG_parse(struct TMPL_CLASS_NAME *p, int argc, char *argv[]);
