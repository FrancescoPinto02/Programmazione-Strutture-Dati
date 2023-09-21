#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

void riordina(punto *p, int n, char coordinata, char criterio);

int main(void){
    int n=0; //numero punti
    int i;
    float ascissa=0, ordinata=0;
    punto * p; //array di punti


    //allocazione array di punti
    printf("Quanti punti vuoi inserire? ");
    scanf("%d", &n);
    p=calloc(n, sizeof(punto));
    if(!p){
        printf("Allocazione Fallita!\n");
        exit(1);
    }

    //Riempimento array
    for (i=0; i<n; i++){
        printf("\nCreazione p[%d]\nInserisci x: ",i);
        scanf("%f", &ascissa);
        printf("Inserisci y: ");
        scanf("%f", &ordinata);
        p[i]=creaPunto(ascissa, ordinata);
    }

    //Chiamata funzione ordinamento
    char coord, crit; //parametri ordinamento
    printf("Inserire parametro coordinata: ");
    scanf("\n%c", &coord);
    printf("Inserire parametro criterio: ");
    scanf("\n%c", &crit);
    riordina(p,n,coord,crit);

    //Stampa punti ordinati
    for(i=0; i<n; i++){
        printf("p[%d]:\n", i);
        stampa(p[i]);
    }
    return 0;
}

void riordina(punto *p, int n, char coordinata, char criterio){
    int i,j;
    punto swap;
    switch (coordinata)
    {
    case 'a':
        switch (criterio)
        {
        case 'a':
            for (i=0; i<n-1; i++){
                for(j=i+1; j<n; j++){
                    if(ascissa(p[j])<ascissa(p[i])){
                        swap=p[j];
                        p[j]=p[i];
                        p[i]=swap;
                    }
                }
            }
            break;
        case 'd':
            for (i=0; i<n-1; i++){
                for(j=i+1; j<n; j++){
                    if(ascissa(p[j])>ascissa(p[i])){
                        swap=p[j];
                        p[j]=p[i];
                        p[i]=swap;
                    }
                }
            }
            break; 
        default:
            printf("Parametri Errati!\n");
            return;
            break;
        }
        break;
    
    case 'o':
        switch (criterio)
        {
        case 'a':
            for (i=0; i<n-1; i++){
                for(j=i+1; j<n; j++){
                    if(ordinata(p[j])<ordinata(p[i])){
                        swap=p[j];
                        p[j]=p[i];
                        p[i]=swap;
                    }
                }
            }
            break;
        case 'd':
            for (i=0; i<n-1; i++){
                for(j=i+1; j<n; j++){
                    if(ordinata(p[j])>ordinata(p[i])){
                        swap=p[j];
                        p[j]=p[i];
                        p[i]=swap;
                    }
                }
            }
            break;
        default:
            printf("Parametri Errati!\n");
            return;
            break;
        }
        break;

    default:
        printf("Parametri Errati!\n");
        return;
        break;
    }
}