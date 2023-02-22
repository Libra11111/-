#include<stdio.h>
#include<stdlib.h>
//����
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//��ʼ��
bool InitList(LinkList&L)
{
	L=(LNode*) malloc(sizeof(LNode));
	return (L!=NULL);
} 
//�п� 
bool Empty(LinkList L)
{
	return (L->next==NULL); 
}
//1��ָ�����ĺ��
bool InsertNextNode(LNode*p,int e)	/*����ָ����㣬��ʡȥ�˴�����Ȼ����iλ��Ĳ���*/ 
{										/*ͬʱע�⴫���ʱΪLNodeָ����ʽ*,��������NULL�жϵ�ַ/
	/*1������Ϊ�ձ�*/
	if(p==NULL)return false;
	/*2������s��㲢�п�*/
	LNode*s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)return false;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true; 
}
//2��ָ������ǰ�� 
bool InsertPriorNode(LNode*p,int e)
{
	//1�������
	if(p==NULL)
		return false;			
	//2������s������
	LNode*s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)
		return false;
	s->next=p->next;
	p->next=s;/*���*/
	s->data=p->data;/*����Ԫ��*/ 
	p->data=e;
	return true;
}
//3����λ��ɾ�����
bool ListDelete(LinkList&L,int i,int e)
{
	//1�����i�Ϸ� 
	if(i<1)return false;
	//2����i-1��� 
	LNode*p=L;
	int j=0;
	while(p!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	//3��iֵ���Ϸ�
	if(p==NULL)
		return false;
	//4���Ƿ��п�ɾ���
	if(p->next==NULL)		/*��˲���ɾ��β���Ԫ�ص�ֵ����i����Ϊβ���*/ 
		return false;
	//5��ɾ��p�ĺ�̽ڵ㣬�� 
	LNode*q=p->next;
	e=q->data;
	p->next=q->next;
	free(q);
	return true; 
} 
//4��ָ������ɾ��
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
/*��ӡ��ʾ����Ԫ��*/
void Printf(LinkList&L)
{
	LNode*p=L;
	int j=0;
	while(p!=NULL){
		if(j>0)
			printf("��%d��Ԫ��Ϊ%d\n",j,p->data);
		p=p->next;
		j++;
	}
}
int main()
{
	LinkList L;
	if(InitList(L))printf("��ʼ�����\n");
	if(Empty(L))printf("Ϊ�ձ�\n");
		else printf("��Ϊ�ձ�\n");
/*���Ӽ���Ԫ��*/
	LNode*p=L;
	for(int i=0;i<5;i++)
	{
		LNode*s=(LNode*)malloc(sizeof(LNode));
		s->data=i;
		p->next=s;
		//����p���
		p=s;
		p->next=NULL;
	}
	Printf(L);
	printf("��ӡ���\n"); 
	//1�����Ժ�����
	if(InsertNextNode(p,10))	/*��ʱpΪβ���*/
		printf("������\n");
	else 
		printf("���δ���\n");
	Printf(L);
	//2������ǰ�����
	LNode*q=L->next;
	if(InsertPriorNode(q,20))	/*��ʱpΪβ���,��ͷ���֮��ǰ����Ԫ��20*/
		printf("ǰ�����\n");
	else 
		printf("ǰ��δ���\n");
	Printf(L);
	//3����λ��ɾ��
	int e;/*���ڷ��ر�ɾԪ��*/
	if(ListDelete(L,3,e))	/*ɾ������λԪ��*/
		printf("λ��ɾ�����\n");
	else 
		printf("ɾ��δ���\n");
	Printf(L);	
	//4��ָ������ɾ��
	LNode*s=L->next->next;
	if(DeleteNode(s))	/*��ɾ���ڶ������*/
			printf("ָ�����ɾ�����\n");
		else 
			printf("ָ��ɾ��δ���\n");
		Printf(L);	
	return 0;
}
