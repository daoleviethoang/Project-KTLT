#include <fstream>
using namespace std;
bool saveattendance(const char*file, nodeat *l1)
{
	ofstream fout;
	fout.open(file);
	if (fout.fail())
		return false;
	fout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10  Week 11" << endl;

	for (nodeat *p = l1; p != NULL; p = p->next)
	{
		fout << p->data.id << ",";
		for (int i = 0; i < 11; i++)
		{
			fout << p->data.a[i] << ",";
		}
		fout << endl;
	}
	return true;
}
bool saveattendanceth(const char*file, nodeatth *l1th)
{
	ofstream fout;
	fout.open(file);
	if (fout.fail())
		return false;
	fout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10  Week 11" << endl;

	for (nodeatth *p = l1th; p != NULL; p = p->next)
	{
		fout << p->data.id << ",";
		for (int i = 0; i < 11; i++)
		{
			fout << p->data.a[i] << ",";
		}
		fout << endl;
	}
	return true;
}