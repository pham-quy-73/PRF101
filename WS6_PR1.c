//Write a program that will accept a number (>=1 000 000 000)
//then show whether the number is an ISBN or not.

#include <stdio.h>
#include <stdlib.h>

int checkISBN(int n) 
{
	int N[10];
	int T = 0;
	int i, j;
	for (i = 9; i >= 0; i--)
	{
		N[i] = n % 10;//chia lay du roi gan vo mang N
		n = n / 10; //loai bo so da bi chia
	}
	for (i = 0; i < 9; i++)
		{
			T += N[i]*(10-i);// 
		}
	T += N[9];
	if ((T % 11) == 0)
		printf("This is a valid ISBN!\n");
	else
		printf("This is not a valid ISBN!\n");
}

int main() {
	int n, check;
	check = 1;
	printf("ISBN Validator\n==============\n");
	while (check == 1) {
		do 
		{
			printf("Enter ISBN (0 to exit): ");
			scanf("%d", &n);
			if (n < 0)
				printf("Wrong input!!! Enter again!\n");
		}
		while (n < 0);
		if (n != 0)
			checkISBN(n);
		else check = 0;
	}
	printf("Bye! Have a nice day!");
	return 0;
}
