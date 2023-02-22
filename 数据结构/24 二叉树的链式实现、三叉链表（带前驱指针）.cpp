#include<stdio.h>
#include<stdlib.h>
//链式存储
typedef struct BiTNode{
	int data;
	struct BiTNode*lchild,*rchild;//左、右孩子指针 
}BiTNode,*BiTree;
//初始化
void InitTree(BiTree&root)
{
	root=(BiTNode*)malloc(sizeof(BiTNode));
	root->data={1};	/*初始化值为1*/
	root->lchild=NULL;
	root->rchild=NULL; 
}
int main()
{
	//1、定义一棵空树并初始化 
	BiTree root=NULL;/*其实直接定义也可*/ 
	InitTree(root);
	//2、插入新节点
	BiTNode*p=(BiTNode*)malloc(sizeof(BiTNode));
	p->data={2};
	p->lchild=NULL;
	p->rchild=NULL;
	root->lchild=p;//作为根节点的左孩子 
} 
/*三叉链表：为了更便捷的找到p结点的父节点
	在定义中加上	struct BiTNode*parent*/
