#include <stdio.h>
#include <stdlib.h>

struct PNodo{
	double peso_real;
	double peso_teorico;
	struct PNodo* next;
};

typedef struct PNodo PNodo;
typedef struct PNodo* Pila;

//Prototipos
void CrearPila(Pila* pila);
int EsPilaVacia(Pila*);
void Push(Pila* pila, double p_t, double p_r);
int Pop(Pila* pila);
void ImprimirPila(Pila pila);
void EliminarPila(Pila* pila);
void OrdenarPila(Pila* pila);
void Top(Pila* pila, double* p_t, double* p_r);

void CrearPila(Pila* pila){
	*pila = NULL;
}

int EsPilaVacia(Pila* pila){
	return (*pila == NULL);
}

void Push(Pila* pila, double p_t, double p_r){
	PNodo* newNodo;
	newNodo = (PNodo*)malloc(sizeof(PNodo));
	newNodo->peso_teorico = p_t;
	newNodo->peso_real = p_r;
	newNodo->next = *pila;
	*pila = newNodo;
}

/*int Pop(Pila* pila){
	PNodo* ptrEliminar;
	int valor;
	if(!EsPilaVacia(pila)){
		ptrEliminar = *pila;
		valor = ptrEliminar->elem;
		*pila = ptrEliminar->next;
		free(ptrEliminar);
		return valor;
	}
	return -1;
}*/

void Top(Pila* pila, double* p_t, double* p_r){
	if(!EsPilaVacia(pila)){
		PNodo* aux = *pila;
		(*p_t) = aux->peso_teorico;
		(*p_r) = aux->peso_real;
	}
}

void ImprimirPila(Pila pila){
	if(pila == NULL) return;
	PNodo* aux = pila;
	while(aux){
		printf("%.1lf - %.1lf\n", aux->peso_real, aux->peso_teorico);
		aux = aux->next;
	}
}

void EliminarPila(Pila* pila){
	PNodo* ptrEliminar = *pila;
    while(ptrEliminar != NULL){
        *pila = (*pila)->next;
        free(ptrEliminar);
        ptrEliminar = (*pila);
    }
    *pila = NULL;
}

/*void OrdenarPila(Pila* pila){
    int max, aux;
    Pila P2;
    P2 = NULL;

    while(!EsPilaVacia(pila)){
        max = Pop(pila);

        while(!EsPilaVacia(&P2)){
            aux = Top(&P2);

            if(aux > max){
                Push(pila, aux);
                Pop(&P2);
            }else break; 
        }

        Push(&P2, max);
    }

    EliminarPila(pila);
    
    while(!EsPilaVacia(&P2)){
        Push(pila, Pop(&P2));
    }

    EliminarPila(&P2);
}*/