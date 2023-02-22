#include<stdio.h>
#include<stdlib.h>
//���� 
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//��ʼ��
bool InitList(LinkList &L)
{
	L=(LNode*)malloc(sizeof(LNode));
	return (L!=NULL);
}
//�п�
bool Empty(LinkList L)
{
	return (L!=NULL);
} 
//1����� 
int length(LinkList L)
{
	int len=0;
	LNode*p=L;
	while(p->next!=NULL)	/*ֻ�С����Ϊ�ա���һ������*/
	{
		p=p->next;
		len++; 
	}
	return len;
}
//2����λ�����
LNode*GetElem(LinkList &L,int i)
{
	if(i<0)
		return NULL;
	LNode*p=L;
	int j=0;	//��ǰpָ��ڼ������ 
	while(p!=NULL&&j<i){/*����������е�i-1��Ϊi�����ҵ�i�ڵ�*/ 
		p=p->next;
		j++;
	}
	return p;
} 
//3����ֵ����
LNode*LocateElem(LinkList L,int e)
{
	LNode*p=L->next;
	//�ӵ�1����㿪ʼ��������
	while(p!=NULL&&p->data!=e)	/*�����ҵ�ֵ��ͬ��Ԫ�أ�Ȼ�󷵻ظý���ָ��*/ 
		p=p->next;
	return p;//�ҵ��󷵻ظ�ָ�룬���򷵻�NULL 	/*NULL��ʾָ����β����Ȼû�ҵ� 
} 
/*��ӡ��ʾ*/
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
		p=s;	/*���ӽ��+ָ�����*/
	}
	//1�����Բ��
	Printf(L);
	printf("��Ϊ��%d\n",length(L));
	//2������λ�����
	printf("��5λΪ%d",GetElem(L,5)->data); 
	//3����ֵ����
	printf("�ҵ�ֵΪ9��Ԫ�أ�ȷ�Ϸ��ؽ���е�ֵΪ%d",LocateElem(L,9)->data); 
}
