#include <stdio.h>
#include <stdlib.h>

struct CNodo{
	double peso_real;
	double peso_teorico;
	struct CNodo* next;
};

typedef struct CNodo CNodo;

struct Cola{
	CNodo* inicio;
	CNodo* fin;
};

typedef struct Cola Cola;

//Prototipos
void CrearCola(Cola* cola);
int EsColaVacia(Cola* cola);
void Encolar(Cola* cola, double p_t, double p_r);
void Desencolar(Cola* cola, double* p_real, double* p_teorico);
int LongitudCola(Cola* cola);
void ImprimirCola(Cola);
void EliminarCola(Cola*);
//void OrdenarCola(Cola* cola, int n);
//Fin Prototipos

void CrearCola(Cola* cola){
	cola->inicio = NULL;
	cola->fin = NULL;
}

int EsColaVacia(Cola* cola){
	return cola->inicio == NULL && cola->fin == NULL;
}

void Encolar(Cola* cola, double p_t, double p_r){
	CNodo* newNodo = (CNodo*)malloc(sizeof(CNodo));
	newNodo->peso_real = p_r;
	newNodo->peso_teorico = p_t;
	newNodo->next = NULL;

	if(EsColaVacia(cola)) cola->inicio = newNodo;
	else cola->fin->next = newNodo;
	
	cola->fin = newNodo;
}

void Desencolar(Cola* cola, double* p_real, double* p_teorico){
	if(cola->inicio == NULL){
		printf("La cola esta vacia\n");
		return;
	}
	CNodo* ptrAux = cola->inicio;
	(*p_real) = ptrAux->peso_real;
	(*p_teorico) = ptrAux->peso_teorico;
	cola->inicio = (cola->inicio)->next;
	free(ptrAux);
}

int LongitudCola(Cola* cola){
	int cant=0;
	CNodo* ptrAux = cola->inicio;
	while(ptrAux){
		ptrAux = ptrAux->next;
		cant++;
	}
	return cant;
}

void ImprimirCola(Cola cola){
	CNodo* ptrAux = cola.inicio;
	while(ptrAux){
		printf("%.1lf - %.1lf\n", ptrAux->peso_real, ptrAux->peso_teorico);
		ptrAux = ptrAux->next;
	}
}

void EliminarCola(Cola* cola){
    CNodo* ptrAux1, *ptrAux2 = cola->inicio;
    while (ptrAux2){
        ptrAux1 = ptrAux2->next;
        free(ptrAux2);
        ptrAux2 = ptrAux1;
    }
    cola->inicio = cola->fin = NULL;
}