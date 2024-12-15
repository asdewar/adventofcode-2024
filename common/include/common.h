#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Pattern Searcher */
typedef struct {
    int rows;
    int cols;
    char data[]; // flexible array member
} Matrix;

Matrix *init_matrix_from_file(FILE *fptr);
Matrix *init_matrix(int rows, int cols);
char get_matrix_data(Matrix *m, int i, int j);
void set_matrix_data(Matrix *m, int i, int j, char c);
void print_matrix(Matrix *m);
void destroy_matrix(Matrix *m);

/* Pattern Searcher */
typedef struct {
    int size;
    int last;
    char *pattern;
    char buff[]; // flexible array member
} PatternSearcher;

PatternSearcher *init_pattern_searcher(char* pattern);
void add_pattern_searcher_char(PatternSearcher *stack, char c);
bool check_pattern_searcher(PatternSearcher *stack);
void clean_pattern_searcher(PatternSearcher *stack);
void destroy_pattern_searcher(PatternSearcher *stack);
void print_pattern_searcher(PatternSearcher *ps);
int get_pattern_searcher_index(PatternSearcher *ps, int i);

/* File utils */
FILE *open_file_with_args(int argc, char const *argv[]);
int count_file_lines(FILE *fptr);
int count_line_lenght(FILE *fptr);
