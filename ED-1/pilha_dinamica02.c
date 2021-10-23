#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

    typedef struct celula{
    	int dado;
    	struct celula *prox;
	}celula;
	
	
	
	int pilha_cont;
	celula *topo;
	
void pilha_construtor(){
	topo=NULL;
	pilha_cont =0;
	
}

int pilha_vazia(){
	if(topo == NULL){
		return 1;
	}else{
		  return 0;
	}
}

 int tamanho_pilha(){
 	return pilha_cont;
 }
    
 int push(int valor){
      	celula *nova_celula = (celula*) malloc(sizeof(celula));
      	if(nova_celula == NULL){
      		printf("Sem memoria disponivel!\n");
      		exit(1);
		  }else{
		  	   nova_celula->dado = valor;
		  	   nova_celula->prox = topo;
		  	   
		  	   topo = nova_celula;
		  	   pilha_cont ++;
		  	   printf("DADO INSERIDO NO TOPO[%d]\n", valor);
		  	  // return valor;
		  }
 }
     
int pop(){
	celula *tmp;
	if(pilha_vazia()==1){
		printf("VAZIA!!\n\n");
	}else{
		int valor;
		 valor = topo->dado;
		 tmp = topo;
		 topo = topo->prox;
		 
		 tmp->prox=NULL;
		 free(tmp);
		 pilha_cont --;
		 get_pilha();
	}
}

int get_pilha(){
	if(pilha_vazia()==1){
		printf("pilha vazia!!!\n\n");
		return 0;
	}else{
	    int valor;
		 valor=topo->dado;
		 printf("valor do topo->%d",topo->dado);
		 //return valor;
	}
}

int destruir(){
	if(pilha_vazia()==1){
		return 0;
	}else{
		celula *tmp;
		 while(topo!=NULL){
		 	tmp=topo;
		 	tmp->prox=NULL;
		 	
		 	topo=topo->prox;
		 	free(tmp);
		 }
		 pilha_cont=0;
		 return 1;
	}
}

 void menu(){
   printf("Escolha uma opcao:\n1. para inserir,\n2. para retirar do topo,\n3.para destruir,\n4. para sair!\nOPC: ");
   int opc,valor;
   scanf("%d",&opc);
     pilha_construtor();
     switch(opc){
     	case 1:
     		printf("digite um valor: ");
     		scanf("%d",&valor);
     		push(valor);
     		return menu();
     		break;
     		      case 2:
     		      	pop();
     		      	return menu();
     		      	break;
     		      	      case 3:
     		      	      	 destruir();
     		      	      	 return menu();
     		      	      	 break;
     		      	      	  case 4:
     		      	      	  	tamanho_pilha();
     		      	      	  	return menu();
     		      	      	  	break;
     		      	      	  	case 5:
     		      	      	  		exit(1);
     		      	      	  		break;
     		      	      	  		default:
     		      	      	  			printf("opcao invalida!\n\n");
     		      	      	  			return menu();
     		      	      	  			break;
	 }	
 }
 
int main(int argc, char *argv[]) {
	menu();
	return 0;
}
