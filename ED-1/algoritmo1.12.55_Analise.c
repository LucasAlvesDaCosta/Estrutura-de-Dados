#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
clock_t t1, t2;	
double xA, xB, y, tempo; int i=0;
xA = 1.5;
        t1 = clock();
        tempo = t1/CLOCKS_PER_SEC;
        printf("Start:%.1lf m.seconds...",tempo);
        while(i < 30){
        	
        	xB = xA - (pow(xA,3) - (3*pow(xA,2)) +1)/( (3*pow(xA,2)) - 6*xA);
        	xA = xB;
        	
        	i++;
		}
		
		printf("\nTrigesima aproximacao e: %lf\n\n",xB);
		y = pow(xB,3) - 3*pow(xB,2)+1;
		printf("Valor da Funcao: %lf\n\n",y);
		t2 = clock();
		 tempo = t2-t1/CLOCKS_PER_SEC;
		printf("tempo: %.1lf M.sec...\n",tempo);
	
	return 0;
}
