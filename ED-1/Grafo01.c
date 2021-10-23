#include <stdio.h>
#include <stdlib.h>
#define MAXVERTICES 5

struct vertice{
	char nome;
};

struct aresta{
	int adj;
};

struct grafo{
	struct vertice vertices[MAXVERTICES];
	struct aresta arestas[MAXVERTICES][MAXVERTICES];

};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct grafo g1;
	int i,j;

	g1.vertices[0].nome = 'A';
	g1.vertices[1].nome = 'B';
	g1.vertices[2].nome = 'C';
	g1.vertices[3].nome = 'D';
	g1.vertices[4].nome = 'E';
	
		//A
		g1.arestas[0][0].adj = 0;
		g1.arestas[0][1].adj = 1;
		g1.arestas[0][2].adj = 1;
		g1.arestas[0][3].adj = 0;
		g1.arestas[0][4].adj = 1;
		//B
		g1.arestas[1][0].adj = 1;
		g1.arestas[1][1].adj = 0;
		g1.arestas[1][2].adj = 0;
		g1.arestas[1][3].adj = 1;
		g1.arestas[1][4].adj = 0;
		//C
		g1.arestas[2][0].adj = 1;
		g1.arestas[2][1].adj = 0;
		g1.arestas[2][2].adj = 0;
		g1.arestas[2][3].adj = 1;
		g1.arestas[2][4].adj = 0;
		//D
		g1.arestas[3][0].adj = 0;
		g1.arestas[3][1].adj = 1;
		g1.arestas[3][2].adj = 1;
		g1.arestas[3][3].adj = 0;
		g1.arestas[3][4].adj = 0;
		//E
		g1.arestas[4][0].adj = 1;
		g1.arestas[4][1].adj = 0;
		g1.arestas[4][2].adj = 0;
		g1.arestas[4][3].adj = 0;
		g1.arestas[4][4].adj = 1;
		
		  for(i=0; i<MAXVERTICES;i++){
		  	for(j=0; j<MAXVERTICES; j++){
		  		if(g1.arestas[i][j].adj == 1)
		  		 printf("\n\n %c e adjacente de %c", g1.vertices[j].nome, g1.vertices[i].nome);
			  }
		  }
	return 0;
}
