#include<stdio.h>
#include<stdlib.h>
//1、声明单链表结点和链队列 
typedef struct LinkNode{
	int data;
	struct LinkNode *next;/*其实LinkNode就是LNode的扩写*/ 
}LinkNode;
typedef struct {
	LinkNode *front,*rear;//链队列的队头和队尾指针 
}LinkQueue;  
//2、初始化
void InitQueue(LinkQueue&Q){
	//初始化，front和rear都指向头结点
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL; 
} 
//3、判空
bool IsEmpty(LinkQueue Q)
{
	return (Q.front==Q.rear);
} 
//4、入队（带头结点）
void EnQueue(LinkQueue&Q,int x)
{
	//1、开辟新结点s，并初始化 
	LinkNode*s=(LinkNode*)malloc(sizeof(LinkNode));
	s->data=x;
	s->next=NULL;
	//2、连接新节点+后移 
	Q.rear->next=s;	/*新节点插入到rear之后*/ 
	Q.rear=s;		/*rear后移*/ 
}
//5、出队
bool DeQueue(LinkQueue&Q,int&x)
{
	//1、判空
	if(Q.front==Q.rear)
		return false;/*头尾重合，空队*/ 
	//2、取数据	（ 链队列所用链表节点为指针形式，都要用箭头->指示） 
	LinkNode*p=Q.front->next;/*p在头结点的下一位置，即队列中第一个存了元素的节点*/
	x=p->data;	
	Q.front->next=p->next;/*后移*/ 
	//3、若只有一个节点，则rear指回front
	if(p->next==NULL)
		Q.rear=Q.front;
	free(p);
	return false; 
} 
/*遍历打印*/
void Printf(LinkQueue&Q)
{
	printf("队列元素如下：\n");
	for(LinkNode*p=Q.front;p->next!=NULL;){
		p=p->next;
		printf("%d ",p->data);
	}
	printf("以上\n");
} 
int main()
{
	LinkQueue Q;
	InitQueue(Q);
	for(int i=0;i<10;i++)
		EnQueue(Q,i);
	Printf(Q);
	int x;
	for(int i=0;i<5;i++){
		DeQueue(Q,x);
		printf("出队元素为：%d\n",x);
	}
	Printf(Q);
	return 0;
}
/*以上是带头结点的链队列，
	不带头节点则
	1）在初始化中为	front=NULL，rear=NULL
	2）在处理第一个节点时，加上判空 
		if(Q.front==NULL){
			Q.front=s;
			Q.rear=s; 
			}
		*/
