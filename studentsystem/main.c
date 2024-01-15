// student information system
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "myfunctions.h"

//int i = 0;

int main() {
    int performTask;
    while(1)
    {
        printf("Enter the task that you want to perform\n");
        printf("1. Add a new Student Detail\n");
        printf("2. Find the details of a Student using the Name\n");
        printf("3. Find Total number of Students\n");
        printf("4. Delete the student's information\n");
        printf("5. Update the student's information\n");
        printf("6. Exit\n");
        scanf("%d", &performTask);

        switch (performTask)
        {
            case 1:
                add_student("/home/nillusha/Documents/GitHub/student-management-system/studentdb.txt");
                break;
            case 2:
                findByFirstName("/home/nillusha/Documents/GitHub/student-management-system/studentdb.txt");
                break;
            case 3:
                totalCount();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                updateStudent();
                break;
            case 6:
                exit(0);
                break;
            default:
                exit(0);

        }
    }
    return 0;
}
