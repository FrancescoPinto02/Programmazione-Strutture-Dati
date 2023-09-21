#ifndef ITEM_H
#define ITEM_H
typedef struct puntoitem *item;
#endif


#define NULLITEM 0

int eq(item a, item b);

item creaItem(float x, float y);

item input_item(); 

float distanza(item p1, item p2);

void output_item(item it);

float get_x(item it);

float get_y(item it);


