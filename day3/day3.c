#include "common.h"

#define DO_PATTERN   "do()"
#define DONT_PATTERN "don't()"

int main(int argc, char const *argv[]) {
    // open file
    FILE *fptr = open_file_with_args(argc, argv);
    if (!fptr)
        return EXIT_FAILURE;
    
    PatternSearcher *do_stack   = init_pattern_searcher(DO_PATTERN);
    PatternSearcher *dont_stack = init_pattern_searcher(DONT_PATTERN);
    
    int mul1, mul2;
    bool mul_enable = true;

    // try to read mul, else, increment one character
    int total = 0;
    while(!feof(fptr)) {
        int ret = fscanf(fptr, "mul(%d,%d", &mul1, &mul2);
        // mul() pattern.
        if (ret == 2) {
            if (fgetc(fptr) == ')') {
                // printf("Mul: %d, %d\n", mul1, mul2);
                if (mul_enable)
                    total += mul1 * mul2;
            }
        }
        // Check do pattern
        else {
            char c = fgetc(fptr);
            add_pattern_searcher(do_stack, c);
            add_pattern_searcher(dont_stack, c);
            if (check_pattern_pattern_searcher(do_stack)) {
                printf("MUL ENABLED\n");
                mul_enable = true;
            }
            if (check_pattern_pattern_searcher(dont_stack)) {
                printf("MUL DISABLED\n");
                mul_enable = false;
            }
        }
    }

    printf("Total: %d\n", total);

    return 0;
}
