#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int tabela[MAX];

int menu(){

	int valor, resp;
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
	 		
	 		 if(insere(valor,tabela)){
	 		 		printf("\t->Inserido!1\n\n");
			  }else printf("\t->Nao inserido\n");
	 	
	 		return menu();
	 		break;
	 		
	 		case(2):
	 			printf(">> Buscar\n");
	 			printf("Digite o valor a ser buscado: ");
	 			scanf("%d",&valor);
	 			 resp =procura(valor,tabela);
	 			 if(resp != -1){
	 			 	printf("Valor encontrado na posicao:[%d] tabela[%d]\n",resp,tabela[resp]);
				  }else
				       printf("Value not found!\n");
				       
	 			return menu();
	 			break;
	 			      case(3):
	 			      	    printf(">> IMPRIMIR\n");
	 			      	    impressao(tabela);
	 			      	    return menu();
	 			      	    break;
	 					
	 				        	default:
	 				        		printf("OPCAO INVALIDA!!\n");
	 				        
	 						    return menu();
	 						    break;
	 }
		
}
int hash(int x){
	int key = MAX%x;
	return key;
}

int impressao(int *tabela){
	int i;
	for(i=0; i<MAX; i++){
		printf("[%d]->[%d]\n",tabela[i],i);
	}
	
}
int insere(int valor, int *vetor){
	int chave,i,cont=0;
	
	chave = hash(valor);
	printf("\n\t\t\tHASH:[%d]",hash(valor));
	 if(vetor[chave] == -1 && chave<MAX){
	 	vetor[chave]=valor;
	 	return 1;
	 }
	 else{
	 	
	 	while(vetor[chave] != -1 && chave<MAX){
	 		printf("\n>>>>[%d]\n",chave);
	 		if(vetor[chave+1] == -1){
	 		  vetor[chave+1]=valor;
	 		  return 1;
			 }else
			      if(chave<MAX-1)
			    chave++;
			     else{
			        if(chave >= MAX-1){
			        	chave=0;
			         	printf("\nchave[%d] max[%d]",chave,MAX-1);
			    		printf("\tChave = %d\n",cont);
			 	         while(vetor[chave]== -1){
			 	        	printf("------>(%d)\n",vetor[chave]);
			 	             if(vetor[chave]== -1){
			 	         	  vetor[chave]=valor;
			 	   	          return 1;
				        	}else
					          chave++;	
				         }
		     	    }	
		     	  
				}     
	    }
	       
    }    
			 
	  return 0;
}
int procura(int valor, int *vetor){
	int chave;
	chave = hash(valor);
	printf("sen in key [%d]\n",chave);
	 if(vetor[chave] == valor){
	 	printf("vetor[%d] = %d\n",vetor[chave],valor);
	 	return chave;
	 } else{
	 	
	 	while(vetor[chave] != valor && chave<MAX){
	 		printf("\n>>>>[%d]\n",chave);
	 		if(vetor[chave+1] == valor){
	 		  return chave+1;
			 }else
			      if(chave<MAX-1)
			    chave++;
			     else{
			        if(chave >= MAX-1){
			        	chave=0;
			         	printf("\nchave[%d] max[%d]",chave,MAX-1);
			 	         while(vetor[chave] !=valor && chave<MAX){
			 	        	printf("------>(%d)\n",vetor[chave]);
			 	             if(vetor[chave]== valor){
			 	   	          return chave;
				        	}else
					          chave++;	
				         }
		     	    }	
		     	  
				}     
	    }
	       
    }    
	 return -1;
}
int main(int argc, char *argv[]) {
		int i;
	for(i=0; i<MAX; i++){
		tabela[i]=-1;
	}
	menu();
	return 0;
}
