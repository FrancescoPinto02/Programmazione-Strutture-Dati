#define NULLITEM 0
#define MIN_ITEM INT_MIN
#define MAX_ITEM INT_MAX

typedef struct c_item *item;

int is_min(item x, item y);
int eq(item x, item y);
item newItem(int n);
item inputItem(void);
void outputItem(item x);