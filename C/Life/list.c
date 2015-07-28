#include "list.h"
#include <stdlib.h>

struct Node
{
	int info;
	struct Node* next;
	struct Node* prev;
};
struct List
{
	struct Node* first;
	struct Node* last;
	int sum;
	int size;
};

struct List* newList()
{
	struct List* list = malloc(sizeof(struct List));
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	list->sum = 0;
	return list;
}

void deleteList(struct List* list)
{
	if (listSize(list)>0)
	{
		struct Node* runner = list->first;
		/*run through the list and free its members*/
		while (runner != list->last)
		{
			struct Node* temp = runner;
			runner = runner->next;
			free(temp);
		}
		free(list->last);
	}

	free(list);
}
void listInsert(struct List* list, int info)
{
	/*allocate new node and fill it with values*/
	struct Node* n = malloc(sizeof(struct Node));
	n->info = info;
	n->next = NULL;
	n->prev = list->last;
	/*the new node is now the list's last node*/
	list->last = n;
	if (list->size==0)
	{
		/*if list is empty, first node needs to be updated*/
		list->first = n;
	}
	else
	{
		/*if list is not empty, the previous node is not null, and thus, it's next node needs to be updated*/
		n->prev->next = n;
	}
	list->size++;
	list->sum += info;
}
void deleteListMember(struct List* list, struct Node* member)
{
	if (listSize(list) == 0)
	{
		return;
	}
	if (listSize(list) == 1)
	{
		/*member is the only node in the list*/
		list->first = NULL;
		list->last = NULL;
	}
	else if (member == list->last )
	{
		/* if member is the last node in the list, the las node needs to be member's previous node*/
		list->last = member->prev;
		list->last->next = NULL;
	}
	else if (member == list->first){
		/*if member is the first node in the list, the first node needs to be member's next node*/
		list->first = member->next;
		list->first->prev = NULL;
	}
	else
	{
		/*if member is not the first node or the last node in the list, it's previous node need to be updated */
		member->prev->next = member->next;
	}
	list->sum -= member->info;
	list->size--;
	free(member);
}
int listSize(struct List* list)
{
	return list->size;
}
struct Node* getListFirst(struct List* list)
{
	return list->first;
}
struct Node* getListLast(struct List* list)
{
	return list->last;
}
struct Node* getNextNode(struct Node* member)
{
	return member->next;
}
struct Node* getPrevieousNode(struct Node* member)
{
	return  member->prev;
}
int getNodeInfo(struct Node* member)
{
	return member->info;
}
float getListAverage(struct List* list)
{
	return (float)list->sum / list->size;
}