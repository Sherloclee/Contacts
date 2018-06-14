#include "stdafx.h"

int search(SqList contactList, char name[])
{
	if (contactList.get(name) == 0)
	{
		cout << "There is no contact named " << name << endl;
		return 0;
	}
	return 1;
}

int add(SqList &contactList)
{
	contact info;
	cout << "name:";
	cin >> info.name;
	cout << "tel:";
	cin >> info.tel;
	cout << "mail";
	cin >> info.mail;
	cout << "addr";
	cin >> info.addr;
	info.ID = contactList.MaxLength + 1;
	contactList.append(info);
	return 1;
}

int del(SqList &contactList, LinkList &delList)
{
	char name[20];
	int n,infoID;
	contact info;
	cout << "Please input the name of the contact who you want to delet:";
	cin >> name;
	cout << "Here are the contact named " << name << endl;
	n = contactList.get(name);
	if ( n == 0)
	{
		cout << "You will back to the main menu soon.";
		system("pause");
		return 0;
	}
	else
	{
		cout << "There are " << n << " contact named "<<name<<'.'<<endl;
		cout << "Please input the ID:";
		cin >> infoID;
		info=contactList.del(infoID);
		delList.append(info);
	}
	return 1;
}

int edit(SqList &contactList, LinkList &delList)
{
	char name[10];
	int n,infoID;
	contact info; 
	cout << "Please input the name which you want to edit:";
	cin >> name;
	cout << "Here are the contact named " << name << endl;
	n = contactList.get(name);
	if (n == 0)
	{
		cout << "You will back to the main menu soon.";
		system("pause");
		return 0;
	}
	else
	{
		try
		{
			cout << "There are " << n << " contact named " << name << '.' << endl;
			cout << "Please input the ID:";
			cin >> infoID;
			strcpy(info.name, contactList.get(infoID).name);
			cout << "Enter the new contact infomation:" << endl;
			cout << "tel:";
			cin >> info.tel;
			cout << "mail:";
			cin >> info.mail;
			cout << "addr:";
			cin >> info.addr;
			info.ID = infoID;
			delList.append(contactList.get(infoID));
			contactList.edit(infoID, info);
			return 1;
		}
		catch (int)
		{
			cout << "The ID is out of range." << endl;
			return 0;
		}
	}
}

int revert(SqList &contactList, LinkList &delList)
{
	int id;
	int i = 0;
	if (delList.length == 0)
	{
		cout << "You haven't delet or edit any contact yet.";
		return 0;
	}
	cout << "Here are the contacts you have delet or edit." << endl;
	delList.show();
	cout << "Please input the ID of the :";
	cin >> id;
	if (contactList.get(id).ID == -1)
	{
		contactList.append(delList.get(id),id);
		delList.del(id);
	}
	else
	{
		contactList.edit(id, delList.get(id));
		delList.del(id);
	}
}

int save(SqList contactList)
{
	savelist(contactList, "../contacts_save.txt");
	return 1;
}