#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct 
{
   int valor;
   void *proximo;
} elementoFila;

elementoFila *inicioFila1 = NULL; //inicia fila

int filaVazia(  elementoFila **inicioFila )
{
   int retorno = 1;
   
   if ( *inicioFila != NULL )
   {
      retorno = 0;
   }   
   
   return retorno;
}

void insereFila(  elementoFila **inicioFila, int valor )
{
   elementoFila *novoElemento;
   elementoFila *auxiliar;
   novoElemento = (elementoFila*) malloc( sizeof(elementoFila) );  
   novoElemento->valor = valor; 
   novoElemento->proximo = NULL; 

   if ( filaVazia( inicioFila )  )
   {
      *inicioFila = novoElemento;
   }
   else
   {
      auxiliar = *inicioFila;
      while ( auxiliar->proximo != NULL )
      {
        auxiliar = auxiliar->proximo;
      }
      auxiliar->proximo = novoElemento;
   }
}

int removeFila( elementoFila **inicioFila  )
{
   elementoFila *auxiliar;
   int retorno = -1;
   if ( !filaVazia( inicioFila ) )
   {
      retorno = (*inicioFila)->valor;  
      auxiliar =  *inicioFila;
      *inicioFila = (*inicioFila)->proximo;
      free(auxiliar);
   }
   
   return retorno;
}

int main(int argc, char *argv[]) {
	int dado;
	int opc;
	do{
		printf("\t\tFILA DINAMICA!\n\n");
		printf("(1). para inserir na fila.\n(2). para remover e visualizar.\n(3). para sair!\nOPC: ");
		scanf("%d",&opc);
		
		switch(opc){
			case(1):
				
				printf("Entre com o dado: ");
				scanf("%d",&dado);
				insereFila(&inicioFila1, dado);
				break;
				
				case(2):
				printf("RETIRADO-> %d",removeFila(&inicioFila1));
					break;
					
					default:
						printf("opc invalid!\n");
						break;
		}
	}while(opc!=3);
	
	return 0;
}
