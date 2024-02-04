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
    char dob[20];
    char mobile[20];
    int flag;
};

// Declare function prototypes
extern int count;  // Declare i as extern to avoid multiple definitions

int read_StudentDB(const char* fileName);
int write_StudentDB (const char* fileName);
void print_st(int max);
void add_student(const char* fileName);
void findByFirstName(const char* fileName);
void totalCount(const char* fileName);
void deleteStudent(const char* fileName);
void updateStudent(const char* fileName);

#endif // MYFUNCTIONS_H_INCLUDED
