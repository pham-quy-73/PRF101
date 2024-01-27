#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double makeDouble(int ipart, int fraction);
int main(int argc, char *argv[]) {
	int ipart , fraction;
	double value;
	printf("Enter ipart: ");
	scanf("%d",&ipart);
	do { 
		printf("Enter fraction : ");
		scanf("%d",&fraction); }
	while ( fraction < 0 );
	value = makeDouble(ipart,fraction);
 	printf("Value is : %lf",value);
	return 0;
}
double makeDouble(int ipart, int fraction){
	double f=fraction;
	while(f>=1) 
		f=f / 10;
	if(ipart < 0) return ipart - f;
	return ipart + f;
}
