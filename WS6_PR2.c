#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY 	100

int getUserChoice()
{
	int choice = 0;
	printf("| ---------------------- MENU ---------------------- |\n");
	printf("| -------------------------------------------------- |\n");
	printf("| 1. Add a value.                       Press 1      |\n");
	printf("| 2. Search a value.                    Press 2      |\n");
	printf("| 3. Print out the array.               Press 3      |\n");
	printf("| 4. Print out values in a range.       Press 4      |\n");
	printf("| 5. Print out the array in ascending.  Press 5      |\n");
	printf("| 6. Quit.                              Press anykey |\n");
	printf("| -------------------------------------------------- |\n");
	
	printf("\nYour choice:\n>> ");
	scanf("%d", &choice);
	fflush(stdin);
	
	return choice;
}

void add(int array[], int value, int* count)
{
	array[*count] = value;
	(*count)++;
}

int search(int array[], int value, int n)
{
	int count = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (array[i] == value)
		{
			count++;
		}
	}
	
	return count;
}

void printArray(int array[], int n)
{
	printf("Array of number:\n");
	
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}

void printRange(int array[], int n)
{
	int min = 0;
	int max = 0;
	
	printf("Enter the range [a..b]:\n");
	
	printf("a = ");
	scanf("%d", &min);
	fflush(stdin);
	
	printf("b = ");
	scanf("%d", &max);
	fflush(stdin);
	
	int check = -1;
	
	for (int i = 0; i < n; i++)
	{
		if (array[i] >= min && array[i] <= max)
		{
			printf("%d ", array[i]);
			check = i;
		}
	}
	
	if (check < 0)
	{
		printf("No value between range!\n");
	}
}

void printASC(int array[], int n)
{
	int* address = (int*)calloc(n, sizeof(int));
	
	for (int i = 0; i < n; i++)
	{
		address[i] = array[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (address[j] < address[j - 1])
			{
				int temp = address[j];
				address[j] = address[j - 1];
				address[j - 1] = temp;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("%d ", address[i]);
	}
	
	free(address);
}

int main()
{
	int number_array[MAX_ARRAY];
	
	int count = 0;
	int value = 0;
	int choice = 0;
	
	do
	{
		choice = getUserChoice();
		
		switch (choice)
		{
			case 1:
				system("cls");
				
				printf("| ----------------------- 01 ----------------------- |\n");
				printf("Enter a value: ");
				
				scanf("%d", &value);
				fflush(stdin);
				
				add(number_array, value, &count);
				
				printf("Added!\n");
				
				getchar();
				break;
			
			case 2:
				system("cls");
				
				printf("| ----------------------- 02 ----------------------- |\n");
				printf("Enter a value to search: ");
				
				scanf("%d", &value);
				fflush(stdin);
				
				int count_value = search(number_array, value, count);
				
				if (count_value == 0)
				{
					printf("Not found!\n");
				}
				else
				{
					printf("Number of existences: %d.\n", count_value);
				}
				
				getchar();
				break;
			
			case 3:
				system("cls");
				
				printf("| ----------------------- 03 ----------------------- |\n");
				
				printArray(number_array, count);
				
				getchar();
				break;
			
			case 4:
				system("cls");
				
				printf("| ----------------------- 04 ----------------------- |\n");
				
				printRange(number_array, count);
				
				getchar();
				break;
			
			case 5:
				system("cls");
				
				printf("| ----------------------- 05 ----------------------- |\n");
				
				printASC(number_array, count);
				
				getchar();
				break;
			
			default:
				system("cls");
				printf("Goodbye. See you again...\n");
				break;
		}
		
	} while (choice > 0 && choice < 6);
	
	return 0;
}

