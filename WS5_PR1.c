#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Random(int min, int max);
int main(int argc, char *argv[]) {
	srand(time(NULL));
	int total , x ,y ,count;
	do{
		printf("Dice throw...\n");
		printf("total: ");
		scanf("%d",&total);
	}while(total<2 || total >12);
	 	
	count=1;
	//random tim ra x+y =total
	do {
		x = Random(1,6);
		y = Random(1,6);
		printf("result throw= %d= %d + %d\n", count, x, y);
		count++;
	}while(x+y!= total);
	printf("you got %d throw", count);
	return 0;
}
int Random(int min, int max){
	//random tu 1-6
	int random = 1 + rand()% 6;
	return random;
}
