#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int  gcd( int a, int b);
int lcm ( int a, int b);
int main(int argc, char *argv[]) {
	int a , b, d , m ;
	do {
		printf("Enter a: ");scanf("%d",&a);
		printf("Enter b: ");scanf("%d",&b);
	}while ( a<=0 || b <=0);
	d = gcd(a,b);
	m = lcm (a,b);
 	printf(" d = %d",d);
 	printf(" m = %d",m);
	return 0;
}
int  gcd( int a, int b){
	while ( a != b )
       if (a>b)  {a -=b;}
       else 
	   { b -= a; }
   return a;
}
int lcm ( int a, int b){
	return a*b/ gcd(a,b);
}
