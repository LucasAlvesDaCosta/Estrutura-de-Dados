/***********************************************

  "dijkstra.c"

  Created by Michael Cheng on 07/08/2016 22:00
            http://michaelcheng.us/
            michael@michaelcheng.us
            --All Rights Reserved--

***********************************************/

#include <stdio.h>
#include <stdlib.h>

#define INFINITO 9999999
#define null NULL

typedef enum {false, true} bool;
typedef struct _Aresta Aresta;
typedef struct _Vertex Vertex;
typedef struct _LinkedList LinkedList;

struct _Aresta {
	int peso;
	Vertex *to;
	Aresta *next;
};

struct _Vertex {
	char valor;
	LinkedList *arestas;
	bool visitado;
	int menorPeso;
};

struct _LinkedList {
	Aresta *head;
	Aresta *cauda;
};
const char G[] = {'M', 'P', 'Z', 'A', 'B', 'p'};
LinkedList *lista;
const char *caminho;

void letra_city(const char *G);
Aresta *createAresta(int peso, Vertex *to) {
	Aresta *aresta = (Aresta *) malloc(sizeof(Aresta));
	aresta->peso = peso;
	aresta->to = to;
	aresta->next = null;
	return aresta;
}

Vertex *createVertex(char valor) {
	Vertex *vertex = (Vertex * ) malloc(sizeof(Vertex));
	vertex->valor = valor;
	vertex->arestas = null;
	vertex->visitado = false;
	vertex->menorPeso = INFINITO;
	return vertex;
}

LinkedList *createLinkedList() {
	LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
	list->head = null;
	list->cauda = null;
	return list;
}

void insertIntoList(LinkedList *list, Aresta *aresta) {
	if(list->head == null) {
		list->head = aresta;
		list->cauda = aresta;
	} else {
		list->cauda->next = aresta;
		list->cauda = aresta;
	}
}

void visita(Vertex *vertex) {
	
	printf("Visitando ");
	letra_city(&vertex->valor);
	printf("\n");

	vertex->visitado = true;
}

bool isVisited(Vertex *vertex) {
	return vertex->visitado;
}

/*void bfs(Vertex *vertices[], int size, int from) {
	printf("\n\nPerforming Breadth-First Search\n");
	Vertex *toVisit[size], *current;
	int top = -1;
	toVisit[++top] = vertices[from];
	visita(toVisit[top]);
	while(current = toVisit[top--]) {
		Aresta *iterator = current->arestas->head;
		while(iterator != null) {
			if(isVisited(iterator->to) == false) {
				visita(iterator->to);
				toVisit[++top] = iterator->to;
			}
			iterator = iterator->next;
		}
		if(top == -1) break;
	}
}
*/
void dfs(Vertex *vertices[], int size, int from) {
	printf("\n\nPerforming Depth-First Search\n");
	Vertex *toVisit[size], *current;
	int top = -1;
	toVisit[++top] = vertices[from];
	while(current = toVisit[top--]) {
		if(isVisited(current) == false) {
			visita(current);
			Aresta *iterator = current->arestas->head;
			while(iterator != null) {
				toVisit[++top] = iterator->to;
				iterator = iterator->next;
			}
		}
		if(top == -1) break;
	}
}

void dijkstra(Vertex *vertices[], int size, int from) {
	printf("\n\nUtilizando o algoritmo de: Dijkstra\n");
	Vertex *toVisit[size], *current;
	int top = -1;
	toVisit[++top] = vertices[from];

	// Defina o peso da fonte como 0, pois ele não precisa ser percorrido
	vertices[from]->menorPeso = 0;
	while(current = toVisit[top--]) {
		Aresta *aresta = current->arestas->head;
        
		while(aresta != null) {
			// O peso atual é o menor peso do vértice anterior mais o aresta
			int _wgt = current->menorPeso + aresta->peso;
			//printf("\n_wgt =%d, current->menorPeso = %d, aresta->peso = %d\n",_wgt,current->menorPeso,aresta->peso);
			
				
			if(_wgt < aresta->to->menorPeso) {
				aresta->to->menorPeso = _wgt;
				toVisit[++top] = aresta->to;
				
				if(current->menorPeso < toVisit[top]->menorPeso && current->valor == G[from] && current->visitado == true){
				//if(current->visitado == true && toVisit[top]->menorPeso > current->menorPeso){
					letra_city(&aresta->to->valor);	printf(" ---- ");
			    //}
			
			}
			printf("<%d>--[%d]\n",top,toVisit[top]->menorPeso);
		
				
			}
		
			aresta = aresta->next;
			
			
		}
		if(top == -1) break;
	}
}
void letra_city(const char *G){
     switch(G[0]){
           case 'M':    	
     	   printf("Madrid-Espanha ");
     	   break;
     	    
     	   case 'P':
     	   	printf("Paris-Franca ");
     	   	break;
     	   	
     	   	 case 'Z':
     	   	  printf("Zurique-Suica");
     	   	  break;
     	   	  
     	   	  case 'A':
     	   	  	printf("Amsterda-Holanda");
     	   	  	break;
     	   	  	
     	   	  	case 'B':
     	   	  	  printf("Berlin-Alemanha");
     	   	  	  break;
     	   	  	  
     	   	  	   case 'p':
     	   	  	   	printf("Praga-Republica_Tchequia");
     	   	  	   	break;
     	   	  	   	
     	   	  	   	 default:
     	   	  	   	 	printf("City not identified!!");
     	   	  	   	 	break;
	 }	
}
void listaCity(){
printf("indice | Cidade\n");
 printf("0 _ Madrid - Espanha.\n");
 printf("1 - Paris - Franca.\n");
 printf("2 - Zurique - Suica.\n");
 printf("3 - Amsterda - Holanda.\n");
 printf("4 - Berlin - Alemanha.\n");
 printf("5 - Praga - Republica Tchequia.\n");	
}

int menuDistancia(Vertex *vertices[], int size){
int partida, destino;	
 listaCity();
 printf("6 - para sair..\n\n");
 printf("Escolha o indice da cidade de partida:\n");
 printf("=>_");	
 scanf("%d",&partida);
  if(partida == 6)
       exit(1);
       
  while(partida < 0 || partida > 6){
  	printf("Opc invalida!\n=>_");
  	scanf("%d",&partida);
  }
  printf("Escolha o indice da cidade de destino:\n=>_");
  scanf("%d",&destino);
   while(destino < 0 || destino > 6){
   	printf("Destino invalido!!\nDigite o destino:\n=>_ ");
   	scanf("%d",&destino);
   }
    
       
   	dijkstra(vertices, size, partida);
		
		printf("\nA menor distancia de: "); letra_city(&(G[partida]));
		printf(" para: "); letra_city(&G[destino]);
		 printf(" = %d km\n",vertices[destino]->menorPeso);
		system("pause");
		system("cls");
		menuDistancia(vertices,size);
	
}

int main(int argc, char *argv[]) {
	int from = 0;
	int len = sizeof(G)/sizeof(G[0]), i;
	Vertex *vertices[len];

	// First create all the vertices and store them
	for(i=0; i<len; i++) {
		vertices[i] = createVertex(G[i]);
	}

	// Then insert the arestas into the linked list
	for(i=0; i<len; i++) {
		LinkedList *list = createLinkedList();
		switch(i) {
			case 0:
				insertIntoList(list, createAresta(1277,vertices[1]));
				insertIntoList(list, createAresta(1659,vertices[2]));
				break;
			case 1:
				insertIntoList(list, createAresta(1277,vertices[0]));
				insertIntoList(list, createAresta(656, vertices[2]));
				insertIntoList(list, createAresta(510, vertices[3]));
				break;
			case 2:
				insertIntoList(list, createAresta(1659,vertices[0]));
				insertIntoList(list, createAresta(656, vertices[1]));
				insertIntoList(list, createAresta(817, vertices[3]));
				insertIntoList(list, createAresta(683, vertices[5]));
				break;
			case 3:
				insertIntoList(list, createAresta(510, vertices[1]));
				insertIntoList(list, createAresta(817, vertices[2]));
				insertIntoList(list, createAresta(655, vertices[4]));
				insertIntoList(list, createAresta(876, vertices[5]));
				break;
			case 4:
				insertIntoList(list, createAresta(655, vertices[3]));
				insertIntoList(list, createAresta(350, vertices[5]));
				break;
			case 5:
				insertIntoList(list, createAresta(683, vertices[2]));
				insertIntoList(list, createAresta(876, vertices[3]));
				insertIntoList(list, createAresta(350, vertices[4]));
				break;
			default:
				break; 
		}
		vertices[i]->arestas = list;
		lista = list;
	}
     void imprime_lista(){
     	while(lista != null){
     		printf("%d",lista->head->to->menorPeso);
     		lista = lista->head->next;
		 }
	 }
	// Set entry point for graph traversals
	


	//bfs(vertices, len, from);
	dfs(vertices, len, from);


	/* Calculando caminho mais curto
	dijkstra(vertices, len, from);

	// Print shortest path from "from" to all vertices
	for(i=0; i<len; i++) {
		if(i == from) continue;
		printf("A menor distancia de: "); letra_city(&(G[from]));
		printf(" para: "); letra_city(&G[i]);
		 printf(" = %d km\n",vertices[i]->menorPeso);
		
	}

	system("pause");*/
	menuDistancia(vertices,len);

	return 0;
}
