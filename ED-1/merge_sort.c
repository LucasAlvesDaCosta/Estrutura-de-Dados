#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void merge(int vetor[], int inicio, int meio, int fim){

int comeco = inicio;
int metade = meio+1;
int comAux = 0;
int size = fim-inicio+1;
int*vetAux = (int*)malloc(size*sizeof(int));

    while(comeco <= meio && metade <= fim){
    	if(vetor[comeco] <= vetor[metade]){
    		vetAux[comAux] = vetor[comeco];
    		comeco++;
		}else{
			vetAux[comAux] = vetor[metade];
			metade ++;
		}
		comAux++;
	}
	while(comeco<=meio){
		vetAux[comAux] = vetor[comeco];
		comAux++;
		comeco++;
	}
	
	 while(metade <= fim){
	     vetAux[comAux] = vetor[metade];
	     comAux++;
	     metade++;	 	
	 }
	  for(comAux=inicio; comAux <= fim; comAux++){
	  	vetor[comAux] = vetAux[comAux-comeco];
	  }
	free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){

	int meio;
	if(comeco < fim){
	  meio = (fim+comeco)/2;
	  
	  mergeSort(vetor, comeco, meio);
	  mergeSort(vetor, meio+1, fim);
	  
	  merge(vetor, comeco, meio, fim);	
	}
}

void imprime(int vetor[], int size){
	int i;
	printf("vetor ordenado-> ");
	for(i=0; i<=size-1; i++){
		printf("[%d] " ,vetor[i]);
	}printf("\nEND\n");
}

int main(int argc, char *argv[]) {
	int tam;
	int i;
	printf("\t\tMergeSort!\n\nDigite o tamanho do vetor a ser ordenado\n->.");
	scanf("%d",&tam);
	int vetor[tam];
	   for(i=0; i<=tam-1; i++){
	   	printf("digite o valor da posicao[%d]: ",i);
	   	scanf("%d",&vetor[i]);
	   }
	   int size = sizeof(vetor)/sizeof(vetor[0]);
	   mergeSort(vetor, 0, size-1);
	   
	   imprime(vetor, size);
	
	return 0;
}
