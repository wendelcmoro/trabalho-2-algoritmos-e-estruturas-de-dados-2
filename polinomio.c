#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "polinomio.h"

/*----------------------------------------------------------------------------*/


polinomio constroi_polinomio(char *s) {
	lista *l=construirLista();
	for (int i =1; i < 5; i++)
		inserirLista(l, i);
    /*int i = 0;
	int j = 0;
	float valor;

	int tamS=strlen(s);
	lista *l=construirLista();
	char stringAux[tamS];
	
	for (i = 0; i <= tamS; i++){
		if (s[i] != ' ' && s[i] != '0')
			break;
		}
  
	while (i <= tamS){
		stringAux[j] = s[i];
		j = j+1;
		if (s[i] == ' ' || s[i] == '\0'){
			stringAux[j] = '\0';
			j = 0;
			valor = atof(stringAux);
			inserirLista(l,valor);
		}
		i = i+1;
	}*/
	calcularExpoentes(l);
	return l;
}
/*----------------------------------------------------------------------------*/
void destroi_polinomio(polinomio p) { 
	No *x;
	No *a = p->prim;
	while (a != NULL){
		x = a;
		a = a->prox;
		free(x);
	}
	free(p);
 }
/*----------------------------------------------------------------------------*/
polinomio escreve_polinomio(polinomio p) {
	No *k = p->prim;
	if (k->coef == -1 && k != p->ult)
		printf ("-");
	
	while (k != p->ult){
			
		if (k->coef != 1 && k->coef != -1 && k->coef != 0){
			if (k->coef == (int)k->coef)
				printf ("%.0f", k->coef);
			else
				printf ("%.2f", k->coef);
		}
		
		if (k->exp > 0 && k->coef != 0){
			if (k->exp > 1)
				printf ("x^%d ", k->exp);
			else
				printf ("x ");
		}
		
		if (k->prox != NULL){
			if (k->prox->coef > 0)
				printf ("+");
			if (k->prox->coef == -1 && k->prox->exp != 0)
				printf ("-");
		}
		k = k->prox;
	}
	if (k->coef != 0){
		if (k->coef == (int)k->coef)
			printf ("%.0f", k->coef);
		else
			printf ("%.2f", k->coef);
	}
		
	return p;
}
/*----------------------------------------------------------------------------*/
polinomio soma(polinomio p, polinomio q) {
	lista *resul = construirLista();
	lista *maior, *menor;
	No *noR, *noMa, *noMe;
	float valor;

	if (p->tam >= q->tam) {
		maior = p;
		menor = q;
	} else {
		maior = q;
		menor = p;
	}

	noMa = maior->prim;
	noMe = menor->prim;
	for (int i = maior->tam - 1; i >= 0; i--) {
		valor = noMa->coef;

		if (i <= menor->tam - 1) {
			valor += noMe->coef;
			noMe = noMe->prox;
		}
		inserirLista(resul, valor);
		noMa = noMa->prox;
	}

	calcularExpoentes(resul);
	return resul;
}
/*----------------------------------------------------------------------------*/
polinomio multiplica(polinomio p, polinomio q) {
	lista *resulParcial = construirLista();
	lista *resul = construirLista();
	No *noP, *noQ;

	noP = p->prim;
	while (noP != NULL) {
		noQ = q->prim;
		while (noQ != NULL) {
			inserirLista(resulParcial, noP->coef * noQ->coef);
			noQ = noQ->prox;
		}
		for (int i = 0; i <= noP->exp + q->ult->exp - 1; i++) {
			inserirLista(resulParcial, 0);
		}
		calcularExpoentes(resulParcial);
		resul = soma(resul, resulParcial);
		destroi_polinomio(resulParcial);
		resulParcial = construirLista();
		noP = noP->prox;

	}
	calcularExpoentes(resul);

	return resul;
}
/*----------------------------------------------------------------------------*/
polinomio subtrai(polinomio p, polinomio q) {
	lista *resul = construirLista();
	lista *maior, *menor;
	No *noR, *noMa, *noMe;
	float valor;

	if (p->tam >= q->tam) {
		maior = p;
		menor = q;
	} else {
		maior = q;
		menor = p;
	}

	noMa = maior->prim;
	noMe = menor->prim;
	for (int i = maior->tam - 1; i >= 0; i--) {
		if (maior == q) {
			valor = -noMa->coef;
		} else {
			valor = noMa->coef;
		}

		if (i <= menor->tam - 1) {
			if (menor == q) {
				valor -= noMe->coef;
			} else {
				valor += noMe->coef;
			}
			noMe = noMe->prox;
		}
		
		inserirLista(resul, valor);
		noMa = noMa->prox;
	}

	calcularExpoentes(resul);
	return resul;
}
/*----------------------------------------------------------------------------*/
polinomio derivada(polinomio p) {
  lista *der =  construirLista();
  No *x = p->prim;
  
	while (x != p->ult){
		
		inserirLista(der,(x->coef)*(x->exp));
		x = x->prox;
	}
	if (der->tam >= 1)
		calcularExpoentes(der);
	else
	 	inserirLista(der,0);
	return der;
}
/*----------------------------------------------------------------------------*/
polinomio primitiva(polinomio p) {
  lista *primitiva =  construirLista();
  No *x = p->prim;
  
  while (x != NULL){
		inserirLista(primitiva, (x->coef)/(x->exp +1));
		x = x->prox;
	}
	
	inserirLista(primitiva, 0);
	calcularExpoentes(primitiva);
	return primitiva;
}
/*----------------------------------------------------------------------------*/
float avalia(polinomio p, float x) {
	float soma=0;
	No *k = p->prim;
	
	while (k != NULL){
		soma = soma + (k->coef)*pow(x, k->exp);
		k = k->prox;
	}
	return soma;
}
