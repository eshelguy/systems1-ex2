#include <stdio.h>
#include "my_mat.h"

#define LOAD_MATRIX 'A'
#define HAS_PATH 'B'
#define FLOYD_WARSHALL 'C'
#define QUIT 'D'

void loadMatrix(int matrix[MAT_DIM][MAT_DIM]) {
    for (int i = 0; i < MAT_DIM; i++) {
        for (int j = 0; j < MAT_DIM; j++) {
            scanf(" %d", &matrix[i][j]);
        }
    }
}

int main() {
    char command;
    int matrix[MAT_DIM][MAT_DIM] = {0};
    int i, j;

    do {
        scanf("%c", &command);

        switch (command) {
            case LOAD_MATRIX:
                loadMatrix(matrix);
                break;
            case HAS_PATH:
                scanf(" %d %d", &i, &j);
                hasPath(matrix, i, j);
                break;
            case FLOYD_WARSHALL:
                scanf(" %d %d", &i, &j);
                int fw = floydWarshall(matrix, i, j);
                printf("%i\n", fw);
                break;
        }
    } while (command != QUIT && command != EOF);

    return 0;
}
