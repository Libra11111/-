#include<stdio.h>
#include<stdlib.h>
//双链表声明 
typedef struct DNode
{
	int data;	//数据域 
	struct DNode *prior,*next;//前驱和后继指针 
}DNode,*DLinkList;
//1、初始化				/*初始化就是将空指针指向NULL*/
bool InitDLinkList(DLinkList&L)
{
	//1、为数据结构开辟空间 
	L=(DNode*)malloc(sizeof(DNode));
	//2、若内存不足，则分配失败
	if(L==NULL)
		return false;
	//3、将指针置空 
	L->prior=NULL;		/*头结点的前驱始终为空*/ 
	L->next=NULL;		/*都节点后暂时还没有结点*/ 
	return true; 
} 
//2、双链表判空 
bool Empty(DLinkList&L)
{
	return (L->next==NULL);
} 
//3、后插结点 
bool InsertNextDNode(DNode*p,DNode*s)/*在p结点后插入s结点*/
{
	//1、检验数据是否可完成操作（合理性）
	if(p==NULL||s==NULL)
		return false;
	//2、后插	(将s接入到p和q结点之间)
	s->next=p->next;
	if(p->next!=NULL)	/*后继节点不为空，将后继的前驱指向s*/
		p->next->prior=s;/*以上是s和q*/ 
	p->next=s; 
	s->prior=p;/*以上是p和s*/
	return true;
}
/*双链表可以通过前驱指针将前插操作转化为对前驱结点的后插*/
//4、删除
bool DeleteNextDNode(DNode*p)/*删除p结点的后继结点*/
{
	//1、检验结点是否有效 （p本身不为空） 
	if(p==NULL)
		return false;
	//2、p后继不为空
	DNode *q=p->next;
	if(q==NULL)
		return false;
	//3、删除q结点
	p->next=q->next;
	/*若q的后继不为NULL（q不为尾结点）*/
	if(q->next!=NULL)
		q->next->prior=p;
	free(q);
	return true; 
}
//5、清除
bool DestroyDList(DLinkList&L)
{
	//1、循环释放各个数据结点
	while(L->next!=NULL)
		DeleteNextDNode(L);/*循环删除头结点的后继节点*/ 
	//2、 释放头结点 
	free(L);
	L=NULL;/*头结点指向NULL*/
	return true;
}
//6、双链表的遍历 
/*
	1、后向遍历
	while(p!=NULL){
		//对头结点做相应处理，如打印 
		p=p->next;
	}
	2、前向遍历
	while(p!=NULL){
		//~
		p=p->prior;
	}
	3、前向遍历（跳过头结点）
	while(p->prior!=NULL){		/*p不指向头结点 
		//~
		p=p->prior;
	}
	*/
/*打印显示*/
void Printf(DLinkList L)
{
	DNode*p=L;
	while(p->next!=NULL){
		p=p->next;
		printf("%d\n",p->data);
	}
	printf("打印完成\n"); 
}

int main()
{
	DLinkList L;
	//1、初始化 
	InitDLinkList(L);
	//2、判空
	//3、插入
	DNode*p=L;/*尾结点指针*/
	for(int i=0;i<5;i++){
		DNode*s=(DNode*)malloc(sizeof(DNode));
		s->data=i;
		s->next=NULL;
		InsertNextDNode(p,s);
		p=s;/*在循环中不能free（s）*/
	}
	Printf(L);
 	//4、删除
 	p=p->prior;
 	if(DeleteNextDNode(p))
 		printf("删除完成\n");
 	else
 		printf("删除未完成\n");
	Printf(L);
 	DestroyDList(L);
 	return 0;
} 



















