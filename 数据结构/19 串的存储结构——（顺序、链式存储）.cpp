#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 255 	//Ԥ������󴮳�Ϊ255 

//˳��洢 
typedef struct {
	char ch[MAXLEN];	//ÿ�������洢һ���ַ� 
	int length;			//����ʵ�ʳ��� 
}SString;
//��̬����
typedef struct{
	char*ch;
	int length;
}SSString; 
//��ʽ�洢
typedef struct {
	char ch[4];		/*һ������д�Ŷ��Ԫ��*/
	int length;
	StringNode *next;
}StringNode,*String;	/*��ʵ���ڽ����߼���������ͬ�������ṹҲ��ͬ*/
//
int main()
{
	
}
