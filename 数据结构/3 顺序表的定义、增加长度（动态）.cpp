#include<stdio.h>
#include<stdlib.h> 
#define InitSize 10	/*˳����ʼ����*/ 
//1������ 
typedef struct 
{
	int *data;//ָʾ��̬���������ָ��
	int MaxSize;//˳�����������
	int length;//˳���ĵ�ǰ���� 
}SeqList;//˳�������Ͷ��壨��̬���䷽ʽ�� 

//2����ʼ��
void InitList(SeqList &L)
{
	L.data=(int*)malloc(InitSize*sizeof(int));
	L.length=0;
	L.MaxSize=InitSize;/*��ʼ�������ΪInitSize*/
} 
//3�����Ӷ�̬���鳤��
void IncreaseSize(SeqList &L,int len)
{
	/*1������ԭʼָ��*/ 
	int *p=L.data;
	/*2�����ٸ�����µ�ַ*/ 
	L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));/*�ȸ���˳����������С�������¿��ٿռ�*/
	/*3����������*/
	for(int i=0;i<L.length;i++)
		L.data[i]=p[i];
	/*4������+len*/ 
	L.MaxSize=L.MaxSize+len;
	free(p); 
} 
/*�ںϷ���Χ�ڴ�ӡ������lengthʼ��Ϊ0 �����޸� 
ѭ��������ӦΪlength���������ڼ���˳����������
*/
void Printf(SeqList&L)
{
	for(int i=0;i<L.MaxSize;i++)
		printf("%d\n",L.data[i]);/*��Ҫ��ʾ��ӡ���ݣ���length��Ϊ10����*/	 
}

int main()
{
	//���� 
	SeqList L;
	//��ʼ�� 
	InitList(L);
	//��ӡչʾ˳���Ԫ�� 
	Printf(L);
	/*�����ú���*/
	system("pause");
	system("cls");
	
	IncreaseSize(L,5);
	Printf(L);
	
		
	return 0;
} 
