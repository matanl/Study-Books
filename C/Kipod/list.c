#include "list.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct Node* newNode(struct Node* parent,int x,int y)
{
	struct Node* n = malloc(sizeof(struct Node));
	n->next = NULL;
	n->parent = parent;
	n->f = n->g = n->h = 0;
	n->x = x;
	n->y = y;
	return n;
}
struct List* newList()
{
	struct List* list = malloc(sizeof(struct List));
	list->first = NULL;
	list->last = NULL;
	return list;
}

void deleteList(struct List* list)
{
	if (!isListEmpty(list))
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
void listInsert(struct List* list, struct Node* n)
{
	n->next = NULL;
	/*the new node is now the list's last node*/
	if (isListEmpty(list))
	{
		/*if list is empty, first node needs to be updated*/
		list->first = n;
	}
	else
	{
		list->last->next = n;
	}
	list->last = n;
}
struct Node*  listPop(struct List* list)
{
	struct Node* n;
	if (isListEmpty(list))
	{
		return NULL;
	}
	n = list->first;
	if (list->first == list->last)/*only one member*/
	{
		list->first = NULL;
		list->last = NULL;
	}
	else {
		list->first = list->first->next;
	}
	return n;
}
void deleteListMember(struct List* list, struct Node* member,int del)
{
	struct Node* n;
	if (isListEmpty(list))
	{
		return;
	}
	if (list->first==list->last)
	{
		/*member is the only node in the list*/
		list->first = NULL;
		list->last = NULL;
	}
	else if (member == list->first){
		/*if member is the first node in the list, the first node needs to be member's next node*/
		list->first = member->next;
	}
	else
	{
		n = list->first;
		while (n->next!=member)
		{
			n = n->next;
		}
		if (member == list->last)
		{
			/* if member is the last node in the list, the las node needs to be member's previous node*/
			list->last = n;
			n->next = NULL;
		}
		else
		{
			n->next = member->next;
		}
	}
	if (del==TRUE)
	{
		free(member);
	}
}
int isListEmpty(struct List* list)
{
	return list->first == NULL;
}
int isInList(struct List* list, struct Node* node)
{
	struct Node* runner = list->first;
	while (runner!=NULL)
	{
		if (runner==node)
		{
			return TRUE;
		}
		runner = runner->next;
	}
	return FALSE;
}

