#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 255
//Sub的定义 
typedef struct{
	char ch[MAXLEN];	//每个分量储存一个字符
	int length;			//串的实际长度 
}SString;
void Printf(SString S);
/*1、串的初始化*/
bool InitString(SString&S)
{
	int len;
	char c;			/***************临时字符char c的利用时必要的，保证输入可以正常进行，且不用直接调用串的地址*/
	printf("确定要输入的串长：(确定后直接输入完整字符串)");
	scanf("%d\n",&len);		/*在输入后加\n,防止在换行中手动加上的换行被读入下一行scanf中*/ 
	for(int i=0;i<len;i++){
		scanf("%c",&c);		/*在输入中录入完整字符串，scanf会自动根据循环次数进行读取*/
		S.ch[i]=c;
	}
	S.length=len;
	return true;
} 
//1、求子串
bool SubString(SString&Sub,SString S,int pos,int len)	/*sub用于返回子串，S为传入函数的原串，从第pos个字符处开始取len个长度的字符*/
{
	//1、判断长度有效性
	if(pos+len>S.length+1)
		return false;	/*子串范围越界*/
	//2、读串
	for(int i=pos;i<pos+len;i++)/*从pos处开始赋值*/
		Sub.ch[i-pos]=S.ch[i];
	Sub.length=len;
	return true;
}
//2、比较操作	
int StrCompare(SString S,SString T)
{
	//1、以S或T的遍历结束 
	for(int i=0;i<S.length&&i<T.length;i++)		/*调试了很久发现这一句出现问题，按目前结构要求i从0开始，循环次数与长度关系要用<*/ 
	{
		if(S.ch[i]!=T.ch[i]){
			return S.ch[i]-T.ch[i];
		}		/*若S>T，则返回值>0	若S<T，则返回值<0*/
	}
	//2、扫描过的字符都相同，则长度大的串在比较中更大 
	return S.length-T.length; 
}
//3、定位操作
int Index(SString S,SString T)
{
	int i=0,n=S.length,m=T.length;	/*n,m保存两串的长度值*/		/*i=0表示从串起始位置开始，若i=1说明串在存储时在i第一个位置留了空格*/
	SString sub;
	/*用Sub返回S串中在i位置后m个长度的子串*/
	while(i<n-m+1){
		SubString(sub,S,i,m); 
		if(StrCompare(sub,T))	i++; 
			else return i;//返回子串在主串中的位置 
	}
	return 0;//S中不存在与T相等的子串 		/*遍历后仍未得到T的位置 
}
/*打印展示串值*/
void Printf(SString S)
{
	for(int i=0;i<S.length;i++)
	{
		printf("%c ",S.ch[i]);
	}
	printf("\n");
}

int main()
{
	SString S,T;
	//1、初始化
	InitString(S);
	Printf(S); 
	//2、求子串 
	if(SubString(T,S,2,5))
		Printf(T); 
	else printf("未找到子串\n");
	//3、比较操作
	if(StrCompare(S,T)>0)
		printf("S比T更长\n");
	else if(StrCompare(S,T)<0)
		printf("T比S更长\n");
	//4、定位
	SString sub;
	SubString(sub,S,2,5);
	if(StrCompare(sub,T)==0)
		printf("两串相同\n\n");/*用于调试*/
		
	printf("T为S的第%d位子串",Index(S,T)); 
	return 0;
}
/*测试完成*/ 
