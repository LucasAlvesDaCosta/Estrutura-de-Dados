#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int *V1,*V2,*V3,N,M,i,j=0;
	printf("Digite o tamanho do primeiro vetor;\n");
	scanf("%d",&M);
	printf("Digite o nome do segundo vetor\n");
	scanf("%d",&N);
	V1= (int*)malloc(M*(sizeof(int)));
	V2= (int*)malloc(N*(sizeof(int)));
	V3= (int*)malloc(M+N*(sizeof(int)));
	
	for(i=0;i<M;i++){
		printf("informe a posicao [%d]\n",i);
		scanf("%d",&V1[i]);
		
	}
	       for(i=0;i<N;i++){
	       	printf("informe a posicao [%d]\n",i);
		scanf("%d",&V2[i]);
		
		  }
		    int PiranhaSafada=M+N; 
		     for(i=0;i<PiranhaSafada;i++){
		     	if(V1[i]==V2[i]){
		     		V3[i]=V1[i];
		     		printf("<[%d]>\n",V3[i]);
				}else
				printf("posicao[%d] != [%d]\n",V1[i],V2[i]);
		     	
			}
	free(V1);	
	free(V2);
	free(V3);	
	return 0;
}
