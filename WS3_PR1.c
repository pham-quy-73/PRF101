#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool ktsonguyento(int n);
int main(int argc, char *argv[]) {
	int number;
	printf(" enter your number:");
	scanf("%d",&number);
	if(number<=1){
		printf("error");
	}	printf("so nguyen to la: ");
	for(int i=0;i<=number;i++){
		if(ktsonguyento(i)){
			printf("%d ",i);
		}
		}
	}

bool ktsonguyento(int n){
	if(n<=1){
	 return false;}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
