#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"
#include "item.h"

item maxHeap(PQueue Q);
item minHeap(PQueue Q);
int incKey(PQueue Q, int K, int newK);
int* heapfy(int *arr, int n);
PQueue mergePQ(PQueue Q1, PQueue Q2);

static void inputFilePQ(char *filename, PQueue pq);
static void printPQ(PQueue pq);
static void orderHeap(int *heap, int j);


int main(int argc, char *argv[]){
    PQueue pq = newPQ();
    inputFilePQ(argv[1], pq);
    printPQ(pq);

    printf("\n\nMAXHEAP: ");
    outputItem(maxHeap(pq));

    printf("\n\nMINHEAP: ");
    outputItem(minHeap(pq));

    printf("\n\nINCREMENTO KEY: ");
    incKey(pq, 7, 22);
    printPQ(pq);

    printf("\n\nHEAPFY: \n");
    int arr[]={2,8,5,12,5,8,6};
    int *heap = heapfy(arr, 7);
    for(int i=1; i<=9; i++){
        printf("heap[%d]=%d\n", i, heap[i]);
    }

    return 0;
}

static void inputFilePQ(char *filename, PQueue pq){
    FILE *fp = fopen(filename, "r");
    if(!fp){
        printf("Errore apertura file!\n");
        return;
    }

    int key, val;
    while(fscanf(fp, "%d %d", &key, &val) == 2){
        insert(pq, newItem(key, val));
    }
    fclose(fp);
}

static void printPQ(PQueue pq){
    PQueue tmp = newPQ();
    item it;

    while(!emptyPQ(pq)){
        it = getMax(pq);
        outputItem(it);
        deleteMax(pq);
        insert(tmp, it);
    }

    while(!emptyPQ(tmp)){
        it = getMax(tmp);
        deleteMax(tmp);
        insert(pq, it);
    }

    free(tmp);
}


/* 
PROGETTAZIONE: maxHeap(PQueue) ---> item

-Ricevi una PQueue (Q) come parametro

-se Q è vuota
    allora restituisci un NULLITEM

-Altrimenti
    restistuisci il primo elemento di Q


NB: In una coda a priorità l`elemento con maggiore priorità è quello in testa (banale)
*/

item maxHeap(PQueue Q){
    if(emptyPQ(Q)){
        return NULLITEM;
    }
    else{
        return getMax(Q);
    }
}


/* 
PROGETTAZIONE: minHeap(PQueue) ---> item

-Ricevi una PQueue (Q) come parametro

-Crea una PQueue temporanea (tmp)
-Crea un item di appoggio (it) e inizializzalo con NULLITEM

-Sposta tutti gli elementi di Q in tmp utilizzando it

-Sposta tutti gli elementi da tmp di nuovo in Q

-Libera tmp
-restituisci it (dopo aver spostato tutti gli item dalla coda, it conterrà quello con minore priorità oppure NULLITEM se la coda è vuota)
*/

item minHeap(PQueue Q){
    PQueue tmp = newPQ();
    item it = NULLITEM;

    while(!emptyPQ(Q)){
        it=getMax(Q);
        deleteMax(Q);
        insert(tmp, it);
    }

    while(!emptyPQ(tmp)){
        it=getMax(tmp);
        deleteMax(tmp);
        insert(Q, it);
    }

    free(tmp);
    return it;
}



/* 
PROGETTAZIONE: incKey(PQueue, int, int) ---> PQueue

-Ricevi una PQueue (Q) e due int (K, newK) come parametri

-Se K >= newK
    allora restituisci 0 (Controllo precondizione)

-Crea una coda temporanea (tmp)
-Crea un item di appoggio (it)
-Crea una flag (found) e inizializzala a 0

-Finchè Q non è vuota AND !found{
    assegna a it il Max di Q
    cancella il Max da Q

    se K è uguale alla key di it{
        inserisci it in Q modificando K con newK
        aggiorna found a 1 (esci dal ciclo)
    }
    altrimenti{
        inserisci it in tmp
    }
}

-Sposta i nodi in tmp di nuovo in Q
-libera tmp

-restituisci found
*/

int incKey(PQueue Q, int K, int newK){
    //Controllo Precondizione
    if(K >= newK){
        return 0;
    }

    PQueue tmp = newPQ(); //coda temporanea
    item it; //item di appoggio
    int found = 0; //flag


    //Ricerca nodo con priorità K
    while (!emptyPQ(Q) && !found){
        it = getMax(Q);
        deleteMax(Q);
        
        if(K == get_key(it)){
            insert(Q, newItem(newK, get_val(it))); //Modifica nodo
            found=1;
        }
        else{
            insert(tmp, it);
        }
    }

    //Sposta tutti i nodi da tmp di nuovo in Q
    while(!emptyPQ(tmp)){
        it = getMax(tmp);
        deleteMax(tmp);
        insert(Q, it);
    }

    free(tmp);
    return found;
}


/* 
PROGETTAZIONE: heapfy(int[], int) ---> int[]

-Ricevi un array int (arr) e un int (n) come parametri

-Crea e alloca un nuovo array di int (heap) di taglia n+1 (gli elementi partiranno da indice 1)
-Controlla allocazione

-Sposta una alla volta tutti gli elementi da arr ad heap
-Ad ogni spostamento ristabilisci l`ordine di heap (funzione orderHeap)

-Restituisci heap


PROGETTAZIONE: orderHeap(int[], int) ---> void

-Ricevi un array di int (heap) e un int (j) come parametri

-Se j <= 1 
    allora termina funzione (Passo Base: heap già ordinato)

-Se heap[j] > heap[j/2]
    scambia heap[j] e heap[j/2]
    richiama orderHeap con parametri heap e j/2
    (Passo Ricorsivo)
*/

int* heapfy(int *arr, int n){
    int *heap = calloc(n+1, sizeof(int));
    if(!heap){
        printf("errore di allocazione!\n");
        return NULL;
    }

    for(int i=0; i<n; i++){
        heap[i+1]=arr[i];
        orderHeap(heap, i+1);
    }
    
    return heap;
}

static void orderHeap(int *heap, int j){
    if(j<=1){
        return;
    }

    int swap;
    if(heap[j] > heap[j/2]){
        swap = heap[j];
        heap[j] = heap[j/2];
        heap[j/2] = swap;

        orderHeap(heap, j/2);
    }
}


/*
PROGETTAZIONE: mergePQ(PQueue, PQueue) ---> PQueue

-Ricevi come parametri due PQueue (Q1, Q2)

-Crea una nuova PQueue (Q)
-Crea una PQueue temporanea (tmp)
-Dichiara un item di appoggio

-Sposta tutte le entry di Q1 in Q e in tmp
-Sposta tutt le entry da tmp di nuovo in Q1

-Sposta tutte le entry di Q2 in Q e in tmp
-Sposta tutt le entry da tmp di nuovo in Q2

-Libera tmp

-Restituisci Q
*/

PQueue mergePQ(PQueue Q1, PQueue Q2){
    PQueue Q = newPQ();
    PQueue tmp = newPQ();
    item it;

    while(!emptyPQ(Q1)){
        it = getMax(Q1);
        deleteMax(Q1);
        insert(Q, it);
        insert(tmp, it);
    }

    while(!emptyPQ(tmp)){
        it = getMax(tmp);
        deleteMax(tmp);
        insert(Q1, it);
    }

    while(!emptyPQ(Q2)){
        it = getMax(Q2);
        deleteMax(Q2);
        insert(Q, it);
        insert(tmp, it);
    }

    while(!emptyPQ(tmp)){
        it = getMax(tmp);
        deleteMax(tmp);
        insert(Q2, it);
    }

    free(tmp);
    return Q;
}