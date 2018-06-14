#pragma once

#include <cstring>
struct contact
{
	contact() {}
	contact(const contact &cont);

	int ID = -1;
	char name[10] = "";
	char addr[10] = "";
	char mail[30] = "";
	char tel[12] = "";
	void printSelf();
};

struct List
{
	virtual void show() = 0;
	virtual void append(contact info) = 0;
	virtual contact del(int i) = 0;
	virtual void clear() = 0;
	virtual int get(char name[]) = 0;
};

struct SqList
{
	contact *datas;
	contact operator[] (int index);
	int length,MaxLength;
	SqList();
	void show();
	contact show(int index);
	void append(contact info);
	void append(contact info, int i);
	void edit(int infoID,contact info);
	contact del(int i);
	contact get(int index);
	int get(char name[]);
	void clear()
	{
		length = 0;
		MaxLength = 0;
	}
};

struct LinkList
{
	LinkList();
	void show();
	contact get(int i);
	int get(char name[]);
	void append(contact info);
	contact del(int i);
	int length;
	void clear()
	{
		LNode p,q;
		q = head;
		p = head->Next;
		while (p != NULL)
		{
			q = p->Next;
			free(p);
			p = q;
		}
	}
	typedef struct Node
	{
		contact datas;
		Node *Next;
	}*LNode;
	LNode head;
};