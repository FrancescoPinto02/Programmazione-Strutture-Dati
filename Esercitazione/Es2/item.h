#define NULLITEM 0

typedef struct c_item * item;


int eq(item x, item y);
char *get_titolo(item x);
char *get_cantante(item x);
int get_durata(item x);
item inputItem(void);
void outputItem(item x);
item cloneItem(item x);