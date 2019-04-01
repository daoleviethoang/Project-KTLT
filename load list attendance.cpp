struct att {
	char id[100];
	int a[11];
};
struct nodeat {
	att data;
	nodeat*next;
};
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
bool loadattendance(const char*file, nodeat *l1, char b[])
{
	ifstream fin;
	fin.open(file);
	if (fin.fail())
		return false;
	fin.getline(b, 200, '\n');
	att a;
	while (!fin.eof())
	{
		fin.getline(a.id, 10, ',');
		for (int i = 0; i < 11; i++)
		{
			fin >> a.a[i];
			fin.get();
		}


		insertTail(l1, a);
	}
	return true;
}
struct attth {
	char id[100];
	int a[10];
};
struct nodeatth {
	attth data;
	nodeatth*next;
};
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

bool loadattendanceth(const char*file, nodeatth *l1th, char b[])
{
	ifstream fin;
	fin.open(file);
	if (fin.fail())
		return false;
	fin.getline(b, 200, '\n');
	attth a;
	while (!fin.eof())
	{
		fin.getline(a.id, 10, ',');
		for (int i = 0; i < 10; i++)
		{
			fin >> a.a[i];
			fin.get();
		}


		insertTail(l1th, a);
	}
	return true;
}
void main()
{
	nodeatth *l1th = new nodeatth;
	l1th = NULL;
	char bth[200];
	loadattendanceth("18CLC1-CTT003th.csv", l1th, bth);
	nodeat *l1 = new nodeat;
	l1 = NULL;
	char b[200];
	loadttendance("18CLC1-CTT003.csv", l1, b);
}
