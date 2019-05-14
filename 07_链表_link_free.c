#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
	int num;
	char name[30];
	struct student *next; 
}STU;

//遍历链表
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

//插入链表
STU *link_insert(STU *head,STU *pnew)//链表的创建 封装成函数  创建成功的 地址返回
{
	if(head == NULL)
	{
		head = pnew;
		pnew->next = NULL;
	}
	else
	{
		pnew->next = head;
		head = pnew;
	}
	return head;
}

//创建链表
STU *link_creat(STU *head)
{
	STU *pnew;int num,i;
	puts("请输入初始链表节点数");
	scanf("%d",&num);
	puts("请输入学号，姓名");
	for(i=0;i<num;i++)
	{
		pnew = malloc(sizeof(STU));//赋值运算符自己转
		scanf("%d%s",&pnew->num,pnew->name);
		head = link_insert(head,pnew);
	}
	return head;
}

//查找链表
STU *link_search(STU *head,int num)
{
	//可以以学号，或者姓名的方式找
	//遍历链表
	STU *pb = head;
	while(pb != NULL)
	{
		if(pb->num == num)
		break;
		pb = pb->next;
	}
	return pb;
}

//删除链表
STU *link_delete(STU *head,char *name)
{
	STU *pb = head,*pf;
	pf = pb;
	while(pb != NULL)
	{
		if(strcmp(pb->name,name) == 0)
		break;
		pf = pb;
		pb = pb->next;
	}
	if(pb != NULL)
	{
		if(pb == head)
			head = head->next;
		else
			pf->next = pb->next;
		free(pb);
	}
	return head;
}
//释放链表
//跟遍历非常像
void link_free(STU *head)
{
	STU *pb = head,*pf = head;
	while(pb != NULL)
	{
		pf = pb;
		pb = pb->next;
		free(pf);
	}
}
int main(int argc,char *argv[])
{
	STU *head = NULL,*p;int num,i;char name[30];
	
	head = link_creat(head);
	
	link_print(head);//函数 查看链表的所有节点 把头传进去 链表的首地址
	/*while(1)
	{
		puts("请输入需要找的学号");
		scanf("%d",&num);
		p = link_search(head,num);
		if(p != NULL)
		{
			printf("找到节点：%d %s\n",p->num,p->name);

		}
		else
			printf("未找到！\n");
	}*/
	/*while(1)
	{
		puts("请输入需要找的姓名");
		scanf("%s",name);
		head = link_delete(head,name);
		link_print(head);	
	}*/
	link_free(head);
	return 0;
}