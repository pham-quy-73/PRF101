#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double factorial(int n);
int main(int argc, char *argv[]) {
	int n;
	do{
		printf("A number want caculate factorial:");
		scanf("%d",&n);
	}while(n<0);
	int result=factorial(n);
	printf("%d",result);
	return 0;
}
double factorial(int n){
	double p=1;
	for(int i=2;i<=n;i++){
		p*=i;
	}
	return p;
}
