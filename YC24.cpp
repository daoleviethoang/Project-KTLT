#include <iostream>
#include <fstream>
using namespace std;
struct score {
	char id[100];
	int a[4];
};
struct nodesc {
	score data;
	nodesc*next;
};
nodesc*createnodesc(score x)
{
	nodesc *p = new nodesc;
	p->next = NULL;
	p->data = x;
	return p;
}
void insertTail(nodesc *&head, score a)
{
	nodesc *blank = createnodesc(a);
	nodesc *current = new nodesc;
	if (head == NULL)
	{
		head = blank;
	}
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = blank;
	}
}
bool loadscoreboard(const char*file, nodesc *&l1, char b[])
{
	ifstream fin;
	fin.open(file);
	if (fin.fail())
		return false;
	fin.getline(b, 200, '\n');
	score a;
	while (fin.getline(a.id, 10, ','))
	{

		for (int i = 0; i < 4; i++)
		{
			fin >> a.a[i];
			fin.get();
		}


		insertTail(l1, a);
	}
	return true;
}
void viewscoreboard(nodesc *l)
{
	
	cout << "Student ID  Midterm  Final  Lab  Bonus" << endl;
	for (nodesc *p = l; p != NULL; p = p->next)
	{
		cout << p->data.id << "       ";
		for (int i = 0; i < 4; i++)
		{
			cout << p->data.a[i] << "       ";
		}
		cout << endl;
	}
}
void main()
{
	nodesc *l1 = new nodesc;
	l1 = NULL;
	char b[200];
	loadscoreboard("18CLC1-CTT008-score.csv", l1, b);
	viewscoreboard(l1);
}