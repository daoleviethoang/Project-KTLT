void moveStudent(listst*&lst, listallst &last, listallstsave &lasts)
{
	char ID[10];
	int cla;
	int cla1;
	int flag = 0;
	nodest*temp = new nodest;
	do
	{
		cout << "Input the student ID you want to move to another class: ";
		cin >> ID;
		do
		{
			cout << "Enter the class of that student (1 -> " << listn() << ") \n " << outputClass(last);
			cin >> cla;
		} while (cla > listn() && cla < 1 && cout << "We only have " << listn() << " classes!" << endl);
		int i = cla - 1;
		for (nodest *p = lst[i].head; p != NULL; p = p->next)
		{
			if (strcmp(lst[i].head->data.id, ID) == 0)
			{
				cout << "Found student with ID " << ID << " in the class!" << endl;
				temp = lst[i].head;
				lst[i].head = lst[i].head->next;
				while (p->next != NULL)
				{
					p->next->data.no -= 1;
					p = p->next;
				}
				break;
			}
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
				flag = 1;
				break;
			}
			if (p->next->next == NULL)
			{
				cout << "Can't find student with ID " << ID << " in the class!" << endl;
				flag = 0;
			}
		}
	} while (flag == 0);
	do
	{
		do
		{
			cout << "Enter the class you want that student to move to(1 -> " << listn() << ") \n " << outputClass(last);
			cin >> cla1;
		} while (cla1 > listn() && cla1 < 1 && cout << "We only have " << listn() << " classes!" << endl);
	} while ((cla1 == cla) && cout << "Opps, Please not enter 2 class same " << endl);
	temp->data.no = lst[cla1 - 1].tail->data.no + 1;
	temp->next = NULL;
	insertTail(lst[cla1 - 1], temp);
	int index = 0;
	for (nodeallstsave *t = lasts.head; t != NULL; t = t->next)
	{
		index++;
		if (index == cla)
		{
			saveStudent(t, lst[cla - 1]);
		}
		if (index == cla1)
		{
			saveStudent(t, lst[cla1 - 1]);
		}
	}
}
