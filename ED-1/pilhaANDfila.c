#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct File{
	int dado;
	void *proximo;
}fila;

typedef struct Node{
	int dado;
	struct Node *prox;
}no;

no *tmp;
int size;

void iniciar(no *pilha){
	pilha->prox=NULL;
	size =0;
}

int vazia(no *pilha){
	if(pilha->prox ==NULL){
		return 1;
	}else{
		return 0;
	}
}

no *aloca(){
	no *Novo = (no*)malloc(sizeof(no));
	printf("Novo dado: "); scanf("%d",&Novo->dado);
	return Novo;
}

void push(no *pilha){
	no *new = aloca();
	new->prox=NULL;
	
	 if(vazia(pilha)){
	 	pilha->prox=new;
	 	size ++;
	 }else{
	 	  tmp=pilha->prox;
	 	  while(tmp->prox!=NULL){
	 	  	tmp=tmp->prox;
		   }
		   tmp->prox=new;
		   size ++;
	 }
}

no *pop(no *pilha){
	
	if(vazia(pilha)){
		printf("pilha vazia\n");
		
	}else{
	    no *ultimo = pilha->prox;
     	no *penultimo=pilha;
	   
		 while(ultimo->prox!=NULL){
		 	penultimo = ultimo;
		 	ultimo = ultimo->prox;
		 }
		 penultimo->prox =NULL;
		 size --;
		 return ultimo;
		 }
}

void clearStack(no *pilha){
	no *node=pilha->prox;
	no *nxt;
	
	if(vazia(pilha)){
		printf("pilha vazia!\n");
	}else{
	     while(node!=NULL){
	     	nxt=node->prox;
	     	free(node);
	     	node=nxt;
		 }	
	}printf("Stack Clear\n");
}

void showStack(no *stack){
if(vazia(stack)){
printf("\n\nPilha vazia\n\n");
}else{
tmp = stack->prox;
printf("\n");
while(tmp != NULL){
printf("%d ", tmp->dado);
tmp = tmp->prox;
}
printf("\nTamanho da Pilha: %d\n\n", size);
}
}


int main(int argc, char *argv[]) {
	int opc;
	no *pilha =(no*)malloc(sizeof(no));
	iniciar(pilha);
	
	printf("\t\t****PILHA***\n");
	do{
	
	printf("ESCOLHA:\n<1> Para inserir\n<2> Para remover\n<3> Para ver o tamanho\n<4> Para limpar..\n<5> Para sair!\n\nOPC: ");
	scanf("%d",&opc);
	
	
	 	switch(opc){
	 		case(1):
	 			push(pilha);
	 		
	 			break;
	 			
	 			case(2):
	 				tmp = pop(pilha);
	 				if(tmp!=NULL){
					
	 				printf("DADO REMOVIDO-> %d\n\n",tmp->dado);
	 				free(tmp);
	 		     	}
	 				break;
	 				
	 				case(3):
	 					printf("tamanho da PILHA = [%d]",size);
	 				    showStack(pilha);
	 					break;
	 					
	 					case(4):
	 						clearStack(pilha);
	 					     iniciar(pilha);
	 						break;
	 						
	 	
	 							default:
	 								printf("opcao invalida!\n");
	 								break;
	 	  }
	}while(opc!=5); 
		 
		 

	return 0;
}



