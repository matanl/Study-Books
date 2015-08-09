#include "queue.h"
#include "list.h"
#include <stdlib.h>

struct Queue
{
	struct List* list; // T: nice reuse!
};

struct Queue* newQueue()
{
	struct Queue* queue = malloc(sizeof(struct Queue)); // T: malloc can fail and return null
	queue->list = newList();
	return queue;
}
void deleteQueue(struct Queue* queue)
{
	deleteList(queue->list); // T: check queue is not null
	free(queue);
}
void queueInsert(struct Queue* queue, int info)
{
	listInsert(queue->list, info); // T: check queue is not null
}
int queuePop(struct Queue* queue)
{
	struct Node* first = getListFirst(queue->list); // T: check queue is not null
	int info = getNodeInfo(first); // T: check node* first is not null
	deleteListMember(queue->list,first);
	return info;
}
int queueSize(struct Queue* queue)
{
	return listSize(queue->list); // T: check queue is not null
}
int getQueueFirst(struct Queue* queue)
{
	struct Node* first = getListFirst(queue->list); // T: check queue is not null
	int info = getNodeInfo(first); // T: check node* first is not null
	return info;
}
