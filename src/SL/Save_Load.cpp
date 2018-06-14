#include "stdafx.h"

void loadList(SqList &contactList)
{
	ifstream fp;
	contact info;
	fp.open("../contacts.txt");
	int n = 1;
	while (fp >> info.ID >> info.name >> info.tel >> info.mail >> info.addr)
	{
		info.ID = n;
		contactList.append(info);
		n++;
	}
	fp.close();
}



void savelist(SqList contactList,char path[])
{
	ofstream fp("../contacts.txt");
	if (fp.is_open())
		for (int i = 0; i<contactList.length; i++)
		{
			contact info(contactList[i]);
			fp << left << setw(5) << i+1       << ' ';
			fp << left << setw(10)<< info.name << ' ';
			fp << left << setw(13)<< info.tel  << ' ';
			fp << left << setw(30)<< info.mail << ' ';
			fp << left << setw(20)<< info.addr << ' '<<endl;
		}
	fp.close();
}