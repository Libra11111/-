#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 255
typedef struct {
	char ch[MAXLEN];	//数据域 
	int length;			//串长 
}SString;
//初始化
void InitString(SString&S)	/*对传入参数进行修改的操作，一定要加引用！！！！！*/ 
{
	int len;
	char c;
	printf("确定串长：");
	scanf("%d\n",&len); 
	for(int i=1;i<=len;i++)	/*从输入到匹配对串整体作统一，下标都从1开始*/ 
	{
		scanf("%c",&c);
		S.ch[i]=c;
	}
	S.length=len;
}
//1、求串的next数组
int get_next(SString T,int next[])/*next需提前设定容量*/
{
	int i=1,j=0;
	next[1]=0;/*next数组 首位next[1]必为0,next[2]必为1（在用nextval优化之前该原则成立）*/
	while(i<T.length){
		if(j==0||T.ch[i]==T.ch[j]){
			++i;++j;
			//若pi=pj,则next[j+1]=next+1;
			next[i]=j; 
		}else	//否则j=next[j],循环继续 
			j=next[j]; 			/*next[j]即j应该要回溯到的位置，且i严格>j*/
	}
}
//2、KMP算法（串的朴素匹配算法的优化
int Index_KMP(SString S,SString T,int next[])/*此处需要传入已完成开辟的next数组，还可进一步优化将next开辟在KMP算法内*/
{
	int i=1,j=1;	
	//1、匹配遍历 
	while(i<=S.length&&j<=T.length){
		if(j==0||S.ch[i]==T.ch[j]){
			++i;++j;//继续比较后续字符  
		}else 
			j=next[j];//模式串向右移动 		/*i不回溯，匹配失败时，模式串下标j进行移动 
	}
	//2、匹配结束 
		/**/printf("\n匹配结束时，i=%d，j=%d\n",i,j); 
	if(j>T.length)	
		return i-T.length;//匹配成功 
	else 
		return 0;
} 
/*打印展示串值*/
void Printf(SString S)
{
	for(int i=1;i<=S.length;i++)
	{
		printf("%c ",S.ch[i]);
	}
	printf("\n");
}

int main()
{
	//1、设置串S和模式串T 
	SString S,T;
	InitString(S);Printf(S);
	InitString(T);Printf(T);
	/**/
	//2、设置并求出T的next数组 
	int*next=(int*)malloc(T.length*sizeof(int));
	get_next(T,next);	
	/*展示*/printf("T的next数组为："); 
	for(int i=1;i<=T.length;i++){		 /*输出的下标范围要与前面函数相匹配，从1开始*/
		printf(" %d",next[i]);			
	}
	//3、进行匹配
	int ret=Index_KMP(S,T,next); 
	printf("\n结果为：%d",ret);
	return 0; 
} 
/*测试完成，定位功能与index相同*/
