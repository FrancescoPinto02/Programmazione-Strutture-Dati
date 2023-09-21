#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"
#include "list.h"

void stampaIntervallo(BST T, int A, int B);
BST bilanciato(int *arr, int n);
list nodes_At_Lvl(BST T, int K);
int mediano(BST T, int U);

int heightBST(BST T);
int KbilanciatoBST(BST T, int k);

static BST crea_bil_BST(BST T, int *arr, int start, int end);
static int perfect(int n);
static void sort(int *A, int n);
void printBST(BST T, int space);
static void lvlNode(list L, BST T, int K);
void BST_to_List(BST T, list L);




int main(int argc, char *argv[]){
    //CREAZIONE ALBERO BILANCIATO DA ARRAY
    BST T = newBST();
    int arr[7]={2,3,8,9,12,6,5};
    T = bilanciato(arr, 7);
    printBST(T,0);

    //ALTEZZA
    printf("\n\nALTEZZA: %d\n", heightBST(T));
    if(KbilanciatoBST(T, 0)){
        printf("K BILANCIATO\n");
    }
    else{
        printf("NON K BILANCIATO\n");
    }

    //STAMPA INTERVALLO
    printf("\n\nSTAMPA INTERVALLO:\n");
    stampaIntervallo(T, 10, 25);

    //STAMPA NODI A LVL K
    printf("\n\nNODI A LVL K:\n");
    list L = newList();
    L = nodes_At_Lvl(T, 2);
    outputList(L);

    //MEDIANO
    printf("\n\nMEDIANO:\n");
    if(mediano(T,88)){
        printf("88 e il mediano\n");
    }
    else{
        printf("88 non è il mediano\n");
    }
    return 0;

}

/*
/*
PROGETTAZIONE: isBST(btree) ---> bool

-Ricevi un btree (T) come parametro

-Se T è un albero vuoto
    allora restituisci 1    (PASSO BASE: un albero vuoto è un bst)

-Se T è minore del MAX nel suo sottoalbero SX  OR  è maggiore del MIN nel suo sottoalbero DX 
    allora restituisci 0    (PASSO BASE: la radice di un BST deve essere maggiore di tutti i valori nel suo sottoalbero SX 
                                            e minore di tutti quelli del suo sottoalbero DX)

-altrimenti resituisci l`esito del controllo sul figlioSX  &&  l`esito del controllo sul figlioDX (PASSO RICORSIVO)



int isBST(btree T){
    //PASSO BASE
    if(emptyBtree(T)){
        return 1;
    }

    item maxSX = maxBtree(figlioSX(T)); //massimo sottoalbero SX
    item minDX = minBtree(figlioDX(T)); //minimo sottoalbero DX

    //PASSO BASE
    if(is_min(getItem(T), maxSX) || is_min(minDX, getItem(T))){
        return 0;
    }

    //PASSO RICORSIVO
    else{
        return isBST(figlioSX(T)) && isBST(figlioDX(T));
    }
}

*/


void printBST(BST T, int space){
    if (emptyBST(T)){
        return;
    }
    else{
        space+=5;
        printBST(figlioDX(T), space);

        printf("\n");
        for (int i = 5; i<space; i++){
            printf(" ");
        }
        outputItem(getRoot(T));

        printBST(figlioSX(T), space);
    }
}


/*
PROGETTAZIONE: stampaIntervallo(BST, int, int) ---> void

Ricevi un BST (T) e due int (A, B) come parametri

Se A >= B
    allora termina funzione(Controllo su precondizione per evitare problemi)

Se T è un BST vuoto
    Allora Termina funzione (Passo Base: BST vuoto non ha valori da stampare)

Se la radice di T è compresa tra A e B  
    StampaIntervallo sottoalbero SX
    Stampa radice di T
    Stampa Intervallo sottoalbero DX

Se la radice di T è maggiore di B   
    Stampa Intervallo sottoalbero SX

Se la radice di T è minore di A    
    Stampa Intervallo sottoalbero DX
*/

void stampaIntervallo(BST T, int A, int B){
    //CONTROLLO PRECONDIZIONE
    if(A>=B){
        return;
    }

    //PASSO BASE
    if(emptyBST(T)){
        return;
    }


    //PASSI RICORSIVI
    //Radice compresa tra A e B
    if(get_num(getRoot(T))>=A  && get_num(getRoot(T))<=B){
        stampaIntervallo(figlioSX(T), A, B);
        outputItem(getRoot(T));
        stampaIntervallo(figlioDX(T), A, B);
    }

    //Radice oltre l`intervallo
    if(get_num(getRoot(T))>B){
        stampaIntervallo(figlioSX(T), A, B);
    }

    //Radice prima dell`intervallo
    if(get_num(getRoot(T))<A){
        stampaIntervallo(figlioDX(T), A, B);
    }
}


static int perfect(int n){
    if(n==1){
        return 1;
    }

    if(n%2 == 0){
        return 0;
    }
    else{
        return perfect(n/2);
    }
}

static void sort(int *A, int n){
    int tmp;
    for (int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(A[j]<A[i]){
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}

/*
PROGETTAZIONE: bilanciato(int[], int) ---> BST

-Ricevi un array di int (arr) e un int (n) come parametri

-Se n <=0 
    Allora restituisci un BST vuoto (array vuoto)

-Se n non è un numero valido (1, 3, 7, 15, 31...) ??????
    allora restituisci un BST vuoto ?????

-ordina l`array arr
-crea un nuovo BST (T)
-restituisci T riempito con gli elementi di arr (funzione crea_bil_BST)

NB: Passare come parametri a crea_bil_BST(T, arr, 0, n-1)



PROGETTAZIONE: crea_bil_BST(BST, int[], int, int) ---> BST

-Ricevi un BST (T), un array di int (arr) e due int (start, end) come parametri

-Se start > end 
    Allora restituisci T (Passo Base: nessun elemento da inserire nel BST)


-Inserisci l`elemento centrale dell`array in T
-Ripeti la funzione con la parte di array a sinistra dell`elemento centrale
-Ripeti la funzione con la parte di array a destra dell`elemento centrale
*/

BST bilanciato(int *arr, int n){
    //Array vuoto
    if (n<=0){
        return newBST();
    }

    /*if(!perfect(n)){
        return newBST();
    }*/

    sort(arr, n); //ordinamento array
    
    BST T = newBST();

    return crea_bil_BST(T, arr, 0, n-1);
}

static BST crea_bil_BST(BST T, int *arr, int start, int end){
    //PASSO BASE
    if(start > end){
        return T;
    }

    int mid = (start + end)/2; //Calcolo indice centrale
    
    T = insert(T, newItem(arr[mid])); //Inserimento elemento centrale
    
    T = crea_bil_BST(T, arr, start, mid-1); //chiamata ricorsiva array a sinistra di mid

    T = crea_bil_BST(T, arr, mid+1, end); //chiamata ricorsiva array a destra di mid
}


/*
PROGETTAZIONE: nodes_At_Lvl(BST, int) ---> List

-Ricevi un BST (T) e un int (K) come parametri

-se K <= 0
    allora restituisci una lista vuota (Un BST non può avere meno di un livello)

-crea una nuova lista (L)
-visita l`albero T e inserisci nella lista L tutti i nodi al livello K (funzione lvlNode)
-restituisci L



PROGETTAZIONE: lvlNode(list, BST, int) ---> void

-Ricevi una lista (L), un BST (T) e un int (K) come parametri

-se T è vuoto
    allora termina funzione (Passo Base: BST vuoto non ha nodi)

-se K == 1 (Passo Base: raggiunto livello desiderato)
    allora inserisci la radice di T nella lista L
    termina funzione

-Altrimenti
    richiama funzione per figlioSX(T) decrementando k
    richiama funzione per figlioDX(T) decrementando k
    (Passo Ricorsivo)


NB: quando si scende di livello, K viene decrementata.
    quando K = 1 il livello desiderato è stato raggiunto.
*/


list nodes_At_Lvl(BST T, int K){
    //Numero Livelli non valido
    if(K<=0){
        return newList();
    }


    list L = newList();
    lvlNode(L, T, K);
    return L;
}

static void lvlNode(list L, BST T, int K){
    //PASSO BASE
    if(emptyBST(T)){
        return;
    }

    //PASSO BASE (livello raggiunto, non ha senso continuare a scendere)
    if(K==1){
        insertList(L, 0, getRoot(T));
        return;
    }

    //PASSO RICORSIVO
    else{
        lvlNode(L, figlioDX(T), K-1);
        lvlNode(L, figlioSX(T), K-1);
    }
}


/*
PROGETTAZIONE: mediano(BST, int) ---> bool

-Ricevi un BST (T) e un int (U) come parametri

-se U non è presente in BST (non ha senso continuare se U non è proprio presente)
    allora restituisci 0

-crea una nuova lista (L)
-inserisci tutti i nodi di T nella lista L (in ordine) (funzione BST_to_List())

-dichiara una variabile int (n)
-assegna ad n la lunghezza di L (sizelist)

Se n è pari AND U == getItem(L, n/2-1)
    allora libera L
    restituisci 1

Se U == getItem(L, n/2)
    allora libera L
    restituisci 1

altrimenti 
    libera L
    restituisci 0


NB: se il numero di nodi è pari gli elementi che si possono considerare mediana sono 2


PROGETTAZIONE: BST_to_List(BST, List) ---> void
    
-Ricevi un BST (T) e una Lista (L) come parametri

-Se T è vuoto
    allora termina funzione (PASSO BASE: BST vuoto = nessun nodo da inserire)


(PASSO RICORSIVO)
-Richiama funzione su figlioDX(T) ed L
-Inserisci la radice di T nella lista L
-Richiama funzione su figlioSX(T) ed L
*/

int mediano(BST T, int U){
    //U non è presente in T
    if(!contains(T, newItem(U))){
        return 0;
    }

    list L = newList();
    BST_to_List(T, L); //Sposta tutti gli elementi da T nella lista L (in ordine)
    
    item Uitem = newItem(U);
    int n = sizeList(L);
    
    //solo quando n è pari
    if(n%2==0 && eq(Uitem, getItem(L, (n/2)-1))){
        free(L);
        return 1;
    }
    
    //sia quando n è pari che quando è dispari
    if(eq(Uitem, getItem(L, n/2))){
        free(L);
        return 1;
    }
    //U non è al centro della lista
    else{
        free(L);
        return 0;
    }
}

void BST_to_List(BST T, list L){
    if(emptyBST(T)){
        return;
    }

    BST_to_List(figlioDX(T), L);
    insertList(L, 0, getRoot(T));
    BST_to_List(figlioSX(T), L);
}


int heightBST(BST T){
    if(emptyBST(T)){
        return 0;
    }

    if(emptyBST(figlioSX(T)) && emptyBST(figlioDX(T))){
        return 1;
    }

    int HSX, HDX;
    HSX=1+heightBST(figlioSX(T));
    HDX=1+heightBST(figlioDX(T));

    if(HSX > HDX){
        return HSX;
    }
    else{
        return HDX;
    }
}

int KbilanciatoBST(BST T, int k){
    if(emptyBST(figlioSX(T)) && emptyBST(figlioDX(T))){
        return 1;
    }

    int diff = abs(heightBST(figlioSX(T)) - heightBST(figlioDX(T)));
    int KSX = KbilanciatoBST(figlioSX(T), k);
    int KDX = KbilanciatoBST(figlioDX(T), k);

    if(diff <= k){
        return 1 && KSX && KDX;
    }
    else{
        return 0;
    }
}

/*BST arrLeaf(int arr[], int n){
    BST T = newBST();

    for(int i=0; i<n; i++){
        if(arr[i]<arr[i+1]){
            insert(T, newItem(arr[i]));
            insert(T, newItem(arr[i]+1));
        }
    }
}*/
