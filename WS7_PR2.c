#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_VALUE	100

int getUserChoice()
{
	int choice = 0;
	
	system("cls");
	
	printf("| ---------------------- MENU ---------------------- |\n");
	printf("| -------------------------------------------------- |\n");
	printf("| 1. Add a new employee.                Press 1      |\n");
	printf("| 2. Search a data of employee.         Press 2      |\n");
	printf("| 3. Remove an employee.                Press 3      |\n");
	printf("| 4. Print the list in descending order.Press 4      |\n");
	printf("| 5. Quit.                              Press anykey |\n");
	printf("| -------------------------------------------------- |\n");
	
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
	strlwr(str);// viet thuong name
	
	int length = strlen(str);
	//viet hoa ki tu dau tien: ex:anh-->Anh
	for (int i = 0; i < length; i++)
	{
		if (i == 0 || (i > 0 && str[i - 1] == ' '))
		{
			str[i] = toupper(str[i]);
		}
	}
	
	return str;
}

void addEmployee(char id_array[][9], char name_array[][21], int salary_array[], int allowance_array[], int* count)
{
	char id[9];
	char name[21];
	
	int salary = 0;
	int allowance = 0;
	
	printf("!--Please Enter Employee Information--!\n");
	
	printf("Employee ID: ");
	scanf("%[^\n]", id);
	fflush(stdin);
	
	printf("Employee name: ");
	scanf("%[^\n]", name);
	fflush(stdin);
	
	printf("Employee salary (VND): ");
	scanf("%d", &salary);
	fflush(stdin);
	
	printf("Employee allowance (VND): ");
	scanf("%d", &allowance);
	fflush(stdin);
	
	trim(id);
	nameStr(name);
	
	strcpy(id_array[*count], id);
	strcpy(name_array[*count], name);
	salary_array[*count] = salary;
	allowance_array[*count] = allowance;
	
	(*count)++;
}

void printList(char id_array[][9], char name_array[][21], int salary_array[], int allowance_array[], int n)
{
	printf("ID: %s\n", id_array[n]);
	printf("Name: %s\n", name_array[n]);
	printf("Salary: %d VND\n", salary_array[n]);
	printf("Allowances: %d VND\n", allowance_array[n]);
}

void printBasedName(char id_array[][9], char name_array[][21], int salary_array[], int allowance_array[], int count)
{
	printf("Enter NAME of employee you wanna find the information: ");
	
	char name[21];
	scanf("%[^\n]", name);
	fflush(stdin);
	
	nameStr(name);
	
	int check = 0;
	
	for (int i = 0; i < count; i++)
	{
		if (strcmp(name, name_array[i]) == 0)
		{
			printf("-- Information of Employee --\n");
			printList(id_array, name_array, salary_array, allowance_array, i);
			
			check = 1;
		}
	}
	
	if (check == 0)
	{
		printf("Not found information of employee was entered!\n");
	}
}

void removeEmployee(char id_array[][9], char name_array[][21], int salary_array[], int allowance_array[], int* count)
{
	printf("Enter ID of employee you wanna REMOVE: ");
	
	char id[9];
	scanf("%[^\n]", id);
	fflush(stdin);
	
	trim(id);
	
	int check = 0;
	
	for (int i = 0; i < *count; i++)
	{
		if (strcmp(id_array[i], id) == 0)
		{
			for (int j = i + 1; j < *count; j++)
			{
				strcpy(id_array[j - 1], id_array[j]);
				strcpy(name_array[j - 1], name_array[j]);
				salary_array[j - 1] = salary_array[j];
				allowance_array[j - 1] = allowance_array[j];
			}
			
			check = 1;
			
			(*count)--;
		}
	}
	
	if (check == 1)
	{
		printf("Removed!\n");
	}
	else
	{
		printf("Unremove!\n");
	}
}

void printEmployee(char id_array[][9], char name_array[][21], int salary_array[], int allowance_array[], int* count)
{
	for (int i = 0; i < *count - 1; i++)
	{
		for (int j = *count - 1; j > i; j--)
		{
			if ((salary_array[j] + allowance_array[j]) > (salary_array[j - 1] + allowance_array[j - 1]))
			{
				char temp_id[9];
				strcpy(temp_id, id_array[j]);
				strcpy(id_array[j], id_array[j - 1]);
				strcpy(id_array[j - 1], temp_id);
				
				char temp_name[21];
				strcpy(temp_name, name_array[j]);
				strcpy(name_array[j], name_array[j - 1]);
				strcpy(name_array[j - 1], temp_name);
				
				int temp_salary = salary_array[j];
				salary_array[j] = salary_array[j - 1];
				salary_array[j - 1] = temp_salary;
				
				int temp_allowance = allowance_array[j];
				allowance_array[j] = allowance_array[j - 1];
				allowance_array[j - 1] = temp_allowance;
			}
		}
	}
	
	printf("---List of employees---\n");
	
	for (int i = 0; i < *count; i++)
	{
		printList(id_array, name_array, salary_array, allowance_array, i);
		printf("\n");
	}
}

int main()
{
	char id_array		[MAX_ARRAY_VALUE][9];
	char name_array		[MAX_ARRAY_VALUE][21];
	int salary_array	[MAX_ARRAY_VALUE];
	int allowance_array	[MAX_ARRAY_VALUE];
	
	int count = 0;
	
	int choice = 0;
	
	do
	{
		choice = getUserChoice();
		
		switch (choice)
		{
			case 1:
				system("cls");
				
				printf("| ----------------------- 01 ----------------------- |\n");
				
				if (isFull(count))
				{
					printf("Sorry! The list is full!\n");
				}
				else
				{
					addEmployee(id_array, name_array, salary_array, allowance_array, &count);
					printf("Added!\n");
				}
				
				getchar();
				break;
			
			case 2:
				system("cls");
				
				printf("| ----------------------- 02 ----------------------- |\n");
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					printBasedName(id_array, name_array, salary_array, allowance_array, count);
				}
				
				getchar();
				break;
			
			case 3:
				system("cls");
				
				printf("| ----------------------- 03 ----------------------- |\n");
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					removeEmployee(id_array, name_array, salary_array, allowance_array, &count);
				}
				
				getchar();
				break;
			
			case 4:
				system("cls");
				
				printf("| ----------------------- 04 ----------------------- |\n");
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					printEmployee(id_array, name_array, salary_array, allowance_array, &count);
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

