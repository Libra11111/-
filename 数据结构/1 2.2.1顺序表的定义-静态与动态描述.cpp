#include<stdio.h>
#include<string>
#define MaxSize 50		//定义线性表的最大高度
/*1、静态分配一维数组*/ 
typedef struct{
	int data[MaxSize];	//顺序表的元素 
	int length;			//顺序表的当前长度 
}SqList;			//顺序表的类型定义 			
/*2、动态分配一维数组*/
typedef struct{
	int *data;	//指示动态分配数组的指针 
	int Maxsize,length;			//数组的最大容量和当前个数 
}SeqList;			//动态分配数组顺序表的类型定义 	
/*--->
	C的初始分配语句为：
		L.data=(ElemType*)malloc(sizeof(ElemType)*InitSize);			/*InitSize指一个字节 
	C++的初始分配语句为：
		L.data=new ElemType[InitSize];	
*/
/*
	注：动态分配并不是链式存储，它同样属于顺序存储结构，
		物理结构没有变化，依然是随机存取方式，只是分配的空间大小可以在运行时动态决定 
*/ 
 
int main()
{
	SqList q;/*创建线性表*/
	 
	return 0; 
} 
