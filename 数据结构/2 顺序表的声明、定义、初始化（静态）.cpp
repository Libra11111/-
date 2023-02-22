#include<stdio.h>
#include<string>
#define MaxSize 10
//1、声明 
typedef struct{
	int data[MaxSize];	//用静态的数组存放数据元素 
	int length;			//当前表长 
}SqList;//顺序表的类型定义（静态分配） 
 
void InitList(SqList&L)
{
	for(int i=0;i<MaxSize;i++)
		L.data[i]=0;
	L.length=0;
}
/*在合法范围内打印数据，循环次数为length而不是maxsize*/
void Printf(SqList&L)
{
	for(int i=0;i<L.length;i++)
		printf("%d\n",L.data[i]);/*若要显示打印数据，将length改为需要显示数即可*/	 
}

int main()
{
	//2、定义 
	SqList L;
	//3、初始化 
	InitList(L);
	
	Printf(L);
	
	
	
	
	return 0;
} 
