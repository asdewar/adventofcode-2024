#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_lines(FILE *fptr) {
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

int *read_report(FILE *fptr, int *size) {
    int *list = NULL;
    *size = 0;
    do {
        // do alloc stuff
        (*size)++;
        if (!list)
            list = malloc(sizeof(int));
        else
            list = realloc(list, (*size) * sizeof(int));
        
        // read value
        fscanf(fptr, "%d", &list[*size - 1]);        

    } while(fgetc(fptr) != '\n' && !feof(fptr));

    return list;
}


bool check_safeness_with_omit(int list[], int size, int omit_value) {
    // Mount list omitting value.
    int omitted_list[size - 1];
    for(int i = 0, j = 0; i < size; i++) {
        if (i == omit_value)
            continue;
        // store original value.
        omitted_list[j++] = list[i];
    }

    // list
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", omitted_list[i]);
    }
    printf("\n");

    // check safeness
    bool safeness = check_safeness(),

}


int main(int argc, char const *argv[]) {
    FILE *fptr = fopen("input.txt", "r");

    // It's plus one because last index has no new line.
    int num_elements = count_lines(fptr) + 1;
    printf("Num elements: %d\n", num_elements);

    // Calculate safeness.
    int safeness = 0;
    for (int i = 0; i < 1; i++) {
        // read report
        int size = 0;
        int *list = read_report(fptr, &size);
        
        // iterate avoiding data
        for (int i = 0; i < size; i++) {
            bool safeness = check_safeness_with_omit(list, size, i);
        }

        // free list at end.
        free(list);
    }

    printf("Safeness: %d\n", safeness);
    return 0;
}
