#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <cstdlib>
using namespace std;
struct date {
	char day[100];
	char month[100];
	char year[100];
};
struct student {
	int no;
	char id[100];
	char lastname[100];
	char firstname[100];
	char sex[100];
	date birth;
};
struct time {
	char hour[5];
	char minute[5];
};
struct course
{
	int no;
	char id[100];
	char name[100];
	char classn[100];
	char lecture[100];
	date start;
	date end;
	char day[100];
	time start1;
	time end1;
	char room[100];
};
struct nodest
{
	student data;
	nodest *next;
};
struct listst
{
	nodest *head;
	nodest *tail;
};
struct nodecr
{
	course data;
	nodecr *next;
};
struct listcr
{
	nodecr *head;
	nodecr *tail;
};
struct password
{
	int no;
	char id[100];
	char user[100];
	char pass[100];
};
struct nodepw
{
	password data;
	nodepw *next;
};
struct listpw
{
	nodepw *head;
	nodepw *tail;
};

void init(listst &l);
nodest *createNode(student x);
nodecr *createNode(course x);
void insertTail(listcr &l, nodecr *p);
void insertTail(listst &l, nodest *p);
bool loadStudent(const char *path, listst &l,	char b[]);
bool saveStudent(const char *path, listst &l, char b[]);
bool loadCourse(const char *path, listcr &l, char b[]);
bool saveCourse(const char *file, listcr &l, char b[]);
void menu(listpw pw,listst st);
bool loadPassword(const char *path, listpw &l, char b[]);
bool savePassword(const char *path, listpw &l, char b[]);