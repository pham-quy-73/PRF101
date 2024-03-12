#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXM 100
#define MAXN 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int checkFull(int n);
int isEmpty(int n);
char* nameStr (char str[]);
int getUserChoice();
void printAStudent(int IDs, char *name, int gender, int dayAbsent);
void printAllStudents( int IDs[], char names[][MAXN] ,int genders[], int dayAbsent[], int count);
void addStudents( int IDs[], char names[][MAXN] ,int genders[], int dayAbsent[], int *pCount);
void searchStudent(int IDs[], char names[][MAXN], int genders[], int dayAbsent[], int count);
void saveToFile(int IDs[], char names[][MAXN], int genders[], int dayAbsent[], int count);
void removeStudent(int IDs[], char names[][MAXN], int genders[], int dayAbsent[], int *pCount);
void removeAllStudents(int* pCount);
int main(int argc, char *argv[]) {
	int  IDs[MAXN];
	char names[MAXM][MAXN];
	int  genders[5];	
	int dayAbsent[50];
	int count =0;
	int choice=0;
	do{
		choice= getUserChoice();
		switch(choice){
			case 1:{
				printAllStudents(IDs, names, genders, dayAbsent, count);
				getchar();
				break;
			}
			case 2:{
				addStudents(IDs, names, genders, dayAbsent, &count);
				getchar();
				break;
			}	
			case 3:{
				searchStudent(IDs, names, genders, dayAbsent, count);
				getchar();
				break;
			}
			case 4:{
				saveToFile(IDs, names, genders, dayAbsent, count);
				getchar();
				break;
			}
			case 5:{
				removeStudent(IDs, names, genders, dayAbsent, &count);
				getchar();
				break;
			}
			case 6:{
				removeAllStudents(&count);
				getchar();
				break;
			}
			default:{
				getchar();
				break;
			}
		}
	}while(choice>0 && choice<7);
	return 0;
}

// ktra mang co the add tiep hay khong
int checkFull(int n){
	return n >= MAXM;
}

//ktra mang rong or not
int isEmpty(int n){
	return n<= 0;
}

//viet lai ten EX: nGUYEN vAN A==> Nguyen Van A
char* nameStr (char str[]){
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

int getUserChoice()
{
	int choice = 0;
	
	printf("\n\n\n");
	printf("--------------------------------------------------------------\n");
	printf("\t\t       1. Display all students                |  Press 1\n");
	printf("\t\t       2. Add new student                     |  Press 2\n");
	printf("\t\t       3. Search a student                    |  Press 4\n");
	printf("\t\t       4. Write data to file                  |  Press 5\n");
	printf("\t\t       5. Remove a student                    |  Press 6\n");
	printf("\t\t       6. Remove all students                 |  Press 7\n");
	printf("\t\t       7. Quit!                               |  Press any\n\n\n");
	printf("--------------------------------------------------------------\n");
	printf("\t\t\t\t\t Your choice: ");
	scanf("%d", &choice);
	fflush(stdin);
	return choice;
}

//print a student
void printAStudent(int IDs, char *name, int genders, int dayAbsent){
	printf("\t| %-4d | %-35s | %-8s | %-3d |\n", IDs, name, genders ? "Female" : "Male", dayAbsent);
}

//print list students and sone infomation
void printAllStudents(int IDs[], char names[][MAXN], int genders[], int dayAbsent[], int count) {
    if (isEmpty(count)) {
        printf("The list is empty!\n");
        return;
    }
    printf("\t\t The list of all students:\n");
    printf("\t| %-4s | %-35s | %-8s | %-3s |\n", " ID", "             Full name", " Gender", " Number Of Days Absent");
    for (int i = 0; i < count; i++) {
    	printAStudent(IDs[i], names[i], genders[i], dayAbsent[i]);
    }
    printf("\n\t\t\t\t\t  Enter to exit...");
    
}

//add student to array
void addStudents( int IDs[], char names[][MAXN] ,int genders[], int dayAbsent[], int *pCount){
	if(checkFull(*pCount)){
		printf("\t\t The list students is full!\n");
		return;
	}
	int ID=0;
	char name[MAXN];
	int gender=0;
	int dayofAbsent=0;
	printf("\t\t Please!Enter in4 of students!\n");
	
	printf("\t\t - Student ID: ");
	scanf("%d", &ID);
	fflush(stdin);
	
	printf("\t\t - Full name: ");
	scanf("%[^\n]", name);
	fflush(stdin);
	
	printf("\t\t - Gender (0 is male, 1 is female): ");
	scanf("%d", &gender);
	fflush(stdin);
	
	printf("\t\tNumber Of Days Absent:");
	scanf("%d", &dayofAbsent);
	fflush(stdin);
	
	nameStr(name);
	
	IDs[*pCount] = ID;
	strcpy(names[*pCount], name);
	genders[*pCount] = gender;
	dayAbsent[*pCount]=dayofAbsent;
	(*pCount)++;
	
	printf("\t\t\t\t Added!!!!!!");
	printf("\t\t\t Enter to exit!");
}

//search students by their id
void searchStudent(int IDs[], char names[][MAXN], int genders[], int dayAbsent[], int count){
		if(isEmpty(count)){
		printf("The list is emmpty!\n");
		getchar();
		return;
	}
	int ID=0;
	
	printf("\t\t't Enter student ID to search: \n");
	scanf("%d",&ID);
	fflush(stdin);
	
	printf("\n\t| %-4s | %-35s | %-8s | %-10s |\n", " ID", "             Full name", " Gender", " Number Of Days Absent");
	
	for(int i=0;i<count;i++){
		if(IDs[i] == ID){
			printAStudent(IDs[i],names[i],genders[i],dayAbsent[i]);
		}
	}
	printf("\t\t\t Enter to exit!");
}


void saveToFile(int IDs[], char names[][MAXN], int genders[], int dayAbsent[], int count){
	if(isEmpty(count)){
		printf("The list is emmpty!\n");
		getchar();
		return;
	}
	printf("\t\t\t Save list students to file!");
	printf("\t\t\t Enter file name to save!");
	printf("\t\t\t File name with last word .txt : EX: list.txt");
	printf("\t\t\t File name:");
	
	char fileName[MAXN];
	scanf("%[^\n]",fileName);
	fflush(stdin);
	
	FILE* file = fopen(fileName, "w");
	for (int i = 0; i < count; i++)
	{
		fprintf(file, "%d, %s, %d, %d\n", IDs[i], names[i], genders[i] ? "Female" : "Male", dayAbsent);
	}
	fclose(file);
	printf("\n\t\t Saved!");
	printf("\t\t\t Enter to exit!");
}

//remove student
void removeStudent(int IDs[], char names[][MAXN], int genders[], int dayAbsent[], int *pCount){
	if(isEmpty(*pCount)){
	printf("The list is emmpty!\n");
	getchar();
	return;
 }
	printf("\t\t\t REMOVE a student!\n");
	int ID=0;
	printf("\t\t\t Enter student ID want REMOVE !\n");
	scanf("%d",&ID);
	fflush(stdin);
	
	int check = 0;
	int pos = 0;

	for (int i = 0; i < *pCount && !check; i++){
    	if (IDs[i] == ID){
        	pos = i;
        	check = 1;
    }
 }
 	if(check ==0 ){
 		printf("\t\t\t Cannot find this student!\n");
 		return;
	}
	for(int i=pos;i<*pCount -1;i++){
			IDs[i] = IDs[i + 1];
			strcpy(names[i], names[i + 1]);
			genders[i] = genders[i + 1];
			dayAbsent[i] = dayAbsent[i+1]; 
	}
	*pCount--;
	printf("\t\t\t REMOVED!");
	printf("\t\t\t Enter to exit!");
}


//remove all student
void removeAllStudents(int* pCount){
	if (isEmpty(*pCount))
	{
		printf("\n\n\t\t\t\t     Sorry! The list is empty!\n");
		return;
	}
	*pCount=0;
	printf("\t\t\t REMOVED ALL STUDENTs");
	printf("\t\t\t Enter to exit!");
}
