#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#include "list.h"

struct node
{
    item value;
    struct node * next;
};

list newList(void){
    return NULL;
}

//Se la lista è vuota restituisce 1 altrimenti restituisce 0
int emptyList(list l){
    if (l==NULL){
        return 1;
    }
    else return 0;
}

//Restituisce l'indirizzo del nodo successivo
list tailList(list l){
    if (!emptyList(l)){  //se la lista non è vuota restituisce il contenuto di l->next (indirizzo nodo successivo)
        return l->next; 
    }
    else return NULL;  //se la lista è vuota restituisce NULL
}

//Aggiunge un nuovo nodo in testa alla lista
list consList(list l, item val){
    struct node * new;  //crea e alloca nuovo nodo
    new=malloc(sizeof(*new));
    
    if(!new){  //se l'allocazione è fallita restituisce la lista invariata
        printf("Allocazione Fallita\n");
        return l;  
    }
    else{  //Se l'allocazione è riuscita aggiunge il nuovo nodo in testa modificando opportunamente i puntatori
        new->value=val;
        new->next=l;
        l=new;
        return l;  //Restituisce l'indirizzo di memoria del nuovo nodo
    }
}

//Restituisce il valore dell'item contenuto nel nodo in testa alla lista
item getFisrt(list l){
    if (!emptyList(l)){  //se la lista non è vuota restituisce il contenuto del campo l->value
        return l->value;
    }
    else{  //se la lista è vuota restituisce NULLITEM
        return NULLITEM;
    }
}

//Restituisce il numero di nodi contenuti nella lista
int sizeList(list l){
    int size=0;
    while(!emptyList(l)){  //finche la lista non è vuota incrementa size e richiama tailList
        size++;
        l=tailList(l);
    }
    return size;  //restituisce size
}

//Data una lista e un item restituisce la posizione che l`item occupa all`interno della lista
int posItem(list l, item val){
    int found=0;
    int pos=0;
    
    while(!emptyList(l) && !found){  //finchè la lista non è vuota e l`item non è stato trovato confronta val e il primo elemento della lista
        if(eq(val, getFisrt(l))){  //se val e il primo elemento della lista sono uguali assegna 1 a found e quindi esce dal while
            found=1;
        }
        else{  //se non sono uguali scorre la lista con tailList e incrementa pos
            l=tailList(l);
            pos++;
        }
    }
    if (!found){  //Se found è ancora a 0 (elemento non trovato) restituisce -1
        return -1;
    }
    else return pos;  //Altrimenti restituisce la posizione
}

//Data una lista e una posizione restituisce l`item in quella posizione
item getItem(list l, int pos){
    if (pos >= sizeList(l) || pos<0){  //Se pos è maggiore o uguale della dimensione della lista, o è una posizione non valida (<0) 
        return NULLITEM;  //restituisce NULLITEM
    }
    else{  //Se pos è minore della dimensione della lista 
        for(int i=0; i!=pos; i++){  //Scorre la lista con tailList fino alla posizione pos
            l=tailList(l);
        }
        return getFisrt(l);  //Restituisce l`item in posizione pos
    }
}

//Data una lista restituisce una lista con gli elementi in ordine inverso
list reverseList(list l){
    list rev=newList(); //Crea una nuova lista

    while(!emptyList(l)){  //Finchè la lista non è vuota 
        rev=consList(rev ,getFisrt(l));  //aggiunge il primo item della lista l alla nuova lista
        l=tailList(l);  //Scorre la lista l
    }
    return rev; //restituisce la nuova lista
}

//Data una lista la stampa su standard output
void outputList(list l){
    int i=0;
    if(emptyList(l)){  //Se la lista è vuota stampa "Lista Vuota!"
        printf("Lista Vuota!\n");
    }
    else{
        while(!emptyList(l)){ //Altrimenti finchè la lista non è vuota
            printf("Elemento %d: ",i);
            outputItem(getFisrt(l)); //stampa il primo item
            printf("\n");
            l=tailList(l); //scorri la lista
            i++;
        }
    }
}

//Dato un intero n , restituisce una lista di n elementi 
list inputList(int n){
    list l=newList();  //crea una nuova lista
    
    for(int i=0; i<n; i++){ //prende in input un item e lo aggiunge alla lista per n volte
        printf("Elemento %d: ",i);
        l=consList(l, inputItem());
    }
    //NB: gli elementi vengono aggiunti in testa alla lista quindi il primo elemento sarà l`ultimo
    //    perciò bisogna restituire la reverse 
    return reverseList(l); //restituisce la lista al contrario
}

//Aggiunge l`item nella posizione pos della lista   !!ATTENZIONE: LA FUNZIONE HA EFFETTI COLLATERALI!!
list insertItem(list l, int pos, item val){
    list prec, tmp;
    prec=l;

    if(pos > sizeList(l) || pos < 0){  //se la posizione non è valida restituisce la lista senza modifiche
        printf("Posizione non valida\n");
        return l;
    }

    if(pos==0){  //Se la posizione è 0 aggiunge l`item in testa con consList
        l=consList(l, val);
    }
    else{  //Altrimenti scorre la lista fino alla posizione precedente a pos
        for(int i=0; i<pos-1; i++){
            prec=tailList(prec);
        }
        tmp=consList(prec->next, val);  //Aggiunge il nuovo item in posizione pos
        prec->next=tmp;  //Collega il nodo precedente al nodo nuovo
    }
    return l;  //restituisce la lista
}


//Elimina l`item in posizione pos della lista   !!ATTENZIONE: LA FUNZIONE HA EFFETTI COLLATERALI!!
list removeItem(list l, int pos){
    list prec, tmp;
    
    if(pos<0 || pos>=sizeList(l)){  //Se la posizione pos non è valida restituisce la lista invariata
        printf("Posizione non valida\n");
        return l;
    }

    if(pos==0){  //se la posizione è 0 elimina il nodo in testa
        tmp=l;
        l=tailList(l);
        free(tmp);
    }
    else{ //altrimenti se la posizione è maggiore di 0
        prec=l;
        for(int i=0; i < pos-1; i++){  //scorre la lista fino al nodo precedente di quello da eliminare
            prec=tailList(prec);
        }
        tmp=tailList(prec);
        prec->next=tmp->next;
        free(tmp);  //elimina il nodo dopo aver collegato il precedente con il successivo
    }
    return l;  //restituisce la lista
}

//Scambia due elementi di una lista
void swapItem(list e1, list e2){
    item tmp;
    tmp=e1->value;
    e1->value=e2->value;
    e2->value=tmp;
}

//Duplica una lista 
list cloneList(list l){
    list clone=newList();  //Crea una nuova lista

    while(!emptyList(l)){  //finche la lista da clonare non è vuota 
        clone=consList(clone, getFisrt(l));  //aggiungi un nuovo nodo al clone con il primo item della lista da clonare
        l=tailList(l);  //Scorri la lista da clonare
    }
    return reverseList(clone);  //Restituisci la reverse del clone
}