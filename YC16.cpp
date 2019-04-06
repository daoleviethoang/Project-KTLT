#include "YC16.h"
//coursesID , academicyearID va semestersID
bool remove_Course(Courses &tmp, const char * path)
{
    string AcademicyearID ;
    cout << "Remove AcademicyearID : ";
    cin >> AcademicyearID;
    
    string courseID ;
    cout << "Remove courseID : ";
    cin >> courseID ;
    
    string semestersID ;
    cout << "Remove semestersID : ";
    cin >> semestersID;
    
    ifstream fin;
    ofstream fout;
    fin.open (path);
    if (!fin.is_open())
        return false;
    fout.open("temp.txt", ofstream::out);
    if (!fout.is_open())
        return false;
    while (!fin.eof()){
        fin >> tmp.no;
        fin.ignore(100, ',');
        
        getline (fin,tmp.courseID,',');
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
        
        getline (fin,tmp.dayofweek,',');
        
        fin >> tmp.start1.hours ;
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
        
        
        
        if ((AcademicyearID != tmp.academicyearID) && (courseID != tmp.courseID) && (semestersID != tmp.semestersID))
        {
            cout << "Remove to one courses :" << endl;
            
            enterCoursesEnd(tmp);
            
            fout << tmp.stt << ",";
            
            fout << tmp.courseID<< ",";
            fout << tmp.courseName << ",";
            fout << tmp.classID<< ",";
            fout << tmp.lecture << ",";
            fout << tmp.start.day << "/";
            fout << tmp.start.month << "/";
            fout << tmp.start.year<< ",";
            fout << tmp.end.day << "/";
            fout << tmp.end.month << "/";
            fout << tmp.end.year<< ",";
            fout << tmp.day<< ",";
            fout << tmp.start1.hour<< ":";
            fout << tmp.start1.minute<< ",";
            fout << tmp.end1.hour<<"-";
            fout << tmp.end1.minute<< ":";
            
            fout << tmp.academicyearID ;
            fout << tmp.semestersID ;
            fout << tmp.room;
        }
    }
    
    fout.close();
    fin.close();
    remove (path);
    rename ("temp.txt",path);
    return true ;
}

void enterCoursesEnd ( Courses &add ){
    cout << "No : ";
    cin >> add.no;
    cout << "AcademicyearID : ";
    cin >> add.academicyearID;
    cout << "SemestersID : ";
    cin >> add.semestersID;
    cout << "CourseID : ";
    cin >> add.courseID;
    cout << "ClassID : ";
    cin >> add.classID;
    cout << "Lecture name : ";
    cin >> add.lecture;
    cout << "Start Date : ";
    cin >> add.start.day;
    cin >> add.start.month;
    cin >> add.start.year;
    cout << "End Date: ";
    cin >> add.end.day;
    cin >> add.end.month;
    cin >> add.end.year;
    cout << "Day of week : ";
    cin >> add.day;
    cout << "Start Time : ";
    cin >> add.start1.hour;
    cin >> add.start.minute;
    cout << "End Time";
    cin >> add.end1.hour;
    cin >> add.end1.minute;
    cout << "Room : ";
    cin >> add.room;
}


void addCourses (Courses &a)
{
    string AcademicyearID ;
    cout << "Add AcademicyearID : ";
    cin >> AcademicyearID;
    
    string courseID ;
    cout << "Add courseID : ";
    cin >> courseID ;
    
    ifstream fin;
    ofstream fout;
    fin.open("Courses.txt");
    if (!fin.is_open())
        return;
    fout.open ("Courses.txt", ios::app);
    if (!fout.is_open())
        return;
    while (!fin.eof())
    {
        //
        
        fin >> a.stt;
        fin.ignore(100, ',');
        
        getline (fin,a.courseID,',');
        getline (fin,a.courseName,',');
        getline (fin,a.classID,',');
        getline (fin,a.lecture,',');
        fin >> a.start.day;
        fin.ignore(100, '/');
        fin >> a.start.month;
        fin.ignore(100, '/');
        fin >> a.start.year;
        fin.ignore(100, ',');
        
        fin >> a.end.day;
        fin.ignore(100, '/');
        fin >> a.end.month;
        fin.ignore(100, '/');
        fin >> a.end.year;
        fin.ignore(100, ',');
        
        getline (fin,a.day,',');
        
        fin >> a.start1.hour ;
        fin.ignore(100,':');
        fin >> a.start1.minute ;
        fin.ignore(100,'-');
        fin >> a.end1.hour ;
        fin.ignore(100,':');
        fin >> a.end1.minute ;
        fin.ignore(100,',');
        
        getline (fin,a.academicyearID,',');
        getline (fin,a.semestersID,',');
        
        getline (fin,a.room,',');
        
        if ((AcademicyearID == a.academicyearID) && (courseID == a.courseID) )
        {
            cout << "You entered the wrong";
            return ;
        }
        
    }
    cout << "Add to one courses :" << endl;
    enterCoursesEnd(a);
    
    fout << a.stt << ",";
    
    fout << a.courseID<< ",";
    fout << a.courseName << ",";
    fout << a.classID<< ",";
    fout << a.lecture << ",";
    fout << a.start.day << "/";
    fout << a.start.month << "/";
    fout << a.start.year<< ",";
    fout << a.end.day << "/";
    fout << a.end.month << "/";
    fout << a.end.year<< ",";
    fout << a.dayofweek<< ",";
    fout << a.start1.hour<< ":";
    fout << a.start1.minute<< ",";
    fout << a.end1.hours<<"-";
    fout << a.end1.minute<< ":";
    
    
    fout << a.academicyearID ;
    fout << a.semestersID ;
    fout << a.room;
    
    fout.close();
    fin.close();
    
}

void enterStudentExist (Courses &edit, int n){
    switch (n) {
            
        case 1:
            cout << "STT : ";
            cin >> edit.no;
            break;
        case 2:
            cout << "CourseID : ";
            cin >> edit.courseID;
            break;
        case 3:
            cout << "Courses name : ";
            cin >> edit.courseName;
            break;
        case 4:
            cout << "Class ID : ";
            cin >> edit.classID;
            break;
        case 5:
            cout << "LetureName : ";
            cin >> edit.lecture ;
            break;
        case 6:
            cout << "Start Day : "<< endl;
            cout << "Day : ";
            cin >> edit.start.day;
            cout << "Month : ";
            cin >> edit.start.month;
            cout << "Year : ";
            cin >> edit.start.year;
            break;
        case 7:
            cout << "End Day : "<< endl;
            cout << "Day : ";
            cin >> edit.end.day;
            cout << "Month : ";
            cin >> edit.end.month;
            cout << "Year : ";
            cin >> edit.end.year;
            break;
        case 8:
            cout << "Day of week : ";
            cin >> edit.day;
            break;
        case 9:
            cout << "AcademicyearID :";
            cin  >> edit.academicyearID;
            break;
        case 10:
            cout << "Semesters ID :";
            cin  >> edit.semestersID;
            break;
        case 11:
            cout << "Room :";
            cin  >> edit.room;
            break;
            
        default:
            cout << "you enter wrong ";
            break;
    }
    
}

void editCourses(Courses a){
    cout << "Choose courses you change : ";
    
    string AcademicyearID ;
    cout << "Add AcademicyearID : ";
    cin >> AcademicyearID;
    
    string courseID ;
    cout << "Add courseID : ";
    cin >> courseID ;
    
    ifstream fin;
    ofstream fout;
    fin.open("Courses.txt");
    if (!fin.is_open())
        return;
    fout.open("output.txt");
    if (!fout.is_open())
        return;
    int n;
    while (!fin.eof()){
        fin >> a.no;
        fin.ignore(100, ',');
        
        getline (fin,a.courseID,',');
        getline (fin,a.courseName,',');
        getline (fin,a.classID,',');
        getline (fin,a.lectureName,',');
        fin >> a.start.day;
        fin.ignore(100, '/');
        fin >> a.start.month;
        fin.ignore(100, '/');
        fin >> a.start.year;
        fin.ignore(100, ',');
        
        fin >> a.end.day;
        fin.ignore(100, '/');
        fin >> a.end.month;
        fin.ignore(100, '/');
        fin >> a.end.year;
        fin.ignore(100, ',');
        
        getline (fin,a.dayofweek,',');
        
        fin >> a.start1.hours ;
        fin.ignore(100,':');
        fin >> a.start1.minute ;
        fin.ignore(100,'-');
        fin >> a.end1.hour ;
        fin.ignore(100,':');
        fin >> a.end1.minute ;
        fin.ignore(100,',');
        
        getline (fin,a.academicyearID,',');
        getline (fin,a.semestersID,',');
        
        getline (fin,a.room,',');
        
        
        
        if ((AcademicyearID == a.academicyearID) && (courseID == a.courseID))
        {
            while(true)
            {
                cout << "Have a student choose option or 0 exit:";
                cin >> n;
                if (n == 0)
                    break;
                enterCoursesEnd (a);
            }
            fout << a.stt << ",";
            
            fout << a.courseID<< ",";
            fout << a.courseName << ",";
            fout << a.classID<< ",";
            fout << a.lecture << ",";
            fout << a.start.day << "/";
            fout << a.start.month << "/";
            fout << a.start.year<< ",";
            fout << a.end.day << "/";
            fout << a.end.month << "/";
            fout << a.end.year<< ",";
            fout << a.day<< ",";
            fout << a.start1.hour<< ":";
            fout << a.start1.minute<< ",";
            fout << a.end1.hour<<"-";
            fout << a.end1.minute<< ":";
            
            fout << a.academicyearID ;
            fout << a.semestersID ;
            fout << a.room;
            
        }
        else
        {
            cout << "You entered the wrong ! ";
        }
        fout.close();
        fin.close();
    }
}
