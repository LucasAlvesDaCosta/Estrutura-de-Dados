#include <stdio.h>
#include <stdlib.h>
#define VERMELHA 1 
#define PRETA 0
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	int valor;
	int cor;
	struct node *esquerda;
	struct node *direita;
	struct node *pai;
};

void rotacionar_esquerda(struct node *x, struct node* raiz){
		 struct node y;
		 y = (x)-> esquerda;
		 (*x) -> esquerda = y -> direita;
			 if (y -> direita == NULL) {
					( y -> direita) -> pai = (*x);
			 }
			 y -> pai = (*x) -> pai;
			 if ( ( (*x) -> pai) == NULL ) {
						 (*raiz) = y;
			 }
			 else {
							if ( (*x) == ( (*x) -> pai ) -> esquerda ) {
								 (*x) -> pai -> esquerda = y;
							}
							else {
									 (*x) -> pai -> direita = y;
							}
			 }
			 y -> direita = (*x);
			 (*x) -> pai = y;
 }

void rotacionar_direita(struct node *pai, struct node* raiz){
	
}

void insercao_caso2(struct node *n);
void insercao_caso3(struct node *n);
void insercao_caso4(struct node *n);
void insercao_caso5(struct node *n);

struct node *avo(struct node *n){
	if ((n != NULL) && (n->pai != NULL))
		return n->pai->pai;
	else
		return NULL;
}

struct node *
tio(struct node *n)
{
	struct node *g = avo(n);
	if (g == NULL)
		return NULL; // Não ter avô significa não ter tio
	if (n->pai == g->esquerda)
		return g->direita;
	else
		return g->esquerda;
}
void insercao_caso1(struct node *n){
	if (n->pai == NULL)
		n->cor = PRETA;
	else
		insercao_caso2(n);
}
void insercao_caso2(struct node *n){
	if (n->pai->cor == PRETA)
		return; /* Árvore ainda é válida */
	else
		insercao_caso3(n);
}
void
insercao_caso3(struct node *n)
{
	struct node *u = tio(n), *g;

	if ((u != NULL) && (u->cor == VERMELHA)) {
		n->pai->cor = PRETA;
		u->cor = PRETA;
		g = avo(n);
		g->cor = VERMELHA;
		insercao_caso1(g);
	} else {
		insercao_caso4(n);
	}
}
void
insercao_caso4(struct node *n)
{
	struct node *g = avo(n);

	if ((n == n->pai->direita) && (n->pai == g->esquerda)) {
		rotacionar_esquerda(n->pai,n);
		n = n->esquerda;
	} else if ((n == n->pai->esquerda) && (n->pai == g->direita)) {
		rotacionar_direita(n->pai,n);
		n = n->direita;
	}
	insercao_caso5(n);
}
void
insercao_caso5(struct node *n)
{
	struct node *g = avo(n);

	n->pai->cor = PRETA;
	g->cor = VERMELHA;
	if ((n == n->pai->esquerda) && (n->pai == g->esquerda)) {
		rotacionar_direita(g,n);
	} else {
		/*
		 * Aqui, (n == n->pai->direita) && (n->pai == g->direita).
		 */
		rotacionar_esquerda(g,n);
	}
}

int main(int argc, char *argv[]) {
	return 0;
}
