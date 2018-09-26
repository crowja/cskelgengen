SHELL = /bin/sh

GCC_STRICT_FLAGS = -pedantic -ansi -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -O2
CPPFLAGS = -I.
CFLAGS = $(GCC_STRICT_FLAGS)
LDFLAGS =
OTHER_SOURCE = ./fgetopt.c
OTHER_INCLUDE =
INDENT_FLAGS = 

.PHONY: check vcheck echeck check-examples indent clean

TESTS = t/test
EXAMPLES = examples/ex1

TMPL_CLASS_NAME.o: TMPL_CLASS_NAME.c TMPL_CLASS_NAME.h fgetopt.c fgetopt.h
	$(CC) -c $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) -o $@ TMPL_CLASS_NAME.c

fgetopt.o: fgetopt.c fgetopt.h
	$(CC) -c $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) -o $@ fgetopt.c

check: TMPL_CLASS_NAME.o fgetopt.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(LDFLAGS) \
		-o t/a.out $$i.c TMPL_CLASS_NAME.o $(OTHER_SOURCE) ) \
	  && ( t/a.out ); \
	done 

vcheck: TMPL_CLASS_NAME.o fgetopt.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(LDFLAGS) \
		-o t/a.out $$i.c TMPL_CLASS_NAME.o $(OTHER_SOURCE) ) \
	  && ( valgrind t/a.out ); \
	done 

echeck: TMPL_CLASS_NAME.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i ..."; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) $(LDFLAGS_EFENCE) \
		-o t/a.out $$i.c TMPL_CLASS_NAME.o ) \
	  && ( LD_PRELOAD=libefence.so ./t/a.out ); \
	done 

check-examples: TMPL_CLASS_NAME.o fgetopt.o
	@for i in $(EXAMPLES); \
	do \
	  echo "--------------------"; \
	  echo "Running example $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(LDFLAGS) \
		-o examples/a.out $$i.c TMPL_CLASS_NAME.o $(OTHER_SOURCE) ) \
	  && ( examples/a.out -h ); \
	done

indent:
	indent $(INDENT_FLAGS) TMPL_CLASS_NAME.c
	indent $(INDENT_FLAGS) TMPL_CLASS_NAME.h
	indent $(INDENT_FLAGS) fgetopt.c
	indent $(INDENT_FLAGS) fgetopt.h
	@for i in $(TESTS); \
	do \
	  indent $(INDENT_FLAGS) $$i.c; \
	done 
	@for i in $(EXAMPLES); \
	do \
	  indent $(INDENT_FLAGS) $$i.c; \
	done 

clean:
	@/bin/rm -f *.o *~ *.BAK *.bak core.* a.out
	@/bin/rm -f t/*.o t/*~ t/*.BAK t/*.bak t/core.* t/a.out
	@/bin/rm -f examples/*.o examples/*~ examples/*.BAK examples/*.bak examples/core.* examples/a.out

