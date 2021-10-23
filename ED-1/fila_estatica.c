#include <stdio.h>
#include <stdlib.h>
#define max 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct fila{
	int cod;
	char nome[20];
}fila;

 fila f[max];
 int inicio;
 int final =0;
 int opc;
 
void insere(){
   if(final==max){
   	printf("\n\t\t################fila cheia!!###############\n\n");
   
   	return menu();
   }else{
   	    fila file;
   	    printf("Digite o codigo: ");
   	    scanf("%d",&f[final].cod);
   	    
   	    printf("Digite o nome: ");
   	    scanf("%s",&f[final].nome);
   	    final ++;
   }
   imprime();
}



void retira(){
	printf("elemento |%d+%s| retirado do inicio da fila!\n",f[inicio].cod,f[inicio].nome);
	f[inicio].cod = NULL;
	f[inicio].nome;
	
	inicio++;
	if(inicio == final){
		inicio =0;
		final = 0;
		
	}
	imprime();
}

 void imprime(){
 	int i;
 	for(i=inicio; i<final; i++){
 		printf(" [%d-(%s)]-",f[i].cod,f[i].nome);
	 }
	 printf("\n_____________________________\n");
 }
 
 
   void menu(){
   	
   	printf("FILA em C!\nEscolha:\n1. Para inserir\n2.Para retitar\n3. Para sair!\nOPC: ");
   	scanf("%d",&opc);
   	   switch(opc){
   	   	     case(1):
   	   	     	insere();
   	   	     	return menu();
   	   	     	break;
   	   	     case(2):
   	   	     	retira();
   	   	     	return menu();
   	   	     	break;
   	   	     case(3):
   	   	     	 exit(1);
   	   	     	 break;
   	   	     default:
   	   	     	 printf("EROOOUU!!\n");
   	   	     	 return menu();
   	   	     	 break;
		  }
   }
int main(int argc, char *argv[]) {
	menu();
	return 0;
}
