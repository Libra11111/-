#include<stdio.h>
#include<stdlib.h>
//����
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList; 
//1����ʼ��һ��������
bool InitList(LinkList &L)
{
	L=(LNode*)malloc(sizeof(LNode));/*������ĳ�ʼ������Ϊ������һ��ռ�*/ 
	return (L!=NULL);
} 
//2���жϵ������Ƿ�Ϊ��
bool Empty(LinkList &L)
{
	return (L->next==NULL);
}
/*�Գ�ʼ�����пպ�������ɼ�*/
//3����λ����� 
bool ListInsert(LinkList&L,int i,int e)
{
	//1�����i������ 
	if(i<1)return false;
	//2������ͷ��㣬������i������ڲ��� 
	LNode*p=L;
	int j=0;
	while(p!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	//3������i����Ƿ��ҵ� 
	if(p==NULL)return false;/*������i���Ϸ�*/
	//4������ڵ�
	LNode*s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true; 
} 
/*����չʾԪ�ص��������*/
void Printf(LinkList&L)
{
	LNode*p=L;
	int j=0;//λ�������� 
	while(p!=NULL)
	{
		printf("��%dλΪ%d\n",j+1,p->data);
		p=p->next;
		j++;
	}
}
int main()
{
	LinkList L;
	if(InitList(L))
		printf("��ͷ��������ʼ�����\n");
	if(Empty(L))
		printf("����Ϊ��\n");
	else
		printf("����Ϊ��\n"); 
		
/*���Լ���һЩԪ��*/
	LNode *p;//��ʱ��� 
	L=p;
	for(int i=0;i<5;i++)
	{
		LNode*s=(LNode*)malloc(sizeof(LNode));
		s->data=i;
		p->data=s->data;
		p->next=s;
		/*p��s���Ӻ󣬽�p���ƣ�������p��nextָ��*/ 
		p=s;
		p->next=NULL;
	}
	if(Empty(L))
		printf("����Ϊ��,��ͷ���\n");
	else
		printf("����Ϊ��\n"); 
	/*��ӡ��ʾ*/
	Printf(L);		
	//��������λ��������
	if(ListInsert(L,2,10))
		printf("\n������ɣ�����������Ϊ��\n");
	Printf(L);
	//...��������...
	return 0;		
}

/*ͷ��㲻�����ݣ��������ܷ��㣬���迼��i=1ʱ��λ���������*/
