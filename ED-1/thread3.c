	#include <stdio.h>
	#include <stdlib.h>
	#include <pthread.h>
	// programa para criar varios threads e o tempo de criacao de cada processo. 
	/*neste programa eu simulo varios processos e apresento o codigo
	de identificaçao de cada processo e o tempo de criação.
	Logo em seguida agrupo em ordem aleatoria todos os processos e o tempo
	que cada thread gastou para ser executada.*/
	struct valor{
	   int tempo;
	   int id;
	};
	// funçao para gerar processos e listar cada um e o tempo de criaçao.
	   void *espera(void *tmp){
	   struct valor *v = (struct valor *) tmp;
	   sleep(v->tempo);// de acordo com o valor de argumento a funçao sleep ira pausar por segundos cada processo 
	   printf("Numero da thread: [%d]\t Tempo de espera: [%d segundos antes de executar!]\n\n",v->id,v->tempo);
	   }
	
	int main(){
		     // apenas uma barra de progresso!!
	          printf("Gerando threads....\n0%%");
	          int a;
	          for(a=1;a<=10;a++){
	          	 
	        	   usleep(500000);//meio segundo
	          	printf("==");
	         	
	          	 if(a == 5){
	          	 	printf(" 50%% ");
	          	 	
				    }
		   	}
		   	
			printf(" 100%% Concluido!\n");
	   pthread_t linhas[10];
	   int execute,i;
	   struct valor *v;
	   srand(time(NULL));
	   for (i=0;i<10;i++){
	      v = (struct valor *) malloc(sizeof(struct valor *));// alocaçao de espaço
	      v->tempo = (rand()%10)+2;/* aqui o ponteiro (v) apontado para o tempo recebe um valor aleatorio
		 gerado pela funçao rand()*/
		 
	      v->id = i;// o ponteiro apontado para o numero de identificaçao recebe o valor do laço
	      printf("Thread |%d| criada...\tcreation time: [%d seconds]\n",v->id,v->tempo);/*imprime cada processo
		 correspondente ao seu 'id' e o tempo*/
	      execute = pthread_create(&linhas[i],NULL,espera,(void *)v); 
	   }
	   printf("\n______________________________________________________________________][%d]\n\n",execute);
	   pthread_exit(NULL);
	}
