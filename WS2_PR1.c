#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b;
	char c;
	printf("Enter simple expression: ");
	scanf("%d%c%d", &a, &c, &b);
    		switch (c)
		{
			case '+':
				printf("%d + %d = %d\n", a, b, a+b);
                		break;
            		case '-':
                		printf("%d - %d = %d\n", a, b, a-b);
                		break;
            		case '*':
				printf("%d * %d = %d\n", a, b, a*b);
                		break;
            		case '/':
                		if (b == 0)
                    			printf("Cannot devide 0\n");
                		else
                    			printf("%d / %d = %d\n", a, b, a/b);
                		break;}
                		
	return 0;
}
