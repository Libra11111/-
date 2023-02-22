#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
//���� 
typedef struct{
	int data[MaxSize];
	int length;
}SqList;
//��ʼ�� 
void InitList(SqList &L)
{
	for(int i=0;i<MaxSize;i++)/*��̬����ֱ�Ӹ���ֵ���ɣ���̬������Ϊ��mallocΪָ�뿪�ٿռ�*/ 
		L.data[i]=0;
	L.length=0;
}
//1������ 
bool ListInsert(SqList &L,int i,int e)
{
 	if(i<1||i>L.length+1)/*�����У�����δ�����������Ԫ��ʱ��length=0��������ɲ��뺯���Ϸ����ж�*/ 
 		return false;
  	if(L.length>=MaxSize)
 		return false;
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;
	return true;
}
//2��ɾ�� 
bool ListDelete(SqList &L,int i,int e)
{
	if(i<1||i>L.length)
		return false;
	e=L.data[i-1];
	for(int j=i;i<L.length;i++)//ǰ�� 
		L.data[j-1]=L.data[j];
	L.length--;
	return true;
} 
/*�ںϷ���Χ�ڴ�ӡ���ݣ�ѭ������Ϊmaxsize*/
void Printf(SqList&L)
{
	for(int i=0;i<MaxSize;i++)
		printf("%d\n",L.data[i]);/*չʾ����������Ԫ��*/	 
}
int main()
{
	SqList L;
	InitList(L);
	/*ֱ�Ӹı�,�൱�ڲ��뼸��Ԫ�����㺯������Ҫ��,
		ͬʱҪע�ⲻ��ʹ����������������ͬ����������*/
	L.length=5; 
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
}
