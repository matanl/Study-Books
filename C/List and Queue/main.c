#include <stdio.h>
#include "list.h"
#include "queue.h"

static void printList(struct List* l);
static void printQueue(struct Queue* q);

int main()
{
	/*List demonstration*/
	struct List* l = newList();
	listInsert(l, 5);
	listInsert(l, 1);
	listInsert(l, 4);
	listInsert(l, 8);
	printList(l);
	printf("List Average: %f\n", getListAverage(l));
	deleteListMember(l,getListFirst(l));
	deleteListMember(l,getListLast(l));
	printList(l);
	printf("List Average: %f\n", getListAverage(l));

	deleteList(l);
	/*List demonstration*/

	/*Queue demonstation*/
	struct Queue* q = newQueue();
	queueInsert(q, 5);
	queueInsert(q, 20);
	queueInsert(q, 8);
	printQueue(q);
	deleteQueue(q);
	/*Queue demonstation*/

	getc(stdin);
	return 0;
}
static void printQueue(struct Queue* q)
{
	printf("Queue members: ");
	while (queueSize(q) != 0)
	{
		printf("%d ", queuePop(q));
	}
	printf("\n");
}
static void printList(struct List* l)
{
	struct Node* n = getListFirst(l);
	printf("List members: ");
	do
	{
		printf("%d ", getNodeInfo(n));
	} while ((n = getNextNode(n)) != NULL);
	printf("\n");
}