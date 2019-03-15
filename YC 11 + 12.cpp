void viewlist(listst l1, listst l2, listst l3, listst l4, listst l5, listst l6)
{
	int check;
	do
	{
		cout << "Please input the class you want to watch list of student: " << endl;
		cout << "1. 18CLC1" << endl;
		cout << "2. 18CLC2" << endl;
		cout << "3. 18CLC3" << endl;
		cout << "4. 18CLC4" << endl;
		cout << "5. 18CLC5" << endl;
		cout << "6. 18CLC6" << endl;
		cout << "7. Done" << endl;
		cin >> check;
		switch (check)
		{
		case 1:
		{
			cout << "No \t Student ID \t Lastname \t Firstname \t Sex \t Date of birth " << endl;
			for (nodest *p = l1.head; p != NULL; p = p->next)
			{
				student st = p->data;
				if (st.no < 0) break;
				fout << st.no << "," << st.id << "," << st.lastname << "," << st.firstname << "," << st.sex << "," << st.birth.month << "/" << st.birth.day << "/" << st.birth.year << endl;
			}
		}
		case 2:
		{
			cout << "No \t Student ID \t Lastname \t Firstname \t Sex \t Date of birth " << endl;
			for (nodest *p = l2.head; p != NULL; p = p->next)
			{
				student st = p->data;
				if (st.no < 0) break;
				fout << st.no << "," << st.id << "," << st.lastname << "," << st.firstname << "," << st.sex << "," << st.birth.month << "/" << st.birth.day << "/" << st.birth.year << endl;
			}
		}
		case 3:
		{
			cout << "No \t Student ID \t Lastname \t Firstname \t Sex \t Date of birth " << endl;
			for (nodest *p = l3.head; p != NULL; p = p->next)
			{
				student st = p->data;
				if (st.no < 0) break;
				fout << st.no << "," << st.id << "," << st.lastname << "," << st.firstname << "," << st.sex << "," << st.birth.month << "/" << st.birth.day << "/" << st.birth.year << endl;
			}
		}
		case 4:
		{
			cout << "No \t Student ID \t Lastname \t Firstname \t Sex \t Date of birth " << endl;
			for (nodest *p = l4.head; p != NULL; p = p->next)
			{
				student st = p->data;
				if (st.no < 0) break;
				fout << st.no << "," << st.id << "," << st.lastname << "," << st.firstname << "," << st.sex << "," << st.birth.month << "/" << st.birth.day << "/" << st.birth.year << endl;
			}
		}
		case 5:
		{
			cout << "No \t Student ID \t Lastname \t Firstname \t Sex \t Date of birth " << endl;
			for (nodest *p = l5.head; p != NULL; p = p->next)
			{
				student st = p->data;
				if (st.no < 0) break;
				fout << st.no << "," << st.id << "," << st.lastname << "," << st.firstname << "," << st.sex << "," << st.birth.month << "/" << st.birth.day << "/" << st.birth.year << endl;
			}
		}
		case 6:
		{
			cout << "No \t Student ID \t Lastname \t Firstname \t Sex \t Date of birth " << endl;
			for (nodest *p = l6.head; p != NULL; p = p->next)
			{
				student st = p->data;
				if (st.no < 0) break;
				fout << st.no << "," << st.id << "," << st.lastname << "," << st.firstname << "," << st.sex << "," << st.birth.month << "/" << st.birth.day << "/" << st.birth.year << endl;
			}
		}
		case 7:
		{
			break;
		}
		default:
			cout << "You can only input from 1 to 7" << endl;
		}
	} while (check != 7);
	system("pause");
	exit(0);
}