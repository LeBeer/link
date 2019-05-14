#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
	int num;
	char name[30];
	struct student *next; 
}STU;
main()
{
	STU *head,*pnew;
	pnew = malloc(sizeof(STU));//赋值运算符自己转
	
	head = pnew;//head开头 就和数组的数组名开头一样 找到链表的第一个成员
	head->num = 101;
	strcpy(head->name,"lk");
	//head->name = "lk";	错的
	printf("%d %s\n",head->num,head->name);

	pnew = malloc(sizeof(STU));
	head->next = pnew;
	pnew->num = 102;
	strcpy(pnew->name,"rs");
	printf("%d %s\n",pnew->num,pnew->name);
	
	pnew = malloc(sizeof(STU));
	head->next->next = pnew;
	pnew->num = 103;
	strcpy(pnew->name,"kp");
	printf("%d %s\n",pnew->num,pnew->name);
	
	return 0;
}