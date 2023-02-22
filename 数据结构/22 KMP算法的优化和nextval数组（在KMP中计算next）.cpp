#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 255
//����
typedef struct {
	char ch[MAXLEN];//������ 
	int length;		//���� 
}SString;
//��ʼ�� 
void InitString(SString&T)
{
	int len;
	char c;
	printf("ȷ��������");
	scanf("%d\n",&len);
	for(int i=1;i<=len;i++){
		scanf("%c",&c);
		T.ch[i]=c;
	}
	T.length=len;	
}
//1����nextval����
void get_next(SString T,int next[])
{
	int i=1,j=0;
	next[1]=0;
	while(i<T.length){
		if(j==0||T.ch[i]==T.ch[j]){
			++i;++j;//ƥ��ɹ������±������
			next[i]=j;
			if(T.ch[i]==T.ch[1])
				next[i]=0;/*��next[0]��ͬ*/ 
		}else	
			j=next[j];//ƥ�䲻�ɹ�,���� 
	}
	/*��ӡչʾ*/printf("nextval����Ϊ��");
	for(int i=1;i<=T.length;i++){		 	/*������±귶ΧҪ��ǰ�溯����ƥ�䣬��1��ʼ*/
		printf(" %d",next[i]);			
	}		
}
//2��KMP�㷨 
int Index_KMP(SString S,SString T)
{
	int i=1,j=1;
	//1������next���鲢���� 
	int next[T.length+1];		/*�ں����У��βο��Ե�����ʹ��*/
	get_next(T,next);
	//2��ƥ��ģʽ�� 
	while(i<=S.length&&j<=T.length){	/*��һ����ɱ��������˳�*/ 
		if(j==0||S.ch[i]==T.ch[j]){
			++i;++j;
		}else 
			j=next[j];
	}
	
	//3��ƥ����� 
	if(j>T.length)
		return i-T.length;
	else 
		return 0; 
}
/*��ӡչʾ�ַ���*/
void Printf(SString T)
{
	for(int i=1;i<=T.length;i++)
		printf("%c ",T.ch[i]);
	printf("\n");
}
int main()
{
	//1�����ô�S��ģʽ��T 
	SString S,T;
	InitString(S);Printf(S);
	InitString(T);Printf(T);
	//2������ƥ��
	printf("\n���Ϊ��%d",Index_KMP(S,T));
	return 0; 
}
/*�������*/
