#include<stdio.h>
#include<stdlib.h>
//���� 
typedef struct LNode 
{
	int data;
	struct LNode *next; 
}LNode,*LinkList;
//1����ʼ��һ���յĵ�����
bool InitList(LinkList &L)
{
	L=NULL;
	return true;
} 
//2���жϿ������Ƿ�Ϊ��	
bool Empty(LinkList L)
{
	if(L==NULL)
		return true;
	else 
		return false; 
}
/*�򻯰�
bool Empty(LinkList L)
{
	return (L==NULL);/*��Ϊ����Ϊtrue\false
}*/
//3��λ�����
bool ListInsert(LinkList &L,int i,int e)
{
	//����i�Ϸ��� 
	if(i<1)
		return false;
	if(i==1){
		LNode*s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		s->next=L;
		L=s;
		return true;	
	}
	//������ʱ��㣨������㲻��malloc�� 
	LNode*p;
	int j=0;
	p=L;
	while(p!=NULL&&j<i-1)
	{/*���½��ŵ���i-1������*/ 
		p=p->next;
		j++;//ͨ��ѭ���ҵ�β��㣬��p 
	}
	//��p��ѭ����Ϊ����i���Ϸ� 
	if(p==NULL)
		return false;
	LNode*s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;/*�������䲻�ɵߵ�*/
	return true;
}
/*����չʾԪ�ص��������*/
void Printf(LinkList&L)
{
	LNode*p=L;/*�䵱ͷָ�룬���ڱ�������β���*/
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
	//��ʼ��һ���ձ�
	if(InitList(L))
		printf("��ͷ��������ʼ�����\n");
	if(Empty(L))
		printf("����Ϊ��,��ͷ���\n");
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
		p->next=NULL;//
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

/*����ͷ�ڵ㵥�����
ȱ������д�����鷳 
*/
