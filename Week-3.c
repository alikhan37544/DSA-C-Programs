#include <stdio.h>
#include <stdlib.h>

// Function to perform matrix multiplication
void multiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2, int** result) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to display the matrix
void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions of the matrices
    printf("Enter the number of rows for Matrix 1: ");
    scanf("%d", &rows1);

    printf("Enter the number of columns for Matrix 1: ");
    scanf("%d", &cols1);

    printf("Enter the number of rows for Matrix 2: ");
    scanf("%d", &rows2);

    printf("Enter the number of columns for Matrix 2: ");
    scanf("%d", &cols2);

    // Check if matrices can be multiplied
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible. Invalid dimensions.\n");
        return 1;
    }

    // Allocate memory for the matrices using dynamic memory allocation
    int** matrix1 = (int**)malloc(rows1 * sizeof(int*));
    int** matrix2 = (int**)malloc(rows2 * sizeof(int*));
    int** result = (int**)malloc(rows1 * sizeof(int*));

    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int*)malloc(cols1 * sizeof(int));
        result[i] = (int*)malloc(cols2 * sizeof(int));
    }

    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int*)malloc(cols2 * sizeof(int));
    }

    // Input elements of Matrix 1
    printf("Enter elements of Matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements of Matrix 2
    printf("Enter elements of Matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform matrix multiplication
    multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2, result);

    // Display the result
    printf("\nResultant Matrix:\n");
    displayMatrix(result, rows1, cols2);

    // Free allocated memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
        free(result[i]);
    }

    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
