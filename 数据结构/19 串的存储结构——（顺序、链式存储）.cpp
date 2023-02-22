#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 255 	//预定义最大串长为255 

//顺序存储 
typedef struct {
	char ch[MAXLEN];	//每个分量存储一个字符 
	int length;			//串的实际长度 
}SString;
//动态数组
typedef struct{
	char*ch;
	int length;
}SSString; 
//链式存储
typedef struct {
	char ch[4];		/*一个结点中存放多个元素*/
	int length;
	StringNode *next;
}StringNode,*String;	/*其实由于结点的逻辑与链表相同，命名结构也相同*/
//
int main()
{
	
}
