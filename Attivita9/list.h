#include "item.h"

typedef struct c_list * list;

list newList(void);

int emptyList(list l);

int sizeList(list l);

int consList(list l, item val);

item getFisrt(list l);

item getItem(list l, int pos);

int posItem(list l, item val);

int insertList(list l, int pos, item val);

int removeList(list l, int pos);

int outputList(list l);

list cloneList(list l);

//-------------------------------------------------------

int sizeListIt(list l);

int sizeListRec(list l);