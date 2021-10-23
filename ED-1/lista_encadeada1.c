#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int opc;
typedef struct NO{
	char *p_dados;
	struct NO *prox;
}NO;

 NO criar_Lista(struct NO **p_raiz){
 *p_raiz =NULL;
 printf("Digite um DADO: ");
 char *str;
 scanf("%s",&str);
 inserir_inicio(p_raiz,str);
 }
 
 
void inserir_inicio(NO **p_raiz, char *p_string){
 	NO *p_novo;
 	p_novo = (NO*)malloc(sizeof(NO));
 	
 	  if(p_novo == NULL){
 	  	puts("FUDEU!!\n");
 	  	exit(1);
	   }
	   
	 p_novo->p_dados = p_string;
	 p_novo->prox = *p_raiz;
	 *p_raiz = p_novo;  
	menu(); 
 } 

 void inserir_fim(NO **p_raiz, char *p_string){
 	NO *p_novo;
	NO *p_atual;
 	p_novo = (NO*)malloc(sizeof(NO));
 	 if(p_novo ==NULL){
 	 	printf("sem memoria disponivel!\n");
 	 	exit(1);
	  }
	   p_novo->p_dados=p_string;
	   p_novo->prox =NULL;
	   
	      if(*p_raiz == NULL){
	      	*p_raiz = p_novo;
		  }else{
		  	    p_atual = *p_raiz;
		  	    while(p_atual->prox != NULL){
		  	    	p_atual = p_atual->prox;// enquanto elE for diferente de NULL ele ira apontar para o prox elemento!!
				}
				p_atual->prox = p_novo;
		  }
 }
 
  void remove_inicio(NO **p_raiz){
   	if(*p_raiz == NULL){
   		printf("Lista vazia!!\n\n");
	   }else{
	   	    NO *p_atual;
	   	    p_atual = *p_raiz; // recebo a cabeça da lista e guardo em outo nó auxiliar
	
	   	    
	   	 *p_raiz = (*p_raiz)->prox; //agora aponto a cabeça para a proxima posição
	   	 free(p_atual); // agora elimino a antiga cabeça da lista (;
	   }
   }   


 void remove_fim(NO **p_raiz){
 	if(*p_raiz == NULL){
 		printf("Lista vazia!\n");
 		exit(1);
	 }else{
	 	   NO *p_atual;
	 	   NO *p_anterior;
	 	   p_atual = *p_raiz;
	 	   
	 	   while(p_atual->prox != NULL){
	 	   	p_anterior = p_atual;// enquanto eu nao estiver na cauda da lista  a variavel 'p_anterior' vai receber o proximo elemento
	 	   	p_atual = p_atual->prox;//
			}
			
			p_anterior->prox = NULL;// logo apos achar a caudA eu posso finalmente descartala apontando a mesma para NULL
			free(p_atual);// liberamos a variavel 
	 }
 }
 
 
  void mostrar_traz_frente(NO *p_raiz){
  	NO *p_atual;
  	NO *p_fim;
  	if(p_raiz == NULL){
  		printf("FAILLL\n");
  		exit(1);
	  }
	   while(p_fim->prox != NULL){// enquanto nao for o ultimo elemento o 'p_fim' irá receber o proximo elemento da lista
	   	p_fim = p_fim->prox;
	   }
	   
	   while(p_atual != p_fim){// enquanto eu não chegar no fim!!
	   	   if(p_atual->prox == p_fim){
	   	   	printf("<-[%s] ",p_fim->p_dados);
	   	   	p_fim = p_atual;
	   	   	p_atual = p_raiz;
		   }else{
		   	     p_atual = p_atual->prox;
		   }
		     printf("<-{%s}",p_fim->p_dados);
	   }
  }
  
  void mostrar_frente_traz(NO *p_raiz){
  	if(p_raiz == NULL){
  		printf("SEM MEMORIA!\n");
	  }
	  NO *p_atual;
	  p_atual = p_raiz;
	    while(p_atual->prox != NULL){
	    	printf("<-[%s]",p_atual->p_dados);
	    	p_atual = p_atual->prox;
		}
  }
  
  void menu(){
  	printf("LISTA ENCADEADA EM C!\n");
  	printf("Digite:\n1. para inserir na cabeça,\n2. para inserir na cauda,\n3. retirar da cabeça,\n4.retirar da cauda,\n5.para imprimir de traz p/ frente,\n6.para imprimir de frente p traz.\nOPC: ");
  	scanf("%d",&opc);
  	char *str;
  	str=malloc(10*sizeof(char));
  	NO ** p_raiz;
  	p_raiz=malloc(sizeof(NO));
  	switch(opc){
  		case 1:
  			criar_Lista(p_raiz);
  			break;
  			
  			case(2):
  				printf("Digite um DADO: ");
  				scanf("%s",&str);
  				inserir_fim(*p_raiz,str);
  				system("cls");
  				menu();
  				break;
  				
  				case(3):
  					remove_inicio(*p_raiz);
  					system("cls");
  					menu();
  					break;
  					
  					case(4):
  						remove_fim(p_raiz);
  						system("cls");
  						menu();
  						break;
  						case(5):
  							mostrar_traz_frente(p_raiz);
  							
  							menu();
  							break;
  							
  							case(6):
  								mostrar_frente_traz(p_raiz);
  								menu();
  								break;
  								
  								default:
  									printf("OPC invalid!\n");
  									system("cls");
  									menu();
  								
  							
	  }
  }
int main(int argc, char *argv[]) {
	menu();
	return 0;
}
