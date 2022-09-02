#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int **addMatrix(int **matrix1, int **matrix2, int rows, int columns){
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++){
        result[i] = (int *)malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}


int **multiplyMatrix(int **matrix1, int **matrix2, int rows1, int columns1, int rows2, int columns2){
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++){
        result[i] = (int *)malloc(columns2 * sizeof(int));
        for (int j = 0; j < columns2; j++){
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}



int **substractMatrix(int **matrix1, int **matrix2, int rows, int columns){
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++){
        result[i] = (int *)malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}





int** randomMatrix(int n){
    int i, j;
    int **matrix = (int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++){
        matrix[i] = (int*)malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            matrix[i][j] = rand()%10;
        }
    }
    return matrix;
}


int main(){
    srand(time(NULL));
    int n = 0;
    scanf("%d", &n);


    int **matrix = randomMatrix(n);
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    printf("\n");


    int **matrix2 = randomMatrix(n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }



    int operation = 0;
    printf("Elige la operación. 1 suma, 2 resta y 3 multiplicación");
    scanf("%d", &operation);
    int **result;
    if (operation == 1){
        result = addMatrix(matrix, matrix2, n, n);
    }
    else if (operation == 2){
        result = substractMatrix(matrix, matrix2, n, n);
    }
    else if (operation == 3){
        result = multiplyMatrix(matrix, matrix2, n, n, n, n);
    }
    else{
        printf("Operación no válida");
    }
    


    //print the result
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }



    

}
