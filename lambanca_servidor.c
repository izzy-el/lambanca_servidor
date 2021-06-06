#include <stdio.h>
#include <math.h>

int main() {
    //max size for matrix is 10x10
    int matrixSize;
    int correction;

    scanf("%d", &matrixSize);
    scanf("%d", &correction);
    
    int matrix[matrixSize][matrixSize];
    int newMatrix[matrixSize][matrixSize]; //corrected matrix
    int matrixPath[matrixSize][matrixSize];

    //getting the user's input for the matrix
    for(int i = 0; i < matrixSize; i++) {
        for(int j = 0; j < matrixSize; j++) {
            scanf("%d", &matrix[i][j]);
            matrix[i][j] *= correction;
        }
    }

    for(int i = 0; i < matrixSize; i++) {
        for(int j = 0; j < matrixSize; j++) {
            scanf("%d", &matrixPath[i][j]);
        }
    }    

    printf("Matriz corrigida\n");
    for(int i = 0; i < matrixSize; i++) {
        for(int j = 0; j < matrixSize; j++) {
            newMatrix[j][i] = matrix[j][matrixPath[i][j]];
        }
    }

    for(int i = 0; i < matrixSize; i++) {
        for(int j = 0; j < matrixSize; j++) {
            printf("%d\t", newMatrix[i][j]);
        }
        printf("\n");
    }

    //getting the sum of each column
    printf("Somas::");
    for(int i = 0; i < matrixSize; i++) {
        float temp = 0;
        for(int j = 0; j < matrixSize; j++) {
            temp += newMatrix[j][i];
        }
        printf("%.2f\t", temp);
    }
    printf("\n");

    //getting the average of each column
    printf("Media::");
    for(int i = 0; i < matrixSize; i++) {
        float temp = 0;
        for(int j = 0; j < matrixSize; j++) {
            temp += newMatrix[j][i];
        }
        temp /= matrixSize;
        printf("%.2f\t", temp);
    }
    printf("\n");

    //getting the standard deviation of each column
    printf("Desvios::");
    for(int i = 0; i < matrixSize; i++) {
        float temp = 0;
        float tempDp = 0;

        for(int j = 0; j < matrixSize; j++) {
            temp += newMatrix[j][i];
        }

        temp /= matrixSize;
        for(int j = 0; j < matrixSize; j++) {
            tempDp += pow((newMatrix[j][i] - temp), 2);
        }

        float dp = sqrt(tempDp/matrixSize);
        printf("%.2f\t", dp);
    }
    printf("\n");


    return 0;
}