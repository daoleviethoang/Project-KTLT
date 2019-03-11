void changePassword(listpw &l, char user[], char password[])
{
	char check[50];
	char a[50], b[50];
	do
	{
		cout << "Enter your old password: ";
		cin >> check;
		if (strcmp(check, password) == 0)
		{
			do
			{
				cout << "Enter new password: ";
				cin >> a;
				cout << "Enter new password again: ";
				cin >> b;
				if (strcmp(a, b)==0)
				{
					nodepw*p = l.head;
					while (p != NULL)
					{
						if (strcmp(p->data.user, user) == 0)
						{
							strcpy(p->data.pass, a);
							return;
						}
						p = p->next;
					}
				}
			} while (a != b);
		}
	} while ((strcmp(check, password) != 0) && cout << "Wrong!! Please do it again!" << endl);
}