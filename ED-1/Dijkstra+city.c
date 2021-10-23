/**
 * Algoritmo de Dijikstra.c Aplicado na ideia de calculo de distancias das cidades da Europa.
 *
 * Copyright 2018  <Lucas Alves da Costa. Lizandra>
 *
 * Esse programa tem como objetivo calcular melhores rotas para diversas verices de um Grafo armazenadas em uma pilha dinamica.
 * Suas vertices são pré-definidas de forma fixa, para 
 * utilizar o programa basta apenas digitar o indice correspondente
 * a cidade de partida e o indice da cidade de destino.
 * A partir destes indices será calculada a melhor rota em relação a distancia,
 * alem disso será responsável por apresentar no console a sequencia de vertices 
 * utilizadas para alcançar o destino com menor custo.
 *
 * Para calcular essa distância foi utilizado o algoritmo de Dijkstra
 * também conhecido como algorimo de caminho minimo.
 * A idéia principal deste algoritmo é calcular o camino que apresente o menor custo entre suas vertices e arestas.
 * 
 *
 * IFG - Campus Formosa-GO - 2018-junho.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
        int vertex;
        int peso;
} aresta_t;

typedef struct {
        aresta_t **arestas;
        int aresta_len;
        int aresta_size;
        int dist;
        int anterior;
        int visited;
} vertex_t;

typedef struct {
        vertex_t **vertices;
        int vertices_len;
        int vertices_size;
} grafo_t;

typedef struct {
        int *data;
        int *prio;
        int *index;
        int len;
        int size;
} heap_t;

// Protótipos das funções
void add_vertex(grafo_t *g, int i);
void add_aresta(grafo_t *g, int a, int b, int w);
heap_t * create_heap(int n);
void push_heap(heap_t *h, int v, int p);
int min(heap_t * h, int i, int j, int k);
int pop_heap(heap_t *h);
void dijkstra(grafo_t * g, int a, int b);
void imprimir_caminho(grafo_t *g, int i);


int main(int argc, char *argv[]) {
	
	printf("\t\t\t\t%cCIDADES DA EUROPA%c\n",186,186);
	printf("\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
	
        grafo_t * g = calloc(1, sizeof(grafo_t));

        add_aresta(g, 0, 1, 1277);
        add_aresta(g, 0, 2, 1659);
        
        add_aresta(g, 1, 0, 1277);
        add_aresta(g, 1, 2, 656);
        add_aresta(g, 1, 3, 510);
        
        add_aresta(g, 2, 0, 1659);
        add_aresta(g, 2, 1, 656);
        add_aresta(g, 2, 3, 817);
        add_aresta(g, 2, 5, 683);
        
        add_aresta(g, 3, 1, 510);
        add_aresta(g, 3, 2, 817);
        add_aresta(g, 3, 4, 655);
        add_aresta(g, 3, 5, 876);
       
        
        add_aresta(g, 4, 3, 655);
        add_aresta(g, 4, 5, 350);
        
        add_aresta(g, 5, 2, 683);
        add_aresta(g, 5, 3, 876);
        add_aresta(g, 5, 4, 350);

       
        menuDistancia(g);

        return 0;
}
void letra_city(const char *G){
     switch(G[0]){
           case 'a':    	
     	   printf("(Madrid-Espanha) ");
     	   break;
     	    
     	   case 'b':
     	   	printf("(Paris-Fran%ca) ",135);
     	   	break;
     	   	
     	   	 case 'c':
     	   	  printf("(Zurique-Sui%ca) ",135);
     	   	  break;
     	   	  
     	   	  case 'd':
     	   	  	printf("(Amsterd%c-Holanda) ",198);
     	   	  	break;
     	   	  	
     	   	  	case 'e':
     	   	  	  printf("(Berlin-Alemanha) ");
     	   	  	  break;
     	   	  	  
     	   	  	   case 'f':
     	   	  	   	printf("(Praga-Republica_Tchequia) ");
     	   	  	   	break;
     	   	  	   	
     	   	  	   	 default:
     	   	  	   	 	printf("City not identified!!");
     	   	  	   	 	break;
	 }	
}
void listaCity(){
 printf("\n___________________________________\n");
 printf("%cId %c Cidade                      %c\n",186,186,186);
 printf("-----------------------------------\n");
 printf("|0 -| Madrid - Espanha.           |\n");
 printf("-----------------------------------\n");
 printf("|1 -| Paris - Fran%ca.             |\n",135);
 printf("-----------------------------------\n");
 printf("|2 -| Zurique - Sui%ca.            |\n",135);
 printf("-----------------------------------\n");
 printf("|3 -| Amsterd%c - Holanda.         |\n",198);
 printf("-----------------------------------\n");
 printf("|4 -| Berlin - Alemanha.          |\n");
 printf("-----------------------------------\n");
 printf("|5 -| Praga - Republica Tchequia. |\n");
 printf("-----------------------------------\n");	
}
int calcular_tempo(int distancia){
	float tempo;
	float minuto, velocidade_media=80;
	int hora, absoluto;
	int aux;

	tempo=(float)distancia/velocidade_media;
	absoluto = abs(tempo);
	minuto = tempo - absoluto;
	hora = absoluto;
	aux = minuto * 100;

	if(aux >= 60){
		aux -= 60;
		hora += 1;

	}

	printf("<Tempo medio de percurso = (%d_horas:%d_min)>\n\n\n",hora, aux);
	
	return 0;
}
void add_vertex(grafo_t * g, int i) {
        if (g->vertices_size < i + 1) {
                int size = g->vertices_size * 2 > i ? g->vertices_size * 2 : i + 4;
                g->vertices = realloc(g->vertices, size*sizeof(vertex_t *));

                int j;
                for (j = g->vertices_size; j < size; j++) {
                        g->vertices[j] = NULL;
                }

                g->vertices_size = size;
        }

        if (!g->vertices[i]) {
                g->vertices[i] = calloc(1, sizeof(vertex_t));
                g->vertices_len++;
        }
}

void add_aresta(grafo_t * g, int a, int b, int w) {
        add_vertex(g, a);
        add_vertex(g, b);

        vertex_t *v = g->vertices[a];

        if (v->aresta_len >= v->aresta_size) {
                v->aresta_size = v->aresta_size ? v->aresta_size * 2 : 4;
                v->arestas = realloc(v->arestas, v->aresta_size * sizeof (aresta_t *));
        }

        aresta_t * e = calloc(1, sizeof(aresta_t));
        e->vertex = b;
        e->peso = w;

        v->arestas[v->aresta_len++] = e;
}

heap_t * create_heap(int n) {
        heap_t * h = calloc(1, sizeof(heap_t));
        h->data = calloc(n+1, sizeof(int));
        h->prio = calloc(n+1, sizeof(int));
        h->index = calloc(n, sizeof(int));

        return h;
}

int menuDistancia(grafo_t *vertices){
 int partida, destino;
 
 do{

 listaCity();
 printf("|6 -| para sair..                 |\n");
 printf("-----------------------------------\n\n");
 printf("Escolha o indice_[Id] da cidade de partida: OU '6' para sair:\n");
 printf(">_");	
 scanf("%d",&partida);
  if(partida == 6)
       exit(1);
       
  while(partida < 0 || partida > 6){
  	listaCity();
  	printf("\nOpc invalida!\n Digite o 'Id' da Cidade de partida: OU '6' para sair!\n>_");
  	scanf("%d",&partida);
  	if(partida==6)
  	exit(1);
  	
  }
  printf("Escolha o indice da cidade de destino:\n>_");
  scanf("%d",&destino);
   while(destino < 0 || destino > 6){
   	
   	if(destino != 1 || destino != 2 || destino != 3 || destino != 4 || destino != 5)
   	printf("Destino invalido!!\nDigite o destino OU '6' para sair!\n=>_ ");
   	scanf("%d",&destino);
   	if(destino == 6)
   	exit(1);
   }
    
    system("cls");
   	dijkstra(vertices,partida,destino);
   	 
   	printf("\nMELHOR ROTA: ");imprimir_caminho(vertices,destino);
	system("pause");
		
	  return menuDistancia(vertices);
	  
	  }while(partida || destino != 6);
	
}

void push_heap(heap_t * h, int v, int p) {
        int i = h->index[v] == 0 ? ++h->len : h->index[v];
        int j = i / 2;
        while (i > 1) {
                if (h->prio[j] < p)
                        break;

                h->data[i] = h->data[j];
                h->prio[i] = h->prio[j];
                h->index[h->data[i]] = i;
                i = j;
                j = j/2;
        }

        h->data[i] = v;
        h->prio[i] = p;
        h->index[v] = i;
}

int min(heap_t *h, int i, int j, int k) {
        int m = i;
        if (j <= h->len && h->prio[j] < h->prio[m])
                m = j;
        if (k <= h->len && h->prio[k] < h->prio[m])
                m = k;
        return m;
}

int pop_heap(heap_t *h) {
        int v = h->data[1];
        int i = 1;

        while (1) {
                int j = min(h, h->len, 2*i, 2*i+1);
                if (j == h->len)
                        break;
                h->data[i] = h->data[j];
                h->prio[i] = h->prio[j];
                h->index[h->data[i]] = i;
                i = j;
        }

        h->data[i] = h->data[h->len];
        h->prio[i] = h->prio[h->len];
        h->index[h->data[i]] = i;
        h->len--;

        return v;
}

void dijkstra(grafo_t * g, int a, int b) {
	printf("\t\tCalculando rota com algoritmo de Djikstra:\n\n\n");
        int i, j;
        for (i = 0; i < g->vertices_len; i++) {
                vertex_t * v = g->vertices[i];
                v->dist = INT_MAX;
                v->anterior = 0;
                v->visited = 0;
        }
        vertex_t * v = g->vertices[a];
        v->dist = 0;
        heap_t * h = create_heap(g->vertices_len);
        push_heap(h, a, v->dist);
        while (h->len) {
                i = pop_heap(h);

                if (i == b)
                        break;

                v = g->vertices[i];
                v->visited = 1;
                for (j = 0; j < v->aresta_len; j++) {
                        aresta_t * e = v->arestas[j];
                        vertex_t * u = g->vertices[e->vertex];
                        if (!u->visited && v->dist + e->peso <= u->dist) {
                                u->anterior = i;
                                u->dist = v->dist + e->peso;
                                push_heap(h, e->vertex, u->dist);
                        }
                }
        }
}

void imprimir_caminho(grafo_t * g, int i) {
        int n, j;
        vertex_t *v, *u;
        v = g->vertices[i];
        if (v->dist == INT_MAX) {
             printf("Sem rota para essa cidade!\n\n");
             return listaCity();
        }

        for (n = 1, u = v; u->dist; u = g->vertices[u->anterior], n++);

        char * path = malloc(n);

        path[n-1] = 'a' + i;

        for (j = 0, u = v; u->dist; u = g->vertices[u->anterior], j++)
                path[n - j - 2] = 'a' + u->anterior;

       
        for(j=0; j<n; j++){
        	letra_city(&path[j]);
        	if(j<n-1)
        	printf("%c ",175);
		}
		printf("\n\nMENOR DISTANCIA DE: "); letra_city(&path[0]);
		printf(" PARA: "); letra_city(&path[n-1]);
		printf("= %d_km\n\n",v->dist);
		calcular_tempo(v->dist);
        
}
