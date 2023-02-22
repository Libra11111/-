#include<stdio.h>
#include<stdlib.h>
//˫�������� 
typedef struct DNode
{
	int data;	//������ 
	struct DNode *prior,*next;//ǰ���ͺ��ָ�� 
}DNode,*DLinkList;
//1����ʼ��				/*��ʼ�����ǽ���ָ��ָ��NULL*/
bool InitDLinkList(DLinkList&L)
{
	//1��Ϊ���ݽṹ���ٿռ� 
	L=(DNode*)malloc(sizeof(DNode));
	//2�����ڴ治�㣬�����ʧ��
	if(L==NULL)
		return false;
	//3����ָ���ÿ� 
	L->prior=NULL;		/*ͷ����ǰ��ʼ��Ϊ��*/ 
	L->next=NULL;		/*���ڵ����ʱ��û�н��*/ 
	return true; 
} 
//2��˫�����п� 
bool Empty(DLinkList&L)
{
	return (L->next==NULL);
} 
//3������� 
bool InsertNextDNode(DNode*p,DNode*s)/*��p�������s���*/
{
	//1�����������Ƿ����ɲ����������ԣ�
	if(p==NULL||s==NULL)
		return false;
	//2�����	(��s���뵽p��q���֮��)
	s->next=p->next;
	if(p->next!=NULL)	/*��̽ڵ㲻Ϊ�գ�����̵�ǰ��ָ��s*/
		p->next->prior=s;/*������s��q*/ 
	p->next=s; 
	s->prior=p;/*������p��s*/
	return true;
}
/*˫�������ͨ��ǰ��ָ�뽫ǰ�����ת��Ϊ��ǰ�����ĺ��*/
//4��ɾ��
bool DeleteNextDNode(DNode*p)/*ɾ��p���ĺ�̽��*/
{
	//1���������Ƿ���Ч ��p����Ϊ�գ� 
	if(p==NULL)
		return false;
	//2��p��̲�Ϊ��
	DNode *q=p->next;
	if(q==NULL)
		return false;
	//3��ɾ��q���
	p->next=q->next;
	/*��q�ĺ�̲�ΪNULL��q��Ϊβ��㣩*/
	if(q->next!=NULL)
		q->next->prior=p;
	free(q);
	return true; 
}
//5�����
bool DestroyDList(DLinkList&L)
{
	//1��ѭ���ͷŸ������ݽ��
	while(L->next!=NULL)
		DeleteNextDNode(L);/*ѭ��ɾ��ͷ���ĺ�̽ڵ�*/ 
	//2�� �ͷ�ͷ��� 
	free(L);
	L=NULL;/*ͷ���ָ��NULL*/
	return true;
}
//6��˫����ı��� 
/*
	1���������
	while(p!=NULL){
		//��ͷ�������Ӧ�������ӡ 
		p=p->next;
	}
	2��ǰ�����
	while(p!=NULL){
		//~
		p=p->prior;
	}
	3��ǰ�����������ͷ��㣩
	while(p->prior!=NULL){		/*p��ָ��ͷ��� 
		//~
		p=p->prior;
	}
	*/
/*��ӡ��ʾ*/
void Printf(DLinkList L)
{
	DNode*p=L;
	while(p->next!=NULL){
		p=p->next;
		printf("%d\n",p->data);
	}
	printf("��ӡ���\n"); 
}

int main()
{
	DLinkList L;
	//1����ʼ�� 
	InitDLinkList(L);
	//2���п�
	//3������
	DNode*p=L;/*β���ָ��*/
	for(int i=0;i<5;i++){
		DNode*s=(DNode*)malloc(sizeof(DNode));
		s->data=i;
		s->next=NULL;
		InsertNextDNode(p,s);
		p=s;/*��ѭ���в���free��s��*/
	}
	Printf(L);
 	//4��ɾ��
 	p=p->prior;
 	if(DeleteNextDNode(p))
 		printf("ɾ�����\n");
 	else
 		printf("ɾ��δ���\n");
	Printf(L);
 	DestroyDList(L);
 	return 0;
} 



















