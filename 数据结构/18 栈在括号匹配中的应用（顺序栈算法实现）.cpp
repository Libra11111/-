#include<stdio.h>
#include<stdlib.h>
//声明顺序栈	
#define MaxSize 10
typedef struct{
	char data[MaxSize];		/*注意应用是匹配括号，elemtype应为char类型*/ 
	int top;
}SqStack;
//初始化 
void InitStack(SqStack&S)
{
	S.top=-1;
} 
//判空
bool StackEmpty(SqStack&S)
{
	return (S.top==-1);
} 
//入栈
bool Push(SqStack&S,char x)
{
	//1、判满 
	if(S.top==MaxSize-1)
		return false; 
	//2、后移+插数据 
	S.data[++S.top]=x;
	return true; 
} 
//出栈
bool Pop(SqStack&S,char&x)
{
	//1、判空
	if(S.top==-1)
		return false;
	//2、取数据+前移
	x=S.data[S.top--];
	return true; 
} 
/*打印展示*/
void Printf(SqStack S)
{
	printf("栈中元素有%d个\n",S.top+1);
	for(int i=0;i<=S.top;i++)
		printf("%c\n",S.data[i]);
	
} 
//栈在括号匹配中的应用 
bool bracketCheck(char str[],int length)
{
	SqStack S;
	//1、初始化一个栈 
	InitStack(S);
	for(int i=0;i<length;i++){ 
		/**/printf("第%d次循环，",i);
		if(str[i]=='('||str[i]=='['||str[i]=='{'){ 
			Push(S,str[i]);//扫描到左括号，入栈
			/**/printf("入栈完成\n");
			/**/Printf(S);
		}else{
			if(StackEmpty(S)){//扫描到右括号，且当前栈空 	/*扫描到右括号时必须是有左括号在栈中的*/
				/**/printf("为空栈\n"); 
				return false;//匹配失败
				} 
			/**/printf("出栈完成\n");
		char topElem;//栈顶元素出栈 
		Pop(S,topElem);
		if((str[i]==')'&&topElem=='(')||
			(str[i]==']'&&topElem=='[')||
			(str[i]=='}'&&topElem=='{'))		/*将三组匹配用或运算符连接在一起，保证匹配完成的判断充分，有一组完成即可*/
			continue;	 
		else return false;
		}
	}
	//2、检索完全部括号后，栈空说明匹配成功
	return StackEmpty(S);
}
//
int main()
{
	char str[6]={'(',')','{','}','[',']'};
	int length=6;
	for(int i=0;i<length;i++){
		printf("str[%d] = %c\n",i,str[i]);
	}
	/**/
	printf("以下记录调试过程：\n");
	if(bracketCheck(str,length))
		printf("\n匹配成功!\n");
	else printf("\n匹配不成功!\n");
	return 0; 
}
