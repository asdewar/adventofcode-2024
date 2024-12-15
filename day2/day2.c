#include "common.h"

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
        int ret = fscanf(fptr, "%d", &list[*size - 1]);
        if (ret != 1) {
            printf("Failure on file format\n");
            exit(EXIT_FAILURE);
        }

    } while(fgetc(fptr) != '\n' && !feof(fptr));

    return list;
}

int check_safeness(int list[], int size) {
    int value1 = list[0];
    int value2 = 0;

    int inc_dec_checker = 0;
    int diff_ok = true;

    for (int i = 1; i < size; i++) {
        // Update values
        value2 = value1;
        value1 = list[i];

        // check increasing or decreasing
        inc_dec_checker += (value1 - value2) > 0 ? 1 : -1;

        // check diff safeness
        int abs_diff = abs(value1 - value2);
        if (abs_diff < 1 || abs_diff > 3) {
            diff_ok = false;
        }
    }

    // list
    // for (int i = 0; i < size; i++)
    //     printf("%d ", list[i]);
    // printf("\n");

    // check increase and decrease and diff wrong checker
    int safeness = abs(inc_dec_checker) == (size - 1) && diff_ok ? 1 : 0;
    // printf("Safeness: %d, inc_dec_checker: %d, diff_ok: %d\n", safeness, inc_dec_checker, diff_ok);
    return safeness;
}

int check_safeness_with_omit(int list[], int size, int omit_value) {
    int small_size = size - 1;
    int small_list[small_size];

    // Mount list omitting values
    for(int i = 0, j = 0; i < size; i++) {
        if (i == omit_value)
            continue;
        // store original value
        small_list[j++] = list[i];
    }

    // check safeness
    return check_safeness(small_list, small_size);
}

int main(int argc, char const *argv[]) {
    // Open file.
    FILE *fptr = open_file_with_args(argc, argv);
    if (!fptr)
        return EXIT_FAILURE;

    // It's plus one because last index has no new line.
    int num_elements = count_file_lines(fptr) + 1;
    printf("Num elements: %d\n", num_elements);

    // Calculate safeness.
    int safeness = 0;
    for (int i = 0; i < num_elements; i++) {
        // read report
        int size = 0;
        int *list = read_report(fptr, &size);
        
        // check safeness of every item
        if (check_safeness(list, size)) {
            safeness++;
            continue;
        }

        // check safeness omitting data
        for (int i = 0; i < size; i++) {
            if (check_safeness_with_omit(list, size, i)) {
                safeness++;
                break;
            }
        }

        // free list at end.
        free(list);
    }

    printf("Safeness: %d\n", safeness);
    return 0;
}
