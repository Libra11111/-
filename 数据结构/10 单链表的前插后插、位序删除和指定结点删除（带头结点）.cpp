#include<stdio.h>
#include<stdlib.h>
//声明
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//初始化
bool InitList(LinkList&L)
{
	L=(LNode*) malloc(sizeof(LNode));
	return (L!=NULL);
} 
//判空 
bool Empty(LinkList L)
{
	return (L->next==NULL); 
}
//1、指定结点的后插
bool InsertNextNode(LNode*p,int e)	/*有了指定结点，就省去了传链表然后找i位点的操作*/ 
{										/*同时注意传结点时为LNode指针形式*,否则不能用NULL判断地址/
	/*1·检查否为空表*/
	if(p==NULL)return false;
	/*2、创建s结点并判空*/
	LNode*s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)return false;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true; 
}
//2、指定结点的前插 
bool InsertPriorNode(LNode*p,int e)
{
	//1·检查表空
	if(p==NULL)
		return false;			
	//2、创建s并检验
	LNode*s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)
		return false;
	s->next=p->next;
	p->next=s;/*后接*/
	s->data=p->data;/*交换元素*/ 
	p->data=e;
	return true;
}
//3、按位序删除结点
bool ListDelete(LinkList&L,int i,int e)
{
	//1、检查i合法 
	if(i<1)return false;
	//2、找i-1结点 
	LNode*p=L;
	int j=0;
	while(p!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	//3、i值不合法
	if(p==NULL)
		return false;
	//4、是否有可删结点
	if(p->next==NULL)		/*因此不能删除尾结点元素的值，即i不能为尾结点*/ 
		return false;
	//5、删除p的后继节点，并 
	LNode*q=p->next;
	e=q->data;
	p->next=q->next;
	free(q);
	return true; 
} 
//4、指定结点的删除
bool DeleteNode(LNode*p)
{
	if(p==NULL)
		return false;
	LNode*q=p->next;
	p->data=q->data;
	p->next=q->next;
	free(q);
	return true;
} 
/*打印显示链表元素*/
void Printf(LinkList&L)
{
	LNode*p=L;
	int j=0;
	while(p!=NULL){
		if(j>0)
			printf("第%d个元素为%d\n",j,p->data);
		p=p->next;
		j++;
	}
}
int main()
{
	LinkList L;
	if(InitList(L))printf("初始化完成\n");
	if(Empty(L))printf("为空表\n");
		else printf("不为空表\n");
/*随便加几个元素*/
	LNode*p=L;
	for(int i=0;i<5;i++)
	{
		LNode*s=(LNode*)malloc(sizeof(LNode));
		s->data=i;
		p->next=s;
		//后移p结点
		p=s;
		p->next=NULL;
	}
	Printf(L);
	printf("打印完成\n"); 
	//1、测试后插操作
	if(InsertNextNode(p,10))	/*此时p为尾结点*/
		printf("后插完成\n");
	else 
		printf("后插未完成\n");
	Printf(L);
	//2、测试前插操作
	LNode*q=L->next;
	if(InsertPriorNode(q,20))	/*此时p为尾结点,在头结点之后前插入元素20*/
		printf("前插完成\n");
	else 
		printf("前插未完成\n");
	Printf(L);
	//3、按位序删除
	int e;/*用于返回被删元素*/
	if(ListDelete(L,3,e))	/*删除第三位元素*/
		printf("位序删除完成\n");
	else 
		printf("删除未完成\n");
	Printf(L);	
	//4、指定结点的删除
	LNode*s=L->next->next;
	if(DeleteNode(s))	/*，删除第二个结点*/
			printf("指定结点删除完成\n");
		else 
			printf("指定删除未完成\n");
		Printf(L);	
	return 0;
}
