#define NULLITEM 0

typedef struct c_item * item;

item newItem(int key, int val);
int maggiore(item x, item y);
int minore(item x, item y);
int eq(item x, item y);
item inputItem(void);
void outputItem(item x);