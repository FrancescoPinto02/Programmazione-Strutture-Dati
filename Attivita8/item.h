#define NULLITEM 0

typedef struct c_item * item;

int eq(item x, item y);
float getX(item a);
float getY(item a);
item inputItem(void);
void outputItem(item a);
float distance (item a, item b);