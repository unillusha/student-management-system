// student information system
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfunctions.h"

#define DBFILE ("/home/nillusha/Documents/GitHub/student-management-system/studentdb.txt")

// global variables
extern int studentCount;
extern struct  studentInfo st[500];

int main() {
    int performTask;
    //read_StudentDB("/home/nillusha/Documents/GitHub/student-management-system/studentdb.txt");
    //print_st(studentCount);
    //st[1].flag = 0;
    //write_StudentDB ("/home/nillusha/Documents/GitHub/student-management-system/studentdb1.txt");
    //return 0;

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
                add_student(DBFILE);
                break;
            case 2:
                findByFirstName(DBFILE);
                break;
            case 3:
                totalCount(DBFILE);
                break;
            case 4:
                deleteStudent(DBFILE);
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
