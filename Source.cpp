#include "test.h"
void main()
{
	listst l;
	student st;
	listcr n;
	course cr;
	char a[200];
	char b[200];
	listpw list;
	char c[100];
	int k = loadPassword("password.csv", list, c);
	if (k)
	{
		k = savePassword("outputCLC1.csv", list, c);
		if (k)
		{
			cout << "Load and save file success full" << endl;
		}
	}
	int h = loadStudent("18CLC1.csv", l, b);
	if (h)
	{
		h = saveStudent("outputCLC1.csv", l, b);
		if (h)
		{
			cout << "Load and save file success full" << endl;
		}
	}

	int z = loadCourse("CoursesCLC1.csv", n, a);
	if (z)
	{
		z = saveCourse("outputcourseCLC1.csv", n, a);
		if (z)
		{
			cout << "Load and save file success full";
		}
	}
	else cout << "Can't load data";
	menu(list,l);
	_getch();
}