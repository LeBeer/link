#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
	int num;
	char name[30];
	struct student *next; 
}STU;

void link_print(STU *head)//严格意义上讲 head是这个函数的局部变量
{
	//再定义一个变量
	STU *pb = head;//可以去掉
	while(pb != NULL)
	{//要输出三个节点，打印的东西是一样的
	
		printf("%d %s\n",pb->num,pb->name);//打印第一个
		pb = pb->next;//让pb指向pb下一个节点
	}
}

main()
{
	STU *head,*pnew;
	pnew = malloc(sizeof(STU));//赋值运算符自己转
	
	head = pnew;//head开头 就和数组的数组名开头一样 找到链表的第一个成员
	head->num = 101;
	strcpy(head->name,"lk");
	//head->name = "lk";	错的
	//printf("%d %s\n",head->num,head->name);

	pnew = malloc(sizeof(STU));
	head->next = pnew;
	pnew->num = 102;
	strcpy(pnew->name,"rs");
	//printf("%d %s\n",pnew->num,pnew->name);
	
	pnew = malloc(sizeof(STU));
	pnew->next = NULL;
	head->next->next = pnew;
	pnew->num = 103;
	strcpy(pnew->name,"kp");
	//printf("%d %s\n",pnew->num,pnew->name);//最后指向NULL 确定链表写完
	
	link_print(head);//函数 查看链表的所有节点 把头传进去 链表的首地址
	return 0;
}