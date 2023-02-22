#include<stdio.h>
#include<stdlib.h>
/*尾插法
	1·初始化单链表（开辟空间） 
	2·设置变量length记录长度
		while循环{
			每次取一个数据元素e （输入） 
			ListInsert(L,length+1,e)差尾部
			length++ 
		}
	*/
/*头插法
	1·初始化单链表（开辟空间）
	2·设置变量length记录长度
		while循环{
			每次取一个数据元素e（输入）
			ListNextNode(L,e)在头结点后插
			length++ 
	*/
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//1、尾插法
LinkList List_TailInsert(LinkList&L)
{
	int x; 
	L=(LinkList)malloc(sizeof(LNode));
	LNode*s,*r=L;
	/*用于调试操作界面*/printf("请输入尾插法创建要加入的元素值：（9999为结束指令）\n"); 
	scanf("%d",&x);
	while(x!=9999)/*输入9999表示输入结束（当然也可改为其他特定数字）*/
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=NULL;/*最好还是在创建结点时就讲next指针NULL，更安全*/
		r->next=s;
		r=s;
		scanf("%d",&x);//循环输入 
	}
	return L;
}
//2、头插法
LinkList List_HeadInsert(LinkList &L)
{
	LNode*s;
	int x;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	/*用于调试操作界面*/printf("请输入头插法创建要加入的元素值：（-1为结束指令）\n"); 
	scanf("%d",&x);
	while(x!=-1)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;/*接入到头结点之后*/
		scanf("%d",&x);
	}
	return L;
} 
/*打印展示*/
void Printf(LinkList L)
{
	LNode*p=L;
	printf("当前数据如下：\n"); 
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d\n",p->data);
	}
}
int main()
{
	LinkList L;
	//1、建立一个尾插链表 
	List_TailInsert(L);
	Printf(L);
	//2、建立一个头插链表 
	List_HeadInsert(L);		/*因为包含了初始化功能，可以直接传临时链表进行初始化*/
	Printf(L);
} 

/*！！！
	头插可以应用于链表的逆置，只需一个函数即可完成逆置要求*/
