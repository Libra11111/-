#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
//������� 
typedef struct {
	int data[MaxSize];
	int front,rear;
}SqQueue;/*����*/
//1����ʼ��
bool InitQueue(SqQueue&Q)/*L������S��ջ��������Q*/
{
	Q.rear=Q.front=0; 
	return true;/*bool����ֵ�ĺô����ڿ�����ʱ�÷���ֵ���е���չʾ*/ 
}
//2���п�
bool QueueEmpty(SqQueue Q)
{
	return (Q.front==Q.rear);
}
//3����� 
bool EnQueue(SqQueue&Q,int x)
{
	//1���ж϶��� 
	if(Q.front==(Q.rear+1)%MaxSize)
		return false;
	//2����Ԫ�ز����β 
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize;/*��βָ���1ȡģ*/
	return true;
}
//4������
bool DeQueue(SqQueue&Q,int&x)
{
	//1���ж϶ӿ�
	if(Q.front==Q.rear)
		return false;
	//2��ȡ����
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true; 
}
//5����ѯ��ͨ��Ϊ��ȡ��ͷԪ�أ�
bool GetHead(SqQueue Q,int&x)
{
	/*�ͺͳ��Ӳ���һģһ����ʡȥ��ͷָ��ĺ��Ƽ���*/
	if(Q.rear==Q.front)
		return false;
	x=Q.data[Q.front];
	return true;
}
/*6������Ԫ�ظ��� 
	(rear+MaxSize-front)%MaxSize	ʵ����ȡ���Ƿ�ֹrear>frontʱ����һ��MaxSizeֵ 
	
	*/
void Printf(SqQueue Q)
{
	printf("����Ԫ�����£�\n");
	for(int i=0;i<(Q.rear+MaxSize-Q.front)%MaxSize;i++)/*�����ڱ����о������˶��г��ȵĶ���*/
		printf("%d\n",Q.data[(Q.front+i)%MaxSize]);
	printf("����\n");
} 
int main()
{
	SqQueue Q;
	InitQueue(Q);
	for(int i=0;i<5;i++)
	{
		EnQueue(Q,i);
	}
	Printf(Q);
	int x=0;
	DeQueue(Q,x);
	printf("����Ԫ��Ϊ%d\n",x);
	DeQueue(Q,x);
	printf("����Ԫ��Ϊ%d\n",x);
	GetHead(Q,x); 
	printf("��ѯ��ͷԪ��Ϊ��%d\n",x);
	Printf(Q);
	return 0;
}

/*�������ֶ��峤�Ȼ���������пյķ�����
2���ڶ��нṹ�嶨���ϼ���int size���ڼ�¼���г��ȣ�
3���ṹ���ж���int tag =0/1 ���ڱ�����һ�ν��е���ɾ��/����
	���ӿ�������front=rear & tag=0
		��������: ~ & tag = 1) 
	*/
