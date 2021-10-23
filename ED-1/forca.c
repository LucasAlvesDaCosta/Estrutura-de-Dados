#include <stdio.h>
#include <stdlib.h>

#define max 8

typedef struct string{
	char str[max];

}str;
str palavra_certa[max];
 


int main(){
	printf("palavra!\n>>>> ");
	scanf("%s",&palavra_certa[0].str);
    char letra;
    char palavra[] = "________";
   // palavra_certa[0];
    char letras_erradas[50];

    int i;
    int erros = 0;
    int acerto;

    while(palavra != palavra_certa[0].str){
        printf("===================================\n");
        printf("               FORCA               \n");
        printf("===================================\n");
        printf("              Aplicativo!          \n");
        printf("              8 LETRAS             \n");
        printf("===================================\n");

        printf("ERROS [%d]:",erros);
        for(i = 0; i < erros; i++){
            printf("  %c",letras_erradas[i]);
        }
        printf("\n===================================\n    ");

        for(i = 0; i < 8; i++){
            printf("  %c",palavra[i]);
        }
        printf("\n===================================\n");

        printf("Digite uma Letra: ");
        scanf("%s",&letra);

        acerto = 0;
        for(i = 0; i < 8; i++){
            if(letra == palavra_certa[i].str){
                palavra[i] = letra;
                acerto++;
            }
        }

        if(acerto == 0){
            letras_erradas[erros] = letra;
            erros++;
        }

        if(strcmp(palavra,palavra_certa)==0){
            system("cls");
            printf("\n===================================\n    ");
            for(i = 0; i < 8; i++){
                printf("  %c",palavra[i]);
            }
            printf("\n===================================\n");
            printf("         ACERTOU MIZERAVI!             \n\n\n");
            
            exit(1);
        }
        system("cls");
    }
}

