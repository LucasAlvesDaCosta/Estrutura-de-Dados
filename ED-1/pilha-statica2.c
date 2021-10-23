#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int dado[10];
int topo;
int opc;


    void exibir(){
    	int i;
    	for(i=topo-1; i>=0; i--){
    		printf("posicao[%d] ->|%d|\n",i,dado[i]);
    		printf("++++++++++++++++++\n");
		}
	}
	
	
	
	void inserir(){
		if(topo == 10){
			printf("pilha cheia!!\n");
		}else{
			printf("Digite um valor inteiro para adicionar a pilha: ");
			scanf("%d",&dado[topo]);
			topo++;
		}
		exibir();
	}
	
	 void remover(){
	 	if(topo ==0){
	 		printf("pilha vazia!!\n");
		 }else{
		 	printf("removendo o elemento [%d] da pilha..\n",dado[topo-1]);
		 	dado[topo-1] = -1;
		 	
		 	//topo --;
		 }
	 }
	 
	 int menu(){
	 		printf("Pilha statica em C!\nDigite [1] para inserir.\nDigite [2] para remover.\nDigite [3] para exibir.\nDigite [4] para sair!\n************************\n\nOPCAO:");
	
	 scanf("%d",&opc);
	   switch(opc){
	   	case 1:
	   		inserir();
	   		break;
	   	case 2:
		   remover();
		   break;
		   
		 case 3: 
		     exibir();
			 break;	
			 
			
			 	 return 0;
	   }
	 }

int main(int argc, char *argv[]) {
while(opc!= 4){
	
	menu();
}
	return 0;
}
