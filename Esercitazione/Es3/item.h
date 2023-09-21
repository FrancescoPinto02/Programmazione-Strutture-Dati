#define NULLITEM 0

typedef struct c_item * item;

int eq(item x, item y);
int get_ID(item x);
int get_votanti(item x);
int get_vot_effettivi(item x);
int get_nulli(item x);
int get_si(item x);
int get_no(item x);
item inputItem(void);
void outputItem(item x);