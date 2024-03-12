#include <stdio.h>
#include <math.h>

int getUserChoice()
{
	int choice = 0;
	
	system("cls");
	
	printf("| ---------------------- MENU ---------------------- |\n");
	printf("| -------------------------------------------------- |\n");
	printf("| 1. Quadratic equation.                Press 1      |\n");
	printf("| 2. Bank deposit problem.              Press 2      |\n");
	printf("| 3. Quit.                              Press anykey |\n");
	printf("| -------------------------------------------------- |\n");
	
	printf("\nYour choice:\n>> ");
	scanf("%d", &choice);
	fflush(stdin);
	
	return choice;
}

void quadratic_equation(float a, float b, float c)
{
	float delta = b * b - 4 * a * c;
	
	if (delta == 0)
	{
		printf("Equation has double solution x1 = x2 = %.3f\n", (-b) / (2 * a));
	}
	else if (delta > 0)
	{
		printf("Equation has double solution x1 = %.3f, x2 = %.3f\n", (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a));
	}
	else
	{
		printf("Equation has no solution!\n");
	}
}

float bank_deposit(float d, float r, int n)
{
	return d * pow(1 + r, n);
}

int main()
{
	int choice = 0;
	
	do
	{
		choice = getUserChoice();
		
		switch (choice)
		{
			case 1:
				system("cls");
				
				printf("| ----------------------- 01 ----------------------- |\n");
				
				float a = 1.f;
				float b = 0.f;
				float c = 0.f;
				
				printf("Quadratic equation: ax^2 + bx + c = 0 (a different from 0)\n");
				printf("Please enter coefficient:\n");
				
				do
				{
					printf("a = ");
					scanf("%f", &a);
					fflush(stdin);
				} while (a == 0);
				
				printf("b = ");
				scanf("%f", &b);
				fflush(stdin);
				
				printf("c = ");
				scanf("%f", &c);
				fflush(stdin);
				
				printf("Quadratic equation is: %.3fx^2 + %.3fx + %.3f = 0\n", a, b, c);
				
				quadratic_equation(a, b, c);
				
				getchar();
				
				break;
			
			case 2:
				system("cls");
				
				printf("| ----------------------- 02 ----------------------- |\n");
				
				float d = 0.f;
				float r = 0.f;
				int n = 0;
				
				do
				{
					printf("Your deposit = ");
					scanf("%f", &d);
					fflush(stdin);
				} while (d <= 0);
				
				do
				{
					printf("Yearly rate (between 0.1 and 1.0) = ");
					scanf("%f", &r);
					fflush(stdin);
				} while (r <= 0.f || r >= 1.f);
				
				do
				{
					printf("Number of year = ");
					scanf("%d", &n);
					fflush(stdin);
				} while (n <= 0);
				
				printf("Your amount after this duration: %.3f\n", bank_deposit(d, r, n));
				
				getchar();
				
				break;
			
			default:
				system("cls");
				printf("Goodbye. See you again...\n");
				break;
		}
		
	} while (choice > 0 && choice < 3);
	
	return 0;
}
