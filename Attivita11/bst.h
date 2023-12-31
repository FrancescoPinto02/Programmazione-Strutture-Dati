typedef struct node *BST;

BST newBST(void);

int emptyBST(BST T);

BST figlioSX(BST T);

BST figlioDX(BST T);

item getRoot(BST T);

BST insert(BST T, item elem);

int contains(BST T, item elem);

BST deleteNode(BST T, item elem);