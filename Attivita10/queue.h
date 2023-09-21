
typedef struct c_queue *queue;

queue newQueue(void);

int emptyQueue(queue q);

int enQueue(queue q, btree val);

btree deQueue(queue q);

