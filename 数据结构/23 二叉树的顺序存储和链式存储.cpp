#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100 
//˳��洢����
struct TreeNode{
	int value;	/*ElemType*/
	bool isEmpty;	//����Ƿ�Ϊ�� 
}; 
/*		��ʼ��ʱ�����нڵ�Ҫ���Ϊ��	*/

//��ʽ�洢���� 
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;//���Һ��� 
}BiTNode,*BiTree;

//
int main()
{
	
}
/*1��
	������ȫ��������˵��˳��洢�������δ洢���нڵ㣬
	����Ҫ�����У�i������--->2i	�Һ���--->2i+1
				i�ĸ��ڵ�--->i/2	i���ڲ��--->log2(n+1)��(log2n)+1
  2��
  	������ȫ�����������������нڵ�ֻ���Һ��ӣ�
	  	�߶�Ϊh��ֻ��h�����ĵ�֧����Ҳ��Ҫ2��n�η�-1���洢��Ԫ 	
	������Ȼ��ʽ�ṹ���� 
	*/ 
	 
