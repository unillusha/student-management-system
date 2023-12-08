#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfunctions.h"

int i = 0;  // To keep track of number of students
struct  studentInfo st[500];

// Function to add student info
void add_student()
{
    printf("Add the Student's Details\n\n");
    printf("Enter the first name of the student\n");
    scanf("%s", st[i].firstName);
    printf("Enter the last name of the student\n");
    scanf("%s", st[i].lastName);
    printf("Enter the address of the student\n");
    scanf("%s", st[i].address);
    printf("Enter the date of birth (dd/mm/yyyy) of the student\n");
    scanf("%d", st[i].dob);
    printf("Enter the mobile number of the student\n");
    scanf("%d", st[i].mobile);

    i = i + 1;
}
// Function to find students by their first name
void findByFirstName()
{
    char temp[20];
    printf("Enter first name of the student\n");
    scanf("%s", temp);
    int c = 0;

    for (int j = 1; j <= i; j++)
    {
        if (!strcmp(st[j].firstName, temp))
        {
            printf("Student information: \n");
            printf("First name: %s\n", st[i].firstName);
            printf("Last name: %s\n", st[i].lastName);
            printf("Address: %s\n", st[i].address);
            printf("Date of birth: %s\n", st[i].dob);
            printf("Mobile number: %s\n", st[i].mobile);
        }
    }
}

// Function to print the total number of students
void totalCount()
{
   printf("The total number of students: %d\n", i);
}

// Function to delete a Student
void deleteStudent()
{
    char temp[20];
    printf("Enter name of student you want to delet from the system: \n");
    scanf("%s", temp);

    for (int j = 1; j <= i; j++)
    {
      if (temp == st[j].firstName)
      {
         for (int k = j; k < 499; k++)
         {
            st[k] = st[k + 1];
         }
         i--;
      }

    }
    printf("The student is removed from the system\n");
}
// Function to update student information
void updateStudent()
{
    int temp;
    printf("Enter first name of student\n");
    scanf("%d", &temp);
    for (int j = 0; j < i; j++)
    {
        if (temp == st[j].firstName)
        {
         printf("1. First Name\n"
                "2. Last Name\n"
                "3. Address\n"
                "4. Date of birth\n"
                "5. Mobile number\n");
         int c;
         scanf("%d", &c);
         switch(c) {
            case 1:
               printf("Enter the updated first name : ");
               scanf("%s", st[j].firstName);
               break;
            case 2:
               printf("Enter the updated last name : ");
               scanf("%s", st[j].lastName);
               break;
            case 3:
               printf("Enter the updated Address : ");
               scanf("%d", st[i].address);
               break;
            case 4:
               printf("Enter the updated Date of birth : ");
               scanf("%f", st[i].dob);
               break;
            case 5:
               printf("Enter the updated Mobile number: ");
               scanf("%d", st[i].mobile);
               break;
            }
            printf("Records updated successfully");
        }

    }
}
