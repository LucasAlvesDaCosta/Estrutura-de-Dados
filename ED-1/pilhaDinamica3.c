#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

  struct aluno{
  	int matricula;
  	char nome[30];
  	float n1, n2, n3;
  	
  };
  
 
  
 typedef struct pilha{
  	struct aluno dados;
  	struct elemento *prox;
  }pilha;
  typedef struct pilha* pil;
 
  pil* pi;
  //pi = criar_pilha();
  pilha* criar_pilha();
     
    pilha* criar_pilha(){
     	pilha* pi = (pilha*)malloc(sizeof(pilha));
     	if(pi==NULL){
     		pi =NULL;
		 }
		 
		 return pi;
	 }



void destruir_pilha(pilha* pi){
	if(pilha != NULL){
		elem* no
	}
	
	 while(pi != NULL){
	 	no = *pi;
	 	*pi = *pi->prox;
	 	free(no);
	 }
	 free(pi);
}



int main(int argc, char *argv[]) {
	
	return 0;
}
