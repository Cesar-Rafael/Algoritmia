#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

void InvertirLista(Lista* lista, int n){
	if(n == 1) return;
	int dato;
	dato = PopFirst(lista);
	InsertarPos(lista, n, dato);
	InvertirLista(lista, n-1);
}

int main(){
	FILE* datos = fopen("datos.txt", "r");
	Lista lista;
	CrearLista(&lista);
	printf("Ingrese la cantidad de datos:\n");
	int n, dato;
	//Ingreso de datos con archivo de texto
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		fscanf(datos, "%d", &dato);
		Append(&lista, dato);
	}

	ImprimirLista(lista);
	InvertirLista(&lista, LongitudLista(&lista));
	printf("Lista invertida\n");
	ImprimirLista(lista);
	return 0;
}