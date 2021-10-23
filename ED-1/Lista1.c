#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float n1,n2,p,Res;
	int Aulas,Freq;
	printf("Entre com as notas do aluno;\n");
	scanf("%f%f",&n1,&n2);
	printf("Quantas aulas foram ministradas?\n");
	scanf("%d",&Aulas);
	printf("Quantas aulas o aluno frequentou?\n");
	scanf("%d",&Freq);
	 
	 // Aulas= (Aulas*90);
	 
	 p=Freq*100;
	 p=p/Aulas;
	 Res=n1+n2/2;
	 
	 if(p<=74||Res<=5.9){
	 	printf("Aluno Reprovado\n");
	 }else
	 printf("Aluno Aprovado");
	  
	return 0;
}
