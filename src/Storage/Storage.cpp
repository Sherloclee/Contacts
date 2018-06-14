#include "stdafx.h"

contact::contact(const contact &cont)
{
	this->ID = cont.ID;
	strcpy(this->name, cont.name);
	strcpy(this->tel, cont.tel);
	strcpy(this->mail, cont.mail);
	strcpy(this->addr, cont.addr);
}
void contact::printSelf()
{
	cout << left << setw(5) << ID << "  ";
	cout << left << setw(8) << name << "  ";
	cout << left << setw(13) << tel << "  ";
	cout << left << setw(30) << mail << "  ";
	cout << left << setw(24) << addr << "  \n";
}

SqList::SqList()
{
	length = MaxLength = 0;
	datas = (contact*)malloc((length + 1) * sizeof(contact));
}

void SqList::show()
{
	for (int i = 0; i < length; i++)
	{
		datas[i].printSelf();
	}
}
contact SqList::show(int index)
{
	return datas[index];
}
void SqList::append(contact info)
{
	datas[length] = info;
	length++;
	MaxLength++;
	if (MaxLength>(sizeof(datas)/sizeof(contact)))
	datas = (contact*)realloc(datas, (length + 1) * sizeof(contact));
}
void SqList::append(contact info, int infoID)
{
	if (infoID >= length + 1)
	{
		append(info);
		return;
	}
	for (int i = 0; i < length; i++)
	{
		if (datas[i].ID >= infoID)
		{
			for (int j = length + 1; j>i; j--)
			{
				datas[j] = datas[j - 1];
			}
			datas[i] = info;
			break;
		}
	}
	length++;
	MaxLength++;
	datas = (contact*)realloc(datas, (length + 1) * sizeof(contact));
}
void SqList::edit(int infoID, contact info)
{
	for (int i = 0; i < length; i++)
	{
		if (datas[i].ID == infoID)
		{
			datas[i] = info;
			break;
		}
	}
}
contact SqList::del(int index)
{
	contact info;
	for (int i = 0; i < length; i++)
	{
		if (datas[i].ID == index)
		{
			info = datas[i];
			for (int j = i; j < length; j++)
			{
				datas[j] = datas[j + 1];
			}
			length--;
			break;
		}
	}
	return info;
}
contact SqList::get(int index)
{
	contact info;
	for (int i = 0; i < length; i++)
	{
		if (datas[i].ID == index)
		{
			return datas[i];
		}
	}
	throw(index);
	return info;
}
int SqList::get(char name[])
{
	int counter = 0;
	contact info;
	for (int i = 0; i < length; i++)
	{
		if (strcmp(datas[i].name, name) == 0)
		{
			info = datas[i];
			info.printSelf();
			counter++;
		}
	}
	if (info.ID == -1)
	{
		return 0;
	}
	return counter;
}
contact SqList::operator[] (int index)
{
	return this->show(index);
}


LinkList::LinkList()
{
	head = (LNode)malloc(sizeof(Node));
	head->Next = NULL;
	length = 0;
}
/*
show()
eg.
LinkList list;
list.show();
*/
void LinkList::show()
{
	LNode p;
	p = head->Next;
	while (p != NULL)
	{
		p->datas.printSelf();
		p = p->Next;
	}
}
void LinkList::append(contact info)
{
	LNode p;
	p = (LNode)malloc(sizeof(Node));
	p->datas = info;
	p->Next = head->Next;
	head->Next = p;
	length++;
}
int LinkList::get(char name[])
{
	LNode p;
	contact info;
	p = head->Next;
	int i = 0;
	while (p != NULL)
	{
		if (strcmp(p->datas.name, name)==0)
		{
			info = p->datas;
			info.printSelf();
		}
	}
	if (info.ID == -1)
	{
		cout << "There is no contact names " << name << endl; \
			return 0;
	}
	return 1;
}
contact LinkList::get(int i)
{
	LNode p;
	contact info;
	p = head->Next;
	while (p != NULL)
	{
		if (p->datas.ID == i)
		{
			info = p->datas;
			break;
		}
		p = p->Next;
	}
	return info;
}
contact LinkList::del(int i)
{
	LNode p, q;
	contact info;
	q = head;
	p = head->Next;
	while (p != NULL)
	{
		if (p->datas.ID == i)
		{
			info = p->datas;
			q->Next = p->Next;
			free(p);
			length--;
			break;
		}
		q = p;
		p = p->Next;
	}
	return info;
}