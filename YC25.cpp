bool saveattendance(const char*file, nodesc *l1)
{
	ofstream fout;
	fout.open(file);
	if (fout.fail())
		return false;
	cout << "Student ID  Midterm  Final  Lab  Bonus" << endl;

	for (nodesc *p = l1; p != NULL; p = p->next)
	{
		fout << p->data.id << ",";
		for (int i = 0; i < 4; i++)
		{
			fout << p->data.a[i] << ",";
		}
		fout << endl;
	}
	return true;
}