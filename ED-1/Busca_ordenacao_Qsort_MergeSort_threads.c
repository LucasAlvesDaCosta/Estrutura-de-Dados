#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <pthread.h>
#define size_vet  1000
   
	int vetorQuick[size_vet];
	int vetorMerge[size_vet];
	
typedef struct NO_q{
	int dir;
	int esq;
	
}no_q;

typedef struct NO_m{
	int inicio;
	int meio;
	int fim;
}no_m;

void *q_sort(void *parametro){
	    printf("Entrou no quick\n");
	    pthread_t td1,td2;
	    
        no_q *param;
	    param = (no_q*)parametro;
	    
	    no_q *no1 = (no_q*)malloc(sizeof(no_q));
	    no_q *no2 = (no_q*)malloc(sizeof(no_q));
	    int *vetor = vetorQuick;
		int esquerda = param->esq; 
		int direita = param->dir;
		int tamanho = direita;
    	int i, j, meio, y;
    	int execute;
    	 printf("param->esq[%d] param->dir[%d]\n",esquerda, param->dir);   	
    	i= esquerda;// 'i' representa o ultimo valor a esquerda do vetor
    	
    	j= direita;  // 'j' representa o primeiro valor a direita do vetor
    	
    	meio = vetor[(esquerda+direita)/2]; // 'meio' recebe a posição central"MEIO" do vetor 
        printf("01 %d->esq, %d->dir\n",i,j);
    	 while(i<=j){// enquanto a direita for maior que a esquerda
         printf("enquanto>>>...\n\n");
    	 	while(vetor[i] < meio && i < direita){// enquanto o vetor na primeira posicao a esquerda for MENOR q o meio do vetor E o ultimo elemento a direita 
    	 	   printf("enquanto>>>2...\n\n");                                   // do vetor for maior que o primeiro a esquerda(que vai ate o meio) eu avanço a direita 'i'
    	 		i++;
			}
			  while(vetor[j] > meio && j > esquerda){ // enquanto o fim do vetor a esquerda for MAIOR que o meio do vetor E a variavel 'J -> ultima posição'
			     printf("enquanto>>>3...\n\n");                                     //for maior que a esquerda(que vai ate no meio do vetor)
			  	j--;
			  }
			  
			  if(i <= j){  // se a esquerda atual for menorOUigual a direita atual faço as trocas
			  	printf("if >>>1...\n\n");
			  	y= vetor[i];  // recebo essa posiçao da esquerda
			  	vetor[i]=vetor[j]; // troco com a posicao do vetor da direita
			  	vetor[j]=y;  // agora a copia do valor que estava na posiçao do vetor da 'direita atual' vai para a esqueda atual
			  	 i++;   // avanço para o meio do vetor
			  	 j--;   // retroceço da posiçao até o meio do vetor
			  }
		}
    	
    	 if(j > esquerda){ // parte recursciva onde eu verifico se a direita ATUAL é maior que a esquerda passa por parametro
    	  
    	  no1->esq = esquerda;
    	  no1->dir = j;
    	execute = pthread_create(&td1, NULL, q_sort, (void *)no1);
    	printf("thread 001\n");
               if (execute){
                 printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, execute);    
                 exit(1);
                }
		 }
		 
		  if(i < direita){ // se a  esquerda atual for maior que a direita passada por parametro
		  
		  no2->esq = i;
		  no2->dir = direita;
	      execute = pthread_create(&td2, NULL, q_sort, (void *)no2);
	       printf("thread 0002\n");
                if (execute){
                printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, execute);    
                exit(1);
               }
               pthread_join(td1,NULL);
               pthread_join(td2,NULL);
        
		}printf("saiu do quick\n");
		//pthread_exit(NULL);
}
/****************************************************************************************************************************/
void merge(int inicio, int meio, int fim){
	printf("entrou no merge\n...");
int *vetor = vetorMerge;	
int comeco = inicio;
int metade = meio+1;
int comAux = 0;
int size = fim-inicio+1;
int*vetAux = (int*)malloc(size*sizeof(int));

    while(comeco <= meio && metade <= fim){
    	if(vetor[comeco] <= vetor[metade]){
    		vetAux[comAux] = vetor[comeco];
    		comeco++;
		}else{
			vetAux[comAux] = vetor[metade];
			metade ++;
		}
		comAux++;
	}
	while(comeco<=meio){
		vetAux[comAux] = vetor[comeco];
		comAux++;
		comeco++;
	}
	
	 while(metade <= fim){
	     vetAux[comAux] = vetor[metade];
	     comAux++;
	     metade++;	 	
	 }
	  for(comAux=inicio; comAux <= fim; comAux++){
	  	vetor[comAux] = vetAux[comAux-comeco];
	  }
	free(vetAux);
}

void *mergeSort(void *parametro){
	printf("entrou no mergesort\n");
	pthread_t td1,td2;
	int execute;
	
	no_m *param;
	param = (no_m *)parametro;
	
	no_q *arg2 = (no_q*)malloc(sizeof(no_q));
	no_q *arg3 = (no_q*)malloc(sizeof(no_q));
		
int *vetor = vetorMerge; 
int comeco = param->inicio;
int fim = param->fim;

	int meio;
	if(comeco < fim){
	 meio = (fim+comeco)/2;
	 arg2->esq = comeco;
     arg2->dir = meio;
	
	 arg3->esq = meio+1;
	 arg3->dir = fim;
	 
	    execute = pthread_create(&td1, NULL, mergeSort, (void *) arg2);
        if (execute){
                printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, execute);    
                exit(1);
        }
        
              execute = pthread_create(&td2, NULL, mergeSort, (void *) arg3);
              if (execute){
                printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, execute);    
                exit(1);
               }
		pthread_join(td1,NULL);
	    pthread_join(td2,NULL);
	    merge(comeco, meio, fim);
	   
         printf("saiu do mergesort\n");
		 pthread_exit(0);
		 return NULL;
	} 
	  
}
//***************************************************************************// 
void imprime(int vetor[], int size){
	int i;
	printf("vetor ordenado-> ");
	for(i=0; i<=size-1; i++){
		printf("[%d] " ,vetor[i]);
	}printf("\nEND\n");
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
           	 printf("valor <%d> encontrado na posicao[%d]\n",valor,middle);
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
      if(found ==0){
      	printf("\t\t#####valor não encontrado!\n");
	  }
}
/*
clock_t inicio, fim;
inicio= clock();
chamada da funcao();
fim= clock() ( (fim - inicio)/CLOCKS_PER_SEC ) printf("%lf",((double)(fim - inicio)/CLOCKS_PER_SEC));*/
void inicializa(){
	printf("\t\tCalculo de tempo entre duas funcoes, QuickSort & MergeSort\n\n");
	no_q *no1 = (no_q*)malloc(sizeof(no_q));
	no_q *no2 = (no_q*)malloc(sizeof(no_q));
	pthread_t t_quick, t_merge;
	printf("0000\n");
	int execute;
	
		printf("teste01\n");
	int i;
	
	int aleatorio;
	
	 for(i=0; i<=size_vet-1; i++){
	 	aleatorio = (rand() % RAND_MAX);
	 		printf("<[%d]>\n",aleatorio);
	 	vetorQuick[i] = aleatorio;
	 	vetorMerge[i] = aleatorio;
	 }
	 printf("saiu do laço\n\n");
	 
	 no1->esq = 0;
	 no1->dir = size_vet-1;
	
	 no2->esq = 0;
	 no2->dir = size_vet-1;
	 //q_sort(no1); 
	 //system("pause");
     //teste();
     mergeSort(no2);
	 /*
	 execute = pthread_create(&t_quick, NULL, q_sort, (void *)no1);
	 printf("END thread_01\n");
	 
	  if (execute!=0) {
                printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, execute);    
                exit(1);
        }
	  
       execute = pthread_create(&t_merge, NULL, mergeSort, (void *)no2);
	  
       if(execute!=0){
       	 printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, execute);    
                exit(1);
	   }
	  pthread_join(t_quick,NULL); 
	  pthread_join(t_merge,NULL);
	  pthread_exit(NULL);*/
}
void teste(){
    imprime(vetorQuick,size_vet);
	printf("\tDIGITE O VALOR A SER PROCURADO!\nVALOR->.");
	int value;
	scanf("%d",&value);
	seek_bin(value,size_vet,vetorQuick);
	//imprime(vetorMerge,size_vet);
	
}
int main(int argc, char *argv[]) {
	    inicializa();
	   printf("\t\t>>> operacao encerrada...\n\n"); 
	   //pthread_exit(0);
	  // imprime(vetorMerge,size_vet);
	  //pthread_exit(NULL);
	return 0;
}
