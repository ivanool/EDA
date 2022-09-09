#include <stdio.h>
#include <stdlib.h>

int **make_matrix(int n, int m)
{
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }
    return matrix;
}



void fill_matrix(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}



void print_matrix(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void restart_matrix(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 0;
        }
    }
}



int main(){

    int n, m;

    printf("Ingrese el tamaño de la matriz: \n");
    scanf("%d %d", &n, &m);

    int **matrix = make_matrix(n, m);

    while(1){
    printf("Ingrese 1 para llenar la matriz\n");
    printf("Ingrese 2 para imprimir la matriz\n");
    printf("Ingrese 3 para reiniciar la matriz\n");

    int option;
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        fill_matrix(matrix, n, m);
        break;
    case 2:
        print_matrix(matrix, n, m);
        break;
    case 3:
        restart_matrix(matrix, n, m);
        break;
    default:
        printf("Opcion no valida\n");
        break;
    }
    }
    
    
}