SHELL = /bin/sh

GCC_STRICT_FLAGS = -pedantic -ansi -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -O2
OTHER_SOURCE =
OTHER_INCLUDE = -I.
CPPFLAGS = -I. $(OTHER_INCLUDE)
CFLAGS = $(GCC_STRICT_FLAGS) 
LDFLAGS =
LDFLAGS_EFENCE = -L/usr/local/lib -lefence $(LDFLAGS)
#VALGRIND_FLAGS = --verbose --leak-check=full --undef-value-errors=yes --track-origins=yes
VALGRIND_FLAGS =  --leak-check=summary --undef-value-errors=yes --track-origins=yes

INDENT_FLAGS = -TFILE -Tsize_t -Tuint8_t -Tuint16_t -Tuint32_t -Tuint64_t

.PHONY: check vcheck indent clean

TESTS = t/test

main.o: main.c main.h
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ main.c

check: main.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i ..."; \
	  $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) $(LDFLAGS) \
		-o t/a.out $$i.c main.o; \
	  t/a.out; \
	done 

vcheck: main.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i ..."; \
	  $(CC) -g $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) $(LDFLAGS) \
		-o t/a.out $$i.c main.o; \
	  valgrind $(VALGRIND_FLAGS) t/a.out; \
	done 

echeck: main.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i ..."; \
	  $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) $(LDFLAGS_EFENCE) \
		-o t/a.out $$i.c main.o; \
	  LD_PRELOAD=libefence.so ./t/a.out; \
	done 

indent:
	indent $(INDENT_FLAGS) main.c
	indent $(INDENT_FLAGS) main.h
	indent $(INDENT_FLAGS) t/test.c

clean:
	@/bin/rm -f *.o *~ *.BAK *.bak core.*
	@/bin/rm -f t/*.o t/*~ t/*.BAK t/*.bak t/core.* t/a.out
