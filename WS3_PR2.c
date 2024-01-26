#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int validDate(int d, int m, int y);
int main(int argc, char *argv[]) {
	int d,m,y;
	printf("nhap vao ngay thang nam muon kiem tra:");
	scanf("%d%d%d",&d ,&m ,&y);
	if(validDate(d,m,y)){
		printf("valid date");}
	else{
		printf("invalid date");
	}
	return 0;
}
int validDate(int d, int m, int y){
	int maxd=31;
	if(d<1 || d>31 || m<1 || m>=12)
	return 0;
	if(m==4||m==6 || m==9 ||m==11)
		maxd=30;
	if(y%400==0|| y%4==0 && y%100!=0)
		maxd=29;
	else 
		maxd=28;
return d<=maxd;
}
