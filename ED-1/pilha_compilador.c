#include <stdio.h>
#include <stdlib.h>
#define tamanho 15
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char vetor[tamanho];
int topo =0;
int opc;
 void menu(){
 	
 	printf("COMPILADOR DE EXPRESSÕES MATEMATICAS:\n\nDigite 1. Para inserir\n2. Para sAiR!!\nOPC: ");
      scanf("%d",&opc);
      while(opc != 2){
	  
    	switch(opc){
	    	case 1:
			inserir();
			return menu();
			break;
	      case 2:
	    	exit(1);
	    	break;
	     default:
	    	printf("EROUUUU!!\n\n\n");
	        return menu();
	    	break;
      }
	}
}
 void inserir(){
 	if(topo == 10){
 		printf("pilha cheia!\n");
	 }else{
	 	printf("Digite a expressao matematica para verificacao: ");
	 	int i;
	 	for(i=tamanho-1; i>=0; i--){
	 		scanf("%c",&vetor[i]);
	 		topo ++;
		 }
	 }
	 verificar();
 }
 
 void verificar(){
 	int i;
 	int cont_open =0;
 	int cont_close =0;
 	for(i=tamanho-1; i>=0; i--){
 		if(vetor[i]=='('){
 			cont_open++;
		 }
		 if(vetor[i]==')'){
		 	cont_close++;
		 }
	 }
	 if(cont_open != cont_close){
	 	printf("#expressao invalida!\n");
	 }else
	      if(cont_open == cont_close){
	      	printf("Expressao Valida!\n");
		  }
		  exibir();
 }

void exibir(){
int i;
  for(i=tamanho-1; i>=0; i--){
  	printf("%c",vetor[i]);
  }
  printf("\n+++++++++++++++++++++++++\n");
}


int main(int argc, char *argv[]) {
menu();	
return 0;
}

