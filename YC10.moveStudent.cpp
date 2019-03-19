void moveStudent(listst*&lst)
{
	char ID[10];
	int cla;
	int cla1;
	nodest*temp = new nodest;
	cout << "Input the student ID you want to move to another class: ";
	cin >> ID;
	do
	{
		cout << "Enter the class of that student(1. 18CLC1 -> 6. 18CLC6): ";
		cin >> cla;
	} while (cla > 6 && cla < 1 && cout << "We only have 6 classes!" << endl);
	int i = cla - 1;
	for (nodest *p = lst[i].head; p->next != NULL; p = p->next)
	{
		if (strcmp(p->next->data.id, ID) == 0)
		{
			cout << "Found student with ID " << ID << " in the class!" << endl;
			temp = p->next;
			p->next = p->next->next;
			while (p->next != NULL)
			{
				p->next->data.no -= 1;
				p = p->next;
			}
			break;
		}
		if (p->next->next == NULL)
		{
			cout << "Can't find student with ID " << ID << " in the class!" << endl;
			moveStudent(lst);
		}
	}
	do
	{
		cout << "Enter the class you want that student to move to(1. 18CLC1 -> 6. 18CLC6): ";
		cin >> cla1;
	} while (cla1 > 6 && cla1 < 1 && cout << "We only have 6 classes!" << endl);
	temp->data.no = lst[cla - 1].tail->data.no + 1;
	insertTail(lst[cla - 1], temp);
	saveStudent("Test.txt", lst[cla - 1]);
}
