#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int mapa[MAX][MAX];
int policia;
 
int rota(int i, int j){
    if (i == 4 && j == 4) return 1;
    else return 0;
}
 
int retornar(int mapa[MAX][MAX],int i,int j){
    if (!policia){
        if ( rota(i,j) == 1){
            policia = 1;
        }else if ( i >=0 && i < MAX && j >= 0 && j < MAX && mapa[i][j] == 0 ){
            mapa[i][j] = 1;
            retornar(mapa,i+1,j);
            retornar(mapa,i-1,j);
            retornar(mapa,i,j+1);
            retornar(mapa,i,j-1);
        }
    }
    return policia;
}
int main(){
    int c,i,j;
    scanf("%d",&c);
    while(c--){
        policia = 1;
        for (i=0;i<MAX;i++){
            for (j=0; j<MAX; j++){
                scanf("%d",mapa[i][j]);
            }
        }
        if ( retornar(mapa,0,0) == 1) printf("Policia ");
        else printf("ladrao ");
    }
    return 0;
}
