#ifndef _lista_
#define _lista_

/* PREENCHER COM SUAS DEFINIÇÕES DE TIPOS E FUNÇÕES */

typedef struct No {
	float coef;
	int exp;
	struct No *prox;
} No;

typedef struct lista {
	int tam;
	No *prim;
	No *ult;
} lista;

lista * construirLista();
void inserirLista(lista *l, float coef);
void calcularExpoentes(lista *l);

#endif
