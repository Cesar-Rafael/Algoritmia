#include <stdio.h>
#include <stdlib.h>
#define max 10

void recorrer(int x, int y, int n, int m, int matriz[][max]) {

    if(x >= n || y>= m) return;
    if(x == n-1 && y == m-1) printf("%d ", matriz[y][x]);

    for(int i=x; i<n-1; i++){
        printf("%d ", matriz[y][i]);
    }

    for (int i = y; i < m-1; i++){
        printf("%d ", matriz[i][n-1]);
    }

    for (int i = n-1; i > x; i--){
        printf("%d ", matriz[m-1][i]);
    }

    for (int i = m-1; i > y; i--){
        printf("%d ", matriz[i][x]);
    }

    recorrer(x + 1, y + 1, n-1, m-1, matriz);
    
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
            
	recorrer(0, 0, columnas, filas, matriz);

	putchar('\n');
	return (EXIT_SUCCESS);
}