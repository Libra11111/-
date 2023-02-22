#include<stdio.h>
#include<stdlib.h>
//声明 
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//初始化
bool InitList(LinkList &L)
{
	L=(LNode*)malloc(sizeof(LNode));
	return (L!=NULL);
}
//判空
bool Empty(LinkList L)
{
	return (L!=NULL);
} 
//1、求表长 
int length(LinkList L)
{
	int len=0;
	LNode*p=L;
	while(p->next!=NULL)	/*只有“后继为空”这一个条件*/
	{
		p=p->next;
		len++; 
	}
	return len;
}
//2、按位序查找
LNode*GetElem(LinkList &L,int i)
{
	if(i<0)
		return NULL;
	LNode*p=L;
	int j=0;	//当前p指向第几个结点 
	while(p!=NULL&&j<i){/*将插入操作中的i-1改为i即可找到i节点*/ 
		p=p->next;
		j++;
	}
	return p;
} 
//3、按值查找
LNode*LocateElem(LinkList L,int e)
{
	LNode*p=L->next;
	//从第1个结点开始查找数据
	while(p!=NULL&&p->data!=e)	/*遍历找到值相同的元素，然后返回该结点的指针*/ 
		p=p->next;
	return p;//找到后返回该指针，否则返回NULL 	/*NULL表示指到表尾了仍然没找到 
} 
/*打印显示*/
void Printf(LinkList&L)
{
	LNode*p=L;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d\n",p->data);
	}
}
int main()
{
	LinkList L;
	InitList(L);
	LNode*p=L;
	for(int i=0;i<10;i++) 
	{
		LNode*s=(LNode*)malloc(sizeof(LNode));
		s->data=i;
		s->next=NULL;
		p->next=s;
		p=s;	/*连接结点+指针后移*/
	}
	//1、测试查表长
	Printf(L);
	printf("表长为：%d\n",length(L));
	//2、测试位序查找
	printf("第5位为%d",GetElem(L,5)->data); 
	//3、按值查找
	printf("找到值为9的元素，确认返回结点中的值为%d",LocateElem(L,9)->data); 
}
