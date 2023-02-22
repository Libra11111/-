#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
//定义队列 
typedef struct {
	int data[MaxSize];
	int front,rear;
}SqQueue;/*队列*/
//1、初始化
bool InitQueue(SqQueue&Q)/*L是链表S是栈，队列用Q*/
{
	Q.rear=Q.front=0; 
	return true;/*bool返回值的好处在于可以随时用返回值进行调试展示*/ 
}
//2、判空
bool QueueEmpty(SqQueue Q)
{
	return (Q.front==Q.rear);
}
//3、入队 
bool EnQueue(SqQueue&Q,int x)
{
	//1、判断队满 
	if(Q.front==(Q.rear+1)%MaxSize)
		return false;
	//2、新元素插入队尾 
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize;/*队尾指针加1取模*/
	return true;
}
//4、出队
bool DeQueue(SqQueue&Q,int&x)
{
	//1、判断队空
	if(Q.front==Q.rear)
		return false;
	//2、取数据
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true; 
}
//5、查询（通常为获取队头元素）
bool GetHead(SqQueue Q,int&x)
{
	/*就和出队操作一模一样，省去队头指针的后移即可*/
	if(Q.rear==Q.front)
		return false;
	x=Q.data[Q.front];
	return true;
}
/*6、队列元素个数 
	(rear+MaxSize-front)%MaxSize	实际上取余是防止rear>front时会多出一个MaxSize值 
	
	*/
void Printf(SqQueue Q)
{
	printf("队列元素如下：\n");
	for(int i=0;i<(Q.rear+MaxSize-Q.front)%MaxSize;i++)/*这里在遍历中就运用了队列长度的定义*/
		printf("%d\n",Q.data[(Q.front+i)%MaxSize]);
	printf("以上\n");
} 
int main()
{
	SqQueue Q;
	InitQueue(Q);
	for(int i=0;i<5;i++)
	{
		EnQueue(Q,i);
	}
	Printf(Q);
	int x=0;
	DeQueue(Q,x);
	printf("出队元素为%d\n",x);
	DeQueue(Q,x);
	printf("出队元素为%d\n",x);
	GetHead(Q,x); 
	printf("查询队头元素为：%d\n",x);
	Printf(Q);
	return 0;
}

/*还有两种定义长度或设计判满判空的方法：
2、在队列结构体定义上加上int size用于记录队列长度；
3、结构体中定义int tag =0/1 用于标记最近一次进行的是删除/插入
	（队空条件：front=rear & tag=0
		队满条件: ~ & tag = 1) 
	*/
