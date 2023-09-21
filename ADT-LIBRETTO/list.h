#include "item.h"

typedef struct node *list;

/*  !!ATTENZIONE!!  !!ATTENZIONE!!  !!ATTENZIONE!!  !!ATTENZIONE!!  
    
    -Usare con cautela assegnamenti del tipo: 
        list l1 = list l2;

    -Funzioni come insertItem e removeItem hanno effetti collaterali e vanno usati solamente nel modo seguente:
        L=insertItem(L, pos, it)    L=removeItem(L, pos)  

    -Facendo operazioni del tipo:
        L1=L2
        L3=removeItem(L2, pos)
    l`operazione verrebbe effettuata su tutte e tre le liste

    -Se si desidera copiare una lista utilizzare la funzione cloneList:
        L2=cloneList(L1)

    !!ATTENZIONE!!  !!ATTENZIONE!! !!ATTENZIONE!!  !!ATTENZIONE!!  */   

//Crea una nuova lista
list newList(void);

//Controlla se la lista è vuota
int emptyList(list l);

//Scorre la lista di una posizione
list tailList(list l);

//Aggiunge un elemento in testa alla lista
list consList(list l, item val);

//Restituisce il primo elemento della lista
item getFisrt(list l);

//Restituisce la lunghezza della lista
int sizeList(list l);

//Restituisce la posizione di un item all`interno della lista
int posItem(list l, item val);

//Restituisce l`item in posizione pos della lista l
item getItem(list l, int pos);

//Restituisce la lista al contrario
list reverseList(list l);

//Stampa la lista su standard output
void outputList(list l);

//Riempie la lista con n elementi
list inputList(int n);

//inserisce un Item in posizione pos della lista
list insertItem(list l, int pos, item val);

//Rimuove un Item in posizione pos della lista
list removeItem(list l, int pos);

//Scambia due item nella lista
void swapItem(list e1, list e2);

//Duplica una lista
list cloneList(list l);