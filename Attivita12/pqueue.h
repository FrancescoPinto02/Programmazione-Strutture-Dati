#include "item.h"
typedef struct c_PQ *PQueue;


PQueue newPQ(void);

int emptyPQ(PQueue q);

item getMax(PQueue q);

int deleteMax(PQueue q);

int insert (PQueue q, item entry);
