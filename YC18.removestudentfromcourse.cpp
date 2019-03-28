void removestfromcourse(listcr &l)
{
	char ID[100];
	char IDst[20];
	char cla[10];
	char a[10];
	int check = 0;
	int flag = 0;
	int yes = 0;
	cout << "Remove student from a course!" << endl;
	nodecr*cr = new nodecr;
	nodest*curr = new nodest;
	nodest*prev = new nodest;
	cr = l.head;
	do
	{
		cout << "Enter the Course ID of the course you want to remove a student: ";
		cin >> ID;
		cout << "Enter the class of the course: ";
		cin >> cla;
		while (cr->next != NULL)
		{
			if (strcmp(cr->data.id, ID) == 0&&strcmp(cr->data.classn,cla)==0)
			{
				cout << "Find the course!!" << endl;
				flag = 1;
				curr = cr->data.liststudent.head;	
				prev = NULL;
				cout << "Enter the Student ID you want to remove: ";
				cin >> IDst;
				while (curr != NULL)
				{
					if (strcmp(curr->data.id, IDst) == 0)
					{
						cout << "Find the student with ID: "<<IDst<<" in the course" << endl;
						check = 1;
						do
						{
							cout << "Do you want to remove (Yes/No): ";
							cin >> a;
							if (strcmp(a, "Yes") == 0)
							{
								yes = 1;
								if (prev == NULL)
								{
									cr->data.liststudent.head = cr->data.liststudent.head->next;
									curr = cr->data.liststudent.head;
								}
								else
								{
									if (curr != cr->data.liststudent.tail)
									{
										prev = curr->next;
										curr = prev->next;
									}
									else
									{
										cr->data.liststudent.tail = prev;
										prev->next = NULL;
										curr = NULL;
									}
								}
								while (curr != NULL)
								{
									curr->data.no -= 1;
									curr = curr->next;
								}
								if (prev != NULL)
									curr = prev;
								else curr = cr->data.liststudent.head;
							}
							else if (strcmp(a, "No") == 0)
							{
								yes = 1;
							}
							else
							{
								yes = 0;
								cout << "You can only input Yes/No, please try again!" << endl;
							}
						} while (yes == 0);
					}
					prev = curr;
					curr = curr->next;
				}
				if (check == 0)
				{
					cout << "Can't find the student" << endl;
					return;
				}
			}
			cr = cr->next;
		}
	} while (flag == 0 && cout << "Can't find the course, Please input again!!" << endl);
	if (flag == 1)
		cout << "Remove student from the course successfully" << endl;
}
