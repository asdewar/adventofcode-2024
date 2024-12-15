#include "common.h"

Matrix *init_matrix(int rows, int cols) {
    Matrix *m = (Matrix *)malloc(sizeof(Matrix) + (rows * cols));
    m->rows = rows;
    m->cols = cols;
    return m;
}

Matrix *init_matrix_from_file(FILE *fptr) {
    int rows = count_file_lines(fptr) + 1; // + 1 due no new line at end
    int cols = count_line_lenght(fptr);
    printf("Matrix of %dx%d\n", rows, cols);
    Matrix *m = init_matrix(rows, cols);

    // fill matrix data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            set_matrix_data(m, i, j, fgetc(fptr));
        }
        fgetc(fptr); // read one char to omit end newline
    }

    return m;
}

char get_matrix_data(Matrix *m, int i, int j) {
    if (i < 0 || i >= m->rows || j < 0 || j >= m->cols ) {
        return 0;
    }
    return m->data[i * m->rows + j];
}

void set_matrix_data(Matrix *m, int i, int j, char c) {
    m->data[i * m->rows + j] = c;
}

void print_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%c", get_matrix_data(m, i, j));
        }
        printf("\n");
    }
}

void destroy_matrix(Matrix *m) {
    free(m);
}
