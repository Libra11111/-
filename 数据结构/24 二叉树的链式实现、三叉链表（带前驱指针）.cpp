#include<stdio.h>
#include<stdlib.h>
//��ʽ�洢
typedef struct BiTNode{
	int data;
	struct BiTNode*lchild,*rchild;//���Һ���ָ�� 
}BiTNode,*BiTree;
//��ʼ��
void InitTree(BiTree&root)
{
	root=(BiTNode*)malloc(sizeof(BiTNode));
	root->data={1};	/*��ʼ��ֵΪ1*/
	root->lchild=NULL;
	root->rchild=NULL; 
}
int main()
{
	//1������һ�ÿ�������ʼ�� 
	BiTree root=NULL;/*��ʵֱ�Ӷ���Ҳ��*/ 
	InitTree(root);
	//2�������½ڵ�
	BiTNode*p=(BiTNode*)malloc(sizeof(BiTNode));
	p->data={2};
	p->lchild=NULL;
	p->rchild=NULL;
	root->lchild=p;//��Ϊ���ڵ������ 
} 
/*��������Ϊ�˸���ݵ��ҵ�p���ĸ��ڵ�
	�ڶ����м���	struct BiTNode*parent*/
