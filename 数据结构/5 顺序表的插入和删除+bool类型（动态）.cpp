#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
//声明顺序表动态实现 
typedef struct{
	int *data;
	int MaxSize;
	int length;
}SeqList;
//初始化
void InitList(SeqList &L)
{
	L.data=(int*)malloc(InitSize*sizeof(int));
	L.length=0;
	L.MaxSize=InitSize;
} 
//增加动态数组长度
void IncreaseSize(SeqList &L,int len)
{
	/*1、保留原始指针*/ 
	int*p=L.data;
	/*2、开辟更大新地址*/ 
	L.data=(int*)malloc((L.MaxSize+len)*sizeof(int) );//扩大数组开辟的空间
	/*3、复制数据到新地址中*/ 
	for(int i=0;i<=L.length;i++)
		L.data[i]=p[i];
	/*4、容量+len*/ 
	L.MaxSize=L.MaxSize+len;
	/*5、清除旧空间*/
	free(p);
}
//1、插入
bool ListInsert(SeqList &L,int i,int e)
{
	if(i<1||i>L.length+1)
		return false;
	if(L.length>L.MaxSize)
		return false;
	/*相比于静态数组，定义动态数组扩增函数后可以通过调用来完成插入的要求*/
	if(L.length==L.MaxSize)
		IncreaseSize(L,1);
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;	 
	return true;
} 
//2、删除 
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
/*在合法范围内打印数据，循环次数为maxsize*/
void Printf(SeqList&L)
{
	for(int i=0;i<L.MaxSize;i++)
		printf("%d\n",L.data[i]);/*展示容量内所有元素*/	 
}
int main()
{
	SeqList L;
	InitList(L);
	
	 /*直接改表长,相当于插入几个元素满足函数调用要求,
	 		同时要注意不能使表满，否则会溢出，同样不能满足*/
	 	for(int i=0;i<10;i++)
		 	L.data[i]=i; 
		L.length=10;
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
	/*插入删除操作完全相同*/ 
}
