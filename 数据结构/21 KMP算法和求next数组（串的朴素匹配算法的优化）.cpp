#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 255
typedef struct {
	char ch[MAXLEN];	//������ 
	int length;			//���� 
}SString;
//��ʼ��
void InitString(SString&S)	/*�Դ�����������޸ĵĲ�����һ��Ҫ�����ã���������*/ 
{
	int len;
	char c;
	printf("ȷ��������");
	scanf("%d\n",&len); 
	for(int i=1;i<=len;i++)	/*�����뵽ƥ��Դ�������ͳһ���±궼��1��ʼ*/ 
	{
		scanf("%c",&c);
		S.ch[i]=c;
	}
	S.length=len;
}
//1���󴮵�next����
int get_next(SString T,int next[])/*next����ǰ�趨����*/
{
	int i=1,j=0;
	next[1]=0;/*next���� ��λnext[1]��Ϊ0,next[2]��Ϊ1������nextval�Ż�֮ǰ��ԭ�������*/
	while(i<T.length){
		if(j==0||T.ch[i]==T.ch[j]){
			++i;++j;
			//��pi=pj,��next[j+1]=next+1;
			next[i]=j; 
		}else	//����j=next[j],ѭ������ 
			j=next[j]; 			/*next[j]��jӦ��Ҫ���ݵ���λ�ã���i�ϸ�>j*/
	}
}
//2��KMP�㷨����������ƥ���㷨���Ż�
int Index_KMP(SString S,SString T,int next[])/*�˴���Ҫ��������ɿ��ٵ�next���飬���ɽ�һ���Ż���next������KMP�㷨��*/
{
	int i=1,j=1;	
	//1��ƥ����� 
	while(i<=S.length&&j<=T.length){
		if(j==0||S.ch[i]==T.ch[j]){
			++i;++j;//�����ȽϺ����ַ�  
		}else 
			j=next[j];//ģʽ�������ƶ� 		/*i�����ݣ�ƥ��ʧ��ʱ��ģʽ���±�j�����ƶ� 
	}
	//2��ƥ����� 
		/**/printf("\nƥ�����ʱ��i=%d��j=%d\n",i,j); 
	if(j>T.length)	
		return i-T.length;//ƥ��ɹ� 
	else 
		return 0;
} 
/*��ӡչʾ��ֵ*/
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
	//1�����ô�S��ģʽ��T 
	SString S,T;
	InitString(S);Printf(S);
	InitString(T);Printf(T);
	/**/
	//2�����ò����T��next���� 
	int*next=(int*)malloc(T.length*sizeof(int));
	get_next(T,next);	
	/*չʾ*/printf("T��next����Ϊ��"); 
	for(int i=1;i<=T.length;i++){		 /*������±귶ΧҪ��ǰ�溯����ƥ�䣬��1��ʼ*/
		printf(" %d",next[i]);			
	}
	//3������ƥ��
	int ret=Index_KMP(S,T,next); 
	printf("\n���Ϊ��%d",ret);
	return 0; 
} 
/*������ɣ���λ������index��ͬ*/
