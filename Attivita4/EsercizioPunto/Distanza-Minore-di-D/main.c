#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int main(void){
    int n=0; //numero punti
    float d=0;//distanza di controllo
    int cont=0; //numero coppie di punti più distanti di d
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

    //Inserimento distanza controllo
    printf("Dammi la distanza:");
    scanf("%f", &d);

    //Calcolo distanze
    int j;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(distanza(p[i],p[j])<d){
                cont++;
            }
        }
    }

    //Stampa di cont
    printf("Le coppie di punti a distanza minore di %f sono %d", d, cont);
    return 0;
}