#include "common.h"

#define XMAS_LEN 4
#define XMAS_PATTERN "XMAS"
#define MAS_LEN 3
#define MAS_PATTERN "MAS"

// search xmas pattern starting on [i, j] and propagating
int search_xmas(Matrix *m, PatternSearcher *ps, int x, int y) {
    int founds = 0;
    for (int dir_x = -1; dir_x <= 1 ; dir_x++) {
        for (int dir_y = -1; dir_y <= 1 ; dir_y++) {
            clean_pattern_searcher(ps);
            // add_pattern_searcher_char(ps, 'X');
            for (int k = 0; k < XMAS_LEN; k++) {
                char c = get_matrix_data(m , x + (dir_x * k), y + (dir_y * k));
                add_pattern_searcher_char(ps, c);
            }
            if (check_pattern_searcher(ps)) {
                // printf("Found XMAX at [%d, %d], [%d, %d]\n", x, y, dir_x, dir_y);
                founds++;
            }
        }
    }
    return founds;
}

// search mas pattern starting on [i, j] and propagating
int search_mas(Matrix *m, PatternSearcher *ps, int x, int y) {
    int founds = 0;
    
    static int mas_dirs[4][3][2] = {
        {{1, 1},   {0, 0},  {-1, -1}},
        {{-1, -1}, {0, 0},  {1, 1}},
        {{-1, 1},  {0, 0},  {1, -1}},
        {{1, -1},  {0, 0},  {-1, 1}},
    };

    // search in each direction
    // printf("Searching %d, %d\n", x, y);
    for (int i = 0; i < 4; i++) {
        clean_pattern_searcher(ps);
        for (int j = 0; j < 3; j++) {
            int dir_x = mas_dirs[i][j][0];
            int dir_y = mas_dirs[i][j][1];
            char c = get_matrix_data(m , x + dir_x, y + dir_y);
            // printf("CHAR [%d, %d] = %c\n", x + dir_x, y + dir_y, c);
            add_pattern_searcher_char(ps, c);
        }
        if (check_pattern_searcher(ps)) {
            // printf("Found MAS at [%d, %d], [%d]\n", x, y, i);
            founds++;
        }
    }

    // only X-MAS pattern found if 2 MAS found
    return founds == 2 ? 1: 0;
}

// main
int main(int argc, char const *argv[]) {
    // open file
    FILE *fptr = open_file_with_args(argc, argv);
    if (!fptr)
        return EXIT_FAILURE;
    
    // create matrix
    Matrix *m = init_matrix_from_file(fptr);
    // print_matrix(m);

    // the xmax searcher
    // PatternSearcher *xmas_searcher = init_pattern_searcher(XMAS_PATTERN);
    PatternSearcher *mas_searcher = init_pattern_searcher(MAS_PATTERN);

    // iterate character per character
    int total_founds = 0;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            char c = get_matrix_data(m, i, j);
            // if (c == 'X') {
            //     // start search
            //     // printf("Searching at %d, %d\n", i, j);
            //     total_founds += search_xmas(m, xmas_searcher, i, j);
            // }
            if (c == 'A') {
                // start search
                // printf("Searching at %d, %d\n", i, j);
                total_founds += search_mas(m, mas_searcher, i, j);
            }
        }
    }
    printf("Total founds: %d\n", total_founds);
    destroy_matrix(m);
    // destroy_pattern_searcher(xmas_searcher);
    destroy_pattern_searcher(mas_searcher);
    return 0;
}
