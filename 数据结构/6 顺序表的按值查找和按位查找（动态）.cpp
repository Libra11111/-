#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
//声明顺序表动态实现 
typedef struct{
	int *data;
	int length;
	int MaxSize;
}SeqList;
//初始化
void InitList(SeqList &L)
{
	L.data=(int*)malloc(InitSize*sizeof(int));
	L.length=0;
	L.MaxSize=InitSize;
}
//增加动态数组的长度 
void IncreaseList(SeqList &L,int len)
{
	int *p=L.data;
	L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++)
		L.data[i]=p[i];
	L.MaxSize=L.MaxSize+len;
	free(p);
} 
//1、按位查找
int GetElem(SeqList &L,int i)/*要返回值，函数名为get*/ 
{
	return L.data[i-1];  
} 
//2、按值查找 
int LocateElem(SeqList &L,int e)/*要返回位置，故函数名为Locate*/ 
{
	for(int i=0;i<=L.length;i++)
		if(L.data[i]==e)
			return i+1;
	return 0;/*为进入循环，不可返回i+1时即得无效的位序0*/	
	
}
int main()
{
	SeqList L;
	InitList(L);
	/*遍历赋初值*/
	for(int i=0;i<L.MaxSize;i++)
		L.data[i]=i;
	L.length=L.MaxSize;/*一定要注意修改表长*/
	//测试按位查找 
	printf("按位查找：第5位元素为=%d\n",GetElem(L,5)); 
	//测试按值查找 
	printf("按值查找：值为5的元素在第%d位",LocateElem(L,5));
	return 0;
}
