#include <stdio.h>
#include <limits.h>
#include "my_mat.h"

int floydWarshall(int matrix[MAT_DIM][MAT_DIM], int src, int dest) {
    if (src == dest) {
        return -1;
    }

    int output[MAT_DIM][MAT_DIM] = {0};

    for (int i = 0; i < MAT_DIM; i++) {
        for (int j = 0; j < MAT_DIM; j++) {
            if (i != j && matrix[i][j] == 0) {
                output[i][j] = INT_MAX;
            } else {
                output[i][j] = matrix[i][j];
            }
        }
    }

    for (int k = 0; k < MAT_DIM; k++) {
        for (int i = 0; i < MAT_DIM; i++) {
            for (int j = 0; j < MAT_DIM; j++) {
                if (output[i][k] != INT_MAX && output[k][j] != INT_MAX) {
                    if (output[i][j] > output[i][k] + output[k][j]) {
                        output[i][j] = output[i][k] + output[k][j];
                    }
                }
            }
        }
    }

    if (output[src][dest] == INT_MAX) {
        return -1;
    }

    return output[src][dest];
}

void hasPath(int matrix[MAT_DIM][MAT_DIM], int i, int j) {
    int fw = floydWarshall(matrix, i, j);
    if (i == j || fw == -1) {
        printf("False\n");
    } else {
        printf("True\n");
    }
}