#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/* Cyclic Stack */
typedef struct {
    int size;
    int last;
    char *pattern;
    char buff[]; // flexible array member
} PatternSearcher;

PatternSearcher *init_pattern_searcher(char* pattern);
void add_pattern_searcher_char(PatternSearcher *stack, char c);
bool check_pattern_pattern_searcher(PatternSearcher *stack);
void clean_pattern_searcher(PatternSearcher *stack);
void destroy_pattern_searcher(PatternSearcher *stack);
void print_pattern_searcher(PatternSearcher *ps);
int get_pattern_searcher_index(PatternSearcher *ps, int i);

/* File utils */
FILE *open_file_with_args(int argc, char const *argv[]);
int count_file_lines(FILE *fptr);
