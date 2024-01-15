#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int x, y;
    do
    {
        printf("Enter number x and y: ");
        scanf("%d%d", &x, &y);
        int t = x;
            x = y;
            y = t;
        printf("x = %d, y = %d\n", x, y);
    }
    while (x != 0 && y !=0);
	return 0;
}
