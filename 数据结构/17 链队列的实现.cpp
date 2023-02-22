#include<stdio.h>
#include<stdlib.h>
//1��������������������� 
typedef struct LinkNode{
	int data;
	struct LinkNode *next;/*��ʵLinkNode����LNode����д*/ 
}LinkNode;
typedef struct {
	LinkNode *front,*rear;//�����еĶ�ͷ�Ͷ�βָ�� 
}LinkQueue;  
//2����ʼ��
void InitQueue(LinkQueue&Q){
	//��ʼ����front��rear��ָ��ͷ���
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL; 
} 
//3���п�
bool IsEmpty(LinkQueue Q)
{
	return (Q.front==Q.rear);
} 
//4����ӣ���ͷ��㣩
void EnQueue(LinkQueue&Q,int x)
{
	//1�������½��s������ʼ�� 
	LinkNode*s=(LinkNode*)malloc(sizeof(LinkNode));
	s->data=x;
	s->next=NULL;
	//2�������½ڵ�+���� 
	Q.rear->next=s;	/*�½ڵ���뵽rear֮��*/ 
	Q.rear=s;		/*rear����*/ 
}
//5������
bool DeQueue(LinkQueue&Q,int&x)
{
	//1���п�
	if(Q.front==Q.rear)
		return false;/*ͷβ�غϣ��ն�*/ 
	//2��ȡ����	�� ��������������ڵ�Ϊָ����ʽ����Ҫ�ü�ͷ->ָʾ�� 
	LinkNode*p=Q.front->next;/*p��ͷ������һλ�ã��������е�һ������Ԫ�صĽڵ�*/
	x=p->data;	
	Q.front->next=p->next;/*����*/ 
	//3����ֻ��һ���ڵ㣬��rearָ��front
	if(p->next==NULL)
		Q.rear=Q.front;
	free(p);
	return false; 
} 
/*������ӡ*/
void Printf(LinkQueue&Q)
{
	printf("����Ԫ�����£�\n");
	for(LinkNode*p=Q.front;p->next!=NULL;){
		p=p->next;
		printf("%d ",p->data);
	}
	printf("����\n");
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
		printf("����Ԫ��Ϊ��%d\n",x);
	}
	Printf(Q);
	return 0;
}
/*�����Ǵ�ͷ���������У�
	����ͷ�ڵ���
	1���ڳ�ʼ����Ϊ	front=NULL��rear=NULL
	2���ڴ����һ���ڵ�ʱ�������п� 
		if(Q.front==NULL){
			Q.front=s;
			Q.rear=s; 
			}
		*/
