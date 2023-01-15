#include <stdio.h>
#include <stdlib.h>

int input_n_m(int *n, int *m) {
    int result = 1;
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0)
        result = 0;
    return result;
}

int input_matrix(int **matrix, int n, int m) {
    int result = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (!scanf("%d", &matrix[i][j])) {
                result = 0;
                i = n;
                break;
            }
        }
    return result;
}

int **mem_alloc(int n, int m) {
    int **result = calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++)
        result[i] = calloc(m, sizeof(int));
    return result;
}

void mem_free(int **matrix, int n) {
    if (matrix) {
        for (int i = 0; i < n; i++)
            free(matrix[i]);
        free(matrix);
    }
}

void sort_rows(int **matrix, int n, int m) {
    int **min_row = matrix, **max_row = matrix;
    int min = matrix[0][0], max = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                min_row = matrix + i;
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                max_row = matrix + i;
            }
        }
    }
    if (max_row != min_row) {
        int *temp = *max_row;
        *max_row = *min_row;
        *min_row = temp;
    }
}

void output_matrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j != m - 1)
                printf(" ");
        }
        if (i != n - 1)
            printf("\n");
    }
}

int main() {
    int n, m, errno = 1, **matrix = NULL;
    errno = input_n_m(&n, &m);
    if (errno) {
        matrix = mem_alloc(n, m);
        errno = input_matrix(matrix, n, m);
    }
    if (errno) {
        sort_rows(matrix, n, m);
        output_matrix(matrix, n, m);
    }
    if (!errno) {
        printf("n/a");
    }
    mem_free(matrix, n);
    return 0;
}
