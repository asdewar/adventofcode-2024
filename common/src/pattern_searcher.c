#include "common.h"

PatternSearcher *init_pattern_searcher(char* pattern) {
    int size = strlen(pattern);
    PatternSearcher *stack = (PatternSearcher *)malloc(sizeof(PatternSearcher) + size);
    memset(stack->buff, 0, size);
    stack->size = size;
    stack->last = 0;
    return stack;
}

void add_pattern_searcher(PatternSearcher *stack, char c) {
    stack->buff[stack->last] = c;
    stack->last = (stack->last + 1) % stack->size;
}

bool check_pattern_pattern_searcher(PatternSearcher *stack) {
    for (int i = 0, j = stack->size - 1; i < stack->size; i++, j = (j - 1) % stack->size) {
        printf("Comparing i=%d, j=%d, c1=%c, c2=%c\n",
            i, j, stack->pattern[i], stack->buff[j]);
        if (stack->pattern[i] != stack->buff[j])
            return false;
    }
    return true;
}

void destroy_pattern_searcher(PatternSearcher *stack) {
    free(stack);
}