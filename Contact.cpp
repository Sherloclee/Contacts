// Contact.cpp : 定义控制台应用程序的入口点。
//
#define NET_OFF 0
#define NET_ON 1
#include <cstdio>
#include <string>
#include "stdafx.h"

#define SAVE 1
#define LOAD 0

int netState = 0;
int net = 0;
int main()
{
	
	SqList contactList;
	LinkList delList;
	printf("是否打开网络储存?\n1.是\n0.否\n");
	scanf("%d", &net);
	if (net == 1)
	{
		int i;
		printf("请选择是否从网络加载通讯录:\n1.是\n2.否\n");
		scanf("%d", &i);
		if (i == 1)
		{
			system("load.exe");
		}
	}
	loadList(contactList);
	int loop(SqList &contactList,LinkList &delList);
	while(loop(contactList,delList));
	//closesocket(sockClient);
    return 0;
}

int loop(SqList &contactList, LinkList &delList)
{
	system("cls");
	int i = -1;
	char name[10];
	printf("请输入指令对应编号:\n");
	printf("1  <--查看通讯录-->\n");
	printf("2  <--查找通讯录-->\n");
	printf("3  <--修改通讯录-->\n");
	printf("4  <--添加联系人-->\n");
	printf("5  <--删除联系人-->\n");
	printf("6  <----恢--复---->\n");
	printf("7  <----保--存---->\n");
	printf("8  <打开/关闭-网络>\n");
	printf("9  <导入本地通讯录>\n");
	printf("0  <----退--出---->\n");
	if (net == 1)
		printf("网络状态:ON\n");
	else
		printf("网络状态:OFF\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1://输出全部联系人
		system("cls");
		contactList.show();
		system("pause"); 
		break;
	case 2://查找联系人
		system("cls");
		printf("---Now:Search---");
		printf("Please input the name.\n");
		scanf("%s", name);
		search(contactList, name);
		system("pause");
		break;
	case 3:
		system("cls");
		printf("---Now:Edit---\n");
		if (edit(contactList, delList))
			printf("Succeed!\n");
		system("pause");
		break;
	case 4://添加联系人
		system("cls");
		printf("---Now:Add---\n");
		if(add(contactList))
			printf("Succeed!\n");
		system("pause");
		break;
	case 5:
		system("cls");
		printf("---Now:Delet---");
		if(del(contactList, delList))
			printf("Succeed!\n");
		system("pause");
		break;
	case 6:
		system("cls");
		printf("---Now:Revert---\n");
		if(revert(contactList, delList))
			printf("Succeed!\n");
		system("pause");
		break;
	case 7:
		system("cls");
		printf("---Now:Saving---\n");
		save(contactList);
		contactList.clear();
		loadList(contactList);
		if (netState == 1)
		{
			int upload = 0;
			printf("是否需要存储到网络:\n1.是\n2.否\n");
			scanf("%d", &upload);
			if (upload)
			{
				system("save.exe");
			}
		}
		system("pause");
		break;
	case 8:
		net = !net;
		break;
	case 0://退出
		delList.clear();
		return 0;
	default:
		break;
	}
	return 1;
}
