#include <stdio.h>
#include <stdlib.h>
#include "cola.c"
#include "pila.c"

//Problema:
void LlenarPila(int tipo, Pila* pila, Cola* cola_cajas){
	double p_r, p_t;
	int n = LongitudCola(cola_cajas);
	int condicion;

	for(int i=0; i<n; i++){
		Desencolar(cola_cajas, &p_r, &p_t);
		switch(tipo){
			case 1: condicion = p_r == p_t; break;
			case 2: condicion = p_r < p_t; break;
			case 3: condicion = p_r > p_t; break;
			default: condicion = 0; break;
		}
		if(condicion) Push(pila, p_t, p_r);
		else Encolar(cola_cajas, p_t, p_r);
	}
}

int main(){
	FILE* datos = fopen("datos.txt", "r");
	Cola cola_cajas;
	Pila pila1, pila2, pila3;
	CrearCola(&cola_cajas);
	CrearPila(&pila1);
	CrearPila(&pila2);
	CrearPila(&pila3);
	int n, cant1, cant2, cant3;
	double p_teo, p_real;

	//INGRESO DE DATOS
	printf("Ingrese la cantidad de cajas: ");
	scanf("%d", &n);
	printf("Ingrese el peso teorico y peso real(ARCH. TEXTO):\n");
	for(int i=0; i<n; i++){
		fscanf(datos, "%lf %lf", &p_teo, &p_real);
		Encolar(&cola_cajas, p_teo, p_real);
	}

	//TEST INPUT
	/*for(int i=0; i<n; i++){
		Desencolar(&cola_cajas, &p_real, &p_teo);
		printf("%.1lf %.1lf \n", p_teo, p_real);	
	}*/

	// 1 - Pila con productos de primera calidad
	// 2 - Pila con productos con defecto
	// 3 - Pila con productos con exceso
	LlenarPila(1, &pila1, &cola_cajas);
	LlenarPila(2, &pila2, &cola_cajas);
	LlenarPila(3, &pila3, &cola_cajas);
	printf("Cola:\n");
	ImprimirCola(cola_cajas);
	printf("Pila calidad:\n");
	ImprimirPila(pila1);
	printf("Pila con defecto:\n");
	ImprimirPila(pila2);
	printf("Pila con exceso:\n");
	ImprimirPila(pila3);
	return 0;
}