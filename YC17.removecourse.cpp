void removecourse(listcr &l)
{
	char ID[100];
	char cla[20];
	char check[10];
	int a = 0;
	int flag = 0;
	cout << "Remove a course!" << endl;
	cout << "Enter the Course ID of the Course you want to remove: ";
	cin >> ID;
	cout << "Enter the class of the Course you want to remove: ";
	cin >> cla;
	nodecr*curr = new nodecr;
	nodecr*prev = new nodecr;
	curr = l.head;
	prev = NULL;
	while (curr != NULL)
	{
		if (strcmp(l.head->data.id, ID) == 0 &&strcmp(cla,l.head->data.classn)==0)
		{
			cout << "Found the course with ID: " << ID <<" with the class: "<<cla<< endl;
			do
			{
			cout << "Do you want to remove this course(Yes/No): ";
			cin >> check;
			if (strcmp(check, "Yes") == 0)
			{
				l.head = l.head->next;
				delete curr;
				curr = l.head;
				while (curr!= NULL)
				{
					curr->data.no -= 1;
					curr = curr->next;
				}
				curr = l.head;
				flag = 1;
				a = 1;
			}
			else if (strcmp(check, "No") == 0)
			{
				return;
			}
			else cout << "You can only input Yes/No! Please input again!" << endl;
			} while (a == 0);
		
		}
		else if (strcmp(curr->data.id, ID) == 0&&strcmp(curr->data.classn,cla)==0)
		{
			cout << "Found the course with ID: " << ID << " with the class: " << cla << endl;
			do
			{
				cout << "Do you want to remove this course(Yes/No): ";
				cin >> check;
				if (strcmp(check, "Yes") == 0)
				{
					prev->next = curr->next;
					if (curr != l.tail)
						delete curr;
					else
					{
						l.tail = prev;
					}
					curr = prev->next;
					while (curr != NULL)
					{
						curr->data.no -= 1;
						curr = curr->next;
					}
					a = 1;
					curr = prev;
					flag = 1;
				}
				else if (strcmp(check, "No") == 0)
				{
					return;
				}
				else cout << "You can only input Yes/No! Please input again!" << endl;
			} while (a == 0);
		}
		prev = curr;
		curr = curr->next;
	}
	if (flag == 0)
		cout << "Can't find the course with ID: " << ID << " and class: " << cla;
	else cout << "Remove course successfully" << endl;
}
