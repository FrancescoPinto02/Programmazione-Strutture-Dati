#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "item.h"
#include "libretto.h"


int main(int argc, char argv[]){
    lib libretto=newLib();
    int n;
    item esame;
    printf("Quanti esami vuoi inserire? ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("ESAME %d\n", i);
        esame=inputItem();
        addExam(libretto, esame);
    }
    printf("CARICAMENTO COMPLETATO\n");

    
    printf("Esame da cercare\n");
    esame=inputItem();

    if(findExam(libretto, esame)==0){
        printf("Esame non trovato\n");
    }
    else{
        printf("Esame trovato\n");
    }
    return 0;
}

