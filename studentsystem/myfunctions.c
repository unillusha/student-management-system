#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfunctions.h"

#define MAX_NAME_SIZE (20)
#define MAX_BUFF_SIZE (128)

int count = 0;
struct  studentInfo st[500];
int studentCount = 0;  // To keep track of number of students

// Function to read file
int read_StudentDB (const char* fileName)
{
    char buff[MAX_BUFF_SIZE];

    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    int i = 0;
    int j = 0;

    while(fgets(buff, MAX_BUFF_SIZE, file))
    {

        // First name
        if (i == 0){
            strcpy(st[j].firstName, buff);
        }

        // Last name
        if (i == 1){
            strcpy(st[j].lastName, buff);
        }

        // Address
        if (i == 2){
            strcpy(st[j].address, buff);
        }

        // dob
        if (i == 3){
            strcpy(st[j].dob, buff);
        }

        // mobile
        if (i == 4){
            strcpy(st[j].mobile, buff);
        }

        st[j].flag = 1;

        i++;


        if (i%6 == 0){
            i = 0;
            j++;

        }
    }

    printf("total number of student = %d\n",j);
    studentCount = j;
    fclose(file);


}

// Function to write to file
int write_StudentDB (const char* fileName)
{
    char buff[MAX_BUFF_SIZE];

    FILE* file = fopen(fileName, "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    int i;
    for(i = 0; i < studentCount; i++)
    {
        if(st[i].flag == 1)
        {
            fprintf(file, "%s",st[i].firstName);
            fprintf(file, "%s",st[i].lastName);
            fprintf(file, "%s",st[i].address);
            fprintf(file, "%s",st[i].dob);
            fprintf(file, "%s",st[i].mobile);
            fprintf(file, "\n");
        }

    }

    fclose(file);

}

void print_st(int max)
{
    int i;
    for(i = 0; i < max; i++)
    {
        printf("%s",st[i].firstName);
        printf("%s",st[i].lastName);
        printf("%s",st[i].address);
        printf("%s",st[i].dob);
        printf("%s",st[i].mobile);
        printf("\n");
    }
}

// Function to add student info
void add_student(const char* fileName)
{
    FILE* file = fopen(fileName, "a"); // Open the file in append mode

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Add the Student's Details\n\n");
    printf("Enter the first name of the student\n");
    scanf("%s", st[count].firstName);
    printf("Enter the last name of the student\n");
    scanf("%s", st[count].lastName);
    printf("Enter the address of the student\n");
    scanf("%s", st[count].address);
    printf("Enter the date of birth (dd/mm/yyyy) of the student\n");
    scanf("%s", st[count].dob);
    printf("Enter the mobile number of the student\n");
    scanf("%s", st[count].mobile);

    // Write the new student information to the file
    fprintf(file, "%s\n%s\n%s\n%s\n%s\n\n", st[count].firstName, st[count].lastName, st[count].address, st[count].dob, st[count].mobile);

    count = count + 1;

    fclose(file); // Close the file
}
// Function to find students by their first name
void findByFirstName(const char* fileName)
{
    char temp[MAX_NAME_SIZE];
    printf("Enter first name of the student\n");
    scanf("%s", temp);

    FILE* file = fopen(fileName, "r");
    if (file == NULL)
        {
            printf("Error opening file.\n");
            return;
        }

    struct studentInfo student;

    // Read the file line by line
    while (fscanf(file, "%s %s %s %s %s", student.firstName, student.lastName, student.address, student.dob, student.mobile) == 5)
        {
        // Compare the first name
        if (strcmp(student.firstName, temp) == 0)
            {
                // Print the details of the student
                printf("Student information: \n");
                printf("First name: %s\n", student.firstName);
                printf("Last name: %s\n", student.lastName);
                printf("Address: %s\n", student.address);
                printf("Date of birth: %s\n", student.dob);
                printf("Mobile number: %s\n", student.mobile);

                fclose(file);
                return;
            }
        }
    printf("No student found with the given first name.\n");
    fclose(file);

}

// Function to print the total number of students
void totalCount(const char* fileName)
{
    int totalStudents = read_StudentDB(fileName);
    printf("The total number of students: %d\n", totalStudents);
}

// Function to delete a Student
void deleteStudent(const char* fileName)
{
    printf("OK\n");
    // Read student data from file
    read_StudentDB(fileName);
    print_st(studentCount);

    char temp[MAX_NAME_SIZE];
    char buff[MAX_NAME_SIZE];
    printf("Enter first name of student you would like to delete f the system: \n");
    scanf("%s", temp);

    // Find & mark specified student as deleted
    int j;
    for(j = 0; j<studentCount; j++)
    {


        strcpy(buff, st[j].firstName);
        buff[strlen(buff) - 1] = 0;
        if(strcmp(temp, buff)==0)
        {
            st[j].flag = 0; // marked for deletion
            printf("student has been deleted from the system \n");
        }
    }

    // Write the updated data back file
    write_StudentDB (fileName);

}

// Function to update student information
void updateStudent(const char* fileName)
{
    int i;
    read_StudentDB(fileName);
    print_st(studentCount);

    char temp[MAX_NAME_SIZE];
    char buff[MAX_NAME_SIZE];
    printf("Enter first name of student you would like to update from the system: \n");
    scanf("%s", temp);

    // Read the file line by line
    for (i = 0; i < studentCount; i++)
    {
        // Compare the first name
        strcpy(buff, st[i].firstName);
        buff[strlen(buff) - 1] = 0;
        if(strcmp(temp, buff)==0)
        {
            // Print the details of the student
            printf("Student information: \n");
            printf("1.First name: %s\n", st[i].firstName);
            printf("2.Last name: %s\n", st[i].lastName);
            printf("3.Address: %s\n", st[i].address);
            printf("4.Date of birth: %s\n", st[i].dob);
            printf("5.Mobile number: %s\n", st[i].mobile);

            int c;
            printf("Select the field to update (1-5): ");
            scanf("%d", &c);

            switch (c)
            {
                case 1:
                    printf("Enter the updated first name : ");
                    scanf("%s", st[i].firstName);
                    strcat(st[i].firstName, "\n");
                    break;
                case 2:
                    printf("Enter the updated last name : ");
                    scanf("%s", st[i].lastName);
                    strcat(st[i].lastName, "\n");
                    break;
                case 3:
                    printf("Enter the updated Address : ");
                    scanf("%s", st[i].address);
                    strcat(st[i].address, "\n");
                    break;
                case 4:
                    printf("Enter the updated Date of birth : ");
                    scanf("%s", st[i].dob);
                    strcat(st[i].dob, "\n");
                    break;
                case 5:
                    printf("Enter the updated Mobile number: ");
                    scanf("%s", st[i].mobile);
                    strcat(st[i].mobile, "\n");
                    break;
                } /* end switch */

                // Write the updated data back file
                write_StudentDB (fileName);
                break;

            } /* end if */


        } /* end for */

        if(i == studentCount)
        {
            printf("No student found with the given first name.\n");
        }

}
