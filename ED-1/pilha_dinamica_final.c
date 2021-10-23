#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PILHA
typedef struct stackNode{
int number;
struct stackNode *next;
}no;
int size;
no *temp;
void startStack(no *stack){
stack->next = NULL;
size = 0;
}
int testEmpty(no *stack){
if(stack->next == NULL) return 1;
else return 0;
}
/*Adiciona valor a pilha e armazena valor*/
no *pusher(){
no *new = (no*) malloc(sizeof(no));
if(!new) printf("\nNenhuma Memoria\n\n");
else{
printf("\nNovo numero: "); scanf("%d", &new->number);
}
return new;
}
/*Adiciona valor a pilha*/
void push(no *stack){
no *new = pusher();
new->next = NULL;
if(testEmpty(stack)){
stack->next = new;
size++;
}else{
temp = stack->next;
while(temp->next != NULL){
temp = temp->next;
}
temp->next = new;
size++;
}
}
/* nó Ponteiro para pop e ponteiro para stack*/
no *pop(no *stack){
if(testEmpty(stack)){
printf("\n\nPilha vazia\n\n");
return NULL;
}else{
no *last = stack->next;
no *antlast = stack;

while(last->next != NULL){
antlast = last;
last = last->next;
}
antlast->next = NULL;
size--; 
return last;
}
}
/*Indica se a ppilha esta vazia, quais os valores armazenados e o tamanho da pilha*/
void showStack(no *stack){
if(testEmpty(stack)){
printf("\n\nPilha vazia\n\n");
}else{
temp = stack->next;
printf("\n");
while(temp != NULL){
printf("%d ", temp->number);
temp = temp->next;
}
printf("\nTamanho da Pilha: %d\n\n", size);
}
}
/*Indica a situacao da pilha se estar vazia e limpa*/
void freeStack(no *stack){
if(testEmpty(stack)){
printf("\n\nPilha Vazia\n\n");
}else{
no *node = stack->next, 
*nxtNode;

while(node != NULL){
nxtNode = node->next;
free(node);
node = nxtNode;
} printf("\nPilha Limpa\n\n");
}
}
/*Funcao principal*/
int main(){
no *stack = (no*) malloc(sizeof(no));

if(!stack) printf("\nnenhuma memoria\n");
else startStack(stack);
int opt;
do{
printf("---------Pilha Dinamica-------------------->\n"); 
printf("<0> Fechar Programa\n");
printf("<1> Adicionar novo numero a Pilha\n");
printf("<2> Remover o ultimo elemento da Pilha\n");
printf("<3> Mostrar Pilha\n");
printf("<4> Limpa Pilha\n");
printf("Escolha uma Opcao: "); scanf("%d", &opt);

switch(opt){
case 1:
push(stack);/*PUSH--- ADICIONAR NOVO NUMERO A PILHA*/
break;
case 2: 
temp = pop(stack);/*POP--- REMOVER O ULTIMO ELEMENTO INSERIDO DA PILHA*/ 
if(temp != NULL){
printf("\nElemento Removido %d\n\n", temp->number);
free(temp);
} break; 
/*Pega todos os valores da pilha e mostra na tela*/
case 3:
showStack(stack);
break;
/*Limpa valores que foram adicionados a pilha*/
case 4:
freeStack(stack);
startStack(stack);
break;
default:
if(opt != 0) printf("Opcao invalida\n\n");/*Escolhe entre os numeros 1\2\3\4 se não aparecerar opcao envalida*/

}
}while(opt != 0);
}

