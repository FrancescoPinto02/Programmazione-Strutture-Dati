#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "item.h"
#include "libretto.h"

#define MAXSTR 51

struct c_lib{
    char * cognome;
    char * nome;
    int matricola;
    list esami;
};

static char *readString(void);

lib newLib(void){
    lib new=malloc(sizeof(*new));
    if(!new){
        printf("Allocazione Fallita\n");
        return NULL;
    }
    else{
        printf("CREAZIONE NUOVO LIBRETTO\n");
        printf("Cognome: ");
        new->cognome=readString();
        printf("Nome: ");
        new->nome=readString();
        printf("Matricola: ");
        scanf("%d", &new->matricola);
        fflush(stdin);
        new->esami=newList();
        return new;
    }
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

char * get_cognome(lib l){
    return l->cognome;
}

char * get_nome(lib l){
    return l->nome;
}

int get_matricola(lib l){
    return l->matricola;
}

list get_esami(lib l){
    return l->esami;
}

int addExam(lib l, item ex){
    if(!l || !ex){
        return 0;
    }

    l->esami=consList(l->esami, ex);
    return 1;
}

int findExam(lib l, item ex){
    if(posItem(l->esami, ex)==-1){
        return 0;
    }
    else{
        return 1;
    }
}