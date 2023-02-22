#include<stdio.h>
#include<stdlib.h>
//����˳��ջ	
#define MaxSize 10
typedef struct{
	char data[MaxSize];		/*ע��Ӧ����ƥ�����ţ�elemtypeӦΪchar����*/ 
	int top;
}SqStack;
//��ʼ�� 
void InitStack(SqStack&S)
{
	S.top=-1;
} 
//�п�
bool StackEmpty(SqStack&S)
{
	return (S.top==-1);
} 
//��ջ
bool Push(SqStack&S,char x)
{
	//1������ 
	if(S.top==MaxSize-1)
		return false; 
	//2������+������ 
	S.data[++S.top]=x;
	return true; 
} 
//��ջ
bool Pop(SqStack&S,char&x)
{
	//1���п�
	if(S.top==-1)
		return false;
	//2��ȡ����+ǰ��
	x=S.data[S.top--];
	return true; 
} 
/*��ӡչʾ*/
void Printf(SqStack S)
{
	printf("ջ��Ԫ����%d��\n",S.top+1);
	for(int i=0;i<=S.top;i++)
		printf("%c\n",S.data[i]);
	
} 
//ջ������ƥ���е�Ӧ�� 
bool bracketCheck(char str[],int length)
{
	SqStack S;
	//1����ʼ��һ��ջ 
	InitStack(S);
	for(int i=0;i<length;i++){ 
		/**/printf("��%d��ѭ����",i);
		if(str[i]=='('||str[i]=='['||str[i]=='{'){ 
			Push(S,str[i]);//ɨ�赽�����ţ���ջ
			/**/printf("��ջ���\n");
			/**/Printf(S);
		}else{
			if(StackEmpty(S)){//ɨ�赽�����ţ��ҵ�ǰջ�� 	/*ɨ�赽������ʱ����������������ջ�е�*/
				/**/printf("Ϊ��ջ\n"); 
				return false;//ƥ��ʧ��
				} 
			/**/printf("��ջ���\n");
		char topElem;//ջ��Ԫ�س�ջ 
		Pop(S,topElem);
		if((str[i]==')'&&topElem=='(')||
			(str[i]==']'&&topElem=='[')||
			(str[i]=='}'&&topElem=='{'))		/*������ƥ���û������������һ�𣬱�֤ƥ����ɵ��жϳ�֣���һ����ɼ���*/
			continue;	 
		else return false;
		}
	}
	//2��������ȫ�����ź�ջ��˵��ƥ��ɹ�
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
	printf("���¼�¼���Թ��̣�\n");
	if(bracketCheck(str,length))
		printf("\nƥ��ɹ�!\n");
	else printf("\nƥ�䲻�ɹ�!\n");
	return 0; 
}
