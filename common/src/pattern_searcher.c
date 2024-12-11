#include "common.h"

PatternSearcher *init_pattern_searcher(char* pattern) {
    int size = strlen(pattern);
    PatternSearcher *ps = (PatternSearcher *)malloc(sizeof(PatternSearcher) + size);
    memset(ps->buff, 0, size);
    ps->pattern = pattern;
    ps->size = size;
    ps->last = 0;
    return ps;
}

void add_pattern_searcher_char(PatternSearcher *ps, char c) {
    ps->last = (ps->last + 1) % ps->size;
    ps->buff[ps->last] = c;
}

bool check_pattern_pattern_searcher(PatternSearcher *ps) {
    for(int i = 0; i < ps->size; i++) {
        int j = get_pattern_searcher_index(ps, i);
        if (ps->pattern[i] != ps->buff[j])
            return false;
    }
    return true;
}

void clean_pattern_searcher(PatternSearcher *ps) {
    memset(ps->buff, 0, ps->size);
    ps->last = -1;
}

void destroy_pattern_searcher(PatternSearcher *ps) {
    free(ps);
}

void print_pattern_searcher(PatternSearcher *ps) {
    printf("Pattern: %s, Buffer:", ps->pattern);
    for(int i = 0; i < ps->size; i++) {
        int j = get_pattern_searcher_index(ps, i);
        printf("%c", ps->buff[j]);
    }
    printf("\n");
}

int get_pattern_searcher_index(PatternSearcher *ps, int i) {
    return (ps->last + i + 1) % ps->size;
}
