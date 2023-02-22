#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100 
//顺序存储定义
struct TreeNode{
	int value;	/*ElemType*/
	bool isEmpty;	//结点是否为空 
}; 
/*		初始化时，所有节点要标记为空	*/

//链式存储定义 
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;//左、右孩子 
}BiTNode,*BiTree;

//
int main()
{
	
}
/*1、
	对于完全二叉树来说，顺序存储可以依次存储所有节点，
	且重要操作中，i的左孩子--->2i	右孩子--->2i+1
				i的父节点--->i/2	i所在层次--->log2(n+1)或(log2n)+1
  2、
  	而非完全二叉树，最坏情况（所有节点只有右孩子）
	  	高度为h且只有h个结点的单支树，也需要2的n次方-1个存储单元 	
	所以显然链式结构更好 
	*/ 
	 
