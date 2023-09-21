
/*
fileBtree(string) ---> btree

DATI IN INPUT: 
filename = stringa

PRECONDIZIONI:
Nessuna

DATI IN OUTPUT:
new = btree

POSTCONDIZIONI:
se il file "filename" non esiste new sarà un albero vuoto, 
altrimenti new sarà un albero formato dagli interi contenuti in "filename"
*/

btree fileBtreeV2(char *filename);


/*
leafCount(btree) ---> int

DATI IN INPUT: 
T = btree

PRECONDIZIONI:
T deve esistere

DATI IN OUTPUT:
count = int

POSTCONDIZIONI:
count sarà uguale al numero di foglie presenti nell`albero T
*/
int leafCount(btree T);


/*
speculare(btree) ---> btree

DATI IN INPUT: 
T = btree

PRECONDIZIONI:
T deve esistere

DATI IN OUTPUT:
ST = btree

POSTCONDIZIONI:
ST avrà tutti i nodi di T posizionati in modo speculare
*/

btree speculare(btree T);


/*
minBtree(btree) ---> item

DATI IN INPUT: 
T = btree

PRECONDIZIONI:
T deve esistere 

DATI IN OUTPUT:
min = item

POSTCONDIZIONI:
Se l`albero T è vuoto min sarà un NULLITEM 
altrimenti min sarà l`item più piccolo tra quelli contenuti nell`albero T
*/

item minBtree(btree T);


/*
maxBtree(btree) ---> item

DATI IN INPUT: 
T = btree

PRECONDIZIONI:
T deve esistere 

DATI IN OUTPUT:
max = item

POSTCONDIZIONI:
Se l`albero T è vuoto max sarà un NULLITEM 
altrimenti max sarà l`item più grande tra quelli contenuti nell`albero T
*/

item maxBtree(btree T);


/*
equalBtree(btree, btree) ---> int

DATI IN INPUT: 
T1 = btree  T2 = btree

PRECONDIZIONI:
T1 e T2 devono esistere 

DATI IN OUTPUT:
int bool

POSTCONDIZIONI:
Se T1 è uguale a T2 restituisce 1
altrimenti restituisce 0
*/

int equalBtree(btree T1, btree T2);



/*
aggiungiNodo(btree, item) ---> btree

DATI IN INPUT: 
T = btree  nodo = item

PRECONDIZIONI:
T deve esistere
nodo != NULLITEM

DATI IN OUTPUT:
T' = btree

POSTCONDIZIONI:
T' sarà uguale a T con l`aggiunta dell`item nodo nella prima posizione disponibile
*/

btree aggiungiNodo(btree T, item nodo);