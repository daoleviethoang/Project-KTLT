
struct att {
	char id[100];
	int a[11];
};
struct nodeat {
	att data;
	nodeat*next;
};
struct attth {
	char id[100];
	int a[10];
};
struct nodeatth {
	attth data;
	nodeatth*next;
};
void viewattendance(nodeat *l)
{
	cout << "Theory(0:absent, 1: present)" << endl;
	cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10  Week 11" << endl;
	for (nodeat *p = l; p != NULL; p = p->next)
	{
		cout << p->data.id << "    ";
		for (int i = 0; i < 11; i++)
		{
			cout << p->data.a[i] << "        ";
		}
		cout << endl;
	}
}
void viewattendanceth(nodeatth *l)
{
	cout << "Practice(0:absent, 1: present)" << endl;
	cout << "Student ID \t Week 01 \t Week 02 \t Week 03 \t Week 04 \t Week 05 \t Week 06 \t Week 07 \t Week 08 \t Week 09 \t Week 10" << endl;
	for (nodeatth *p = l; p != NULL; p = p->next)
	{
		cout << p->data.id;
		for (int i = 0; i < 10; i++)
		{
			cout << "\t" << p->data.a[i];
		}
	}
}
nodeat*createnodeat(att x)
{
	nodeat *p = new nodeat;
	p->next = NULL;
	p->data = x;
	return p;
}
void insertTail(nodeat *&head, att a)
{
	nodeat *blank = createnodeat(a);
	nodeat *current = new nodeat;
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
bool loadattendance(const char*file, nodeat *&l1, char b[])
{
	ifstream fin;
	fin.open(file);
	if (fin.fail())
		return false;
	fin.getline(b, 200, '\n');
	att a;
	while (fin.getline(a.id, 10, ','))
	{

		for (int i = 0; i < 11; i++)
		{
			fin >> a.a[i];
			fin.get();
		}


		insertTail(l1, a);
	}
	return true;
}
nodeatth*createnodeatth(attth x)
{
	nodeatth *p = new nodeatth;
	p->next = NULL;
	p->data = x;
	return p;
}
void insertTail(nodeatth *&head, attth a)
{
	nodeatth *blank = createnodeatth(a);
	nodeatth *current = new nodeatth;
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

bool loadattendanceth(const char*file, nodeatth *&l1th, char b[])
{
	ifstream fin;
	fin.open(file);
	if (fin.fail())
		return false;
	fin.getline(b, 200, '\n');
	attth a;
	while (fin.getline(a.id, 10, ','))
	{

		for (int i = 0; i < 10; i++)
		{
			fin >> a.a[i];
			fin.get();
		}


		insertTail(l1th, a);
	}
	return true;
}
void viewattendancelist()
{
	int cl;
	cout << "Choose the class you want to see attendance list " << endl;
	cout << "1. 18CLC1" << endl;
	cout << "2. 18CLC2" << endl;
	cout << "3. 18CLC3" << endl;
	cout << "4. 18CLC4" << endl;
	cout << "5. 18CLC5" << endl;
	cout << "6. 18CLC6" << endl;
	cin >> cl;
	system("cls");
	switch (cl)
	{
	case 1:
	{
		cout << "Choose the course you want to see attendance list " << endl;
		cout << "1. Programming Techniques" << endl;
		cout << "2. Introductory to Information Technology" << endl;
		cout << "3. Analytics B1" << endl;
		cout << "4. General Economic" << endl;
		cout << "5. Principles of Marxist and Lennist" << endl;
		int cr;
		cin >> cr;
		system("cls");
		switch (cr)
		{
		case 1:
		{
			nodeatth *l1th = new nodeatth;
			l1th = NULL;
			char bth[200];
			loadattendanceth("18CLC1-CTT003th.csv", l1th, bth);
			nodeat *l1 = new nodeat;
			l1 = NULL;
			char b[200];
			loadattendance("18CLC1-CTT003.csv", l1, b);
			cout << "The list attendance of Programming Techniques" << endl;
			viewattendance(l1);
			viewattendanceth(l1th);
		}
		}
	}
	}
}
