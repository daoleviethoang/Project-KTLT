void editstudent(listst &l)
{
	char ID[100];
	int check;
	char temp[100];
	cout << "Edit an existing student" << endl;
	cout << "Input the student ID of the student";
	cin >> ID;
	nodest* head = l.head;
	nodest*current = head;
	while (current != l.tail)
	{
		if (strcmp(current->data.id, ID) == 0)
		{
			do
			{
				cout << "Please input the one you want to edit: " << endl;
				cout << "1. Edit Student ID" << endl;
				cout << "2. Edit Lastname" << endl;
				cout << "3. Edit Firstname" << endl;
				cout << "4. Edit Gender" << endl;
				cout << "5. Edit D.O.B" << endl;
				cout << "6. Done" << endl;
				cin >> check;
				switch (check)
				{
				case 1:
				{
					cout << "Input new Student ID: ";
					cin >> temp;
					strcpy(current->data.id, temp);
					cout << "DONE" << endl;
					break;
				}
				case 2:
				{
					cin.get();
					cout << "Enter new Lastname: ";
					cin.getline(temp, '/n');
					strcpy(current->data.lastname, temp);
					cout << "DONE" << endl;
					break;
				}
				case 3:
				{
					cout << "Enter new Firstname: ";
					cin >> temp;
					strcpy(current->data.firstname, temp);
					cout << "DONE" << endl;
					break;
				}
				case 4:
				{
					do
					{
						cout << "Enter new gender(Male/Female): ";
						cin >> temp;
					} while ((strcmp(temp, "Male") != 0 && strcmp(temp, "Female") != 0) && cout << "Error!! Please try again!" << endl);
					strcpy(current->data.sex, temp);
					cout << "DONE" << endl;
					break;
				}
				case 5:
				{
					cout << "Enter new day of D.O.B:";
					cin >> temp;
					strcpy(current->data.birth.day, temp);
					cout << "Enter new month of D.O.B:";
					cin >> temp;
					strcpy(current->data.birth.month, temp);
					cout << "Enter new year of D.O.B:";
					cin >> temp;
					strcpy(current->data.birth.year, temp);
					cout << "DONE" << endl;
					break;
				}
				case 6:
				{
					break;
				}
				default: cout << "You can only input from 1 to 6" << endl;
				}
			} while (check != 6);
			return;
		}
		current = current->next;
	}
}
