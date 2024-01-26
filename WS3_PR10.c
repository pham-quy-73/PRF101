#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printMinMaxDigits( int n)
{
    int digit;
    int min, max ; 
    digit = n % 10; 
    n = n / 10;
    min = max = digit; 
    while (n > 0)
    {
        digit = n % 10; 
        n = n / 10;
        if (min > digit) min = digit; 
        if (max < digit) max = digit;
   }
   printf("Max digit : %d\n", max);
   printf("Min digit : %d\n", min);
}

int main()
{
    int n;
    do {
    	printf(" Enter n : ");
        scanf("%d", &n);
        printMinMaxDigits(n);
    } while( n < 0);
    return 0;
}
