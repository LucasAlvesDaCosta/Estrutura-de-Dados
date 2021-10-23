#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
     void exibe(int *vetor,int tam);

    void q_sort(int *vetor, int esquerda, int direita){
    	int tamanho = direita;
    	int i, j, meio, y;
    	
    	i= esquerda;// 'i' representa o ultimo valor a esquerda do vetor
    	
    	j= direita;  // 'j' representa o primeiro valor a direita do vetor
    	
    	meio = vetor[(esquerda+direita)/2]; // 'meio' recebe a posição central"MEIO" do vetor 
    	
    	 while(i<=j){// enquanto a direita for maior que a esquerda
    	 
    	 	while(vetor[i] < meio && i < direita){// enquanto o vetor na primeira posicao a esquerda for MENOR q o meio do vetor E o ultimo elemento a direita 
    	 	                                      // do vetor for maior que o primeiro a esquerda(que vai ate o meio) eu avanço a direita 'i'
    	 		i++;
			}
			  while(vetor[j] > meio && j > esquerda){ // enquanto o fim do vetor a esquerda for MAIOR que o meio do vetor E a variavel 'J -> ultima posição'
			                                          //for maior que a esquerda(que vai ate no meio do vetor)
			  	j--;
			  }
			  
			  if(i <= j){  // se a esquerda atual for menorOUigual a direita atual faço as trocas
			  	
			  	y= vetor[i];  // recebo essa posiçao da esquerda
			  	vetor[i]=vetor[j]; // troco com a posicao do vetor da direita
			  	vetor[j]=y;  // agora a copia do valor que estava na posiçao do vetor da 'direita atual' vai para a esqueda atual
			  	 i++;   // avanço para o meio do vetor
			  	 j--;   // retroceço da posiçao até o meio do vetor
			  }
		}
    	
    	 if(j > esquerda){ // parte recursciva onde eu verifico se a direita ATUAL é maior que a esquerda passa por parametro
    	 	q_sort(vetor, esquerda, j); // caso true eu chamo essa mesma função só que com a posiçao "direita atual" como parametro[J] 
    	 	                            // representando a ultima posicão do vetor a direita
		 }
		 
		  if(i < direita){ // se a  esquerda atual for maior que a direita passada por parametro
		  	q_sort(vetor, i, direita);// se true eu chamo essa funçao novamente com a diferença de o inicio do vetor recebe a esquerda atual
		  	                           // que é representada por [i]
		  }
		  
		  exibe(vetor, tamanho);// exibir o vetor ordenado a cada recurçao.
	}
	
      void exibe(int *vetor,int tam){// function para exibir o vetor ordenado
      	
      	int i;
      	    printf("\nORDEM: ");
      	    
      	   for(i=0; i<=tam; i++){
      	   	 printf("[%d]",vetor[i]);
			 }
	  }

void seek_bin(int valor, int size_m, int *MATRIZ){ 

    int found = 0; 
    int high = size_m; 
    int low = 0; 
    int i=0;

    int middle = (high + low) / 2; 

     while((!found) && (high >= low)){ 
           if(valor == MATRIZ[middle]){
           	 found = 1; 
           	 printf("valor <%d> encontrado na posicao[%d]",valor,middle);
		   } 
            else
              if(valor < MATRIZ[middle]){
                high = middle -1;
				} 	
			else{
                	low = middle + 1; 
				} 
                     

           middle = (high + low) /2; 
           i++;
      } 
}

int main(int argc, char *argv[]) {
	
	printf("\t\t\t#* Alg. de ordenacao QuickSort *#\n\n\n");
	int tam;
	
	  printf("Digite a quantidade a ser ordenada: ");
	  scanf("%d",&tam);
	  int vetor[tam];
	  int i;  
	     for(i=0; i<=tam-1;i++){
	     	printf("Digite o valor da posicao->[%d]: ",i);
	     	scanf("%d",&vetor[i]);
		 }
	  q_sort(vetor, 0, tam-1);// passando o vetor o inicio e o final
	  int opc;
	  printf("\nEscolha o valor a ser buscado: ");
	  scanf("%d",&opc);
	  seek_bin(opc, tam-1, vetor);
	return 0;
}

  
