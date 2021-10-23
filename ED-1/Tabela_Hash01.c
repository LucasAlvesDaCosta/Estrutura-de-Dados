#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int tabela[MAX];
	
int hash(int x){
	return abs(x%100);
}

int _delete(int *tabela, int valor){
 int aux;
 int i;	
 int key = hash(valor);
 int tam = MAX;
 tabela[key]=-1;
 
  for(i=key+1; i<tam; i++){
  	if(tabela[i] != hash(tabela[i])){
  	   aux = tabela[i];
	   tabela[i]=-1;
	   inserir(tabela, aux);	
	   if(i>tam){
    	i=0;
    	tam = hash(valor);
	} 
    }
   
  }
 	
}

int colidir( int *tabela, int elemento, int hash){
	int i = hash, cont=0;
	 do{
	 if(tabela[i]!=-1){
	  i++;	
	 }else{
	 	tabela[i]=elemento;
	 	cont =2;
	 }
	
	 
	 if(i>MAX){
	 	i =0;
	 	cont ++;
	 }
	   }while(cont < 2);
}
int colisao( int *tabela, int elemento, int h){
	int TAM = MAX;
	int i = h;
	while(i<TAM && tabela[i]!= -1)
	i++;
	
	if(i<TAM)
	   tabela[i]=elemento;
	   else{
	   	i=0;
	   	while(i<h && tabela[i]!= -1)
	   	i++;
	   	if(i<h)
	   	 tabela[i]=elemento;
	   	
	   	 else
	   	 printf("tabela cheia!\n");
	   }
}

int inserir(int *tabela, int elemento){
	int h;
	h = hash(elemento);
	if(tabela[h]!= -1)
	 colisao(tabela,elemento,h);
	 else
	tabela[h]=elemento;
}

int impressao(int *tabela){
	int i;
	for(i=0; i<MAX; i++){
		printf("[%d]->[%d]\n",tabela[i],i);
	}
	
}

int menu(){
	

	int valor;
	printf("\n\t\t++++++Hash_Table+++++\n\n");
	printf("Entre com uma opcao:\n");
	printf("\n[1]-Para inserir");
	printf("\n[2]-Para Buscar");
	printf("\n[3]-Para Excluir");
	printf("\n[4]-Para Imprimir\n=> ");
	int opc;
	scanf("%d",&opc);
	 switch(opc){
	 	case(1):
	 		printf(">> inserir\n");
	 		printf("Digite o valor a ser inserido:\n=> ");
	 		scanf("%d",&valor);
	 		inserir(tabela,valor);
	 		printf("Inserido!1\n\n");
	 		return menu();
	 		break;
	 		
	 		case(2):
	 			printf(">> Buscar\n");
	 			return menu();
	 			break;
	 			
	 			case(3):
	 				printf(">> Excluir\n");
	 				int valor;
	 				printf("Digite o valor a ser excluido..\n=> ");
	 				scanf("%d",&valor);
	 				_delete(tabela,valor); 
	 				return menu();
	 				break;
	 				
	 				case(4):
	 					printf("TABELA\n\n");
	 					impressao(tabela);
	 					system("pause");
	 					return menu();
	 					break;
	 					
	 				        	default:
	 				        		printf("OPCAO INVALIDA!!\n");
	 				        
	 						    return -1;
	 }
		
}
int main(int argc, char *argv[]) {
	int i;
	for(i=0; i<MAX; i++){
		tabela[i]=-1;
	}
menu();
	return 0;
}
