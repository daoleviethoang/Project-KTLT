#include <iostream>
using namespace std;

bool viewcourse(listcr &lcr, char account[] ) //account của gv đăng nhập
{
	Nodecr* p=lcr.head;
	while (p)
	{
		char *q=strstr(p.lecture,account);
		if (p)
		{
			cout<<p.no<<'.'<<p.id<<','<<p.name<<','<<p.classn<<','<<p.lecture<<
				p.start.day<<','<<p.start.month<<','<<p.start.year<<','<<
				p.end.day<<','<<p.end.month<<','<<p.end.year<<','<<
				p.start1.hour<<','<<p.start1.minute<<','<<
				p.end1.hour<<','<<p.end1.minute<<','<<p.room<<endl;

		}
		p=p->next;
	}
}
