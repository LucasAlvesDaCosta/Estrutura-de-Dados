
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED 1
#define BLACK 0

/* Arvore red-black Red Black Tree.
Autor: lucas Alves da Costa.
IFG Formosa-GO
Aplicação utilizando como base a estrutura de uma arvore rubro-negra
___________________________________________________________________*/

/*Eestrutura de armazenamento das informações de texto*/
typedef struct NO *ArvLLRB;
typedef struct string{
	char *chave;
	char *texto;
}string;
/*Estrutura nativa da arvore redBlack*/
typedef struct NO{ 
	string string;
	int inf;
	int cor;
	struct NO *esq;
	struct NO *dir;	
}NO;

ArvLLRB *raiza;// ponteiro para a estrutura NO da arvore, seu intuito é facilitar a incerção e a remoção dos valores
/*prototipos das funções*/
void trocarCor(struct NO* H);
int cor(struct NO* H);
int insereArvLLRB(ArvLLRB* raiz, int valor, string string);
int removeArvLLRB(ArvLLRB* raiz, int valor);
NO* consultaArvLLRB(NO* raiz,int valor);
struct NO* rotacionaEsquerda(struct NO* A);
struct NO* rotacionaDireita(struct NO* A);
struct NO* move2EsqRed(struct NO* H);
struct NO* move2DirRed(struct NO* H);
struct NO* balancear(struct NO* H);
struct NO* insereNO(struct NO* H, int valor, int *resp, string string);
struct NO* removeNO(struct NO* H, int valor);
struct NO* removerMenor(struct NO* H);
struct NO* procuraMenor(struct NO* atual);
/*Função responsavel por calcular uma chave para uma palavra-chave, retorna um valor inteiro*/
int key_insert(char *string){
	char str[5];
     int i;
	 int key =0;
	 
	        if(strlen(string) <= 3){
	         strncpy(str,string,2);
			 key = str[0]+str[1]-str[2];
	        }else{
	         	for(i=0; i<strlen(string); i++){
	         		key += string[i];
	         		if(i == strlen(string)-1)
	         		 key -= string[i];
				 }
			 
		     }
	         
	 printf("Valor: %d\n",key);
	 int size = strlen(string);
	 printf("tamanho: %d\n",size);
	 
	 for(i=0; i<size; i++){
	 	printf("%c = %d\n",string[i],string[i]*1);
	 }
	 return key;
}
// função para esvaziar uma arvore a partir da raiz
void esvazia(NO** raiz){
	if(*raiz == NULL) return;
	esvazia(&(*raiz)->esq);
	esvazia(&(*raiz)->dir);
	free(*raiz);
	*raiz = NULL;
}
// função utilizada para imprimir apenas os valores chaves da arvore
void pesquisaPreOrdem(NO* raiz, int nivel){
	int i;
	if(raiz == NULL)
		return;	
	for(i=0; i<nivel;i++){
			printf(" ");
		}
	printf("%d \n", raiz->inf);
	pesquisaPreOrdem(raiz->esq, nivel+1);
	pesquisaPreOrdem(raiz->dir, nivel+1);
}
// função utilizada para imprimir todas as informações de cada NÓ
int imprime_pre_ordem(struct NO *arvore){/// a função ultilizada foi a pre-ordem pois imprime primeiro a raiz, depois segue pela esquerda e depois pela direita 
   int a=1,b=1;
   if(arvore != NULL){
      printf("chave de acesso:[%d]\nPalavra chave: %s\nConteudo: %s\n\n",arvore->inf,arvore->string.chave, arvore->string.texto);
      a=imprime_pre_ordem(arvore->esq);///a==0 caso sub_arvore_esquerda==NULL
      b=imprime_pre_ordem(arvore->dir);///a==0 caso sub_arvore_direita==NULL
   }else return 0;//retorna 0 caso arvore == NULL 
}
// verifica se um valor x existe na arvvore
int consulta(NO *raiz, int valor){
	
	if(raiz == NULL){
		return 0;
	}
	struct NO* atual = raiz;
	while(atual!=NULL){
		if(valor == atual->inf){
			return 1;
		}
		 if(valor > atual->inf)
		 	atual = atual->dir;
		    else
		 	  atual = atual->esq;
	}
	 return 0;
}
// função utilizada para buscar por um valor na arvore e reorna-lo caso exista
NO* consultaArvLLRB(NO* raiz,int valor){
	
	if(raiz == NULL){
		return NULL;
	}
	struct NO* atual = raiz;
	while(atual!=NULL){
		if(valor == atual->inf){
			return atual;
		}
		 if(valor > atual->inf)
		 	atual = atual->dir;
		    else
		 	  atual = atual->esq;
	}
	 return NULL;  	         	
}
// Retorna a cor de um NO, pois se a raiz é igual a NULL a cor deve ser preta!
int cor(struct NO* H){
	if(H==NULL){
		return BLACK;
	}else{
		return H->cor;
	}
}
// Função que recebe um NÓ e troca sua cor e as cores de seus filhos, idependentes de serem NULOS ou não.
void trocarCor(struct NO* H){
     H->cor = !H->cor;
	 if(H->esq != NULL){
	 	H->esq->cor = !H->esq->cor;
	 }	
	 if(H->dir != NULL){
	 	 H->dir->cor = !H->dir->cor;
	 }
}
// Esta função rotaciona um Nó e seus filhos para a esquerda
struct NO* rotacionaEsquerda(struct NO* A){
	struct NO* B = A->dir;
	A->dir = B->esq;
	B->esq = A;
	B->cor = A->cor;
	A->cor = RED;
	return B;
}
// rotaciona um nó e seus filhos para direita.
struct NO* rotacionaDireita(struct NO* A){
	struct NO* B = A->esq;
	A->esq = B->dir;
	B->dir = A;
	B->cor = A->cor;
	A->cor = RED;
	return B;
}
// Move um Nó para esquerda e faz o balanceamento
struct NO* move2EsqRed(struct NO* H){
	trocarCor(H);
	if(cor(H->dir->esq) == RED){
		H->dir = rotacionaDireita(H->dir);
		H = rotacionaEsquerda(H);
		trocarCor(H);
	}
	return H;
}
// Move um nó para direita e faz o balanceamento
struct NO* move2DirRed(struct NO* H){
	trocarCor(H);
	if(cor(H->esq->esq) == RED){
		H = rotacionaDireita(H);
		trocarCor(H);
	}return H;
}
// função responsavel pelo balaceamento da arvore completa
struct NO* balancear(struct NO* H){
	if(cor(H->dir) == RED){
		H = rotacionaEsquerda(H);
	}
	 if(H->esq != NULL && cor(H->dir)==RED && cor(H->esq->esq)==RED){
	 	H = rotacionaDireita(H);
	 }
	  if(cor(H->esq)==RED && cor(H->dir)==RED){
	  	trocarCor(H);
	  }return H;
}
// funçao administrativa da funçao de inserção
int insereArvLLRB(ArvLLRB* raiz, int valor, string string){
	int resp;
	*raiz= insereNO((NO*) *raiz,valor,&resp, string);
    	if((*raiz) != NULL){
	    	(*raiz)->cor=BLACK;
    	}
		 return resp;
}

struct NO* insereNO(struct NO* H, int valor, int *resp, string str){// função de inserção
	if(H == NULL){
	struct NO *novo;
	novo = (struct NO*)malloc(sizeof(struct NO));
	  if(novo == NULL){
	  	*resp = 0;
	  	return;
	  }	
	  novo->string.chave = str.chave;
	  novo->string.texto = str.texto;
	  novo->inf = valor;
	  novo->cor = RED;
	  novo->dir =NULL;
	  novo->esq =NULL;
	  *resp = 1;
	  return novo;
	 // free(novo);
	}
	 if(valor == H->inf)
	 	*resp = 0;
	 else{
	 	   if(valor < H->inf)
	 	      H->esq = insereNO(H->esq,valor,resp,str);
	 	   else
	 	       H->dir = insereNO(H->dir,valor,resp,str);
	 	       
	 }
	    if(cor(H->dir) == RED && cor(H->esq) == BLACK){
	  	  H = rotacionaEsquerda(H);
	  	  //printf("\nRotaciona_Esquerda!");
	    }
	     if(cor(H->esq) == RED && cor(H->esq->esq) == RED){
	     	H = rotacionaDireita(H);
	     	//printf("\nRotaciona_Direita!");
		 }
		  if(cor(H->esq) == RED && cor(H->dir) == RED){
		  	 trocarCor(H);
		  	 printf("\ncor trocada!!");
		  }
		 	return H; 
 }
 // função adm. da remoção
int removeArvLLRB(ArvLLRB* raiz, int valor){
	if(consulta(*raiz,valor)){
		struct NO* h = *raiz;
		
		 (*raiz)= removeNO(h,valor);
		  if(*raiz != NULL)
		     (*raiz)->cor = BLACK;
		 return 1;
	}else{
		  return 0;
	}
}
struct NO* removeNO(struct NO* H, int valor){
	if(valor < H->inf){
		if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
		 H = move2EsqRed(H);
		 
		H->esq = removeNO(H->esq,valor);
	}else{
		 if(cor(H->esq)== RED)
		   H = rotacionaDireita(H);
		   
		 if(valor == H->inf && H->dir == NULL){
		 	free(H);
		 	return NULL;
		 }
		 
		  if(cor(H->dir)== BLACK && cor(H->dir->esq) == BLACK)
		     H = move2DirRed(H);
		     
		  if(valor == H->inf){
		  	struct NO* x = procuraMenor(H->dir);
		  	H->inf = x->inf;
		  	H->dir = removerMenor(H->dir);
		  }else
		       H->dir = removeNO(H->dir,valor);
	}
	return balancear(H);
}

struct NO* removerMenor(struct NO* H){// procurar o nó menor e remove-lo
	if(H->esq == NULL){
		free(H);
		return NULL;
	}
	if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
	  H = move2EsqRed(H);
	  
	H->esq = removerMenor(H->esq);
	return balancear(H);
}
// retornar o filho menor de um nó
struct NO* procuraMenor(struct NO* atual){
	struct NO *no1 = atual;
	struct NO *no2 = atual->esq;
	 while(no2 != NULL){
	 	no1 = no2;
	 	no2 = no2->esq;
	 }
	 return no1;
}
// menu da aplicação.
void menu(){
	int opc,i,valor;
	string string;
	char str[50],str2[200];
	printf("Escolha:\n1-iserir\n2-remover\n3-imprimir Arvore\n4-simular busca\n5-|Destruir Arvore|\n0-ZERO - EXIT\n=> ");
	scanf("%d",&opc);
	
	 switch(opc){
	 case(0):
	  printf("\n\t\t<<<|Aplicacao encerrada|>>>");
	  exit(1);
	 break;
	 
	 	case(1):
	 		 system("cls");
	 		 printf("\n---=== inserir ===---");
	 	     setbuf(stdin,NULL);// limpar buffer
	 		 printf("\nDigite a palavra chave: ");
	 		 scanf("%[^\n]s",str);
			   getchar();
	 		 printf("Digite a inf. desta chave: ");
	 		 scanf("%[^\n]s",str2);
	 		 
	 		 valor = key_insert(str);// calcula um valor chave para a palavra digitada
	 		 string.chave = str;// guarda as informações digitadas na estrutura
	 		 string.texto = str2;
	 		 
	 		 i = insereArvLLRB(&raiza,valor,string);
	 		 
	 		 if(i == 1) printf("\n\t\t insert in key ->%d!\n",valor);
	 		 else printf("\n\tNao foi possivel inserir o valor:[%d]\n",valor);
	 		 menu();
	 	break;
	 		   
	 		     case(2):
	 		     	system("cls");
	 		     	 printf("\n====== REMOVER ======");
	 		     	  printf("\nDigite a palavra chave do conteudo: ");
	 		     	  setbuf(stdin,NULL);
	 		     	  scanf("%[^\n]s",str);
	 		     	  valor = key_insert(str);// calcula o valor chave da informação a ser removida
	 		     	  i = removeArvLLRB(&raiza,valor);
	 		     	  
	 		     	  if(i==1) printf("\n\tvalor da chave->[%d] removido!!\n",valor);
	 		     	  else printf("\n\t nao foi possivel remover o valor[%d]\t--Verifique se o valor existe na arvore!\n",valor);
	 		     	  menu();
	 		     break;
	 		           case(3):
	 		           	system("cls");
	 		           	    imprime_pre_ordem(raiza);
	 		           	    printf("\n___________________________________________________________________________\n");
	 		           	    pesquisaPreOrdem(raiza,0);
	 		           	    menu();
	 		           	    break;
	 		           	          case(4):// simula uma busca a partir de uma palavra chave
	 		           	               system("cls");
	 		           	          	   printf("Pesquise por algo: ");
	 		           	          	   setbuf(stdin,NULL);
	 		           	          	   scanf("%[^\n]s",str);
	 		           	          	   valor = key_insert(str);// calcula a chave da palavra chave de busca para procura-la na arvore
	 		           	          	   NO *aux = consultaArvLLRB(raiza, valor);
	 		           	          	         if(aux != NULL){
	 		           	          	   	      printf("\n\t\tBusca:(%s)\nResultado:\n\t[%s]\n",aux->string.chave,aux->string.texto);
											 }else 
											      printf("\nNada encontrado!!\n\n");
											      menu();
									break;
									     
										   case(5):
										   	system("cls");
										        esvazia(&raiza);
												printf("\n\t\t\t<Arvore vazia>!!!\n");
											    menu();
					 							break;		      
							 		                 default:
							 		                 	   system("cls");
							 		                 	   printf("\t\t(opcao invalida!)\n");
							 		                 	   menu();
							 		                 break;
		
	 }
}

int main(int argc, char *argv[]) {
	printf("\t\tSistema de Busca, Remocao e incercao de dados utilizando:\n\t\tArvore RED BLACK na implementacao.\n");
	raiza =NULL;
	menu();
	return 0;
}
