#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
	int matricula;
	char nome[15];
	char sexo[1];
	int cod_curso;
}alu;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 void padroniza(alu *vetor, int tam){// fun�ao ordena, essa fun��o recebe o vetor preenchido e o tamanho do mesmo!
 	int i,j,menorQ;
 
 	for(i=tam-1; i>=1; i--){// verrendo o vetor de traz p frente
 		for(j=0; j<i; j++){// la�o interno para pegar as posi��es do vetor, cada vez o tamanho do vetor ir� diminuir
 			if(vetor[j].matricula < vetor[j+1].matricula){//se a posi��o J do vetor for menor que a proxima a variavel "menorQ" recebe esse valor
 		
 			   menorQ = vetor[j].matricula;//
				vetor[j].matricula =vetor[j+1].matricula;// ja q a posi�ao J+1 � menor a troca � feita... a posicao J recebe a proxima posi�ao
				vetor[j+1].matricula =menorQ;// agora colocamos a posi�ao MAIOR na posi�ao que est� a frente da posi�ao [J]	
			 }
		 }
	 }
	  printf("Ficha:\n*****************\n");
      for(i=tam-1; i>=0; i--){
       	printf("%s\n %s\n %d\n %d\n*********************\n\n",vetor[i].nome,vetor[i].sexo,vetor[i].matricula,vetor[i].cod_curso);
       
      }	 
  	 
 }


int main(int argc, char *argv[]) {
printf("inscris�o de aluno");
 int i,n;
 alu vetor[n];
 
 printf("Quantos alunos ser�o cadastrados hoje:\n=> ");
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
 	printf("%d� Aluno cadastrado no sistema!\n\n",i);
 }	
 
 padroniza(vetor,n);
	return 0;
}
