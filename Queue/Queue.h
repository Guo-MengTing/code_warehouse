#include<stdio.h>
#include<assert.h>
#include<malloc.h>
typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);//创建一个新的结点
void QueuePush(Queue* pq, QUDataType x);//入队
void QueuePop(Queue* pq);//删除队头结点
QUDataType QueueFront(Queue* pq);//返回队头数据
QUDataType QueueBack(Queue* pq);//返回队尾数据
int QueueEmpty(Queue* pq);//判队空
int QueueSize(Queue* pq);//返回队内元素个数

void TestQueue();