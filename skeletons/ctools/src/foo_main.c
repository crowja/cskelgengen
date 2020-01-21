#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define OPTPARSE_IMPLEMENTATION
#define OPTPARSE_API static
#include "optparse.h"

int other_main(int argc, char **argv)
{
    struct optparse_long longopts[] = {
        {"amend", 'a', OPTPARSE_NONE},
        {"brief", 'b', OPTPARSE_NONE},
        {"color", 'c', OPTPARSE_REQUIRED},
        {"delay", 'd', OPTPARSE_OPTIONAL},
        {0}
    };

    bool amend = false;
    bool brief = false;
    const char *color = "white";
    int delay = 0;

    char *arg;
    int option;
    struct optparse options;

    printf("IN OTHER_MAIN()\n");

    optparse_init(&options, argv);
    options.permute = 0;
    while ((option = optparse_long(&options, longopts, NULL)) != -1) {
        switch (option) {
        case 'a':
            amend = true;
            printf("Amending ...\n");
            break;
        case 'b':
            brief = true;
            printf("Briefing ...\n");
            break;
        case 'c':
            color = options.optarg;
            printf("Coloring (with %s) ...\n", color);
            break;
        case 'd':
            delay = options.optarg ? atoi(options.optarg) : 1;
            printf("Delaying ...\n", color);
            break;
        case '?':
            fprintf(stderr, "%s: %s\n", argv[0], options.errmsg);
            exit(EXIT_FAILURE);
        }
    }

    /*  Print remaining arguments. */
    while ((arg = optparse_arg(&options)))
        printf("%s\n", arg);

    return 0;
}
