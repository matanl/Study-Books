#if !defined(LIST_H)
#define LIST_H


struct Node {
	struct Node* next;
	struct Node* parent;
	int x, y;
	int f, g, h;
};
struct List{
	struct Node* first;
	struct Node* last;
};

struct Node* newNode(struct Node* parent, int x, int y);
struct List* newList();
void deleteList(struct List* list);
void listInsert(struct List* list, struct Node* n);
int isListEmpty(struct List* list);
struct Node* listPop(struct List* list);
void deleteListMember(struct List* list, struct Node* member, int del);
int isInList(struct List* list, struct Node* node);


#endif