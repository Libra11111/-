#include<stdio.h>
#include<stdlib.h> 
#define InitSize 10	/*顺序表初始长度*/ 
//1、声明 
typedef struct 
{
	int *data;//指示动态分配数组的指针
	int MaxSize;//顺序表的最大容量
	int length;//顺序表的当前长度 
}SeqList;//顺序表的类型定义（动态分配方式） 

//2、初始化
void InitList(SeqList &L)
{
	L.data=(int*)malloc(InitSize*sizeof(int));
	L.length=0;
	L.MaxSize=InitSize;/*初始最大容量为InitSize*/
} 
//3、增加动态数组长度
void IncreaseSize(SeqList &L,int len)
{
	/*1、保留原始指针*/ 
	int *p=L.data;
	/*2、开辟更大的新地址*/ 
	L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));/*先根据顺序表中数组大小进行重新开辟空间*/
	/*3、复制数据*/
	for(int i=0;i<L.length;i++)
		L.data[i]=p[i];
	/*4、容量+len*/ 
	L.MaxSize=L.MaxSize+len;
	free(p); 
} 
/*在合法范围内打印容量，length始终为0 不用修改 
循环次数本应为length，这里用于检验顺序表的容量，
*/
void Printf(SeqList&L)
{
	for(int i=0;i<L.MaxSize;i++)
		printf("%d\n",L.data[i]);/*若要显示打印数据，将length改为10即可*/	 
}

int main()
{
	//定义 
	SeqList L;
	//初始化 
	InitList(L);
	//打印展示顺序表元素 
	Printf(L);
	/*调试用函数*/
	system("pause");
	system("cls");
	
	IncreaseSize(L,5);
	Printf(L);
	
		
	return 0;
} 
