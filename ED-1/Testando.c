#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int soma(int n1, int n2){
	return n1+n2;
}

int mult(int n1, int n2){
	return n1*n2;
}

int divi(int n1, int n2){
	return n1/n2;
}

int sub(int n1, int n2){
	return n1-n2;
}

int main(int argc, char *argv[]) {
     int n1, n2, opera;
     printf("Digite um numero inteiro: ");
     scanf("%d",&n1);
     
     printf("Digite outro numero inteiro: ");
     scanf("%d",&n2);
     printf("\nEscolha uma opcao:\n1- SOMA\n2-SUBTRACAO\n3-DIVISAO\n4-MULTIPLICACAO\n>");
     scanf("%d",&opera);
     
       if(opera == 1){
       	printf("Resultado da soma: %d\n",soma(n1,n2));
	   }else
	        if(opera ==2)
	           printf("Resultado da subtracao: %d\n",sub(n1,n2));
	           else
	               if(opera ==3)
	                  printf("Resultado da divisao: %d\n",div(n1,n2));
	                  else
	                      if(opera ==4)
	          				 printf("Resultado da multiplicacao: %d\n",mult(n1,n2));
	          				 else
	          				    printf("OPCAO invalida!!\n\n");
       
	return 0;
}
