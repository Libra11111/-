#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
//����˳���̬ʵ�� 
typedef struct{
	int *data;
	int length;
	int MaxSize;
}SeqList;
//��ʼ��
void InitList(SeqList &L)
{
	L.data=(int*)malloc(InitSize*sizeof(int));
	L.length=0;
	L.MaxSize=InitSize;
}
//���Ӷ�̬����ĳ��� 
void IncreaseList(SeqList &L,int len)
{
	int *p=L.data;
	L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++)
		L.data[i]=p[i];
	L.MaxSize=L.MaxSize+len;
	free(p);
} 
//1����λ����
int GetElem(SeqList &L,int i)/*Ҫ����ֵ��������Ϊget*/ 
{
	return L.data[i-1];  
} 
//2����ֵ���� 
int LocateElem(SeqList &L,int e)/*Ҫ����λ�ã��ʺ�����ΪLocate*/ 
{
	for(int i=0;i<=L.length;i++)
		if(L.data[i]==e)
			return i+1;
	return 0;/*Ϊ����ѭ�������ɷ���i+1ʱ������Ч��λ��0*/	
	
}
int main()
{
	SeqList L;
	InitList(L);
	/*��������ֵ*/
	for(int i=0;i<L.MaxSize;i++)
		L.data[i]=i;
	L.length=L.MaxSize;/*һ��Ҫע���޸ı�*/
	//���԰�λ���� 
	printf("��λ���ң���5λԪ��Ϊ=%d\n",GetElem(L,5)); 
	//���԰�ֵ���� 
	printf("��ֵ���ң�ֵΪ5��Ԫ���ڵ�%dλ",LocateElem(L,5));
	return 0;
}
