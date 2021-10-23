#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa_t{
char nome[20];
char cpf[20];
char sexo;
char estadoCivil[10];
double salario;
int idade;
int numFilhos;
	
}pessoa;
int main(int argc, char *argv[]) {
	printf("Nome do cidadao;\n");
	setbuf(stdin,NULL);
	scanf("%[^/n]s",pessoa.nome);
	printf("cpf;\n");
	setbuf(stdin,NULL);
	scanf("%[^/n]s",pessoa.cpf);
	printf("Sexo [M]ou [F]\n");
	scanf("%c",pessoa.sexo);
	printf("Estado Civil;\n");
	setbuf(stdin,NULL);
	scanf("%[^/n]s",pessoa.estadoCivil);
	printf("Salario;\n");
	scanf("%lf",&pessoa.salario);
	printf("Idade;\n");
	scanf("%d",&pessoa.idade);
	printf("Numero de filhos;\n");
	scanf("%d",&pessoa.numFilhos);
	return 0;
}
