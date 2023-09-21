#define NULLITEM 0

typedef struct c_item * item;

int eq(item a, item b);
float getID(item a);
float getBurst(item a);
void cicloClock(item a);
item newItem(int id, int burst);
item inputItem(void);
void outputItem(item a);