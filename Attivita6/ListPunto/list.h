#include "item.h"

typedef struct node *list;

list newList(void);

int emptyList(list l);

list consList(item val, list l);

list tailList(list l);

item getFirst (list l);

int sizeList (list l);

int posItem (list l, item val);

item getItem (list l, int pos);

list reverseList (list l);

void outputList (list l);

list removeList(list l, int pos);

list copiaLista(list l);

list insertList(list l, item val, int pos);

void updateList(list l1, list l2);