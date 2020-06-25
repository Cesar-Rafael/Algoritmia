#include <stdio.h>
#include <stdlib.h>


int recorrer(int ini_fil, int ini_col, int fil, int col, int matriz[fil][col][2]) {
    int cont = 0;

    //Derecha
    for(int i=ini_col; i<=col-ini_fil-1; i++){
    	if(matriz[ini_fil][i][1] != 1){
    		matriz[ini_fil][i][1] = 1;
    		printf("%d ", matriz[ini_fil][i][0]);
    		cont++;
    	}else return cont;
    }

    //Abajo
    for(int i=ini_fil+1; i<=fil - ini_col - 1; i++){
    	if(matriz[i][col-ini_col-1][1] != 1){
    		matriz[i][col-ini_col-1][1] = 1;
    		printf("%d ", matriz[i][col-ini_col-1][0]);
    		cont++;
    	}else return cont;
    }

    //Izquierda
    for(int i=col - ini_col - 2; i>= ini_col; i--){
    	if(matriz[fil - ini_fil - 1][i][1] != 1){
    		matriz[fil - ini_fil - 1][i][1] = 1;
    		printf("%d ", matriz[fil - ini_fil - 1][i][0]);
    		cont++;
    	}else return cont;
    }

    //Arriba
    for(int i=fil - ini_fil - 2; i>= ini_fil + 1; i--){
    	if(matriz[i][ini_col][1] != 1){
    		matriz[i][ini_col][1] = 1;
    		printf("%d ", matriz[i][ini_col][0]);
    		cont++;
    	}else return cont;
    }

    cont += recorrer(ini_fil + 1, ini_col + 1, fil, col, matriz);
    return cont;
}


int main(){

	int filas, columnas, num=0;
	printf("Ingrese las dimensiones de la matriz(filas, columnas):");
	scanf("%d %d", &filas, &columnas);
	int matriz[filas][columnas][2];
	int cant_Monticulos;

	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++)
			matriz[i][j][0] = num++;

	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++)
			matriz[i][j][1] = 0;

    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++)
            printf("%02d ",matriz[i][j][0]);
        printf("\n");
    }

    //Los dos 0 significan de donde voy a empezar el camión, en este caso empezará desde la fila 0 y columna 0, y como la parte C pide
    //la cantidad, le envío por referencia el valor de cant_Monticulos
	cant_Monticulos = recorrer(0, 0, filas, columnas, matriz);

	printf("\nLa cantidad de monticulos encontrados es: %d", cant_Monticulos);

	putchar('\n');
	return (EXIT_SUCCESS);
}