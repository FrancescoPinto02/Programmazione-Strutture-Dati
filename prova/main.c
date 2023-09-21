#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "bst.h"
#include "pqueue.h"

/*
ripCharStack(string) ---> Stack

DATI IN INPUT: str = string
PRECONDIZIONI: nessuna

DATI IN OUTPUT: s = stack
POSTCONDIZIONI: s conterrà tutti i caratteri  identici consecutivi contenuti in str (separati da un apposito carattere)
*/

stack ripCharStack(char *str){
    int n = strlen(str);
    stack s = newStack();

    int k = 1;

    //BISOGNA FARE UN REVERSE STACK 
    for(int i=0; i<n-2; i++){
        while(str[i]==str[i+k] && i+k<n){
            push(s, newItem(str[i]));
            k++;
        }
        if(k!=1){
            push(s, newItem(str[i]));
            push(s, newItem('-'));
            i=i+k;
            k=1;
        }
    }
}


/*
ANALISI E SPECIFICA
*/


item decimazione(int n, int k){
    queue Q = newQueue;
    for(int j=1; j<=n; j++){
        enQueue(Q, newItem(j));
    }

    item posizione;

    //ELIMINA FINCHÈ NON RIMANE UN SOLO ELEMENTO
    while(n>1){
        //Salta k-1 elementi
        for(int i=1; i<k; i++){
            posizione = deQueue(Q);
            enQueue(Q, posizione);
        }
        //elimina elemento K
        deQueue(Q);
        n--;
    }

    return deQueue(Q);
}



/*
balancedBST(BST, int) ---> bool

DATI IN INPUT: T = BST, K = int
PRECONDIZIONI: T deve esistere, K >= 0

DATI IN OUTPUT: 1 o 0
POSTCONDIZIONI: Se T è K-bilanciato restituisce 1, altrimenti restituisce 0



PROGETTAZIONE

-Ricevi un BST (T) e un int (K) come parametri

-Se K < 0 allora restituisci 0 (Controllo precondizione)

-Se T non ha figli restituisci 1 (Passo Base: Una singola radice è sempre K-bilanciata)

-Calcola la differenza tra le altezze dei suoi figli in valore assoluto
-Se la differenza è <= K allora restituisci 1 AND balancedBST(figlioSX) AND balancedBST(figlioDX)  (Passo Ricorsivo)

-Altrimenti restituisci 0
*/

int balancedBST(BST T, int K){
    if(K < 0){
        return 0;
    }

    if(emptyBST(figlioSX(T)) && emptyBST(figlioDX(T))){
        return 1;
    }

    int height = abs(heightBST(figlioSX(T)) - heightBST(figlioDX(T)));
    if(height <= K){
        return 1 && balancedBST(figlioSX(T), K) && balancedBST(figlioDX(T), K);
    }
    else{
        return 0;
    }
}

int heightBST(BST T){
    if(emptyBST(T)){
        return 0;
    }

    int SX = heightBST(figlioSX(T));
    int DX = heightBST(figlioDX(T));
    if(SX > DX){
        return SX + 1;
    }
    else{
        return DX + 1;
    }
}


/*
arrToBST(BST, item[], int n) ---> BST

DATI IN INPUT: T = BST, arr = item[], n = int
PRECONDIZIONI: T deve esistere, arr deve essere ordinato, n deve essere uguale al numero di elementi in arr

DATI IN OUTPUT: T' = BST (T modificato)
POSTCONDIZIONI: l`albero T verrà riempito con gli elementi di arr e il risultato sarà un BST 1-bilanciato



PROGETTAZIONE

-Ricevi un BST (T), un array di item (arr) e due int(start, end) come parametri

-Se end < start allora restituisci T (Passo Base: Array vuoto)

-Calcola la posizione centrale dell`array ((start + end)/2) e assegnala a mid

-Inserisci alla radice di T l`item in arr[mid]
-Richiama la funzione con la parte di array a sinistra di mid
-Richiama la funzione con la parte di array a destra di mid
*/

BST arrToBST(BST T, item arr[], int n){
    return arrToBST_utility(T, arr, 0, n-1);
}

BST arrToBST_utility(BST T, item *arr, int start, int end){
    if(end<start){
        return T;
    }

    int mid = (start + end)/2;

    T=insert(T, arr[mid]);

    T=arrToBST_utility(T, arr, start, mid-1);

    T=arrToBST_utility(T, arr, mid+1, end);
}


/*
printLeaf(BST) ---> void

DATI IN INPUT: T = BST
PRECONDIZIONI: T deve esistere

DATI IN OUTPUT: nessuno
POSTCONDIZIONI: verranno stampati su standard output i nodi fogli in ordine di livello



PROGETTAZIONE

-Ricevi un BST (T) come parametro

-Effettua una visita per livelli utilizzando una coda
-Durante la visita stampa i nodi che non hanno figli (foglie)

*/

void printLeaf(BST T){
    queue Q = newQueue();
    BST tmp = newBST();
        
    enQueue(Q, T);

    while(!emptyQueue(Q)){
        tmp = deQueue(Q);
        if(emptyBST(figlioSX(T)) && emptyBST(figlioDX(T))){
            outputItem(getRoot(tmp));
        }
        
        if(!emptyBST(figlioSX(tmp))){
            enQueue(Q, figlioSX(tmp));
        }

        if(!emptyBST(figlioDX(tmp))){
            enQueue(Q, figlioDX(tmp));
        }
    }

    free(tmp);
    free(Q);
}


/*
listKeys(PQueue) ---> List

DATI IN INPUT: Q = Pqueue
PRECONDIZIONI: Q deve esistere

DATI IN OUTPUT: L = List
POSTCONDIZIONI: Q = [e1, e2, ..., en] AND L =(e1 -> e2 -> ... -> en)



PROGETTAZIONE

-Ricevi una PQueue (Q) come parametro

-Crea due liste (tmp, L)

-Finchè Q non è vuota
    Inserisci l`elemento con maggiore priorita in tmp
    elimina l`elemento con maggiore priorità da Q

-Finchè tmp non è vuota
    inserisci l`elemento in testa a tmp di nuovo in Q
    inserisci l`elemento in testa a tmp in L
    rimuovi l`elemento in testa a tmp

-libera tmp
-restituisci L
*/


list listKeys(PQueue Q){
    list L = newList();
    list tmp = newList();

    while (!emptyPQ(Q)){
        insertList(tmp, 0, getMax(Q));
        deleteMax(Q);
    }

    item val;
    while (!emptyList(tmp)){
        val = getItem(tmp, 0);
        insert(Q, val);
        insertList(L, 0, val);
        removeList(tmp, 0);
    }
    
    free(tmp);
    return L;
}


/*
remGreatestKeys(PQueue, int k) ---> PQueue
DATI IN INPUT: Q = Pqueue, k = int
PRECONDIZIONI: Q deve esistere

DATI IN OUTPUT: Q' = PQueue (Q modificata)
POSTCONDIZIONI: Q' sarà uguale a Q dopo aver rimosso tutte le entry con priorità maggiore o uguale a k



PROGETTAZIONE

-Ricevi una PQueue (Q) e un int (K) come parametri

-finchè Q non è vuota  AND  la key di getMax(Q) >= K
    rimuove l`entry con priorità massima da Q

*/


void remGreatestKeys(PQueue Q, int K){
    while(!emptyPQ(Q) && get_key(getMax(Q)) >= K){
        deleteMax(Q);
    }
}


/*
isAVL(BST) ---> int

DATI IN INPUT: T = BST
PRECONDIZIONI: T deve esistere

DATI IN OUTPUT: int
POST CONDIZIONI: l`output sarà uguale a -1 se T non è un albero AVL altrimenti sarà uguale all`altezza di T


PROGETTAZIONE

-Ricevi un BST (T) come parametro

-Se T non è un AVL  (funzione AVL())
    allora restituisci -1

-Altrimenti
    restituisci heightBST(T)


-----------------------------------------------------------------------------------------

AVL(BST) ---> int

DATI IN INPUT: T = BST
PRECONDIZIONI: T deve esistere

DATI IN OUTPUT: int
POST CONDIZIONI: 1 se T è un AVL, 0 se non lo è


PROGETTAZIONE
-Ricevi un BST (T) come parametro

-Se T è un albero vuoto  
    allora restituisci 1 (Passo Base: Albero vuoto è un AVL)

-Se T non ha figli
    allora restituisci 1 (Passo Base: Una singola radice è un AVL)

-dichiara int HSX e assegnagli l`altezza del figlioSX(T)
-dichiara int HDX e assegnagli l`altezza del figlioDX(T)

-Se la differenza in valore assoluto di HSX e HDX è minore o uguale a 1
    allora restituisci ABS(figlioSX(T)) AND ABS(figlioDX(T))  (Passo Ricorsivo: Ogni sottoalbero deve rispettare la proprietà di un AVL)
-Altrimenti
    restituisci 0 (Non è un albero AVL se la differenza è maggiore di 1)

*/


static int AVL(BST T){
    if(emptyBST(T)){
        return 1;
    }

    if(emptyBST(figlioSX(T)) && emptyBST(figlioDX(T))){
        return 1;
    }

    int HSX = heightBST(figlioSX(T));
    int HDX = heightBST(figlioDX(T));

    if(abs(HSX - HDX) <= 1){
        return ABS(figlioSX(T)) && ABS(figlioDX(T));
    }
    else{
        return 0;
    }
}

int isAVL(BST T){
    if(!AVL(T)){
        return -1;
    }
    else{
        return heightBST(T);
    }
}


/*
fondiDaItem(Queue, Queue, item) ---> Queue

DATI IN INPUT: Q1 = Queue, Q2 = Queue, el = item
PRECONDIZIONI: Q1 e Q2 devono esistere, el non deve essere un NULLITEM

DATI IN OUTPUT: Q3 = Queue
POSTCONDIZIONI: Q3 conterrà tutti gli item in comune contenuti in Q1 e Q2 dopo l`item el, 
                se el non è sia in Q1 che in Q2 allora Q3 sarà vuota


PROGETTAZIONE
-Ricevi due Queue (Q1, Q2) e un item (el) come parametri

-Crea una nuova Queue (Q3)

-Se el non è in Q1  OR  el non è in Q2
    allora restituisci Q3 (sarà vuota)

-Crea due Queue temporanee (tmp1, tmp2)
-riempi tmp1 con gli elementi di Q1 dopo el (senza modficare Q1)
-riempi tmp2 con gli elementi di Q2 dopo el (senza modficare Q2)

-Finchè tmp1 non è vuota
    -Rimuovi il primo elemento ed assegnalo a item it

    -Se it è anche in tmp2
        allora inserisci it in Q3

-Libera tmp1
-Libera tmp2
-Restituisci Q3
*/

static int isInQueue(queue Q, item x){
    int found = 0;
    queue tmp = newQueue();
    item it;

    while (!emptyQueue(Q)){
        it=deQueue(Q);
        if(eq(it, x)){
            found = 1;
        }
        enQueue(tmp, it);
    }

    while (!emptyQueue(tmp)){
        it=deQueue(tmp);
        enQueue(Q, it);
    }

    free(tmp);
    return found;
}

static queue moveFromItem(queue Q, item el){
    queue new = newQueue();
    queue tmp = newQueue();
    item it;
    int found = 0;

    while(!emptyQueue(Q)){
        it = deQueue(Q);
        enQueue(tmp, it);
        
        if(eq(it, el)){
            found = 1;
        }

        if(found){
            enQueue(new, it);
        }
    }


    while(!emptyQueue(tmp)){
        it = deQueue(tmp);
        enQueue(Q, it);
    }

    free(tmp);
    return new;
}

queue fondiDaItem(queue Q1, queue Q2, item el){
    queue Q3 = newQueue();

    if(!isInQueue(Q1, el) || !isInQueue(Q2, el)){
        return Q3;
    }

    queue tmp1 = newQueue();
    queue tmp2 = newQueue();
    item it;

    tmp1 = moveFromItem(Q1, el);
    tmp2 = moveFromItem(Q2, el);

    while(!emptyQueue(tmp1)){
        it = deQueue(tmp1);
        if(isInQueue(tmp2, it)){
            enQueue(Q3, it);
        }
    }

    free(tmp1);
    free(tmp2);
    return Q3;
}