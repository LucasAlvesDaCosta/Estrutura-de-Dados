#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct arvore{
	int chave;
	int dado;
	struct arvore *prox;
	struct arvore *ant;
}no;

typedef no *arvore;

no *busca(arvore r, int k){
	if(r==NULL || r->chave==k){
		return r;
	}
	if(r->chave > k){
		return busca(r->ant, k);
	}else{
		return busca(r->prox, k);
	}
	
}

arvore insere(arvore r, no *novo){
	if(r==NULL){
		return novo;
	}
	if(r->chave > novo->chave){
		r->ant=insere(r->ant, novo);
	}else{
		r->prox=insere(r->prox, novo);
	}
	printf("foi!!\n");
	return r;
}

int main(int argc, char *argv[]) {
	arvore *raiz;
	raiz=NULL;
	
	int opc;
	int dado;
	no *aux;
	no *novo=(no*)malloc(sizeof(no));
	printf("Arvore\n\nopc: ");
	scanf("%d",&opc);
	
	do{
		switch(opc){
			case(1):
				printf("Digite o dado: ");
				
				scanf("%d",&dado);
				novo->dado = dado;
				printf("11111\n");
				insere(&raiz,novo);
				printf("@222\n");
				break;
				
				case(2):
				printf("digite a chave: ");
				scanf("%d",&dado);
				aux=busca(raiz, dado);
				printf("elemento-> %d\nchave-> %d\n",aux->dado,aux->chave);
				break;
				default:
					printf("invalid\n");
				break;
		}
		
	}while(opc!=0);
	return 0;
}
