/*********************************
Autor: Fernando Krein Pinheiro
Data: 06/06/2010
Linguagem: C
========= IMPORTANTE ===========
O código esta livre para usar,
citar e compartilhar desde que
mantida sua fonte e seu autor.
Obrigado.
*********************************
Se voce estiver usando windows
mude a funcao do tempo para esta :
 
tempo = ((double)(fim-inicio))/CLK_TCK;
*/
//###################################################################
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100000000
 
//###################################################################
int comparador(valor1, valor2)
{
    if ( *(int*)valor1 > *(int*)valor2 )
    {
        return 1;
    }
    else
        if( *(int*)valor1 == *(int*)valor2 )
        {
            return 0;
    }
        else
        if ( *(int*)valor1 < *(int*)valor2 )
        {
                  return -1;
        }
}
//##################################################################
int main()
{
    clock_t inicio,fim;
    int *vetor, indice;
    double tempo = 0;
    FILE *arquivo;
 
    vetor = (int *) malloc(sizeof(int)*TAM);
    srand(time(NULL));
 
    arquivo = fopen("Desordenados.txt","w");
    if(!arquivo)
    {
        printf("Arquivo nao pode ser criado");
    }
        for (indice = 0; indice < TAM; indice++)
        {
                vetor[indice] = rand() % TAM;
                fprintf(arquivo,"%d\n",vetor[indice]);
        }
 
        fclose(arquivo);
        inicio=clock();
        qsort(vetor, (size_t)TAM, sizeof(int), comparador );
        fim=clock();
        tempo = (double)(((double)fim-(double)inicio)/CLOCKS_PER_SEC);
        printf("\n\nTempo total para ordenar: %f (segundos.milesimos)\n\n\n",tempo);
 
    arquivo = fopen("Ordenados.txt","w");
    if(!arquivo)
    {
        printf("Arquivo nao pode ser criado");
    }
        for (indice = 0; indice < TAM; indice++)
        {
                fprintf(arquivo,"%d\n",vetor[indice]);
        }
        fclose(arquivo);
 
free(vetor);
return 0;
}
