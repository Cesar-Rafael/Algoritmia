#include <stdio.h>
#include <stdlib.h>
#define max 10

int recorrer(int arriba, int abajo, int izquierda, int derecha, int matriz[][max]) {
	int cant = 0;
    if(izquierda > derecha) return cant;

    for(int i=izquierda; i<=derecha; i++){
        printf("%d ", matriz[arriba][i]);
        cant++;
    }
    arriba++;
    if(arriba > abajo) return cant;

    for (int i = arriba; i <= abajo; i++){
        printf("%d ", matriz[i][derecha]);
        cant++;
    }
    derecha--;
    if(izquierda > derecha) return cant;

    for (int i = derecha; i >= izquierda; i--){
        printf("%d ", matriz[abajo][i]);
        cant++;
    }
    abajo--;
    if(arriba > abajo) return cant++;

    for (int i = abajo; i >= arriba; i--){
        printf("%d ", matriz[i][izquierda]);
        cant++;
    }
    izquierda++;
    return cant + recorrer(arriba, abajo, izquierda, derecha, matriz);
}


int main(){

	int filas, columnas;
	printf("Ingrese las dimensiones de la matriz(filas, columnas):");
	scanf("%d %d", &filas, &columnas);
	int matriz[max][max];
    int cant=0;

    for (int i = 0; i < filas; i++)
      for (int j = 0; j < columnas; j++)
         matriz[i][j] = cant++;
     for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++)
            printf("%02d ", matriz[i][j]);
        printf("\n");
    }

    int arriba = 0, izquierda = 0;
    int abajo = filas-1, derecha = columnas -1;

    int cant_mont;

    cant_mont = recorrer(arriba, abajo, izquierda, derecha, matriz);
    putchar('\n');
    printf("Se ha recorrido %d monticulos\n", cant_mont);

    putchar('\n');
    return (EXIT_SUCCESS);
}