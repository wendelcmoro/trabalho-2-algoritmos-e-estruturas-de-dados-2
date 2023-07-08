#include <stdlib.h>
#include "lista.h"

/*Preencher com o c�digo fonte */
lista * construirLista(){
	lista *l = malloc(sizeof(lista));
	l->tam = 0;
	l->prim = NULL;
	l->ult = NULL;
	return l;
}

void inserirLista(lista *l, float coef){

	No *novo = (No *) malloc(sizeof(No));
	novo->coef = coef;
	novo->prox = NULL;
	l->tam++;

	if (l->prim == NULL) {
		l->prim = l->ult = novo;
	} else {
		l->ult->prox = novo;
		l->ult = novo;
	}

}

void calcularExpoentes(lista *l){
	int e = l->tam-1;
	No *x = l->prim;

	while (x != NULL){
		x->exp = e;
		e = e-1;
		x= x->prox;
	}
}
