#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
	puts("学号 姓名");
	while(pb != NULL)
	{//要输出三个节点，打印的东西是一样的
		printf("%03d %s\n",pb->num,pb->name);//打印第一个
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
	srand((unsigned)time(NULL));

	puts("请输入初始链表节点数");
	scanf("%d",&num);
	
		for(i=0;i<num;i++)
		{
			pnew = malloc(sizeof(STU));
			pnew->num = rand()%1000;
			pnew->name[0] = rand()%26 + 'a';
			pnew->name[1] = rand()%26 + 'a';
			pnew->name[2] = rand()%26 + 'a';
			head = link_insert(head,pnew);
		}	
	/*puts("请输入学号，姓名");
	for(i=0;i<num;i++)
	{
		pnew = malloc(sizeof(STU));//赋值运算符自己转
		scanf("%d%s",&pnew->num,pnew->name);
		head = link_insert(head,pnew);
	}*/
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

STU *link_order(STU *head)
{
	STU *pf,*pb,tmp;
	for(pf = head;pf != NULL;pf = pf->next)
	for(pb = pf->next;pb != NULL;pb = pb->next)
		{
			if(pf->num > pb->num)
			{
				//交换
				tmp = *pf;
				*pf = *pb;
				*pb = tmp;
				tmp.next = pf->next;
				pf->next = pb->next;
				pb->next = tmp.next;
			}
		}
	return head;
}

//提示信息
void help_print(void)
{
	puts("1.创建链表");
	puts("2.插入链表");
	puts("3.查找节点");
	puts("4.删除节点");
	puts("5.输出链表");
	puts("6.排序链表");
	puts("7.逆序链表");
	puts("8.退出链表");
}
int main(int argc,char *argv[])
{
	STU *head = NULL,*p,*pnew;int num,ops,i;char name[30];

	while(1)
	{
		help_print();
		scanf("%d",&ops);
		switch(ops){
			case 1:
				head = link_creat(head);
				break;	
			case 2:
				pnew = malloc(sizeof(STU));//赋值运算符自己转
				if(pnew ==NULL)
				{
					puts("请输入学号，姓名");
					scanf("%d%s",&pnew->num,pnew->name);
					head = link_insert(head,pnew);
				}
				break;
			case 3:
				puts("请输入需要找的学号");
				scanf("%d",&num);
				p = link_search(head,num);
				if(p != NULL)
				{
					printf("找到节点：%d %s\n",p->num,p->name);
				}
				else
					printf("未找到！\n");
				break;
			case 4:
				puts("请输入需要删除的姓名");
				scanf("%s",name);
				head = link_delete(head,name);
				break;
			case 5:
				link_print(head);
				break;			
			case 6://排序
				head = link_order(head);
				break;		
			case 7://逆序
				//head = link_reverse(head);
				break;
			case 8:
				link_free(head);
				return 0;					
		}
	}
	return 0;
}