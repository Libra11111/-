#include<stdio.h>
#include<string>
#define MaxSize 10
//1������ 
typedef struct{
	int data[MaxSize];	//�þ�̬������������Ԫ�� 
	int length;			//��ǰ�� 
}SqList;//˳�������Ͷ��壨��̬���䣩 
 
void InitList(SqList&L)
{
	for(int i=0;i<MaxSize;i++)
		L.data[i]=0;
	L.length=0;
}
/*�ںϷ���Χ�ڴ�ӡ���ݣ�ѭ������Ϊlength������maxsize*/
void Printf(SqList&L)
{
	for(int i=0;i<L.length;i++)
		printf("%d\n",L.data[i]);/*��Ҫ��ʾ��ӡ���ݣ���length��Ϊ��Ҫ��ʾ������*/	 
}

int main()
{
	//2������ 
	SqList L;
	//3����ʼ�� 
	InitList(L);
	
	Printf(L);
	
	
	
	
	return 0;
} 
