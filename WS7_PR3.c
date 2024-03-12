#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_VALUE	100
#define MAX_LENGTH		20

int getUserChoice()
{
	int choice = 0;
	
	system("cls");
	
	printf("| ----------------------------------------- MENU ---------------------------------------- |\n");
	printf("| --------------------------------------------------------------------------------------- |\n");
	printf("| 1. Add a new soft drink.                                                   Press 1      |\n");
	printf("| 2. Printing out items which belong to a same origin. (Country)             Press 2      |\n");
	printf("| 3. Printing out items whose volumes are between [(ml)__and__(ml)].         Press 3      |\n");
	printf("| 4. Printing the list in ascending order based on volumes then prices.      Press 4      |\n");
	printf("| 5. Quit.                                                                   Press anykey |\n");
	printf("| --------------------------------------------------------------------------------------- |\n");
	
	printf("\nYour choice:\n>> ");
	scanf("%d", &choice);
	fflush(stdin);
	
	return choice;
}

int isFull(int n)
{
	return n == MAX_ARRAY_VALUE;
}

int isEmpty(int n)
{
	return n == 0;
}

char* ltrim(char str[])
{
	int i = 0;
	
	while (str[i] == ' ')
	{
		i++;
	}
	
	if (i > 0)
	{
		strcpy(&str[0], &str[i]);
	}
	
	return str;
}

char* rtrim(char str[])
{
	int i = strlen(str) - 1;
	
	while (str[i] == ' ')
	{
		i--;
	}
	
	str[i + 1] = '\0';
	
	return str;
}

char* trim(char str[])
{
	rtrim(ltrim(str));
	
	char* ptr = strstr(str, "  ");
	
	while (ptr != NULL)
	{
		strcpy(ptr, ptr + 1);
		ptr = strstr(str, "  ");
	}
	
	return str;
}

char* nameStr(char str[])
{
	trim(str);
	strlwr(str);
	
	int length = strlen(str);
	
	for (int i = 0; i < length; i++)
	{
		if (i == 0 || (i > 0 && str[i - 1] == ' '))
		{
			str[i] = toupper(str[i]);
		}
	}
	
	return str;
}

void addSoftDrink(char name_array[][MAX_LENGTH], char make_array[][MAX_LENGTH], int volume_array[], int price_array[], int duration_array[], int* count)
{
	char name[MAX_LENGTH];
	char make[MAX_LENGTH];
	
	int volume = 0;
	int price = 0;
	int duration = 0;
	
	printf("--Enter information of Soft Drinks--\n");
	
	printf("Name: ");
	scanf("%[^\n]", name);
	fflush(stdin);
	
	printf("Made in: ");
	scanf("%[^\n]", make);
	fflush(stdin);
	
	printf("Volume (ml): ");
	scanf("%d", &volume);
	fflush(stdin);
	
	printf("Price (VND): ");
	scanf("%d", &price);
	fflush(stdin);
	
	printf("Duration (Days): ");
	scanf("%d", &duration);
	fflush(stdin);
	
	nameStr(name);
	nameStr(make);
	
	strcpy(name_array[*count], name);
	strcpy(make_array[*count], make);
	
	volume_array[*count] = volume;
	price_array[*count] = price;
	duration_array[*count] = duration;
	(*count)++;
}

void printList(char name_array[][MAX_LENGTH], char make_array[][MAX_LENGTH], int volume_array[], int price_array[], int duration_array[], int count)
{
	printf("Name: %s\n", name_array[count]);
	printf("Made in: %s\n", make_array[count]);
	printf("Volume: %d ml\n", volume_array[count]);
	printf("Price: %d VND\n", price_array[count]);
	printf("Duration: %d Days\n\n", duration_array[count]);
}

void printBaseMake(char name_array[][MAX_LENGTH], char make_array[][MAX_LENGTH], int volume_array[], int price_array[], int duration_array[], int count)
{
	char make[MAX_LENGTH];
	
	printf("Enter origin of soft drink you wanna print: ");
	scanf("%[^\n]", make);
	fflush(stdin);
	
	nameStr(make);
	
	int check = 0;
	
	for (int i = 0; i < count; i++)
	{
		if (strcmp(make, make_array[i]) == 0)
		{
			printf(">List of Soft Drink base on %s:\n", make_array[i]);
			printList(name_array, make_array, volume_array, price_array, duration_array, i);
			
			check = 1;
		}
	}
	
	if (check == 0)
	{
		printf("There are not any soft drinks on the list based on %s!!!\n", make);
	}
}

void printBaseVol(char name_array[][MAX_LENGTH], char make_array[][MAX_LENGTH], int volume_array[], int price_array[], int duration_array[], int count)
{
	int min = 0;
	int max = 0;
	
	printf("Enter the MIN and MAX mil of soft drinks you wanna print:\n");
	
	printf("Min (ml): ");
	scanf("%d", &min);
	fflush(stdin);
	
	printf("Max (ml): ");
	scanf("%d", &max);
	fflush(stdin);
	
	int check = 0;
	
	for (int i = 0; i <= count; i++)
	{
		if ((volume_array[i] >= min) && (volume_array[i] <= max))
		{
			printList(name_array, make_array, volume_array, price_array, duration_array, i);
			
			check = 1;
		}
	}
	
	if (check == 0)
	{
		printf("There are not any soft drinks between %d ml and %d ml!!!\n", min, max);
	}
}

void printAsc(char name_array[][MAX_LENGTH], char make_array[][MAX_LENGTH], int volume_array[], int price_array[], int duration_array[], int* count)
{
	for (int i = 0; i < (*count) - 1; i++)
	{
		for (int j = (*count) - 1; j > i; j--)
		{
			if (price_array[j] + duration_array[j] < price_array[j - 1] + duration_array[j - 1])
			{
				char temp_name[MAX_LENGTH];
				strcpy(temp_name, name_array[j - 1]);
				strcpy(name_array[j - 1], name_array[j]);
				strcpy(name_array[j], temp_name);
				
				char temp_make[MAX_LENGTH];
				strcpy(temp_make, make_array[j - 1]);
				strcpy(make_array[j - 1], make_array[j]);
				strcpy(make_array[j], temp_make);
				
				int temp_volume = volume_array[j - 1];
				volume_array[j - 1] = volume_array[j];
				volume_array[j] = temp_volume;
				
				int temp_price = price_array[j - 1];
				price_array[j - 1] = price_array[j];
				price_array[j] = temp_price;
				
				int temp_duration = duration_array[j - 1];
				duration_array[j - 1] = duration_array[j];
				duration_array[j] = temp_duration;
			}
		}
	}
	
	for (int i = 0; i < *count; i++)
	{
		printList(name_array, make_array, volume_array, price_array, duration_array, i);
	}
}

int main()
{
	char name_array		[MAX_ARRAY_VALUE][MAX_LENGTH];
	char make_array		[MAX_ARRAY_VALUE][MAX_LENGTH];
	int volume_array	[MAX_ARRAY_VALUE];
	int price_array		[MAX_ARRAY_VALUE];
	int duration_array	[MAX_ARRAY_VALUE];
	
	int count = 0;
	
	int choice = 0;
	
	do
	{
		choice = getUserChoice();
		
		switch (choice)
		{
			case 1:
				system("cls");
				
				printf("| ----------------------------------------- 01 ------------------------------------------ |\n");
				
				if (isFull(count))
				{
					printf("Sorry! The list is full!\n");
				}
				else
				{
					addSoftDrink(name_array, make_array, volume_array, price_array, duration_array, &count);
					printf("Added!\n");
				}
				
				getchar();
				break;
			
			case 2:
				system("cls");
				
				printf("| ----------------------------------------- 02 ------------------------------------------ |\n");
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					printBaseMake(name_array, make_array, volume_array, price_array, duration_array, count);
				}
				
				getchar();
				break;
			
			case 3:
				system("cls");
				
				printf("| ----------------------------------------- 03 ------------------------------------------ |\n");
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					printBaseVol(name_array, make_array, volume_array, price_array, duration_array, count);
				}
				
				getchar();
				break;
			
			case 4:
				system("cls");
				
				printf("| ----------------------------------------- 04 ------------------------------------------ |\n");
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					printAsc(name_array, make_array, volume_array, price_array, duration_array, &count);
				}
				
				getchar();
				break;
			
			default:
				system("cls");
				printf("Goodbye. See you again...\n");
				break;
		}
		
	} while (choice > 0 && choice < 5);
	
	return 0;
}

