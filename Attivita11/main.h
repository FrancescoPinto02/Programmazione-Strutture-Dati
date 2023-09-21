#include "bst.h"

/*
isBST(btree) ---> bool

DATI IN INPUT:  T = btree
PRECONDIZIONI:  T deve esistere (deve essere prima inizializzato con T = newBtree())
                Servono le funzioni minBtree() e maxBtree()

DATI IN OUTPUT: 1 o 0
POSTCONDIZIONI: Se l`albero binario rispetta le proprietà di un albero binario di ricerca
                allora restituisce 1, altrimenti restituisce 0 

*/

//int isBST(btree T);


/*
stampaIntervallo(BST, int, int) ---> void

DATI IN INPUT:  T = BST, A = int, B = int
PRECONDIZIONI:  T deve esistere (deve essere prima inizializzato con T = newBST())
                A deve essere minore di B

DATI IN OUTPUT: nessuno
POSTCONDIZIONI: Vengono stampati su standard output tutti i nodi con valore compreso tra A e B (o uguale ad uno di essi)
*/

void stampaIntervallo(BST T, int A, int B);


/*
bilanciato(int[], int) ---> BST

DATI IN INPUT:  arr = int[], n = int
PRECONDIZIONI:  arr dovrà contenere n elementi
                n dovra essere uguale appartenere all`insieme X definito come:
                    BASE: 1 appartiene a X
                    PASSO RICORSIVO: se x appartiene a X allora (x*2)+1 appartiene a X


DATI IN OUTPUT: T = BST
POSTCONDIZIONI: T sarà un BST completamente bilanciato che conterrà gli elementi dell`array
*/

BST bilanciato(int *arr, int n);


/*
nodes_At_Lvl(BST, int) ---> List

DATI IN INPUT:  T = BST, K = int
PRECONDIZIONI:  T deve esistere (deve essere prima inizializzato con T = newBST())

DATI IN OUTPUT: L = list
POSTCONDIZIONI: L conterrà i nodi di T al livello K 


NB: primo livello -> K=1
*/

list nodes_At_Lvl(BST T, int K);


/*
mediano(BST, int) ---> bool

DATI IN INPUT:  T = BST, U = int
PRECONDIZIONI:  T deve esistere (deve essere prima inizializzato con T = newBST())

DATI IN OUTPUT: 1 o 0
POSTCONDIZIONI: se U è il valore mediano di T allora restituisce 1
                altrimenti restituisce 0

*/

int mediano(BST T, int U);