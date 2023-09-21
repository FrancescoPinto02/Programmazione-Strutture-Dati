#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"

#define MAXSTR 51

struct c_item{
    char * nome;
    int voto;
    int data;
};

static char *readString(void);

int get_voto(item x){
    return x->voto;
}

int get_data(item x){
    return x->data;
}

int eq(item x, item y){
    if(strcmp(x->nome, y->nome)==0){
        return 1;
    }
    else{
        return 0;
    }
}

item inputItem(void){
    item new=malloc(sizeof(*new));
    if(!new){
        printf("Errore Allocazione\n");
        return NULL;
    }

    printf("NUOVO ESAME\n");
    fflush(stdin);
    printf("Nome: ");
    new->nome=readString();
    printf("Voto: ");
    scanf("%d", &new->voto);
    printf("Data: ");
    scanf("%d", &new->data);
    return new;
}

void outputItem(item x){
    printf("ESAME\n");
    printf("Nome: %s", x->nome);
    printf("Voto: %d", x->voto);
    printf("Data: %d", x->data);
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
