#include<stdio.h>
#include<stdlib.h>
//声明 
typedef struct LNode 
{
	int data;
	struct LNode *next; 
}LNode,*LinkList;
//1、初始化一个空的单链表
bool InitList(LinkList &L)
{
	L=NULL;
	return true;
} 
//2、判断空链表是否为空	
bool Empty(LinkList L)
{
	if(L==NULL)
		return true;
	else 
		return false; 
}
/*简化版
bool Empty(LinkList L)
{
	return (L==NULL);/*因为本身为true\false
}*/
//3、位序插入
bool ListInsert(LinkList &L,int i,int e)
{
	//检验i合法性 
	if(i<1)
		return false;
	if(i==1){
		LNode*s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		s->next=L;
		L=s;
		return true;	
	}
	//创建临时结点（单个结点不用malloc） 
	LNode*p;
	int j=0;
	p=L;
	while(p!=NULL&&j<i-1)
	{/*将新结点放到第i-1个结点后*/ 
		p=p->next;
		j++;//通过循环找到尾结点，即p 
	}
	//若p在循环后为空则i不合法 
	if(p==NULL)
		return false;
	LNode*s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;/*以上两句不可颠倒*/
	return true;
}
/*用于展示元素的输出函数*/
void Printf(LinkList&L)
{
	LNode*p=L;/*充当头指针，用于遍历和找尾结点*/
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
	//初始化一个空表
	if(InitList(L))
		printf("带头结点链表初始化完成\n");
	if(Empty(L))
		printf("链表为空,无头结点\n");
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
		p->next=NULL;//
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

/*不带头节点单链表的
缺点在于写代码麻烦 
*/
