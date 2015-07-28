#if !defined(LIST_H)
#define LIST_H


struct Node;
struct List;

struct List* newList();
void deleteList(struct List* list);
void listInsert(struct List* list,int info);
void deleteListMember(struct List* list,struct Node* member);
int listSize(struct List* list);
struct Node* getListFirst(struct List* list);
struct Node* getListLast(struct List* list);
struct Node* getNextNode(struct Node* member);
struct Node* getPrevieousNode(struct Node* member);
int getNodeInfo(struct Node* member);
float getListAverage(struct List* list);


#endif