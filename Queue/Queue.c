#include"Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = pq->_front = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}

void QueuePush(Queue* pq, QUDataType x)//Èë¶Ó
{
	assert(pq);
	if (pq->_front == NULL)
	{
		pq->_front = pq->_rear = BuyQueueNode(x);
	}
	else
	{
		pq->_rear->_next = BuyQueueNode(x);
		pq->_rear = pq->_rear->_next;
	}
}

void QueuePop(Queue* pq)
{
	if (pq->_front == NULL)
	{
		pq->_rear = NULL;
	}
	else
	{
		QueueNode* next = pq->_front->_next;
		free(pq->_front);
		pq->_front = next;
	}
}
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_front->_data;
}

QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->_rear->_data;
}

int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL ? 0 : 1;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->_front;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}

void TestQueue()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 0);
	QueuePush(&pq, 9);
	QueuePush(&pq, 2);
	QueuePush(&pq, 6);
	printf("front:%d\n", QueueFront(&pq));
	printf("size:%d\n", QueueSize(&pq));
	printf("empty:%d\n", QueueEmpty(&pq));
}
int main()
{
	TestQueue();
	return 0;
}