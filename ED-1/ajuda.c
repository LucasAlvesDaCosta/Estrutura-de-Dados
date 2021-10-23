#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int A,B,C;
	scanf("%d%d%d",&A ,&B, &C);
	
	printf("RSULTADO: %f",sqrt(pow(pow(A,B),C)));
	return 0;
}
