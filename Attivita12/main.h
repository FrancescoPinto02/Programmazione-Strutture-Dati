#include "item.h"
#include "pqueue.h"

/*
maxHeap(PQueue) ---> item

DATI IN INPUT: Q = PQueue
PRECONDIZIONI: Q deve esistere

DATI IN OUTPUT: max = item
POSTCONDIZIONI: max = nodo (item) con maggiore priorità (Key più grande)
*/

item maxHeap(PQueue Q);


/*
minHeap(PQueue) ---> item

DATI IN INPUT: Q = PQueue
PRECONDIZIONI: Q deve esistere

DATI IN OUTPUT: min = item
POSTCONDIZIONI: min = nodo (item) con minore priorità (Key più piccola)
*/

item minHeap(PQueue Q);


/*
incKey(PQueue, int, int) ---> PQueue

DATI IN INPUT:  Q = PQueue, K = int, newK = int
PRECONDIZIONI: Q deve esistere, K < newK

DATI IN OUTPUT: Q' = PQueue (Q modificata)
POSTCONDIZIONI: Q' = Q modificata in modo tale che la priorità del nodo con priorità K (se esiste) diventi newK

NB: La modifica avviene direttamente sulla coda presa in input, quindi la funzione potrebbe restituire un int (esito operazione)
*/

int incKey(PQueue Q, int K, int newK);



/*
heapfy(int[], int) ---> int[]

DATI IN INPUT:  arr = int[], n = int
PRECONDIZIONI: n deve essere uguale al numero di elementi in arr

DATI IN OUTPUT: heap = int[]
POSTCONDIZIONI: heap conterrà gli stessi elementi di arr, ordinati in modo tale da rispettare la struttura di un heap
*/

int * heapfy(int *arr, int n);


/*
mergePQ(PQueue, PQueue) ---> PQueue

DATI IN INPUT:  Q1 = PQueue, Q2 = PQueue
PRECONDIZIONI: Q1 e Q2 devono esistere, non devono esserci entry uguali nelle due code

DATI IN OUTPUT: Q
POSTCONDIZIONI: Q conterrà tutte le entry di Q1 e Q2 

NB: Q1 e Q2 non vengono modificate
*/

PQueue mergePQ(PQueue Q1, PQueue Q2);