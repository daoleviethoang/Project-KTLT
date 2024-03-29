#include "test.h"

void init(listst &l)
{
	l.head = l.tail = NULL;
}
void init(listcr &l)
{
	l.head = l.tail = NULL;
}
void init(listpw &l)
{
	l.head = l.tail = NULL;
}
nodest *createNode(student x)
{
	nodest *p = new nodest;
	p->next = NULL;
	p->data = x;
	return p;
}
nodecr *createNode(course x)
{
	nodecr *p = new nodecr;
	p->next = NULL;
	p->data = x;
	return p;
}
void insertTail(listst &l, nodest *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void insertTail(listcr &l, nodecr *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
bool loadStudent(const char *path, listst &l, char b[])
{
	ifstream fin;
	fin.open(path);
	if (fin.fail())
		return false;
	init(l);
	student st;
	fin.getline(b, 200, '\n');
	while (fin >> st.no)
	{
		fin.get();
		fin.getline(st.id, 9, ',');
		fin.getline(st.lastname, 101, ',');
		fin.getline(st.firstname, 101, ',');
		fin.getline(st.sex, 10, ',');
		fin.getline(st.birth.month, 5, '-');
		fin.getline(st.birth.day, 5, '-');
		fin.getline(st.birth.year, 5, '\n');
		nodest *p = createNode(st);
		insertTail(l,p);
	}
	fin.close();
	return true;
}
bool saveStudent(const char *path, listst &l, char b[])
{
	ofstream fout;
	fout.open(path);
	if (fout.fail())
		return false;
	fout << b << endl;
	for (nodest *p = l.head; p!=NULL;p=p->next)
	{
		student st= p->data;
		if (st.no < 0) break;
		fout << st.no << "," << st.id << "," << st.lastname << "," << st.firstname << "," << st.sex << "," << st.birth.month << "/" << st.birth.day << "/" << st.birth.year << endl;
	}
	fout.close();
	return true;
}

bool loadCourse(const char *path, listcr &l, char b[])
{
	ifstream fin;
	fin.open(path);
	if (fin.fail())
		return false;
	init(l);
	fin.getline(b, 200, '\n');
	course cr;
	while (fin >> cr.no)
	{
		fin.get();
		fin.getline(cr.id, 10, ',');
		fin.getline(cr.name, 100, ',');
		fin.getline(cr.classn, 7, ',');
		fin.getline(cr.lecture, 100, ',');
		fin.getline(cr.start.day, 5, '/');
		fin.getline(cr.start.month, 5, '/');
		fin.getline(cr.start.year, 5, ',');
		fin.getline(cr.end.day, 5, '/');
		fin.getline(cr.end.month, 5, '/');
		fin.getline(cr.end.year, 5, ',');
		fin.getline(cr.day,10, ',');
		fin.getline(cr.start1.hour, 3, ':');
		fin.getline(cr.start1.minute, 3, ',');
		fin.getline(cr.end1.hour, 6, ':');
		fin.getline(cr.end1.minute, 6, ',');
		fin.getline(cr.room, 10, '\n');
		nodecr *p = createNode(cr);
		insertTail(l, p);
	}
	fin.close();
	return true;
}

bool saveCourse(const char *path, listcr &l, char b[])
{
	ofstream fout;
	fout.open(path);

	if (fout.fail())
		return false;

	int i = 0;
	fout << b << endl;
	for (nodecr *p = l.head; p != NULL; p = p->next)
	{
		course cr = p->data;
		if (cr.no < 0) break;
		fout << cr.no << "," << cr.id << "," << cr.name << "," << cr.classn << "," << cr.lecture << "," << cr.start.month << "/" << cr.start.day << "/" << cr.start.year << ',' << cr.end.month << "/" << cr.end.day << "/" << cr.end.year << ',' << cr.day << ',' << cr.start1.hour << ':' << cr.start1.minute << ',' << cr.end1.hour << ':' << cr.end1.minute << ',' << cr.room << endl;
	}
	fout.close();
	return true;
}
nodepw *createNode(password x)
{
	nodepw *p = new nodepw;
	p->next = NULL;
	p->data = x;
	return p;
}
void insertTail(listpw &l, nodepw *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
bool loadPassword(const char *path, listpw &l, char b[])
{
	ifstream fin;
	fin.open(path);
	if (fin.fail())
		return false;
	init(l);
	password pw;
	fin.getline(b, 200, '\n');
	while (fin >> pw.no)
	{
		fin.get();
		fin.getline(pw.user, 15, ',');
		fin.getline(pw.pass, 15, '\n');
		nodepw *p = createNode(pw);
		insertTail(l, p);
	}
	fin.close();
	return true;
}
bool savePassword(const char *path, listpw &l, char b[])
{
	ofstream fout;
	fout.open(path);
	if (fout.fail())
		return false;
	fout << b << endl;
	for (nodepw *p = l.head; p != NULL; p = p->next)
	{
		password pw = p->data;
		if (pw.no < 0) break;
		fout << pw.no << "," << pw.user << "," << pw.pass;
	}
	fout.close();
	return true;
}

void staffmenu()
{
	cout << "Staffmenu: " << endl;
	cout << "1: class" << endl;
	cout << "2: course" << endl;
	cout << "3: scoreboard" << endl;
	cout << "4: attendance List" << endl;
	cout << "5: logout" << endl;
	int s;
	cout << "Let's choose the function you want: " << endl;
	cin >> s;
	switch (s)
	{
	case 1: {break; };
	case 2: {break; };
	case 3: {break; };
	case 4: {break; };
	case 5: {break; };
	default:
		system("cls");
		cout << "Incorrect,please enter again! " << endl;
		system("cls");
		staffmenu();
	}
}

void lecturermenu()
{
	cout << "Lecturemenu: " << endl;
	cout << "1: managestudent" << endl;
	cout << "2: lessonplan" << endl;
	cout << "3: research" << endl;
	cout << "4: logout" << endl;
	int s;
	cout << "Let's choose the function you want: " << endl;
	cin >> s;
	switch (s)
	{
	case 1: {break; };
	case 2: {break; };
	case 3: {break; };
	case 4: {break; };
	default:
		system("cls");
		cout << "Incorrect,please enter again! " << endl;

		lecturermenu();
	}
}

void studentmenu(listpw pw,char y[],listst st)
{
	for (nodest *p=st.head;p!=NULL;p=p->next)
	{
		if (strcmp(y,p->data.id)==0)
			cout << p->data.no << endl <<p->data.id 
			<< endl<< p->data.lastname <<" "
			<< p->data.firstname << endl <<p->data.sex
			<< endl <<p->data.birth.month << "/"
			<< p->data.birth.day<< "/" << p->data.birth.year << endl;
	}
	cout << "Studentmenu: " << endl;
	cout << "1: study" << endl;
	cout << "2: dohomework" << endl;
	cout << "3: preparelesson" << endl;
	cout << "4: logout" << endl;
	int s;
	cout << "Let's choose the function you want: " << endl;
	cin >> s;
	switch (s)
	{
	case 1: {break; };
	case 2: {break; };
	case 3: {break; };
	case 4: {
		menu(pw,st);
		break; };

	default:
		system("cls");
		cout << "Incorrect,please enter again! " << endl;

		studentmenu(pw,y,st);
	}

}
int login(listpw pw,char y[],listst st)
{
	char user[9];
	char password[50];
	int index = 0;
	do
	{
		if (index == 1) cout << "Please, Enter again" << endl;
		index = 0;
		cout << "username: ";
		cin >> user;
		cout << "password: ";
		cin >> password;
		nodepw *lpw = pw.head;
		while (lpw != NULL)
		{
			if (strcmp(user,lpw->data.user)==0 && strcmp(password ,lpw->data.pass)==0)
			{
				strcpy(y,user);
				if (user[0] < 'A')
					return 3;
				else if (strcmp(user, "admin") == 0)
					return 1;
				else
					return 2;
			}
			else index = 1;
			lpw = lpw->next;
		}
	} while (index == 1);
}


void menu(listpw pw,listst st)
{
	cout << "1: login" << endl;
	cout << "2: exit" << endl;
	int x;
	int x1;
	cout << "Please enter " << endl;
	cin >> x;
	char y[11];
	if (x == 1)
	{
		x1 = login(pw,y,st);
		if (x1 == 1)
		{
			system("cls");
			staffmenu();

		}
		if (x1 == 2)
		{
			system("cls");
			lecturermenu();

		}
		if (x1 == 3)
		{
			system("cls");
			studentmenu(pw,y,st);

		}
	}
	else if (x == 2)
	{
		cout << "Have a nice day!" << endl;
		system("pause");
		exit(0);

	}
	else
	{
		system("cls");
		cout << "Invalid,please enter again!" << endl;

		menu(pw,st);
	}
}