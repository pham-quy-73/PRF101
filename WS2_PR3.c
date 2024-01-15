#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int a, sum = 0; 
    printf("Enter integers number: ");
    while (a != 0)
    {
    	scanf("%d", &a);
        sum = sum + a;
    }
    printf("Sum of integers entered: %d", sum);

	return 0;
}
