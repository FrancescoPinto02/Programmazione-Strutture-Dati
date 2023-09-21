#include "item.h"

typedef struct c_list * list;

list newList(void);

int sizeList(list l);

int emptyList(list l);

int tailList(list l);

int consList(list l, item val);

item getFisrt(list l);

int insertList(list l, int pos, item val);

int removeList(list l, int pos);

item getItem(list l, int pos);

int outputList(list l);