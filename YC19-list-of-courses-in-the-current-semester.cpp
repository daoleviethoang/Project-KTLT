#include <iostream>
#include <fstream>
#include "string"
#include <stdlib.h>
using namespace std;

struct date {
    int year;
    int month;
    int day;
};

struct time {
    int hours;
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

void listAttendanceCourses ( ){
    Courses no;
    
    ifstream fin;
    fin.open ("Courses.txt");
    
    if (!fin.is_open()){
        cout <<"Can not open !" << endl;
        return ;
    }
    
    while (!fin.eof()){
        fin >> tmp.no;
        fin.ignore(100, ',');
        
        getline (fin,tmp.courseID,',');
        if (tmp.courseID == "") break;
        getline (fin,tmp.courseName,',');
        getline (fin,tmp.classID,',');
        getline (fin,tmp.lecture,',');
        fin >> tmp.start.day;
        fin.ignore(100, '/');
        fin >> tmp.start.month;
        fin.ignore(100, '/');
        fin >> tmp.start.year;
        fin.ignore(100, ',');
        
        fin >> tmp.end.day;
        fin.ignore(100, '/');
        fin >> tmp.end.month;
        fin.ignore(100, '/');
        fin >> tmp.end.year;
        fin.ignore(100, ',');
        
        getline (fin,tmp.day,',');
        
        fin >> tmp.start1.hour ;
        fin.ignore(100,':');
        fin >> tmp.start1.minute ;
        fin.ignore(100,'-');
        fin >> tmp.end1.hour ;
        fin.ignore(100,':');
        fin >> tmp.end1.minute ;
        fin.ignore(100,',');
   
        getline (fin,tmp.academicyearID,',');
        getline (fin,tmp.semestersID,',');
        
        getline (fin,tmp.room,',');
            
            cout << tmp.courseID<< ", ";
            cout << tmp.courseName<< ", ";
            cout << tmp.classID<< ", ";
            cout << tmp.lecture << ", ";
            cout << tmp.start.day << "/ ";
            cout << tmp.start.month << "/ ";
            cout << tmp.start.year<< ", ";
            cout << tmp.end.day << "/ ";
            cout << tmp.end.month << "/ ";
            cout << tmp.end.year<< ", ";
            cout << tmp.day<< ", ";
            cout << tmp.start1.hours<< ": ";
            cout << tmp.start1.minute<< ", ";
            cout << tmp.end1.hours<<"- ";
            cout << tmp.end1.minute<< ": ";
        
            cout << tmp.academicyearID ;
            cout << tmp.semestersID ;
            cout << tmp.room;
        
        
    }
    fin.close();
}

void listCourseSemester (){
    Courses tmp;
    
    
    ifstream fin;
    fin.open ("Courses.txt");
    if (!fin.is_open()){
        cout <<"Can not open !" << endl;
        return ;
    }
    
    while (!fin.eof()){
        
        fin >> tmp.no;
        fin.ignore(100, ',');
        
        getline (fin,tmp.courseID,',');
        if (tmp.courseID== "") break;
        getline (fin,tmp.courseName,',');
        getline (fin,tmp.classID,',');
        getline (fin,tmp.lecture,',');
        fin >> tmp.start.day;
        fin.ignore(100, '/');
        fin >> tmp.start.month;
        fin.ignore(100, '/');
        fin >> tmp.start.year;
        fin.ignore(100, ',');
        
        fin >> tmp.end.day;
        fin.ignore(100, '/');
        fin >> tmp.end.month;
        fin.ignore(100, '/');
        fin >> tmp.end.year;
        fin.ignore(100, ',');
        
        getline (fin,tmp.day,',');
        
        fin >> tmp.start1.hour ;
        fin.ignore(100,':');
        fin >> tmp.start1.minute ;
        fin.ignore(100,'-');
        fin >> tmp.end1.hours ;
        fin.ignore(100,':');
        fin >> tmp.end1.minute ;
        fin.ignore(100,',');
        
        getline (fin,tmp.academicyearID,' ');
        getline (fin,tmp.semestersID,' ');
        getline (fin,tmp.room,' ');
        
        cout << tmp.courseID<< ", ";
        cout << tmp.courseName<< ", ";
        
        cout << tmp.academicyearID<< " ";
        cout << tmp.semestersID << " ";

        
    }
    fin.close();
}
    

int main(int argc, const char * argv[]) {
   
    
    listAttendanceCourses ();
    listCourseSemester ();
    
}
