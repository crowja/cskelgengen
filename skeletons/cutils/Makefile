SHELL = /bin/sh

GCC_STRICT_FLAGS = -pedantic -ansi -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -O2
OTHER_SOURCE = -I./t
OTHER_INCLUDE =
CPPFLAGS = -g -I. $(OTHER_INCLUDE)
CFLAGS = $(GCC_STRICT_FLAGS) 
LDFLAGS =
LDFLAGS_EFENCE = -L/usr/lib -lefence $(LDFLAGS)
#VALGRIND_FLAGS = --verbose --leak-check=full --undef-value-errors=yes --track-origins=yes
VALGRIND_FLAGS = --leak-check=full --undef-value-errors=yes

INDENT_FLAGS = -TFILE -Tsize_t -Tuint8_t

.PHONY: check vcheck indent clean

##TESTS = t/test01 t/test02 t/test03 t/test04 t/test
TESTS = t/test
EXAMPLES = ex/ex_1

TMPL_CLASS_NAME.o: TMPL_CLASS_NAME.c TMPL_CLASS_NAME.h
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ TMPL_CLASS_NAME.c

check: TMPL_CLASS_NAME.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) $(LDFLAGS) \
		-o t/a.out $$i.c TMPL_CLASS_NAME.o ) \
	  && ( t/a.out ); \
	done 

check-examples: TMPL_CLASS_NAME.o
	@for i in $(EXAMPLES); \
	do \
	  echo "--------------------"; \
	  echo "Running example $$i"; \
	  ( $(CC) -g $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) $(LDFLAGS) \
		-o ex/a.out $$i.c TMPL_CLASS_NAME.o ) \
	  && ( valgrind $(VALGRIND_FLAGS) ex/a.out ); \
	done 

vcheck: TMPL_CLASS_NAME.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC) -g $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) $(LDFLAGS) \
		-o t/a.out $$i.c TMPL_CLASS_NAME.o ) \
	  && ( valgrind $(VALGRIND_FLAGS) t/a.out ); \
	done 

echeck: TMPL_CLASS_NAME.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) $(LDFLAGS_EFENCE) \
		-o t/a.out $$i.c TMPL_CLASS_NAME.o ) \
	  && ( LD_PRELOAD=libefence.so ./t/a.out ) ; \
	done 

indent:
	@indent $(INDENT_FLAGS) TMPL_CLASS_NAME.c
	@indent $(INDENT_FLAGS) TMPL_CLASS_NAME.h
	@for i in $(TESTS); \
	do \
	  indent $(INDENT_FLAGS) $$i.c; \
	done

clean:
	@/bin/rm -f TMPL_CLASS_NAME.o *.o *~ *.BAK *.bak core.* a.out
	@/bin/rm -f t/*.o t/*~ t/*.BAK t/*.bak t/core.* t/a.out
	@/bin/rm -f ex/*.o ex/*~ ex/*.BAK ex/*.bak ex/core.* ex/a.out

