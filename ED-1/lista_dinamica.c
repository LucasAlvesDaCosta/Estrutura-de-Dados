#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int element;
	  struct node *prox;
}node;


node *inserir_lista(node *inicio, node *lista, int i){
    lista->element =i;
    lista->prox =inicio;
    return lista;
}

   node *retirar_lista(node *lista){
   	node *no1;
   	int x;
   	   if(lista->prox ==NULL){
   	   	printf("impossivel retirar elementos da lista.\n");
   	   	return lista;
		}else{
			no1 = lista;
			lista = no1->prox;
			x = no1->element;
			printf("[%d] foi retirado da Lista!\n",x);
			return lista;
		}
   }
   
   void remov(node *p){
   node *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   
   free (lixo);
}
   
   void imprime(node *le){
   	node *p;
   	for (p=le->prox; p!=NULL; p=p->prox){
   		printf("|%d| ",p->element);
	   }
	  // if(p==NULL){
	  // 	printf("***********************END***********************\n");
	  // }
   }
   
   void exibe(node *LISTA){
	system("clear");
	
	
	node *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	while( tmp != NULL){
		printf("%5d", tmp->element);
		tmp = tmp->prox;
	
	}
	printf("\n        ");
	int count;
	for(count=0 ; count != -1; count++)
		printf("  ^  ");
	printf("\nOrdem:");
	for(count=0 ; count < sizeof(node); count++)
		printf("%5d", count+1);
	
		
	printf("\n\n");
}
/*  insere (int x, celula *p)
{
   celula *nova;
   nova = mallocc (sizeof (celula));
   nova->conteudo = x;
   nova->prox = p->prox;
   p->prox = nova;
}*/


   
   int menu(){
   		printf("MENU():\nDigite [1]. para inserir na lista!\nDigite [2]. para remover da lista!\nDigite [3]. para Exibir a lista!\n\tDIGITE [4] PARA SAIR!!\n\nOPCAO: ");
	int opc;
	scanf("%d",&opc);
	while(opc !=4){	int elemento;
			node *inicio;
			inicio = malloc(sizeof(node));
			inicio->element =-1;
			inicio->prox = NULL;
			node *p;
			p= (node*)(malloc(sizeof(node)));
		if(opc ==1){
		       while(elemento != -1){
			   
			   printf("Entre com um DADO: ");
			   scanf("%d",&elemento);
			   
			   inserir_lista(inicio,p,elemento);
		}
		menu();
		}else
		     if(opc ==2){
		           retirar_lista(inicio);
					free(inicio);	
			 }else
			      if(opc ==3){
		        
			        remov(inicio);
					}
				  else
				       if(opc ==4){
				       	return 0;
					   }
	}
   }

int main(int argc, char *argv[]) {
	menu();

	return 0;
}
