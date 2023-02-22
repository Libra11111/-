#include<stdio.h>
#include<stdlib.h>
//声明
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList; 
//1、初始化一个空链表
bool InitList(LinkList &L)
{
	L=(LNode*)malloc(sizeof(LNode));/*最基本的初始化就是为链表开辟一块空间*/ 
	return (L!=NULL);
} 
//2、判断单链表是否为空
bool Empty(LinkList &L)
{
	return (L->next==NULL);
}
/*对初始化和判空函数均完成简化*/
//3、按位序插入 
bool ListInsert(LinkList&L,int i,int e)
{
	//1·检查i合理性 
	if(i<1)return false;
	//2·创建头结点，用于找i结点用于插入 
	LNode*p=L;
	int j=0;
	while(p!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	//3·检验i结点是否找到 
	if(p==NULL)return false;/*出错则i不合法*/
	//4·插入节点
	LNode*s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true; 
} 
/*用于展示元素的输出函数*/
void Printf(LinkList&L)
{
	LNode*p=L;
	int j=0;//位数计数器 
	while(p!=NULL)
	{
		printf("第%d位为%d\n",j+1,p->data);
		p=p->next;
		j++;
	}
}
int main()
{
	LinkList L;
	if(InitList(L))
		printf("带头结点链表初始化完成\n");
	if(Empty(L))
		printf("链表为空\n");
	else
		printf("链表不为空\n"); 
		
/*尝试加入一些元素*/
	LNode *p;//临时结点 
	L=p;
	for(int i=0;i<5;i++)
	{
		LNode*s=(LNode*)malloc(sizeof(LNode));
		s->data=i;
		p->data=s->data;
		p->next=s;
		/*p与s连接后，将p后移，并改正p的next指针*/ 
		p=s;
		p->next=NULL;
	}
	if(Empty(L))
		printf("链表为空,无头结点\n");
	else
		printf("链表不为空\n"); 
	/*打印显示*/
	Printf(L);		
	//进而测试位序插入操作
	if(ListInsert(L,2,10))
		printf("\n插入完成，插入后的链表为：\n");
	Printf(L);
	//...后续代码...
	return 0;		
}

/*头结点不存数据，但操作很方便，无需考虑i=1时的位序插入问题*/
