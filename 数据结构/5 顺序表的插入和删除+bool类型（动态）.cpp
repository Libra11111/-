#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
//����˳���̬ʵ�� 
typedef struct{
	int *data;
	int MaxSize;
	int length;
}SeqList;
//��ʼ��
void InitList(SeqList &L)
{
	L.data=(int*)malloc(InitSize*sizeof(int));
	L.length=0;
	L.MaxSize=InitSize;
} 
//���Ӷ�̬���鳤��
void IncreaseSize(SeqList &L,int len)
{
	/*1������ԭʼָ��*/ 
	int*p=L.data;
	/*2�����ٸ����µ�ַ*/ 
	L.data=(int*)malloc((L.MaxSize+len)*sizeof(int) );//�������鿪�ٵĿռ�
	/*3���������ݵ��µ�ַ��*/ 
	for(int i=0;i<=L.length;i++)
		L.data[i]=p[i];
	/*4������+len*/ 
	L.MaxSize=L.MaxSize+len;
	/*5������ɿռ�*/
	free(p);
}
//1������
bool ListInsert(SeqList &L,int i,int e)
{
	if(i<1||i>L.length+1)
		return false;
	if(L.length>L.MaxSize)
		return false;
	/*����ھ�̬���飬���嶯̬�����������������ͨ����������ɲ����Ҫ��*/
	if(L.length==L.MaxSize)
		IncreaseSize(L,1);
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;	 
	return true;
} 
//2��ɾ�� 
bool ListDelete(SeqList &L,int i,int &e)
{
	if(i<1||i>L.length)
		return false;
	e=L.data[i-1];
	for(int j=i;i<L.length;i++)
		L.data[j-1]=L.data[j];
	L.length--;
	return true; 
}
/*�ںϷ���Χ�ڴ�ӡ���ݣ�ѭ������Ϊmaxsize*/
void Printf(SeqList&L)
{
	for(int i=0;i<L.MaxSize;i++)
		printf("%d\n",L.data[i]);/*չʾ����������Ԫ��*/	 
}
int main()
{
	SeqList L;
	InitList(L);
	
	 /*ֱ�Ӹı�,�൱�ڲ��뼸��Ԫ�����㺯������Ҫ��,
	 		ͬʱҪע�ⲻ��ʹ����������������ͬ����������*/
	 	for(int i=0;i<10;i++)
		 	L.data[i]=i; 
		L.length=10;
	 	/*���Բ���*/ 
	 	if(ListInsert(L,3,3))
	 		printf("������ɣ�\n");/*λ��Ϊ3������Ԫ��3*/ 
	 	if(ListInsert(L,4,5))
	 		printf("������ɣ�\n");/*λ��Ϊ3������Ԫ��3*/ 	
	 	Printf(L);
	 	/*����ɾ��*/
	 	int e=-1;/*e���ڷ��ر�ɾ��ֵ*/ 
	 	if(ListDelete(L,4,e))
		 		printf("ɾ����4��Ԫ�أ�ɾ��Ԫ��ֵΪ=%d��\n",e);
		 	else 
		 		printf("λ�򲻺Ϸ���ɾ��ʧ��"); 
	 	Printf(L); 
	 	 
	 	return 0;
	/*����ɾ��������ȫ��ͬ*/ 
}
