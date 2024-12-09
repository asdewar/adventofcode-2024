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


int check_safeness(FILE *fptr) {
    // values to read
    int value1 = -1;
    int value2 = -1;
    int num_elements = 0;

    // checkers
    int inc_dec_checker = 0;
    int diff_ok = true;

    do {
        // read character and update values
        value2 = value1;
        fscanf(fptr, "%d", &value1);
        if (value2 == -1)
            continue;

        // check incresing or decreasing
        num_elements += 1;
        inc_dec_checker += (value1 - value2) > 0 ? 1 : -1;

        // check diff safeness
        int abs_diff = abs(value1 - value2);
        if (abs_diff < 1 || abs_diff > 3) {
            diff_ok = false;
        } 

        // printf("Value1: %d, Value2: %d\n", value1, value2);
    } while(fgetc(fptr) != '\n' && !feof(fptr));

    // check increase and decrease and diff wrong checker
    return abs(inc_dec_checker) == num_elements && diff_ok ? 1 : 0;
}


int main(int argc, char const *argv[]) {
    FILE *fptr = fopen("input.txt", "r");

    // It's plus one because last index has no new line.
    int num_elements = count_lines(fptr) + 1;
    printf("Num elements: %d\n", num_elements);

    // Calculate safeness.
    int safeness = 0;
    for (int i = 0; i < num_elements; i++) {
        safeness += check_safeness(fptr);
    }

    printf("Safeness: %d\n", safeness);
    return 0;
}
