#include "queue.h"
#include "list.h"
#include <stdlib.h>

struct Queue
{
	struct List* list;
};

struct Queue* newQueue()
{
	struct Queue* queue = malloc(sizeof(struct Queue));
	queue->list = newList();
	return queue;
}
void deleteQueue(struct Queue* queue)
{
	deleteList(queue->list);
	free(queue);
}
void queueInsert(struct Queue* queue, int info)
{
	listInsert(queue->list, info);
}
int queuePop(struct Queue* queue)
{
	struct Node* first = getListFirst(queue->list);
	int info = getNodeInfo(first);
	deleteListMember(queue->list,first);
	return info;
}
int queueSize(struct Queue* queue)
{
	return listSize(queue->list);
}
int getQueueFirst(struct Queue* queue)
{
	struct Node* first = getListFirst(queue->list);
	int info = getNodeInfo(first);
	return info;
}