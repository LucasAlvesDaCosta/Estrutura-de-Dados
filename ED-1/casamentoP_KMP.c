#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int kmp(char *substr, char *str)
{
   int i, j, N, M,tam=0;

   N = strlen(str);
   M = strlen(substr);

   int *d = (int*)malloc(M * sizeof(int));
d[0] = 0;

for(i = 1, j = 0; i < M; i++)
{
    while(j > 0 && substr[j-1] != substr[i-1])
    {
        j = d[j - 1];
    }

    if(substr[j] == substr[i])
        j++;
        tam ++;
        
    d[i] = j;
}

   for(i = 0, j = 0; i < N; i++){
      while(j > 0 && substr[j] != str[i])
      {
         j = d[j - 1];
      }

      if(substr[j] == str[i])
      {
         j++;
      }

      if(j == M)
      {
         free(d);
         return i - j + 1;
      }
   }
   if(tam==M){
   	for(i=0; i<tam; i++){
   		printf("%s",str[i]);
	   }
   }
   free(d);

   return -1;
}

int main(int argc, char *argv[]) {
	int i,n,m;
	char palavra[]="gato, rato, cachorro, macaco, coelho";
	/**## Atenção: escolha o nome a ser procurado na string*/
	printf("\tgato, rato, cachorro, macaco, coelho\n\nescolha um nome a ser procurado nessa string: ");
	char procura[10];// mude a string para o nome que quiser procurar
	scanf("%s",procura);
	int t = strlen(procura);

i= kmp(procura,palavra);

int j;
printf("nome encontrado na posicao %d ate %d\n",i,i+t);
for(j=i; j<=i+t; j++){
	printf("%c",palavra[j]);
}
	return 0;
}
