#include "hellomake.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **create_matrix(int rows, int cols) {
    double **matrix = (double **) malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *) calloc(cols, sizeof(double));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double )(rand() % 100 + 1.0);
        }
    }
    return matrix;
}

double *create_vector(int cols) {
    double *vector = (double *) calloc(cols, sizeof(double));
    for (int i = 0; i < cols; i++) {
        vector[i] = (double )(rand() % 100 + 1.0);
    }
    return vector;
}

double *multiple_matrix_vector(double **matrix, double *vector, int rows, int cols) {
    double *result = (double *) calloc(rows, sizeof(double));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    return result;
}

void write_output(char *outputFileName, double *result, int rows) {
    FILE *output_file = fopen(outputFileName, "w");
    for (int i = 0; i < rows; i++) {
        fprintf(output_file, "%lf\n", result[i]);
    }
    fclose(output_file);
}

void free_memory(double **matrix, double *vector, double *result, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(vector);
    free(result);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Wrong argument usage ERROR! in %s\n", argv[0]);
        return 1;
    }
    srand(time(NULL));
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    char *outputFileName = argv[3];

    double **matrix = create_matrix(rows, cols);
    double *vector = create_vector(cols);
    double *result = multiple_matrix_vector(matrix, vector, rows, cols);
    write_output(outputFileName, result, rows);
    free_memory(matrix, vector, result, rows);


    return 0;
}
