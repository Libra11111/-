#include<stdio.h>
#include<string>
#define MaxSize 50		//�������Ա�����߶�
/*1����̬����һά����*/ 
typedef struct{
	int data[MaxSize];	//˳����Ԫ�� 
	int length;			//˳���ĵ�ǰ���� 
}SqList;			//˳�������Ͷ��� 			
/*2����̬����һά����*/
typedef struct{
	int *data;	//ָʾ��̬���������ָ�� 
	int Maxsize,length;			//�������������͵�ǰ���� 
}SeqList;			//��̬��������˳�������Ͷ��� 	
/*--->
	C�ĳ�ʼ�������Ϊ��
		L.data=(ElemType*)malloc(sizeof(ElemType)*InitSize);			/*InitSizeָһ���ֽ� 
	C++�ĳ�ʼ�������Ϊ��
		L.data=new ElemType[InitSize];	
*/
/*
	ע����̬���䲢������ʽ�洢����ͬ������˳��洢�ṹ��
		����ṹû�б仯����Ȼ�������ȡ��ʽ��ֻ�Ƿ���Ŀռ��С����������ʱ��̬���� 
*/ 
 
int main()
{
	SqList q;/*�������Ա�*/
	 
	return 0; 
} 
