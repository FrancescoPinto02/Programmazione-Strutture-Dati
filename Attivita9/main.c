#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "item.h"
#include "list.h"

#define MAXDIM 100

int quadrato(int n);

int euclide(int m, int n);

int palindroma(char *str);

static int is_palindroma(char *str, int i, int j);

int tartaglia(int a, int b);


char *readString(void);
void inputListFILE (char *fname, list l);



int main (int argc, char *argv[]){

    //LUNGHEZZA DI UNA LISTA (le funzioni sono in list.c)
    list l = newList();
    inputListFILE(argv[1], l);
    printf("SizeList Iterativa: %d\n", sizeListIt(l));
    printf("SizeList Ricorsiva: %d\n", sizeListRec(l));
    printf("SizeList normale: %d\n", sizeList(l));


    //CALCOLO RICORSIVO N-ESIMO QUADRATO
    int num = 0;
    printf("\n\nInserisci numero da elevare al quadrato: ");
    scanf("%d", &num);
    fflush(stdin);
    printf("%d^2 = %d\n\n", num, quadrato(num));


    //CALCOLO MCD CON ALGORITMO EUCLIDEO
    int m=0, n=0;
    printf("Inserisci m: ");
    scanf("%d", &m);
    fflush(stdin);
    printf("Inserisci n: ");
    scanf("%d", &n);
    fflush(stdin);
    printf("MCD tra %d e %d = %d\n\n", m, n, euclide(m, n));


    //PAROLA PALINDROMA
    char *str;
    printf("Inserisci stringa: ");
    str=readString();

    if(palindroma(str)==1){
        printf("La stringa e' palindroma\n\n");
    }
    else{
        printf("La stringa non e' palindroma\n\n");
    }
    
    
    //TRIANGOLO DI TARTAGLIA
    int a=0, b=0;
    printf("Inserisci indice riga: ");
    scanf("%d", &a);
    fflush(stdin);
    printf("Inserisci indice colonna: ");
    scanf("%d", &b);
    fflush(stdin);
    printf("Tartaglia[%d][%d] = %d\n\n", a, b, tartaglia(a, b));


    return 0;
}


void inputListFILE (char *fname, list l){
    int n;
    FILE *fp=fopen(fname, "r");
    
    if(!fp){
        printf("Errore apertura file\n");
        return;
    }
    
    while(fscanf(fp,"%d",&n)==1){
        consList(l, newItem(n));
    }
    
    fclose(fp);
}


//FUNZIONE N-ESIMO QUADRATO
int quadrato(int n){
    if(n==0){
        return 0;
    }
    else{
        return (2*n -1) + quadrato(n-1); 
    }
}


//FUNZIONE MCD
int euclide(int m, int n){
    //Caso con m minore di n
    if(m < n ){
        return euclide(n, m);
    }

    //Caso con m ed n uguali MCD=n=m
    if(m == n){
        return m;
    }
    
    int d = m-n;

    if((d)==n){
        return d;
    }

    else{
        if(d < n){
            return euclide(n, d);
        }
        else{
            return euclide(d, n);
        }
    }
}


//FUNZIONE PAROLA PALINDROMA
int palindroma(char *str){
    return is_palindroma(str, 0, strlen(str)-1);
}

static int is_palindroma(char *str, int i, int j){
    if(i>=j){
        return 1;
    }
    else{
        if(tolower(str[i])==tolower(str[j])){
            return is_palindroma(str, i+1, j-1);
        }

        if(str[i]==' '){
            return is_palindroma(str, i+1, j);
        }

        if(str[j]==' '){
            return is_palindroma(str, i, j-1);
        }

        return 0;
    }
}


//FUNZIONE TRIANGOLO DI TARTAGLIA
int tartaglia(int a, int b){
    if(a==b || b==0){
        return 1;
    }
    else{
        return tartaglia(a-1, b-1) + tartaglia(a-1, b);
    }
}


char *readString(void){
    char *str=calloc(MAXDIM, sizeof(char));
    if (!str){
        printf("Allocazione fallita\n");
        return NULL;
    }

    str=fgets(str, MAXDIM, stdin);
    if(str[strlen(str)-1]=='\n'){
        str[strlen(str)-1]='\0';
    }

    str=realloc(str, sizeof(char)*(strlen(str)+1));
    fflush(stdin);
    return str;
}