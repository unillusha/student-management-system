#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfunctions.h"

int count = 0;  // To keep track of number of students
struct  studentInfo st[500];

// Function to add student info
void add_student()
{
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

    count = count + 1;
}
// Function to find students by their first name
void findByFirstName()
{
    char temp[20];
    printf("Enter first name of the student\n");
    scanf("%s", temp);
    int c = 0;

    for (int j = 0; j < count; j++)
    {
        if (!strcmp(st[j].firstName, temp))
        {
            printf("Student information: \n");
            printf("First name: %s\n", st[j].firstName);
            printf("Last name: %s\n", st[j].lastName);
            printf("Address: %s\n", st[j].address);
            printf("Date of birth: %s\n", st[j].dob);
            printf("Mobile number: %s\n", st[j].mobile);
        }
    }
}

// Function to print the total number of students
void totalCount()
{
   printf("The total number of students: %d\n", count);
}

// Function to delete a Student
void deleteStudent()
{
    char temp[20];
    printf("Enter name of student you want to delete from the system: \n");
    scanf("%s", temp);

    for (int j = 0; j < count; j++)
    {
      if (temp == st[j].firstName)
      {
         for (int k = j; k < 499; k++)
         {
            st[k] = st[k + 1];
         }
         count--;
      }

    }
    printf("The student is removed from the system\n");
}

// Function to update student information
void updateStudent()
{
    int temp;
    printf("Enter first name of student\n");
    scanf("%s", &temp);
    for (int j = 0; j < count; j++)
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
               scanf("%s", st[j].address);
               break;
            case 4:
               printf("Enter the updated Date of birth : ");
               scanf("%s", st[j].dob);
               break;
            case 5:
               printf("Enter the updated Mobile number: ");
               scanf("%s", st[j].mobile);
               break;
            }
            printf("Records updated successfully");
        }

    }
}
