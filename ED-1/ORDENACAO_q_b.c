#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void exibe(int *vetor, int tam);
void q_sort(int *vetor, int esquerda, int direita){
	
	int i;
	int j;
	int aux;
	int pivo;
	
	pivo = vetor[(esquerda+direita)/2];
	i = esquerda;
	j = direita;
	
	do{
		while(vetor[i]<pivo && i<direita){
			i++;
		}
		
		while(vetor[j]>pivo && j>esquerda){
			j--;
		}
		   if(i<=j){
		   	aux = vetor[i];
		   	vetor[i] = vetor[j];
		   	vetor[j] = aux;
		   	i++;
		   	j--;
		   }
		
	}while(i<=j);
	
	if(j>esquerda){
		q_sort(vetor,esquerda,j);
	}
	if(i<direita){
		q_sort(vetor,i,direita);
	}
	exibe(vetor,direita+1);
}

void b_sort(int *vetor, int tam){
	
 int i;
 int j;
 int aux;
 	
 	for(i=tam-1; i>=1; i--){
 	    for(j=0; j<i; j++){
 	    		
 	    	if(vetor[j]>vetor[j+1]){
 	    			
 	    		aux = vetor[j];
 	    			vetor[j]=vetor[j+1];
 	    		vetor[j+1]=aux;
 	    			
			 }
		 }
	}
 	exibe(vetor,tam);
}

void exibe(int *vetor,int tam){
	int i;
	for(i=0; i<=tam-1; i++){
		printf("[%d]",vetor[i]);
		 if(i<tam-1){
		 	printf("_");
		 }
	}
	printf("\n");
}

void menu(int opc, int *vetor, int tam){

	  
	       if(opc == 1){
	       	b_sort(vetor,tam);
		   }
		   if(opc == 2){
		   	q_sort(vetor,0,tam-1);
		   }
	  
}

int main(int argc, char *argv[]) {
	printf("\t\tAlgoritimos de ordenation!\n\n");
		
    int tam;
	int opc;

	printf("digite a quantidade maxima do vetor[]...\nQUANTIDADE: ");
	scanf("%d",&tam);
    	int vetor[tam];
	    int i;
	  for(i=0; i<tam; i++){
	  	printf("Digite o %d elemento: ",i+1);
	  	scanf("%d",&vetor[i]);
	  }
	 do{
	 printf("\n\nESCOLHA O METODO DE ORDENATION:\n1.[BubbleSort]\n2.[QuickSort]\n3.SAIR!\n->_");
	  scanf("%d",&opc);
menu(opc,vetor,tam);
}while(opc != 3);
	return 0;
}
