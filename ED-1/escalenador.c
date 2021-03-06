	#include <stdio.h>
	#include <stdlib.h>
	/* Estrutura */
	struct processos {
	    int id;                   /* Identifi??o do processo*/              
	    int surto;                /* Tempo de dura??o do processo*/
	    int prioridade;           /* Tamanho da prioridade do processo*/
	    int execucao;             /* Tempo de execu??o do processo*/
	    int espera;               /* Tempo de espera do processo*/
	    struct processos *prox;
	};
	/* Prot?tipos de fun??o */
	struct processos *init_processos (int id, int surto, int prioridade);
	void fcfs (struct processos *proc);
	void listprocs (struct processos *proc);
	void prioridade (struct processos *proc);
	void rr (struct processos *proc, int quantum);
	void sjf (struct processos *proc);
	 
	int main (void) {
	    
	    struct processos *plist, *ptmp;
	    plist= init_processos(1,10,3);
	    plist->prox= init_processos(2,1,1); ptmp = plist->prox;
	    ptmp->prox = init_processos(3,2,3); ptmp = ptmp->prox;
	    ptmp->prox = init_processos(4,1,4); ptmp = ptmp->prox;
	    ptmp->prox = init_processos(5,5,2);
	    /* Simula??es de processos*/
	    listprocs(plist);
	    fcfs(plist);
	    sjf(plist);     
	    prioridade(plist);
	    rr(plist,1);
	    
	    while (plist != NULL) {
	        ptmp = plist;
	        plist = plist->prox;
	        free(ptmp);
	    };
	    return(0);
	};
	/* Inicializa??o de entrada da lista de processos*/
	struct processos *init_processos (int id, int surto, int prioridade) {
	    struct processos *proc;
	 proc = (struct processos*)malloc(sizeof(struct processos)); 
	  if (proc == NULL) {
	        printf("Falha na Alocacao de memoria\n");
	        exit(1);
	    };
	    proc->id = id;
	    proc->surto = surto;
	    proc->prioridade = prioridade;
	    proc->execucao = 0;
	    proc->espera = 0;
	    proc->prox = NULL;
	    return(proc);
	};
	
	/* Escalonamento FCFS - o primeiro que chegar na fila ser? o primeiro
	a ser processado, idependente de tamanho ou prioridade */
	
	void fcfs (struct processos *proc) {
	    int tempo = 0, inicio, fim;
	  struct processos *tmp = proc;
	  printf("\n\t[Escalonamento FCFS]\n");
	    printf("\n");
	  while (tmp != NULL) {
	    inicio = tempo;
	    tempo += tmp->surto;
	    fim = tempo;
	    printf("Processo: %d\tSurto: %d\tEspera: %d\tRetorno: %d\n", tmp->id, tempo, inicio, fim);
	    tmp = tmp->prox;
	  };
	    printf("\n\n");
	};
	
	/* Listando Processos */
	void listprocs (struct processos *proc) {
	  struct processos *tmp = proc;
	  printf("\n\t\t<Listagem de Processos>\n");
	  printf("\n");
	  while (tmp != NULL) {
	    printf("Processo: [%d] --- <Prioridade: %d> --- (Surto: %d)\n\n", tmp->id, tmp->prioridade, tmp->surto);
	    tmp = tmp->prox;
	  };
	  printf("\n\n");
	 };
	/* Simula??o de Processos por Prioridade
	 * Obs: O processo de menor valor de prioridade obtem
	 * prioridade maior na fila de processos */
	 
	void prioridade (struct processos *proc) {
	  int tempo, inicio, fim, maior;
	  struct processos *copia, *tmpsrc, *tmp, *maiorprimeiro;
	  printf("\n\tEscalonamento por Prioridade\n");
	   printf("\n");
	  
	     /* Replicando Lista de Processos */
	  tmpsrc = proc;
	  copia = tmp = NULL;
	  while (tmpsrc != NULL) {
	    if (copia == NULL) {
	    copia = init_processos(tmpsrc->id, tmpsrc->surto, tmpsrc->prioridade);
	    tmp = copia;
	    } else {
	    tmp->prox = init_processos(tmpsrc->id, tmpsrc->surto, tmpsrc->prioridade);
	    tmp = tmp->prox;
	    };
	    tmpsrc = tmpsrc->prox;
	  };
	  /* Programa Principal */
	  tempo = 0;
	  while (copia != NULL) {
	    
	          /* Localiza o proximo processo */
	    maiorprimeiro = NULL;
	    maior = copia->prioridade;
	    tmp = copia->prox;
	    tmpsrc = copia;
	    while (tmp != NULL) {
	    if (tmp->prioridade < maior) {
	      maior = tmp->prioridade;
	      maiorprimeiro = tmpsrc;
	    };
	    tmpsrc = tmp;
	    tmp = tmp->prox;
	    };
	     if (maiorprimeiro == NULL) {
	    /* Verifica se o primeiro processo possui maior prioridade */
	    inicio = tempo;
	    tempo += copia->surto;
	    fim = tempo;
	    printf("Processo: <%d>\tSurto: %d\tEspera: %d\tRetorno: %d\n", copia->id, tempo, inicio, fim);
	    tmpsrc = copia->prox;
	    free(copia);
	    copia = tmpsrc;
	    } else {
	    /* Verifica se o primeiro processo n?o possui maior prioridade */
	    tmp = maiorprimeiro->prox;
	    inicio = tempo;
	    tempo += tmp->surto;
	    fim = tempo;
	    printf("Processo: [%d]\tSurto: %d\tEspera: %d\tRetorno: %d\n", tmp->id, tempo, inicio, fim);
	    maiorprimeiro->prox = tmp->prox;
	    free(tmp);
	    };
	  };
	  printf("\n\n");
	};
	/* Escalonamento Round-Robin 
	cada processo ira receber uma fracao de tempo para ser executado*/
	void rr (struct processos *proc, int quantum) {
	  int jobsremain, passes;
	  struct processos *copia, *tmpsrc, *tmp, *slot;
	  printf("\n\tEscalonamento Round-Robin - Quantum: [%d] = Tempo de processamento\n", quantum);
	  printf("\n");
	  tmpsrc = proc;
	  copia = tmp = NULL;
	  while (tmpsrc != NULL) {
	    if (copia == NULL) {
	    copia = init_processos(tmpsrc->id, tmpsrc->surto, tmpsrc->prioridade);
	    tmp = copia;
	    } else {
	    tmp->prox = init_processos(tmpsrc->id, tmpsrc->surto, tmpsrc->prioridade);
	    tmp = tmp->prox;
	    };
	    tmpsrc = tmpsrc->prox;
	  };
	  /* Programa rotina de an?lise de prioridade  */
	  jobsremain = 2;
	  slot = NULL;
	  while (jobsremain) {
	    jobsremain = 0;
	    /* Seleciona o pr?ximo processo efetuando sua aloca??o */
	    if (slot == NULL) {
	    slot = copia;
	    jobsremain = 2;
	    } else {
	    passes = 0;
	    do {
	      if (slot->prox == NULL) {
	        passes++;
	        slot = copia;
	      } else {
	        slot = slot->prox;
	      };
	    } while (passes <= 3 && slot->surto == slot->execucao);
	    if (passes <= 3) {
	      jobsremain = 2;
	    };
	    };
	    /* Executa um ciclo */
	    tmp = copia;
	    while (tmp != NULL) {
	    if (tmp->surto > tmp->execucao) {
	      if (tmp == slot) {
	        tmp->execucao += quantum;
	      } else {
	        tmp->espera += quantum;
	      };
	    };
	    tmp = tmp->prox;
	    };
	  };
	  /* Exibe os resultados e elimina as replica??es */
	  tmp = copia;
	  while (tmp != NULL) {
	  	
	    printf("Processo: %d\tSurto: %d\tEspera: %d\tRetorno: %d\n",
		  tmp->id, tmp->surto, tmp->espera, tmp->execucao + tmp->espera);
	    tmpsrc = tmp;
	    tmp = tmp->prox;
	    free(tmpsrc);
	  };
	  printf("\n");
	};
	
	//***************************************************************************************************************************************//
	/* Escalonamento SJF
	executa os processos menores primeiro dando prioridade a eles*/
	void sjf (struct processos *proc) {
	  int tempo, inicio, fim, shortest;
	  struct processos *copia, *tmpsrc, *tmp, *beforeshortest;
	  printf("\n\t[Escalonamento SJF (Shortest Job First)]\n");
	  printf("\n");
	  /* Lista de processos ? replicada */
	  tmpsrc = proc;
	  copia = tmp = NULL;
	  while (tmpsrc != NULL) {
	    if (copia == NULL) {
	    copia = init_processos(tmpsrc->id, tmpsrc->surto, tmpsrc->prioridade);
	    tmp = copia;
	    } else {
	    tmp->prox = init_processos(tmpsrc->id, tmpsrc->surto, tmpsrc->prioridade);
	    tmp = tmp->prox;
	    };
	    tmpsrc = tmpsrc->prox;
	  };
	  tempo = 0;
	  while (copia != NULL) {
	    /* Encontra o proximo processo*/
	    beforeshortest = NULL;
	    shortest = copia->surto;
	    tmp = copia->prox;
	    tmpsrc = copia;
	    while (tmp != NULL) {
	    if (tmp->surto < shortest) {
	      shortest = tmp->surto;
	      beforeshortest = tmpsrc;
	    };
	    tmpsrc = tmp;
	    tmp = tmp->prox;
	    };
	    /* Executa processo e remove r?plica da lista de processos */
	    if (beforeshortest == NULL) {
	    /* Aloca o primeiro processo caso o mesmo seja menor */
	    inicio = tempo;
	    tempo += copia->surto;
	    fim = tempo;
	    printf("Processo: %d\t[Surto: %d]\tEspera: %d\tRetorno: %d\n", copia->id, tempo, inicio, fim);
	    printf("\n\t\t#PROCESSO MAIOR = [%d] Tempo de espera: %d segundos...\n\n",copia ->id,inicio);
	    tmpsrc = copia;
	    copia = copia->prox;
	    free(tmpsrc);
	    } else {
	    /* Aloca o primeiro processo caso n?o haja 
	    ocorrencia de outro menor 
	    */
	    tmp = beforeshortest->prox;
	    inicio = tempo;
	    tempo += tmp->surto;
	    fim = tempo;
	    printf("Processo: %d\t<Surto: %d>\tEspera: %d\tRetorno: %d\n", tmp->id, tempo, inicio, fim);
	    beforeshortest->prox = tmp->prox;
	    free(tmp);
	    }
	  }
	     
	}
