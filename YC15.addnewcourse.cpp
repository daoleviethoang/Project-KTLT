void addnewcourse(listcr &l, listst*&lst)
{
	course cr;
	cout << "Add new course" << endl;
	cr.no = l.tail->data.no + 1;
	cout << "Enter Course ID: ";
	cin >> cr.id;
	cout << "Enter Course Name: ";
	cin >> cr.name;
	cout << "Enter Class of Course: ";
	cin >> cr.classn;
	cout << "Enter Lecture Account: ";
	cin >> cr.lecture;
	cout << "Enter Day of Start Date: ";
	cin >> cr.start.day;
	cout << "Enter Month of Start Date: ";
	cin >> cr.start.month;
	cout << "Enter Year of Start Date: ";
	cin >> cr.start.year;
	cout << "Enter Day of End Date: ";
	cin >> cr.end.day;
	cout << "Enter Month of End Date: ";
	cin >> cr.end.month;
	cout << "Enter Year of End Date: ";
	cin >> cr.end.year;
	cout << "Enter the Day of Week the course take: ";
	cin >> cr.day;
	cout << "Enter the Start Hour: ";
	cin >> cr.start1.hour;
	cout << "Enter the Start Minute: ";
	cin >> cr.start1.minute;
	cout << "Enter the End Hour: ";
	cin >> cr.end1.hour;
	cout << "Enter the End Minute: ";
	cin >> cr.end1.minute;
	cout << "Enter the room of the Course: ";
	cin >> cr.room;


	//Tự động điền danh sách học sinh từ lớp sang môn học
	int i = cr.classn[5] - 1;
	init(cr.liststudent);
	nodest*pst = new nodest;
	pst = lst[i].head;
	while (pst->next == NULL)
	{
		insertTail(cr.liststudent, pst);
		pst = pst->next;
	}

	nodecr*p = createNode(cr);
	insertTail(l, p);
}
