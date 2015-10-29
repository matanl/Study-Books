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
	struct List* list = malloc(sizeof(struct List)); // T: malloc can fail and return null
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	list->sum = 0;
	return list;
}

void deleteList(struct List* list)
{
	if (listSize(list)>0) // T: check list is not null
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
	struct Node* n = malloc(sizeof(struct Node)); // T: malloc can fail and return null
	n->info = info;
	n->next = NULL;
	n->prev = list->last;
	/*the new node is now the list's last node*/
	list->last = n; // T: check list is not null
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
	if (listSize(list) == 0) // T: check list and member are not null
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
		member->prev->next = member->next; // T: might be segmentation fault if member not in the list 
	}
	list->sum -= member->info; // T: logic error if member was not in the list
	list->size--;
	free(member);
}
int listSize(struct List* list)
{
	return list->size; // T: check list is not null
}
struct Node* getListFirst(struct List* list)
{
	return list->first; // T: check list is not null
}
struct Node* getListLast(struct List* list)
{
	return list->last; // T: check list is not null
}
struct Node* getNextNode(struct Node* member)
{
	return member->next; // T: check member is not null
}
struct Node* getPrevieousNode(struct Node* member)
{
	return  member->prev; // T: check member is not null
}
int getNodeInfo(struct Node* member)
{
	return member->info; // T: check member is not null
}
float getListAverage(struct List* list)
{
	return (float)list->sum / list->size; // T: check list is not null
}
