#include<stdio.h>
#include<stdlib.h>
//声明 
typedef struct LNode{
	int data;
	struct LNode*next;
}LNode,LinkList; 
//关于typedef的用法
void test()
{
	typedef int zhengshu;
	typedef int* zhengshuzhizhen;
	/*等价于*/
	int x=1;	zhengshu y=1;
	int*p;		zhengshuzhizhen q; 
} 
int main()
{
	/*增加节点的语句:
		LNode*p=(LNode*)malloc(sizeof(LNode));*/
	 
	//声明一个指向单链表第一个节点的指针
	LinkList L; 
	 
}
