#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int filas = 0;
int columnas = 0;


int main(){


	srand(time(NULL));
	int **x;

	printf("Ingrese el numero de filas: ");
	scanf("%d", &filas);
	printf("\nIngrese el numero de columnas: ");
	scanf("%d", &columnas);
	printf("\n\n\n\n");
	int sizes = columnas*filas;
	x = (int**)malloc(filas*sizeof(int));


	for(int i =0; i<filas; i++){
		x[i]=(int*)malloc(columnas*sizeof(int));
	}


	for(int i = 0;i<filas; i++){
		for(int j = 0; j<columnas; j++){
			x[i][j] =rand()%11;
		}
	}


	int *rows;
	int *column;
	int sumatoria=0;


	rows = (int*)malloc(sizes*sizeof(int));
	column = (int*)malloc(sizes*sizeof(int));


	int contador = 0;
	printf("matriz:\n");
	for(int i = 0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}



	if(filas >= columnas){
		for(int i = 0;i<filas; i++){
			for(int j = 0; j<columnas; j++){
					
				int numero = x[i][j];
				int numero_c = x[j][i];
					// printf("%d", numero);
				rows[contador] = numero;
				column[contador] = numero_c;
				contador++;
			}
		printf("\n");

		}
	}
	else{
		for(int i = 0;i<filas; i++){
			for(int j = 0; j<columnas; j++){
					
				int numero = x[i][j];
				// int numero_c = x[j][i];
				rows[contador] = numero;
				// column[contador] = numero_c;
				contador++;
			}
	}
		
	}
	//sumatoria filas
	int valor_previo = 0;
	int suma = 0;
	for(int i = 0; i< sizes; i++){
		if(i == 0){
			valor_previo = rows[0];
			suma = suma + valor_previo;
		}
		else{
			int actual  = rows[i];
			
			suma = actual + suma;
			valor_previo=actual;
			rows[i] =suma;
			
		}
	
	}
	sumatoria = rows[sizes-1];
	printf("\n\n\nLa sumatoria total de las filas es: %d", rows[sizes-1]);

	
//sumatoria filas
	valor_previo = 0;
	suma = 0;
	
	for(int i = 0; i< sizes; i++){
		if(i == 0){
			valor_previo = column[0];
			suma = suma + valor_previo;
		}
		else{
			int actual  = column[i];
			suma = actual + suma;
			valor_previo=actual;
			column[i] =suma;
			
		}
	
	}
	printf("\n\n\nLa sumatoria total de las columnas es: %d", sumatoria);
	


	for(int i = 0; i<columnas; i++){
		free(x[i]);
	}
	free(x);
	free(rows);
	free(column);
}