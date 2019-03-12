void addnewstudent(listst &l, listpw &lpw)
{
	student st;
	cout << "Add new student to a class" << endl;
	st.no = l.tail->data.no + 1;
	cout << "Enter ID: ";
	cin >> st.id;
	cin.get();
	cout << "Enter Lastname: ";
	cin.getline(st.lastname, '/n');
	cout << "Enter Firstname: ";
	cin >> st.firstname;
	do
	{
		cout << "Enter gender(Male/Female): ";
		cin >> st.sex;
	} while ((strcmp(st.sex, "Male") != 0 && strcmp(st.sex, "Female") != 0) && cout << "You can only enter Male/Female");
	cout << "Enter day of DOB: ";
	cin >> st.birth.day;
	cout << "Enter month of DOB: ";
	cin >> st.birth.month;
	cout << "Enter year of DOB: ";
	cin >> st.birth.year;
	nodest*p = createNode(st);
	insertTail(l, p);

	password pa;
	pa.no = st.no;
	strcpy(pa.id, st.id);
	strcpy(pa.user, st.id);
	strcpy(pa.pass, st.birth.day);
	strcat(pa.pass, st.birth.month);
	strcat(pa.pass, st.birth.year);
	nodepw*pw = createNode(pa);
	insertTail(lpw, pw);
}