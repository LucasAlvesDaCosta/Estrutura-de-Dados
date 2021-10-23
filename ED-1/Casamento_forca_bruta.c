#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 void ordena(char *vetor, int tam){// funçao ordena, essa função recebe o vetor preenchido e o tamanho do mesmo!
 	int i,j,igual=0;
 	
 
 		for(j=0; j<tam; j++){// laço interno para pegar as posições do vetor, cada vez o tamanho do vetor irá diminuir
 			if(vetor[j] == 'a' && vetor[j+1]=='b' && vetor[j+2]=='b' && vetor[j+3]=='a' && vetor[j+4]=='c'){//se a posição J do vetor for menor que a proxima a variavel "menorQ" recebe esse valor
 		
 			   igual ++;//
 			   printf("padrao encontrado nas posicoes[%d] Ate [%d]\n",j,j+4);
 			   printf("\n%d padroes encontrados\n", igual);
			 }
	 }
       
      for(i=0; i<tam; i++){
      	
       	printf("[%c]",vetor[i]);
      }	 
  	 
 }
int main(int argc, char *argv[]) {
	int i, cod;
	
	char vet[100];
	for(i=0; i<100; i++){
		vet[i] = 'a'+rand()%3;
	}
	ordena(vet,100);
	return 0;
}
