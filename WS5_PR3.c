#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int getChoice();
int validDate(int d , int m, int y);
void characterData(char c1, char c2);
int main(int argc, char *argv[]) {
	int choice= 0;
	do{
		choice=getChoice();
		switch(choice){
			case 1:
				system("cls");
				printf("----------1----------");
				int d, m,y;
				printf("enter day: DD/MM/YY= ");
				scanf("%d / %d / %d",&d ,&m, &y);
				fflush(stdin);
				if(validDate== 1){
					printf("Valid Date.\n");
									}
				else{
					printf("invalid");
					}
				getchar();
			break;
			case 2:
				system("cls");
				printf("----------2----------");
				char c1, c2;
				printf("input character 1=");
				scanf("%c",&c1);
				fflush(stdin);
				printf("input character 2=");
				scanf("%c",&c2);
				fflush(stdin);
				characterData(c1,c2);
				getchar();
				break;
			default:
				break;
		}
	}while(choice>0 && choice< 3);
	
	return 0;
}
int getChoice(){
	int choice=0;
	system("cls");
	printf("---------------------MELU--------------------\n");
	printf("1. Processing date data.\n");
	printf("2. Character data.\n");
	printf("3. Quit.\n");
	printf("---------------------------------------------\n");
	printf("your choise:");
	scanf("%d",&choice);
	fflush(stdin);
	return choice;
}
int validDate(int d , int m, int y){
	int maxDay=31;
	if(d<1 || d>31 || m<1 || m>12){
		return 0;
	}
	if(m== 4 || m==6 || m==9 || m== 11){
		maxDay=30;
	}
	else if(m==2){
		if(y % 400 == 0 || (y %4 == 0 && y % 100 !=0)){
			maxDay=29;
		}
		else{
			maxDay=28;
		}
	}
	return d<=maxDay;
}

void characterData(char c1, char c2){
	if(c1> c2){
		char t= c1;
		c1 = c2;
		c2 = t;
	}
	for (int c=c2; c>=c1; c--){
		printf("%c : %d, %xh\n",c, c, c);
	}
}

