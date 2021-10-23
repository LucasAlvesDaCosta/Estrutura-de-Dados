#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char Vet(char V1[10],char V2[10]){
	//V1=(char*)malloc(20*(sizeof(char)));
	//V2=(char*)malloc(20*(sizeof(char)));
	int i;
	for(i=0;i<10;i++){
	
		if(strcmp(V1[i],V2[i])==0){
			return(printf("A posicao [%d] e igual a posicao [%d]",V1[i],V2[i]));
			
		}
	}
	
}
int main(int argc, char *argv[]) {
	char *Vet1,*Vet2;
	int M,N,i;
	 printf("Digite o tamanho do primeiro vetor!\n");
	 scanf("%d",&M);
	 printf("Digite o tamanho do segundo vetor!\n");
	 scanf("%d",&N);
	
	
	Vet1=(char*)malloc(20*(sizeof(char)));
	Vet2=(char*)malloc(20*(sizeof(char)));
	
	for(i=0;i<M;i++){
		printf("Qual o nome dessa posicao? [%d]\n ",i);
		setbuf(stdin,NULL);
		scanf("%[^\n]s",&Vet1[i]);
	}
	  for(i=0;i<N;i++){
	  	
	  	printf("Digite o nome desta posicao[%d] \n",i);
	  	setbuf(stdin,NULL);
	  	scanf("%[^\n]s",&Vet2[i]);
	  }
	  Vet(Vet1,Vet2);
	return 0;
}
