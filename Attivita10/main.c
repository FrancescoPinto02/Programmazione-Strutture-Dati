#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"
#include "main.h"
#include "queue.h"

#define COUNT 5
#define MAX 20

btree fileBtree(char *filename);
static btree inputBtree(FILE *fp);
btree fileBtreeV2(char *filename);
static btree inputBtreeV2(item *arr, int i, int n);
void printBtree(btree T, int space);
int leafCount(btree T);
btree speculare(btree T);
item minBtree(btree T);
item maxBtree(btree T);
int equalBtree(btree T1, btree T2);
int heightBtree(btree T);
int nodeCount(btree T);
btree aggiungiNodo(btree T, item nodo);
int isBST(btree T);

int main(int argc, char *argv[]){
    //INPUT DA FILE + OUTPUT DI PROVA
    printf("ALBERO\n");
    btree T = newBtree();
    T = fileBtreeV2(argv[1]);
    printBtree(T, 0);

    //CONTA FOGLIE
    printf("\n\nNUMERO FOGLIE: %d\n\n", leafCount(T));

    if(isBST(T)==1){
        printf("albero BST\n");
        return 0;
    }
    else{
        printf("albero NON BST\n");
        return 0;
    }

    //ALBERO SPECULARE
    printf("ALBERO SPECULARE\n");
    btree ST=newBtree();
    ST = speculare(T);
    printBtree(ST, 0);

    //VALORE MINIMO
    printf("\n\nVALORE MINIMO: ");
    outputItem(minBtree(T));

    //VALORE MASSIMO
    printf("\n\nVALORE MASSIMO: ");
    outputItem(maxBtree(T));

    //ALBERI UGUALI
    if(equalBtree(T, ST)){
        printf("\nAlberi Uguali\n");
    }
    else{
        printf("\nAlberi Diversi\n");
    }


    //AGGIUNTA NODO
    printf("\nAGGIUNTA NUOVO NODO:\n");
    T = aggiungiNodo(T, newItem(999));
    printBtree(T, 0);


    return 0;
}


/*
PROGETTAZIONE fileBtree(string) ---> btree

-Ricevi una stringa come parametro(filename)
-Apri il file chiamato filename in modalità lettura 
-Se l`apertura fallisce 
    restituisci un albero vuoto
-Altrimenti
    -restituisci la funzione inputBtree(file)
*/

btree fileBtree(char *filename){
    //Apertura File
    FILE *fp = fopen(filename, "r");
    //Controllo
    if(!fp){
        printf("Errore apertura file!\n");
        return newBtree(); //Restituisci albero vuoto (Apertura file fallita)
    }

    return inputBtree(fp); //Restituisci albero riempito con inputBtree
}

/*
PROGETTAZIONE inputBtree(file *) ---> btree
-Ricevi un puntatore a file (fp) come parametro
-crea due alberi SX e DX
-Dichiara variabile per lettura int (n)
-Dichiara variabile per lettura char (left, right)
-leggi un int e due char da file e assegnale alle rispettive variabili

-Se left == Y allora{
    SX = inputBtree(fp)   //SX albero pieno
}
-Altrimenti{
    SX = newBtree()     //SX albero vuoto
}

-Fare la stessa cosa con right e DX

-Restituisci consBtree(n , SX, DX)


NB: il file dovrà contenere:
        -un intero da inserire nel nodo dell`albero
        -un char che indica se ha un figlio a sinistra (Y=si  N=no)
        -un char che indica se ha un figlio a destra (Y=si N=no)

    L'albero verrà creato in Pre-Ordine (prima radice, poi sottoalbero di sinistra e poi sottoalbero di destra)
*/

btree inputBtree(FILE *fp){
    btree SX, DX;
    int n; //int da file
    char left, right; //char da file
    
    //lettura da file
    fscanf(fp, "%d %c %c", &n, &left, &right);
    
    if(left == 'Y'){
        SX = inputBtree(fp);    //Albero SX non vuoto
    }
    else{
        SX = newBtree();    //Albero SX vuoto
    }

    if(right == 'Y'){
        DX = inputBtree(fp);    //Albero DX non vuoto
    }
    else{
        DX = newBtree();    //Albero DX vuoto
    }

    return consBtree(newItem(n), SX, DX);
}

/*
PROGETTAZIONE fileBtreeV2(string) ---> btree
-Ricevi una stringa come parametro(filename)
-Apri il file chiamato filename in modalità lettura 
-Se l`apertura fallisce 
    restituisci un albero vuoto

-Crea un array di item (arr)
-Allocalo per MAX + 1 item
-Se l`allocazione fallisce restituisci un albero vuoto

-Crea e inizializza a 0 una variabile int (it) per la lettura dei valori da file
-Crea e inizializza a 0 una variabile int (n) per il numero di elementi letti

-Finchè viene letto un intero da file nella variabile it
    incrementa n
    assegna ad arr[n] un newItem(it)    //gli item verranno memorizzati a partire dalla posizione 1

-Restituisci inputBtree(arr, 1, n)  //1 = indice primo elemento   n = numero di elementi
*/

btree fileBtreeV2(char *filename){
    //Apertura File
    FILE *fp = fopen(filename, "r");
    //Controllo
    if(!fp){
        printf("Errore apertura file!\n");
        return newBtree(); //Restituisci albero vuoto (Apertura file fallita)
    }

    //Allocazione array di item
    item *arr = calloc(MAX+1, sizeof(item));
    //Controllo
    if(!arr){
        return newBtree();  //Restituisci albero vuoto (allocazione fallita)
    }

    int it = 0; //lettura int da file
    int n = 0;  //elementi array
    while(fscanf(fp, "%d", &it)==1){
        n++;
        arr[n]=newItem(it);
    }

    return inputBtreeV2(arr, 1, n);
}

/*
PROGETTAZIONE inputBtreeV2(item[], int, int) ---> btree

-Se n<1 restituisci un albero vuoto (Passo Base: array vuoto)

-Se i>n restituisci un albero vuoto (Passo Base: item arr[i] non esiste)

-Altrimenti restituisci un nuovo albero che ha:
    radice = arr[i]
    SX = inputBtreeV2(arr, 2*i, n)
    DX = inputBtreeV2(arr, 2*i+1, n)


NB: se la radice occupa la posizione i nell`array allora:
        la radice del sottoalbero sinistro occuperà la posizione 2*i
        la radice del sottoalbero destro occuperà la posizione 2*i + 1


Il file dovrà contenere solo degli interi.
Non si avrà il controllo totale sulla costruzione dell`albero, ma verrà costruito SEMPRE per livelli
*/

static btree inputBtreeV2(item *arr, int i, int n){
    //Passo Base
    if(n<1){
        return newBtree();
    }

    //Passo Base
    if(i>n){
        return newBtree();
    }
    //Passo Ricorsivo
    else{
        return consBtree(arr[i], inputBtreeV2(arr, 2*i, n), inputBtreeV2(arr, 2*i+1, n));
    }
}

void printBtree(btree T, int space){
    if (emptyBtree(T)){
        return;
    }
    else{
        space+=COUNT;
        printBtree(figlioDX(T), space);

        printf("\n");
        for (int i = COUNT; i<space; i++){
            printf(" ");
        }
        outputItem(getItem(T));

        printBtree(figlioSX(T), space);
    }
}

/*
PROGETTAZIONE leafCount(btree) ---> int

-Ricevi un btree (T) come parametro

-Se T è vuoto
    restituisci 0 (Passo Base)

-Se entrambi i sottoalberi (figli) di T sono vuoti (allora T è una foglia)
    restituisci 1 (Passo Base)

-Altrimenti
    restituisci leafCount(figlioSX(T)) + leafCount(figlioDX(T))     
    
    //Il numero di foglie di un btree è uguale al numero di foglie del suo 
    //sottoalbero sinistro + il numero di foglie del suo sottoalbero destro (Passo Ricorsivo)
*/

int leafCount(btree T){
    //Passo Base
    if(emptyBtree(T)){
        return 0;
    }

    //Passo Base
    if(emptyBtree(figlioSX(T)) && emptyBtree(figlioDX(T))){
        return 1;
    }
    //Passo Ricorsivo
    else{
        return leafCount(figlioSX(T)) + leafCount(figlioDX(T));
    }
}

/*
PROGETTAZIONE speculare(btree) ---> btree

-Ricevi un btree (T) come parametro

-Se T è vuoto
    restituisci un albero vuoto (Passo Base)

-Altrimenti 
    restituisci un nuovo albero che avra:
        come radice il valore della radice di T
        come sottoalbero sinistro la versione speculare del sottoalbero destro di T
        come sottoalbero destro la versione speculare del sottoalbero sinistro di T
        (Passo Ricorsivo)
*/

btree speculare(btree T){
    //Passo Base
    if (emptyBtree(T)){
        return newBtree();
    }
    //Passo Ricorsivo
    return consBtree(getItem(T), speculare(figlioDX(T)), speculare(figlioSX(T)));

}

/*
PROGETTAZIONE minBtree(btree) ---> item

-Ricevi un btree (T) come parametro

-Se T è vuoto
    restituisci un NULLITEM (Passo Base)

-Se T non ha figli
    restituisci il valore contenuto in T (Passo Base)

-Altrimenti restituisci il piu piccolo item tra:
    quello contenuto in T
    quello più piccolo contenuto nel sottoalbero sinistro di T
    quello più piccolo contenuto nel sottoalbero destro di T
    (Passo Ricorsivo)
*/

item minBtree(btree T){
    //Passo Base
    if(emptyBtree(T)){
        return newItem(INT_MAX);
    }

    item min = getItem(T);
    
    //Passo Base
    if(emptyBtree(figlioSX(T)) && emptyBtree(figlioDX(T))){
        return min;
    }

    item Lmin = minBtree(figlioSX(T));  //Item minore sottoalbero SX

    item Rmin = minBtree(figlioDX(T));  //Item minore sottoalbero DX

    if(is_min(Lmin, min)){
        min = Lmin;
    }

    if(is_min(Rmin, min)){
        min = Rmin;
    }

    return min; //min = item piu piccolo tra min, Lmin e Rmin
}

/*
PROGETTAZIONE maxBtree(btree) ---> item

-Ricevi un btree (T) come parametro

-Se T è vuoto
    restituisci un NULLITEM (Passo Base)

-Se T non ha figli
    restituisci il valore contenuto in T (Passo Base)

-Altrimenti restituisci il piu grande item tra:
    quello contenuto in T
    quello più grande contenuto nel sottoalbero sinistro di T
    quello più grande contenuto nel sottoalbero destro di T
    (Passo Ricorsivo)
*/

item maxBtree(btree T){
    if(emptyBtree(T)){
        return newItem(INT_MIN);
    }

    item max = getItem(T);

    if(emptyBtree(figlioSX(T)) && emptyBtree(figlioDX(T))){
        return max;
    }

    item Lmax = maxBtree(figlioSX(T));
    
    item Rmax = maxBtree(figlioDX(T));
    
    if(is_min(max, Lmax)){
        max = Lmax;
    }
    if(is_min(max, Rmax)){
        max = Rmax;
    }

    return max;
}

/*
PROGETTAZIONE equalBtree(btree, btree) ---> int

-Ricevi due btree (T1, T2) come parametri

-Se T1 AND T2 sono vuoti
    restituisci 1 (Passo Base: due alberi vuoti sono uguali)

-Se T1 è vuoto OR T2 è vuoto (si esclude già che siano entrambi vuoti quindi sono diversi)
    restituisci 0 (Passo Base)

-Altrimenti 
    restituisci il risultato del confronto tra:
        l`item contenuto in T1 e quello contenuto in T2
        AND
        sottoalbero sinistro di T1 e sottoalbero sinistro di T2
        AND
        sottoalbero destro di T1 e sottoalbero destro di T2

    //Due btree sono uguali se sono vuoti 
    //oppure se la loro radice è uguale AND i loro sottoalberi sinistri sono uguali AND i loro sottoalberi destri sono uguali (Passo Ricorsivo)
*/

int equalBtree(btree T1, btree T2){
    //Passo Base
    if (emptyBtree(T1) && emptyBtree (T2)){
        return 1;
    }

    //Passo Base
    if (emptyBtree(T1) || emptyBtree (T2)){
        return 0;
    }
    //Passo Ricorsivo
    else{
        return (eq(getItem(T1), getItem(T2)) && equalBtree(figlioSX(T1), figlioSX(T2)) && equalBtree(figlioDX(T1), figlioSX(T2)));
    }

}

int heightBtree(btree T){
    //Passo base
    if(emptyBtree(T)){
        return 0;
    }

    int L_height = heightBtree(figlioSX(T));
    int R_height = heightBtree(figlioDX(T));

    if(L_height > R_height){
        return L_height + 1;
    }
    else{
        return R_height + 1;
    }
}

int nodeCount(btree T){
    //Passo Base
    if(emptyBtree(T)){
        return 0;
    }

    return 1 + nodeCount(figlioSX(T)) + nodeCount(figlioDX(T));
}

/*
PROGETTAZIONE aggiungiNodo(btree, item) ---> btree

-Ricevi un btree (T) e un item (nodo) come parametri

-Crea un nuovo albero senza figli con radice = nodo (new) 

-Se T è vuoto
    restituisci new

-crea un btree temporaneo (tmp)
-crea una coda di btree (q)

-inserisci l`albero T nella coda q

-Finchè q non è vuota
    assegna a tmp l`albero in testa a q (rimuovendolo dalla coda)

    Se tmp non ha il figlio sinistro
        aggiungi new come figlio sinistro di tmp
        Stop ciclo (break)
    altrimenti
        aggiungi il figlio sinistro di tmp alla coda q

    Se tmp non ha il figlio destro
        aggiungi new come figlio destro di tmp
        Stop ciclo (break)
    altrimenti
        aggiungi il figlio destro di tmp alla coda q


-Libera q
-Restituisci T
*/


btree aggiungiNodo(btree T, item nodo){
    btree new = consBtree(nodo, newBtree(), newBtree());    //Nuovo albero
    
    if(emptyBtree(T)){
        return new;
    }
    
    btree tmp;
    queue q = newQueue();   //Coda di btree

    enQueue(q, T);  //Inserisce l`albero nella coda

    while(!emptyQueue(q)){
        tmp = deQueue(q);   //Rimuove l`albero dalla coda e lo assegna a tmp
        
        if(emptyBtree(figlioSX(tmp))){ 
            updateSX(tmp, new);
            break;
        }
        else{
            enQueue(q, figlioSX(tmp));
        }

        if(emptyBtree(figlioDX(tmp))){
            updateDX(tmp, new);
            break;
        }
        else{
            enQueue(q, figlioDX(tmp));
        }
    }

    free(q);
    return T;
}

/*
PROGETTAZIONE: isBST(btree) ---> bool

Ricevi un btree (T) come parametro

Se T è un albero vuoto
    allora restituisci 1    (PASSO BASE: un albero vuoto è un bst)

Se T è minore del MAX nel suo sottoalbero SX  OR  è maggiore del MIN nel suo sottoalbero DX 
    allora restituisci 0    
    (PASSO BASE: la radice di un BST deve essere maggiore di tutti i valori nel suo sottoalbero SX 
                e minore di tutti quelli del suo sottoalbero DX)


altrimenti resituisci l`esito del controllo sul figlioSX  &&  l`esito del controllo sul figlioDX (PASSO RICORSIVO)
*/


int isBST(btree T){
    if(emptyBtree(T)){
        return 1;
    }

    item maxSX = maxBtree(figlioSX(T));
    item minDX = minBtree(figlioDX(T));

    if(is_min(getItem(T), maxSX) || is_min(minDX, getItem(T))){
        return 0;
    }

    else{
        return isBST(figlioSX(T)) && isBST(figlioDX(T));
    }
}




/*
PROTOTIPO FUNZIONE valuta espressioni

float valuta(btree T){
    if(emptyBtree(T)){
        return 0;
    }
    
    if(emptyBtree(figlioSX(T)) && emptyBtree(figlioDX(T))){
        return int(getItem(T));
    }
    
    char c = getItem (T);
    
    if(c == '+'){
        return valuta(figlioSX(T)) + valuta(figlioDX(T));
    }

    if(c == '-'){
        return valuta(figlioSX(T)) - valuta(figlioDX(T));
    }

    if(c == '*'){
        return valuta(figlioSX(T)) * valuta(figlioDX(T));
    }

    if(c == '/'){
        return valuta(figlioSX(T)) / valuta(figlioDX(T));
    }
}*/