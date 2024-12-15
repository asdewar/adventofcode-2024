#include "common.h"


int get_max_and_invalidate(int list[], int size) {
    int max = 0;
    int *max_ptr = &max;

    for (int i = 0; i < size; i++)
        if (list[i] > *max_ptr) // Update pointer if higher
            max_ptr = &list[i];
    
    max = *max_ptr;
    *max_ptr = -1;
    return max;
}


int count_reps(int value, int list[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (list[i] == value)
            count++;
    return count;
}

int main(int argc, char const *argv[]) {
    // Open file.
    FILE *fptr = open_file_with_args(argc, argv);
    if (!fptr)
        return EXIT_FAILURE;

    // It's plus one because last index has no new line.
    int num_elements = count_file_lines(fptr) + 1;
    printf("Num elements: %d\n", num_elements);

    // Alloc arrays as VLA.
    int list1[num_elements];
    int list2[num_elements];

    // Read data.
    for (int i = 0; i < num_elements; i++) {
        int ret = fscanf(fptr, "%d   %d\n", &list1[i], &list2[i]);
        if (ret != 1) {
            printf("Failure on file format\n");
            exit(EXIT_FAILURE);
        }
    }
    printf("num elements: %d\n", num_elements);

    // Calculate similarity
    int total_sim = 0;
    for (int i = 0; i < num_elements; i++) {
        int sim = count_reps(list1[i], list2, num_elements);
        total_sim += sim * list1[i];
    }

    // Calculate distance
    int total_dist = 0;
    for (int i = 0; i < num_elements; i++) {
        int id1 = get_max_and_invalidate(list1, num_elements);
        int id2 = get_max_and_invalidate(list2, num_elements);
        int dist = abs(id1 - id2);
        total_dist += dist;
    }

    printf("Total dist: %d\n", total_dist);
    printf("Total sim: %d\n", total_sim);

    fclose(fptr);
    return 0;
}
