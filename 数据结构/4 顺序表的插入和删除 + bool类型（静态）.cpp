#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
//声明 
typedef struct{
	int data[MaxSize];
	int length;
}SqList;
//初始化 
void InitList(SqList &L)
{
	for(int i=0;i<MaxSize;i++)/*静态数组直接赋初值即可，动态数组则为用malloc为指针开辟空间*/ 
		L.data[i]=0;
	L.length=0;
}
//1、插入 
bool ListInsert(SqList &L,int i,int e)
{
 	if(i<1||i>L.length+1)/*调试中，发现未加入随意插入元素时，length=0，不能完成插入函数合法性判定*/ 
 		return false;
  	if(L.length>=MaxSize)
 		return false;
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;
	return true;
}
//2、删除 
bool ListDelete(SqList &L,int i,int e)
{
	if(i<1||i>L.length)
		return false;
	e=L.data[i-1];
	for(int j=i;i<L.length;i++)//前移 
		L.data[j-1]=L.data[j];
	L.length--;
	return true;
} 
/*在合法范围内打印数据，循环次数为maxsize*/
void Printf(SqList&L)
{
	for(int i=0;i<MaxSize;i++)
		printf("%d\n",L.data[i]);/*展示容量内所有元素*/	 
}
int main()
{
	SqList L;
	InitList(L);
	/*直接改表长,相当于插入几个元素满足函数调用要求,
		同时要注意不能使表满，否则会溢出，同样不能满足*/
	L.length=5; 
	/*调试插入*/ 
	if(ListInsert(L,3,3))
		printf("插入完成！\n");/*位序为3处插入元素3*/ 
	if(ListInsert(L,4,5))
		printf("插入完成！\n");/*位序为3处插入元素3*/ 	
	Printf(L); 
	/*调试删除*/
	int e=-1;/*e用于返回被删除值*/ 
	if(ListDelete(L,4,e))
		printf("删除第4个元素，删除元素值为=%d！\n",e);
	else 
		printf("位序不合法，删除失败"); 
	Printf(L); 
	 
	return 0;
}
