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
	STU *head;
	head = malloc(sizeof(STU));//赋值运算符自己转
	
	head->num = 101;
	strcpy(head->name,"lk");
	//head->name = "lk";	错的

	head->next = malloc(sizeof(STU));
	head->next->num = 102;
	strcpy(head->next->name,"rs");

	
	printf("%d %s\n",head->num,head->name);
	printf("%d %s\n",head->next->num,head->next->name);
	return 0;
}