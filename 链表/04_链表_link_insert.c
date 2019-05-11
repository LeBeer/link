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
int main(int argc,char *argv[])
{
	STU *head = NULL,*pnew;int num,i;
	puts("请输入初始链表节点数");
	scanf("%d",&num);
	puts("请输入学号，姓名");
	for(i=0;i<num;i++)
	{
		pnew = malloc(sizeof(STU));//赋值运算符自己转
		scanf("%d%s",&pnew->num,pnew->name);
		head = link_insert(head,pnew);
	}
	
	link_print(head);//函数 查看链表的所有节点 把头传进去 链表的首地址
	return 0;
}