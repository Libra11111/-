#include<stdio.h>
#include<stdlib.h>
/*β�巨
	1����ʼ�����������ٿռ䣩 
	2�����ñ���length��¼����
		whileѭ��{
			ÿ��ȡһ������Ԫ��e �����룩 
			ListInsert(L,length+1,e)��β��
			length++ 
		}
	*/
/*ͷ�巨
	1����ʼ�����������ٿռ䣩
	2�����ñ���length��¼����
		whileѭ��{
			ÿ��ȡһ������Ԫ��e�����룩
			ListNextNode(L,e)��ͷ�����
			length++ 
	*/
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//1��β�巨
LinkList List_TailInsert(LinkList&L)
{
	int x; 
	L=(LinkList)malloc(sizeof(LNode));
	LNode*s,*r=L;
	/*���ڵ��Բ�������*/printf("������β�巨����Ҫ�����Ԫ��ֵ����9999Ϊ����ָ�\n"); 
	scanf("%d",&x);
	while(x!=9999)/*����9999��ʾ�����������ȻҲ�ɸ�Ϊ�����ض����֣�*/
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=NULL;/*��û����ڴ������ʱ�ͽ�nextָ��NULL������ȫ*/
		r->next=s;
		r=s;
		scanf("%d",&x);//ѭ������ 
	}
	return L;
}
//2��ͷ�巨
LinkList List_HeadInsert(LinkList &L)
{
	LNode*s;
	int x;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	/*���ڵ��Բ�������*/printf("������ͷ�巨����Ҫ�����Ԫ��ֵ����-1Ϊ����ָ�\n"); 
	scanf("%d",&x);
	while(x!=-1)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;/*���뵽ͷ���֮��*/
		scanf("%d",&x);
	}
	return L;
} 
/*��ӡչʾ*/
void Printf(LinkList L)
{
	LNode*p=L;
	printf("��ǰ�������£�\n"); 
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d\n",p->data);
	}
}
int main()
{
	LinkList L;
	//1������һ��β������ 
	List_TailInsert(L);
	Printf(L);
	//2������һ��ͷ������ 
	List_HeadInsert(L);		/*��Ϊ�����˳�ʼ�����ܣ�����ֱ�Ӵ���ʱ������г�ʼ��*/
	Printf(L);
} 

/*������
	ͷ�����Ӧ������������ã�ֻ��һ�����������������Ҫ��*/
