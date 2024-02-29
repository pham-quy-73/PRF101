#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int randomBall(int min, int max);
int main(int argc, char *argv[]) {
	srand(time(NULL));
	int total, x ,y, count;
	while(total<2 || total> 20){
		printf("Ball Lottery...\n");
		printf("total:  ");
		scanf("%d",&total);
	}
	count=0;
	do{
		x= randomBall(1,10);
		count++;
		do{
			y=randomBall(1,10);
			}while(x == y);
		count++;
		
		printf("result of pick %d and %d : %d + %d\n",count-1, count,x,y);
	}while(x+y != total);
	printf("you got total %d pick\n",count);
	return 0;
}
int randomBall(int min, int max){
	int random = 1+ rand()%10;
	return random;
}

