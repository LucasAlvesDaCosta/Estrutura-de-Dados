#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 void ordena(int *vetor, int tam){// funçao ordena, essa função recebe o vetor preenchido e o tamanho do mesmo!
 	int i,j,menorQ;
 
 	for(i=tam-1; i>=1; i--){// verrendo o vetor de traz p frente
 		for(j=0; j<i; j++){// laço interno para pegar as posições do vetor, cada vez o tamanho do vetor irá diminuir
 			if(vetor[j] < vetor[j+1]){//se a posição J do vetor for menor que a proxima a variavel "menorQ" recebe esse valor
 		
 			   menorQ = vetor[j];//
				vetor[j]=vetor[j+1];// ja q a posiçao J+1 é menor a troca é feita... a posicao J recebe a proxima posiçao
				vetor[j+1]=menorQ;// agora colocamos a posiçao MAIOR na posiçao que está a frente da posiçao [J]	
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
