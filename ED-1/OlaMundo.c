	#include <stdio.h>
	#include <stdlib.h>
	#include <conio.h>
	

	void Tanque(){
		FILE *imagem;
	imagem= fopen ("Tanque.txt","rt"); 
	 if(imagem==NULL){
	 	
	 	printf("Nao foi possivel  abrir\n");
	 }
	   char *vet;
	   vet = (char*) malloc (100*(sizeof(char)));
	   char *resultado;
	   resultado = fgets(vet,100,imagem);
	   while( !feof(imagem)){
	   	printf("%s",vet);
	   	resultado = fgets(vet,100,imagem);
	   }
	   fclose(imagem);
	   free(vet);
	}
	
	void ET(){
		FILE *ET;
	ET= fopen ("ET.txt","rt"); 
	 if(ET==NULL){
	 	
	 	printf("Nao foi possivel  abrir\n");
	 }
	   char *vet;
	   vet = (char*) malloc (100*(sizeof(char)));
	   char *resultado;
	   resultado = fgets(vet,100,ET);
	   while( !feof(ET)){
	   	printf("%s",vet);
	   	resultado = fgets(vet,100,ET);
	   }
	   fclose(ET);
	   free(vet);
	}
	  void caveira(){
		FILE *caveira;
	caveira= fopen ("Caveira.txt","rt"); 
	 if(caveira==NULL){
	 	
	 	printf("Nao foi possivel  abrir\n");
	 }
	   char *vet;
	   vet = (char*) malloc (100*(sizeof(char)));
	   char *resultado;
	   resultado = fgets(vet,100,caveira);
	   while( !feof(caveira)){
	   	printf("%s",vet);
	   	resultado = fgets(vet,100,caveira);
	   }
	   fclose(caveira);
	   free(vet);
	}
	void revolver(){
		FILE *revolver;
	revolver= fopen ("Revolver.txt","rt"); 
	 if(revolver==NULL){
	 	
	 	printf("Nao foi possivel  abrir\n");
	 }
	   char *vet;
	   vet = (char*) malloc (100*(sizeof(char)));
	   char *resultado;
	   resultado = fgets(vet,100,revolver);
	   while( !feof(revolver)){
	   	printf("%s",vet);
	   	resultado = fgets(vet,100,revolver);
	   }
	   fclose(revolver);
	   free(vet);
	}
	void menu(){
		int opc;
		printf(" ,___,\n");
		printf(" [O.o]\n");
		printf(" /)__)\n");
		printf(" -”–”-\n");
		printf("*___________________*\n");
		printf("\t Escolha uma opcao!\n");
		printf("\t\t1- Revolver !!!\n  ");
		printf("\t\t2- caveira..\n     ");
		printf("\t\t3- Bug           \n");
		printf("\t\t4- Tanque of war \n");
		printf("");
		printf("");
		printf("");
		printf("");
		printf("");
		printf("");
		scanf("%d",&opc);
		if(opc==1){
			system ("cls");
			system ("color 04");
			revolver();
			menu();
		}
		if(opc==2){
		     system ("cls");
			system ("color 06");
			caveira();
			
			
			menu();
		}
		 if(opc==3){
		 	system ("cls");
		 	system ("color 06");
		 	ET();
		 }
		 if(opc==4){
		 	system ("cls");
		 	system ("color 0");
		 	Tanque();
		 }
	}
	
	int main(int argc, char *argv[]) {
	
	menu();
		return 0;
	}
