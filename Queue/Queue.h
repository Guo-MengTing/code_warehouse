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
QueueNode* BuyQueueNode(QUDataType x);//����һ���µĽ��
void QueuePush(Queue* pq, QUDataType x);//���
void QueuePop(Queue* pq);//ɾ����ͷ���
QUDataType QueueFront(Queue* pq);//���ض�ͷ����
QUDataType QueueBack(Queue* pq);//���ض�β����
int QueueEmpty(Queue* pq);//�жӿ�
int QueueSize(Queue* pq);//���ض���Ԫ�ظ���

void TestQueue();