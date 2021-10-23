#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Rec(int n){
	
	if(n==1||n==2){
		return 1;
	}else
		return(Rec(n-1)+Rec(n-2));
	

}
int main(int argc, char *argv[]) {
	int n,i;
	printf("Digite a sequencia!\n");
	scanf("%d",&n);
	         for(i=0;i<n;i++){
	         	if(Rec(i+1)<=n){
	         		printf("%d\n",Rec(i+1));
			    }
	         	
		    }
	
	return 0;
}
