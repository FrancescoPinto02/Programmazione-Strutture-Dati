#define NULLITEM NULL

typedef struct c_item * item;

item newItem(int key, int val);
int get_key(item x);
int get_val(item x);
int maggiore(item x, item y);
int minore(item x, item y);
int eq(item x, item y);
item inputItem(void);
void outputItem(item x);