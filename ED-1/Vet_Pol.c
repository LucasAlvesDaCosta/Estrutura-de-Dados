#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char *V1,*V2;
	int T1,i,j,str;
	
	printf("Digite o tamano da string!\n");
	   scanf("%d",&T1);
	   j=0;
	V1= (char*) malloc (T1*(sizeof(char)));
	V2= (char*) malloc (T1*(sizeof(char)));
	 printf("Digite a frase!\n");
	 scanf("%s",V1);
	 
	                for(i=0; i<T1; i++){
	                	printf("[%c]\n",V1[i]);
				 }
				 printf("\n");
				 for(i=T1-1;i>=0;i--){
				 	V2[i]=V1[j];
				 	j++;
				 	printf("[%c]\n",V2[i]);
				 }
			str=strcmp(V2,V1);
			printf("(%d)\n",str);
			if(str==0){
				printf("Eh um polindromo..\n");
				
			}else
			
			    printf("Nao eh um polindromo!\n");
			    printf("< %s >\n [%s]\n",V1,V2);
		
     free(V1);
     free(V2);
	return 0;
	
}
