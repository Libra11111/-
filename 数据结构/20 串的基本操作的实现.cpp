#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 255
//Sub�Ķ��� 
typedef struct{
	char ch[MAXLEN];	//ÿ����������һ���ַ�
	int length;			//����ʵ�ʳ��� 
}SString;
void Printf(SString S);
/*1�����ĳ�ʼ��*/
bool InitString(SString&S)
{
	int len;
	char c;			/***************��ʱ�ַ�char c������ʱ��Ҫ�ģ���֤��������������У��Ҳ���ֱ�ӵ��ô��ĵ�ַ*/
	printf("ȷ��Ҫ����Ĵ�����(ȷ����ֱ�����������ַ���)");
	scanf("%d\n",&len);		/*��������\n,��ֹ�ڻ������ֶ����ϵĻ��б�������һ��scanf��*/ 
	for(int i=0;i<len;i++){
		scanf("%c",&c);		/*��������¼�������ַ�����scanf���Զ�����ѭ���������ж�ȡ*/
		S.ch[i]=c;
	}
	S.length=len;
	return true;
} 
//1�����Ӵ�
bool SubString(SString&Sub,SString S,int pos,int len)	/*sub���ڷ����Ӵ���SΪ���뺯����ԭ�����ӵ�pos���ַ�����ʼȡlen�����ȵ��ַ�*/
{
	//1���жϳ�����Ч��
	if(pos+len>S.length+1)
		return false;	/*�Ӵ���ΧԽ��*/
	//2������
	for(int i=pos;i<pos+len;i++)/*��pos����ʼ��ֵ*/
		Sub.ch[i-pos]=S.ch[i];
	Sub.length=len;
	return true;
}
//2���Ƚϲ���	
int StrCompare(SString S,SString T)
{
	//1����S��T�ı������� 
	for(int i=0;i<S.length&&i<T.length;i++)		/*�����˺ܾ÷�����һ��������⣬��Ŀǰ�ṹҪ��i��0��ʼ��ѭ�������볤�ȹ�ϵҪ��<*/ 
	{
		if(S.ch[i]!=T.ch[i]){
			return S.ch[i]-T.ch[i];
		}		/*��S>T���򷵻�ֵ>0	��S<T���򷵻�ֵ<0*/
	}
	//2��ɨ������ַ�����ͬ���򳤶ȴ�Ĵ��ڱȽ��и��� 
	return S.length-T.length; 
}
//3����λ����
int Index(SString S,SString T)
{
	int i=0,n=S.length,m=T.length;	/*n,m���������ĳ���ֵ*/		/*i=0��ʾ�Ӵ���ʼλ�ÿ�ʼ����i=1˵�����ڴ洢ʱ��i��һ��λ�����˿ո�*/
	SString sub;
	/*��Sub����S������iλ�ú�m�����ȵ��Ӵ�*/
	while(i<n-m+1){
		SubString(sub,S,i,m); 
		if(StrCompare(sub,T))	i++; 
			else return i;//�����Ӵ��������е�λ�� 
	}
	return 0;//S�в�������T��ȵ��Ӵ� 		/*��������δ�õ�T��λ�� 
}
/*��ӡչʾ��ֵ*/
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
	//1����ʼ��
	InitString(S);
	Printf(S); 
	//2�����Ӵ� 
	if(SubString(T,S,2,5))
		Printf(T); 
	else printf("δ�ҵ��Ӵ�\n");
	//3���Ƚϲ���
	if(StrCompare(S,T)>0)
		printf("S��T����\n");
	else if(StrCompare(S,T)<0)
		printf("T��S����\n");
	//4����λ
	SString sub;
	SubString(sub,S,2,5);
	if(StrCompare(sub,T)==0)
		printf("������ͬ\n\n");/*���ڵ���*/
		
	printf("TΪS�ĵ�%dλ�Ӵ�",Index(S,T)); 
	return 0;
}
/*�������*/ 
