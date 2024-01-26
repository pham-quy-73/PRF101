#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int code;
    for (code = 0; code <256; code++)
    	printf("%6c, %6d, %6o, %6x\n", code, code, code, code); 
	return 0;
}
