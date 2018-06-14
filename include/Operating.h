#pragma once
int search(SqList contactList, char name[]);
int add(SqList &contactList);
int del(SqList &contactList, LinkList &delList);
int edit(SqList &contactList, LinkList &delList);
int revert(SqList &contactList, LinkList &delList);
int save(SqList contactList);
int myCloud(SqList &contactList,int mode);