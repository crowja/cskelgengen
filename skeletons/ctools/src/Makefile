RM = /bin/rm

all:
	@echo "Limited purpose Makefile. Try 'make clean' or 'make indent' ..."

indent:
	@indent $(INDENT_FLAGS) main.c
	@indent $(INDENT_FLAGS) main.h
	@indent $(INDENT_FLAGS) options.c
	@indent $(INDENT_FLAGS) options.h
	@indent $(INDENT_FLAGS) XXX_main.c
	@indent $(INDENT_FLAGS) XXX_main.h
	@indent $(INDENT_FLAGS) XXX_options.c
	@indent $(INDENT_FLAGS) XXX_options.h

clean:
	@$(RM) -f a.out *.o *~
