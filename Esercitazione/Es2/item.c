#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "item.h"

#define MAXSTR 50

struct c_item{
    char *titolo;
    char *cantante;
    int durata;
};

int eq(item x, item y){
    if(strcmp(x->titolo, y->titolo)==0 && strcmp(x->cantante, y->cantante)==0){
        return 1;
    }
    else{
        return 0;
    }
}

char *get_titolo(item x){
    return x->titolo;
}

char *get_cantante(item x){
    return x->cantante;
}

int get_durata(item x){
    return x->durata;
}

static char *readString(void){
    char *str=calloc(MAXSTR, sizeof(char));
    if (!str){
        printf("Allocazione fallita\n");
        return NULL;
    }

    str=fgets(str, MAXSTR, stdin);
    if(str[strlen(str)-1]=='\n'){
        str[strlen(str)-1]='\0';
    }

    str=realloc(str, sizeof(char)*(strlen(str)+1));
    fflush(stdin);
    return str;
}

item inputItem(void){
    item new = malloc(sizeof(*new));
    if(!new){
        printf("Allocazione fallita!\n");
        return NULLITEM;
    }

    printf("Inserire Titolo: ");
    new->titolo=readString();
    printf("Inserisci Cantante: ");
    new->cantante=readString();
    printf("Inserisci Durata: ");
    scanf("%d", &new->durata);

    return new;
}

void outputItem(item x){
    printf("Titolo: %s\n", x->titolo);
    printf("Cantante: %s\n", x->cantante);
    printf("Durata: %d\n", x->durata);
}

item cloneItem(item x){
    item clone = malloc(sizeof(*clone));
    if(!clone){
        return NULLITEM;
    }

    strcpy(clone->titolo, x->titolo);
    strcpy(clone->cantante, x->cantante);
    clone->durata = x->durata;
    return clone;
}
