#ifndef MY_MAT_H
#define MY_MAT_H

#define MAT_DIM 10

int floydWarshall(int matrix[MAT_DIM][MAT_DIM], int src, int dest);

void hasPath(int matrix[MAT_DIM][MAT_DIM], int i, int j);

#endif //MY_MAT_H
