#if !defined(QUEUE_H)
#define QUEUE_H

struct Queue;

struct Queue* newQueue();
void deleteQueue(struct Queue* queue);
void queueInsert(struct Queue* queue, int info);
int queuePop(struct Queue* queue);
int queueSize(struct Queue* queue);
int getQueueFirst(struct Queue* queue);



#endif