#include<stdio.h>
#include<stdlib.h>
//定义栈中元素的最大个数 
#define MaxSize 10
typedef struct{
	int data[MaxSize];		//静态数组存放栈中元素
	int top;				//栈顶指针 
}SqStack;/*Sq:	sequence顺序*/
//1、初始化 
void InitStack(SqStack&S){
	S.top=-1;	//初始化栈顶指针 
} 
//2、判空 
bool StackEmpty(SqStack S)
{
	return (S.top!=-1);
}
//3、进栈
bool Push(SqStack&S,int x)
{
	//1、判断栈是否已满
	if(S.top==MaxSize-1)	//栈满（栈顶指针达到容量） 
		return false; 
	//2、数据入栈 
//	S.top=S.top+1;		//指针先加1 
//	S.data[S.top]=x;	//新元素入栈 	等价于--> 
	S.data[++S.top]=x;		/*++在前表示先完成扩容再进行,top初始为-1*/ 
	return true; 
}
//4、出栈
bool Pop(SqStack&S,int &x)
{
	//1、判断栈是否为空 
	if(S.top==-1)	//栈空报错 
		return false;
	//2、数据出栈
	x=S.data[S.top--];		/*数据在逻辑上被删除*/
	return true;
} 
//5、读栈操作·（获得栈顶元素） 
bool GetTop(SqStack S,int&x)
{
	//1、判断栈是否为空 
	if(S.top==-1)	//栈空报错 
		return false;
	//2、数据出栈
	x=S.data[S.top];		/*唯一区别：读栈不改变top值*/
	return true;	
}
/*遍历打印*/
void Printf(SqStack&S)
{
	for(int i=0;i<=S.top;i++)/*遍历*/ 
	{
		printf("%d\n",S.data[i]);
	} 	
} 
//6、测试一个顺序栈 
void testStack()
{
	SqStack S;	/*	S是stack的缩写，表示声明为栈	*/
	/*1、声明 + 初始化*/
	InitStack(S);
	/*2、判空*/
	if(StackEmpty(S))
		printf("顺序栈为空\n");
	else printf("顺序栈不为空\n");
	/*3、进栈*/
	Push(S,0);
	Push(S,1);
	Push(S,2);
	Push(S,3);
	Push(S,4);
	Printf(S);
	/*4、出栈*/
	int x;
	Pop(S,x);
	printf("出栈元素为：%d\n",x);
	Printf(S);
}
int main()
{
	testStack();
}
