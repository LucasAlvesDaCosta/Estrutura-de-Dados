#include <stdio.h>
#include <stdlib.h>

   int ordenaIdade(V1,V2);
     {
   	if(*(int*)V1>*(int*)V2){
   		return 1;
   		
	   }else
	   if(*(int*)V1== *(int*)V2){
	   	return 0;
	   	
	   }else
	   if(*(int*)V1< *(int*)V2){
	   	return -1;
	   }
     }



typedef struct pessoa{
char cpf[15];
 int idade;
 double renda;	
}pessoa;

int main(int argc, char *argv[]) {
 int i,N;
             printf("digite a quantidade de pessoas\n");
             scanf("%d",&N);
 for(i=0;i<N;i++){
 	
            printf("Digite seu cpf!\n");
            setbuf(stdin,NULL);
            scanf("%[^\n]s",pessoa.cpf);
          printf("Sua idade;\n");
          scanf("%d",&pessoa.idade);
        printf("Sua renda.\n");
        scanf("%lf",&pessoa.renda);
 }

 
	return 0;
}
