

#ifndef _YC16_H_
#define _YC16_H_

#include "string"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

struct date {
    int year;
    int month;
    int day;
};

struct time {
    int hour;
    int minute;
};

struct Courses {
    int no;
    string academicyearID;
    string semestersID;
    string couresID;
    string courseName;
    
    char id[100];
    char classn [100];
    char lecturer[100];
    date start;
    date end;
    char day[100];
    time start1;
    time end1;
    char room[100];
};

void enterCoursesEnd ( Courses &add );
void addCourses (Courses &a);
void enterStudentExist (Courses &edit, int n);
void editCourses(Courses a);

#endif 
