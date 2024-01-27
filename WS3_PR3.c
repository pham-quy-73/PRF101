#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int getRelPos( double x, double y, double r);
int main(int argc, char *argv[]) {
	int r,x,y;
	printf("enter a point P:\n");
	printf("enter x in P:");
	scanf("%d",&x);
	getchar();
	printf("enter y in P:");
	scanf("%d",&y);
	do{
	printf("enter your radius:");
	scanf("%d",&r);
	}while(r<0);
	int check = getRelPos(x,y,r);
	if(check==1){
		printf("P is in the circle");
	}
	else if(check ==0){
		printf("P is in the circle");
	}
	else{
		printf("P is out the circle");
	}
	return 0;
}
int getRelPos( double x, double y, double r){
	double d=sqrt(x*x+y*y);//d la khoang cach tu O den 1 diem
	if(d<r) // diem thuoc duong tron 
		return 1;
	else if(d==r) //diem nam tren duong tron 	
		return 1;
	else //diem nam ngoai duong tron
		return -1;
	
}
