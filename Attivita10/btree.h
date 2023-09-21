typedef struct node * btree;

btree newBtree(void);

int emptyBtree(btree T);

btree getRoot(btree T);

btree figlioSX(btree T);

btree figlioDX(btree T);

btree consBtree(item val, btree sx, btree dx);

item getItem(btree T);

void updateSX(btree T, btree SX);

void updateDX(btree T, btree DX);