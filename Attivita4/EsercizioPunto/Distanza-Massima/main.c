#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int main(void){
    int n=0; //numero punti
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
    int i; 
    for (i=0; i<n; i++){
        printf("\nCreazione p[%d]\nInserisci x: ",i);
        scanf("%f", &ascissa);
        printf("Inserisci y: ");
        scanf("%f", &ordinata);
        p[i]=creaPunto(ascissa, ordinata);
    }


    //Calcolo distanze
    int pmax1=0, pmax2=0; //indici punti con distanza max
    float dmax=0; //distanza massima
    int j;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(distanza(p[i],p[j])>dmax){
                pmax1=i;
                pmax2=j;
                dmax=distanza(p[i],p[j]);
            }
        }
    }

    //Stampa di punti e distanza
    printf("PUNTI PIU DISTANTI:\n");
    printf("p[%d]:\n",pmax1);
    stampa(p[pmax1]);
    printf("p[%d]:\n",pmax2);
    stampa(p[pmax2]);
    printf("Distanza: %f\n",dmax);
    return 0;
}