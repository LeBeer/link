#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
	int num;
	char name[30];
	struct student *next; 
}STU;

void link_print(STU *head)//�ϸ������Ͻ� head����������ľֲ�����
{
	//�ٶ���һ������
	STU *pb = head;//����ȥ��
	while(pb != NULL)
	{//Ҫ��������ڵ㣬��ӡ�Ķ�����һ����
	
		printf("%d %s\n",pb->num,pb->name);//��ӡ��һ��
		pb = pb->next;//��pbָ��pb��һ���ڵ�
	}
}

main()
{
	STU *head,*pnew;
	pnew = malloc(sizeof(STU));//��ֵ������Լ�ת
	
	head = pnew;//head��ͷ �ͺ��������������ͷһ�� �ҵ�����ĵ�һ����Ա
	head->num = 101;
	strcpy(head->name,"lk");
	//head->name = "lk";	���
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
	//printf("%d %s\n",pnew->num,pnew->name);//���ָ��NULL ȷ������д��
	
	link_print(head);//���� �鿴��������нڵ� ��ͷ����ȥ ������׵�ַ
	return 0;
}