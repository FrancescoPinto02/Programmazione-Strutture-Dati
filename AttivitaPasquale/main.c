#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

list inputList(int elements);
void printList(list l);
int findElement(item element, list l);
list switchCoppie(list l);
list removeCentral(list l);
list inputListFILE(char *fname);


int main (int argc, char *argv[]){
    int n;
    list l=newList();

    //Caricamento Lista
    printf("CARICAMENTO LISTA\n");
    if(argc==2){
        l=inputListFILE(argv[1]);
    }
    else{
        printf("Quanti elementi vuoi inserire? ");
        scanf("%d", &n);
        l=inputList(n);
    }
    
    //Stampa Lista
    printf("STAMPA LISTA\n");
    printList(l);

    //Ricerca Elemento nella lista
    item el;
    printf("\nRICERCA ELEMENTO\n");
    printf("Elemento Da ricercare: ");
    input_item(&el);
    if(findElement(el, l)){
        printf("Elemento Trovato\n");
    }
    else{
        printf("Elemento non Trovato\n");
    }

    //Ricerca posizione elemento 25
    printf("\nRICERCA POSZIONE ELEMENTO 25\n");
    int pos=posItem(l,25);
    if(pos==-1){
        printf("25 non e nella lista\n");
    }
    else{
        printf("25 e in posizione %d\n", pos);
    }

    //Switch a coppie nella lista
    printf("\nSWITCH COPPIE LISTA\n");
    l=switchCoppie(l);
    printList(l);

    //Rimuovi elemento Centrale
    printf("\nRIMOZIONE ELEMENTO/I CENTRALE/I\n");
    l=removeCentral(l);
    printList(l);

    return 0;
}

list inputList(int elements){
    list l=newList();
    item val;
    for(int i=0; i<elements; i++){
        printf("Elemento %d: ", i);
        input_item(&val);
        l=consList(val, l);
        printf("\n");
    }
    return reverseList(l);
}

void printList(list l){
    int i=0;
    if(emptyList(l)){
        printf("Lista vuota!\n");
    }
    while(!emptyList(l)){
        printf("Elemento %d: ",i);
        output_item(getFirst(l));
        printf("\n");
        l=tailList(l);
        i++;
    }
}

int findElement(item element, list l){
    while(!emptyList(l)){
        if (eq(getFirst(l), element)){
            return 1;
        }
        else{
            l=tailList(l);
        }
    }
    return 0;
}

list switchCoppie(list l){
    int n=sizeList(l);
    if(n<2){
        return l;
    }

    list l1,l2;
    l1=l;
    l2=tailList(l1);
    while(!emptyList(l1) && !emptyList(l2)){
        updateList(l1, l2);
        l1=tailList(l2);
        l2=tailList(l1);
    }
    
    return l;
}

list removeCentral(list l){
    int n=sizeList(l);
    l=removeList(l, n/2);
    if(n%2==0){
        l=removeList(l, (n/2)-1);
    }
    return l;
}

list inputListFILE(char *fname){
    FILE *fp=fopen(fname, "r");
    list l=newList();
    int val=0;
    while(fscanf(fp,"%d",&val)==1){
        l=consList(val,l);
    }
    fclose(fp);
    return reverseList(l);
}