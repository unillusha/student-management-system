#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure
struct studentInfo
{
    char firstName[20];
    char lastName[20];
    char address[20];
    int dob[8];
    int mobile[10];
};

// Declare function prototypes
extern int i;  // Declare i as extern to avoid multiple definitions

void add_student();
void findByFirstName();
void totalCount();
void deleteStudent();
void updateStudent();

#endif // MYFUNCTIONS_H_INCLUDED
