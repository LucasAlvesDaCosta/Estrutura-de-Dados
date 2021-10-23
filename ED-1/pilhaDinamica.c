#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int dado;
	int tam;
	struct No *prox;
	
}no;

void push(no *PILHA){

    no *novo = (no*)malloc(sizeof(no));	
	printf("Digite um dado: ");
    	scanf("%d",&novo->dado);
    	novo->prox = NULL;
       
    
	 if(!novo){
	 	printf("sem memoria!\n");
	 	exit(1);
	 }
	 

	if(PILHA->prox==NULL){
		
		PILHA->prox=novo;
		printf("ASDFGHJKLÇ\n");
		
	}else{
	   	 no *tmp=PILHA->prox;
		 while(tmp->prox!=NULL){
		     tmp=tmp->prox;	
			 printf("07\n");
		} 
		 tmp->prox = novo;
	  	 printf("inserido!!\n");
	}
	return menu();
}

  no *pop(no *PILHA){
  	if(PILHA->prox==NULL){
  		printf("Pilha VAZIA!!!\n");
  		exit(1);
	  }else{
	  	
	  	    no *ultimo;
	  	    no *penultimo;
	  	        ultimo = PILHA->prox;
	  	        penultimo = PILHA;
	  	        
	  	   while(ultimo->prox!=NULL){
	  	   	penultimo = ultimo;
	  	   	ultimo = ultimo->prox;
			 }
		
		penultimo->prox=NULL;
		PILHA->tam--;
		return ultimo;
	  }
  }
  
   void exibe(no *PILHA){
   	  if(PILHA->prox==NULL){
   	  	printf("ta vazia essa porra!!\n");
		 }else{
		 	
		 	   no *tmp;
		 	   tmp=PILHA->prox;
		 	    while(tmp!=NULL){
		 	    	printf("[%d]",tmp->dado);
		 	    	tmp=tmp->prox;
				 }
		 }
   }
   
   void menu(){
   		printf("PILHA\n1 para inserir\n2 para retirar\n3 para exibir\n4 para sair!\nOPC: ");
	int opc;
	scanf("%d",&opc);
	 no *PILHA = (no*)malloc(sizeof(no));
	 PILHA->prox==NULL;
	 PILHA->tam =0;
	   if(opc ==1){
	   	
	   	push(PILHA);
	   	return menu();
	   }else
	     if(opc == 2){
	     	pop(PILHA);
	     	return menu();
		 }else
		   if(opc == 3){
		   	 exibe(PILHA);
		   	 return menu();
		   }else{
		   	printf("invalid opc!\n\n");
		   	return menu();
		   }
   }
int main(int argc, char *argv[]) {
  menu();
	return 0;
}
