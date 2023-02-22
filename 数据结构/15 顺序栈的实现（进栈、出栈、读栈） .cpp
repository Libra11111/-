#include<stdio.h>
#include<stdlib.h>
//����ջ��Ԫ�ص������� 
#define MaxSize 10
typedef struct{
	int data[MaxSize];		//��̬������ջ��Ԫ��
	int top;				//ջ��ָ�� 
}SqStack;/*Sq:	sequence˳��*/
//1����ʼ�� 
void InitStack(SqStack&S){
	S.top=-1;	//��ʼ��ջ��ָ�� 
} 
//2���п� 
bool StackEmpty(SqStack S)
{
	return (S.top!=-1);
}
//3����ջ
bool Push(SqStack&S,int x)
{
	//1���ж�ջ�Ƿ�����
	if(S.top==MaxSize-1)	//ջ����ջ��ָ��ﵽ������ 
		return false; 
	//2��������ջ 
//	S.top=S.top+1;		//ָ���ȼ�1 
//	S.data[S.top]=x;	//��Ԫ����ջ 	�ȼ���--> 
	S.data[++S.top]=x;		/*++��ǰ��ʾ����������ٽ���,top��ʼΪ-1*/ 
	return true; 
}
//4����ջ
bool Pop(SqStack&S,int &x)
{
	//1���ж�ջ�Ƿ�Ϊ�� 
	if(S.top==-1)	//ջ�ձ��� 
		return false;
	//2�����ݳ�ջ
	x=S.data[S.top--];		/*�������߼��ϱ�ɾ��*/
	return true;
} 
//5����ջ�����������ջ��Ԫ�أ� 
bool GetTop(SqStack S,int&x)
{
	//1���ж�ջ�Ƿ�Ϊ�� 
	if(S.top==-1)	//ջ�ձ��� 
		return false;
	//2�����ݳ�ջ
	x=S.data[S.top];		/*Ψһ���𣺶�ջ���ı�topֵ*/
	return true;	
}
/*������ӡ*/
void Printf(SqStack&S)
{
	for(int i=0;i<=S.top;i++)/*����*/ 
	{
		printf("%d\n",S.data[i]);
	} 	
} 
//6������һ��˳��ջ 
void testStack()
{
	SqStack S;	/*	S��stack����д����ʾ����Ϊջ	*/
	/*1������ + ��ʼ��*/
	InitStack(S);
	/*2���п�*/
	if(StackEmpty(S))
		printf("˳��ջΪ��\n");
	else printf("˳��ջ��Ϊ��\n");
	/*3����ջ*/
	Push(S,0);
	Push(S,1);
	Push(S,2);
	Push(S,3);
	Push(S,4);
	Printf(S);
	/*4����ջ*/
	int x;
	Pop(S,x);
	printf("��ջԪ��Ϊ��%d\n",x);
	Printf(S);
}
int main()
{
	testStack();
}
