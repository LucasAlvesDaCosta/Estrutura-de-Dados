#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	// fibonasci
	int n,F1=0,F2=1,F3;
	          scanf("%d",&n);
	
		if(n<0){
			printf("Numero invalido\n");
		}else{
			printf("0\n1\n");
		while(F2<n){
			F3=F2+F1;
			if(F3<=n){
				printf("%d\n",F3);
			}
			
			F1=F2;
			F2=F3;
		}	
		
		
	return 0;
	}
}
