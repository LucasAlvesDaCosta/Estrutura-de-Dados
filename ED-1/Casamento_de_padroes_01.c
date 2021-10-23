#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
	int matricula;
	char nome[15];
	char sexo[1];
	int cod_curso;
}alu;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 void padroniza(alu *vetor, int tam){// funçao ordena, essa função recebe o vetor preenchido e o tamanho do mesmo!
 	int i,j,menorQ;
 
 	for(i=tam-1; i>=1; i--){// verrendo o vetor de traz p frente
 		for(j=0; j<i; j++){// laço interno para pegar as posições do vetor, cada vez o tamanho do vetor irá diminuir
 			if(vetor[j].matricula < vetor[j+1].matricula){//se a posição J do vetor for menor que a proxima a variavel "menorQ" recebe esse valor
 		
 			   menorQ = vetor[j].matricula;//
				vetor[j].matricula =vetor[j+1].matricula;// ja q a posiçao J+1 é menor a troca é feita... a posicao J recebe a proxima posiçao
				vetor[j+1].matricula =menorQ;// agora colocamos a posiçao MAIOR na posiçao que está a frente da posiçao [J]	
			 }
		 }
	 }
	  printf("Ficha:\n*****************\n");
      for(i=tam-1; i>=0; i--){
       	printf("%s\n %s\n %d\n %d\n*********************\n\n",vetor[i].nome,vetor[i].sexo,vetor[i].matricula,vetor[i].cod_curso);
       
      }	 
  	 
 }


int main(int argc, char *argv[]) {
printf("inscrisão de aluno");
 int i,n;
 alu vetor[n];
 
 printf("Quantos alunos serão cadastrados hoje:\n=> ");
 scanf("%d",&n);
 for(i=0; i<n; i++){
 	printf("nome do aluno: ");
 	scanf("%s",vetor[i].nome);
 	printf("sexo:[M]_[F]: ");
 	scanf("%s",vetor[i].sexo);
 	printf("Ano atual: ");
 	scanf("%d",&vetor[i].matricula);
 	printf("codigo do curso: ");
 	scanf("%d",&vetor[i].cod_curso);
 	printf("%d° Aluno cadastrado no sistema!\n\n",i);
 }	
 
 padroniza(vetor,n);
	return 0;
}
