#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n=1,i;
	for(;;){
		if(n>1 && n%1==0 && n%n==0){
			printf("%d E primo!\n",n);
			n++;
			//System("pause");
		}else
		n++;
	}
	return 0;
}
