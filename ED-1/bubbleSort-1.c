#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 void ordena(int *vetor, int tam){// fun�ao ordena, essa fun��o recebe o vetor preenchido e o tamanho do mesmo!
 	int i,j,menorQ;
 
 	for(i=tam-1; i>=1; i--){// verrendo o vetor de traz p frente
 		for(j=0; j<i; j++){// la�o interno para pegar as posi��es do vetor, cada vez o tamanho do vetor ir� diminuir
 			if(vetor[j] < vetor[j+1]){//se a posi��o J do vetor for menor que a proxima a variavel "menorQ" recebe esse valor
 		
 			   menorQ = vetor[j];//
				vetor[j]=vetor[j+1];// ja q a posi�ao J+1 � menor a troca � feita... a posicao J recebe a proxima posi�ao
				vetor[j+1]=menorQ;// agora colocamos a posi�ao MAIOR na posi�ao que est� a frente da posi�ao [J]	
			 }
		 }
	 }
	  printf("Ordem!! -> ");
      for(i=tam-1; i>=0; i--){
       	printf("[%d]",vetor[i]);
       	if(i != 0){
       		printf(" -> ");
		   }
      }	 
  	 
 }


int main(int argc, char *argv[]) {
	printf("ORDENATION: bubbleSort!\nEscolha a qtdd a ser ordenada!\nDIGITE: ");
	
	int tam, i, elemento;
	scanf("%d",&tam);
	
	int vetor[tam];
	for(i=0; i<tam;i++){
		printf("DIGITE O %d: elemento:",i+1);
		scanf("%d",&elemento);
		vetor[i]=elemento;
	}
	
	printf("BLZ!\n\n");
	ordena(vetor,tam);
	return 0;
}
