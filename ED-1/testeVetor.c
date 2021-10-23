#include <stdio.h>
#include <stdlib.h>
#define size 100

int vet[size];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void printVet(){
	printf("vetor recebido...\n");
	int *v = vet;
	int i;
	for(i=0;i<size-1;i++){
		printf("[%d]-",v[i]);
	}
}

int main(int argc, char *argv[]) {
	printf("\t\t<<<<<<<<<<<<<<<<<<<<<<<<<xxxxxxxx>>>>>>>>>>>>>>>>>>>>>>\n\n");
	int i;
	for(i=0; i<size-1; i++){
		vet[i]=rand()%100;
	}
	printVet();
	
	return 0;
}
