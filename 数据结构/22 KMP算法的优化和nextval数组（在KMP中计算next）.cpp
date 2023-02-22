#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 255
//定义
typedef struct {
	char ch[MAXLEN];//数据域 
	int length;		//串长 
}SString;
//初始化 
void InitString(SString&T)
{
	int len;
	char c;
	printf("确定串长：");
	scanf("%d\n",&len);
	for(int i=1;i<=len;i++){
		scanf("%c",&c);
		T.ch[i]=c;
	}
	T.length=len;	
}
//1、求nextval数组
void get_next(SString T,int next[])
{
	int i=1,j=0;
	next[1]=0;
	while(i<T.length){
		if(j==0||T.ch[i]==T.ch[j]){
			++i;++j;//匹配成功，两下标均后移
			next[i]=j;
			if(T.ch[i]==T.ch[1])
				next[i]=0;/*与next[0]相同*/ 
		}else	
			j=next[j];//匹配不成功,回溯 
	}
	/*打印展示*/printf("nextval数组为：");
	for(int i=1;i<=T.length;i++){		 	/*输出的下标范围要与前面函数相匹配，从1开始*/
		printf(" %d",next[i]);			
	}		
}
//2、KMP算法 
int Index_KMP(SString S,SString T)
{
	int i=1,j=1;
	//1、声明next数组并计算 
	int next[T.length+1];		/*在函数中，形参可以当常数使用*/
	get_next(T,next);
	//2、匹配模式串 
	while(i<=S.length&&j<=T.length){	/*有一串完成遍历即可退出*/ 
		if(j==0||S.ch[i]==T.ch[j]){
			++i;++j;
		}else 
			j=next[j];
	}
	
	//3、匹配结束 
	if(j>T.length)
		return i-T.length;
	else 
		return 0; 
}
/*打印展示字符串*/
void Printf(SString T)
{
	for(int i=1;i<=T.length;i++)
		printf("%c ",T.ch[i]);
	printf("\n");
}
int main()
{
	//1、设置串S和模式串T 
	SString S,T;
	InitString(S);Printf(S);
	InitString(T);Printf(T);
	//2、进行匹配
	printf("\n结果为：%d",Index_KMP(S,T));
	return 0; 
}
/*测试完成*/
