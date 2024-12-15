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
        // store position to rollback if needed
        unsigned long position = ftell(fptr);
        // try to read mul
        int ret = fscanf(fptr, "mul(%d,%d", &mul1, &mul2);
        if (ret == 2) {
            // if "mul(%d, %d", check for last )
            if (fgetc(fptr) == ')') {
                // clean patterns
                clean_pattern_searcher(do_stack);
                clean_pattern_searcher(dont_stack);

                // add mul if enabled
                if (mul_enable)
                    total += mul1 * mul2;
            }
        } else {
            // return to last position
            fseek(fptr, position, SEEK_SET);
            // read next character
            char c = fgetc(fptr);
            // search do an don't patterns
            add_pattern_searcher_char(do_stack, c);
            add_pattern_searcher_char(dont_stack, c);
            if (check_pattern_searcher(do_stack)) {
                // printf("MUL ENABLED\n");
                mul_enable = true;
            }
            if (check_pattern_searcher(dont_stack)) {
                // printf("MUL DISABLED\n");
                mul_enable = false;
            }
        }
    }

    printf("Total: %d\n", total);
    destroy_pattern_searcher(do_stack);
    destroy_pattern_searcher(dont_stack);
    return 0;
}
