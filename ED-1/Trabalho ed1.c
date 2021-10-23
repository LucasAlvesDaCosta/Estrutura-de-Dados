
#include <stdio.h>
#include <stdlib.h>

     typedef struct lista{
	 int info;
	 struct lista* prox;
     }Lista;
    //Função Inicializa a lista!
    Lista* inicializa(){
 	return NULL;
    }
 // Função verifica se a lista esta vazia!
   int vazia(Lista *L){
  	return(L==NULL);
   }
                  /// Funcao de insercao na lista   
                  Lista* Insere(Lista* L,int i){
               	Lista*novo=(Lista*)malloc(sizeof(Lista));
                  } 
                  //******* Função Concatena Lista!!!*****///
               Lista* CAT(Lista* L1,Lista* L2){
                Lista* p;
			 p=L1;
			   if(p){
			   	   while(p->prox=!NULL){
			   		p+=p->prox;
				   }
			   }	
			   p->prox=L2;
			   return L1;
			}   
int main(int argc, char *argv[]) {
	return 0;
}
