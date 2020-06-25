#include <stdio.h>
#include <stdlib.h>

struct LNodo{
	int elem;
	struct LNodo* next;
};

typedef struct LNodo LNodo;

struct Lista{
	LNodo* inicio;
	LNodo* fin;
};

typedef struct Lista Lista;

//Prototipos:
void CrearLista(Lista* lista);
int EsListaVacia(Lista* lista);
int LongitudLista(Lista* lista);
void Append(Lista* lista, int valor);
void Insertar(Lista* lista, int valor);
void InsertarPos(Lista* lista, int pos, int valor);
void ImprimirLista(Lista lista);
void EliminarLista(Lista* lista);
int PopFirst(Lista* lista);
int GetFirst(Lista lista);
//Fin Prototipos

void CrearLista(Lista* lista){
	lista->inicio = NULL;
	lista->fin = NULL;
}

int EsListaVacia(Lista* lista){
	return lista->inicio == NULL && lista->fin == NULL;
}

int LongitudLista(Lista* lista){
	int cant = 0;
	LNodo* ptrRunner = lista->inicio;
	while(ptrRunner){
		cant++;
		ptrRunner = ptrRunner->next;
	}
	return cant;
}

void Append(Lista* lista, int valor){
	LNodo* newNodo = (LNodo*)malloc(sizeof(LNodo));
	newNodo->elem = valor;
	newNodo->next = NULL;

	if(EsListaVacia(lista)) lista->inicio = newNodo;
	else lista->fin->next = newNodo;

	lista->fin = newNodo;
}

void Insertar(Lista* lista, int valor){
	LNodo* newNodo = (LNodo*)malloc(sizeof(LNodo));
	newNodo->elem = valor;
	if(EsListaVacia(lista)) lista->fin = newNodo;
	else newNodo->next = lista->inicio;

	lista->inicio = newNodo;
}

//Posiciones van desde 1 hasta el numero de elementos
void InsertarPos(Lista* lista, int pos, int valor){
	if(pos == 1){
		Insertar(lista, valor);
		return;
	}else if(pos > LongitudLista(lista) + 1){
		printf("Posicion Invalida\n");
		return;
	}

	LNodo* newNodo = (LNodo*)malloc(sizeof(LNodo));
	newNodo->elem = valor;

	LNodo *aux1, *aux2;
	aux1 = lista->inicio;
	aux2 = aux1->next;

	for(int i=1; i<pos-1; i++){
		aux2 = aux2->next;
		aux1 = aux1->next;
	}

	aux1->next = newNodo;
	newNodo->next = aux2;
}

void ImprimirLista(Lista lista){
	LNodo* aux = lista.inicio;
	while(aux){
		printf("%d -> ", aux->elem);
		aux = aux->next;
	}
	printf("NULL\n");
}

void EliminarLista(Lista* lista){
    LNodo *ptrAux1, *ptrAux2 = lista->inicio;
    while (ptrAux2){
        ptrAux1 = ptrAux2->next;
        free(ptrAux2);
        ptrAux2 = ptrAux1;
    }
    lista->inicio = lista->fin = NULL;
}

int PopFirst(Lista* lista){
	LNodo *aux = lista->inicio;
	int valor = aux->elem;
	lista->inicio = aux->next;
	free(aux);
	return valor;
}

int GetFirst(Lista lista){
	return lista.inicio->elem;
}





