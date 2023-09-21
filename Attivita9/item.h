#define NULLITEM 0

typedef struct c_item * item;

int eq(item x, item y);

item inputItem(void);

item newItem(int n);

void outputItem(item x);