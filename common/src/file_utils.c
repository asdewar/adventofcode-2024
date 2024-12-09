#include <stdio.h>
#include <stdlib.h>

FILE *open_file_with_args(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Filename not passed\n");
        return NULL;
    }

    FILE *fptr = fopen(argv[1], "r");
    if (!fptr)
        printf("Cannot open file %s\n", argv[1]);
    return fptr;
}

int count_file_lines(FILE *fptr) {
    rewind(fptr);
    int lines = 0;
    while(!feof(fptr)) {
        char ch = fgetc(fptr);
        if(ch == '\n')
            lines++;
    }
    rewind(fptr);
    return lines;
}
