#include <stdio.h>
#include <stdlib.h>
#define ENTER 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int khac = 0, nguyen_am = 0, phu_am = 0;
	char c;
	printf("nhap vao choi ki tu: ");
	while ( c != ENTER)
	{
		c = getchar();
        	if ((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')))
        	{
        		switch (c)
			{
				case 'a':
            			case 'i':
            			case 'u':
            			case 'e':
            			case 'o':
            			case 'A':
            			case 'I':
            			case 'U':
            			case 'E':
            			case 'O':
        	     			nguyen_am++;
        	     			break;
        			default:
					phu_am++;
			}
        	}
        	else khac++;
	}
	printf("Number of nguyen am: %d\n", nguyen_am);
	printf("Number of phu am: %d\n", phu_am);
	printf("Number of ki tu khac: %d\n", khac);	
	return 0;
}
