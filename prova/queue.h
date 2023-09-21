#include "item.h"

typedef struct c_queue *queue;

queue newQueue(void);

int emptyQueue(queue q);

int enQueue(queue q, item val);

item deQueue(queue q);

