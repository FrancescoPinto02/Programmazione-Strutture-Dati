#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"


#define BUFFSIZE 100

//Ricerca del libro più vecchio
libro libropiuvecchio(libro* biblioteca, int n);

//Ricerca del libro meno costoso
libro libromenocostoso(libro* biblioteca, int n);

//Trova tutti i libri dell’editore X
libro* ricercaeditore(char* editore, libro* biblioteca, int n, int* num);

//Ridurre del X% il costo dei libri dell’anno AAAA.
// questa funzione potrebbe restituire void oppure un intero
// che restiuisce 0 in caso tutto è andato correttamente
void scontalibri(libro* biblioteca, int n, int anno, float percentuale);

//Trova due libri con scarto di prezzo minore
libro* trovalibriprezzosimile(libro* biblioteca, int n);

//Calcola il costo totale di tutti i libri dell’anno AAAA
float costototale(libro* biblioteca,int n, int anno);

//Elimina i libri dell'anno AAAA
//void eliminaLibri(libro* biblioteca, int n, int anno);

int main(int argc, char *argv[]){
    int n=atoi(argv[2]);
    libro *biblioteca;
    char tit[100];
    char ed[50];
    char buffer[50];
    float pr=0;
    int an=0;
    FILE* fp;

    if(argc!=3){
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }
    
    fp=fopen(argv[1], "r");
    if(!fp){
        printf("Errore apertura file\n");
        exit(1);
    }

    biblioteca = calloc(n, sizeof(libro));
    if(!biblioteca){
        printf("Allocazione fallita\n");
        exit(1);
    }
    
    for (int i=0; i<n; i++){
        fgets(tit, 100, fp);
        if(tit[strlen(tit)-1]=='\n'){
            tit[strlen(tit)-1]='\0';
        }
        fgets(ed, 50, fp);
        if(ed[strlen(ed)-1]=='\n'){
            ed[strlen(ed)-1]='\0';
        }
        fgets(buffer, 50, fp);
        pr=atof(buffer);
        fgets(buffer, 50, fp);
        an=atoi(buffer);
        biblioteca[i]=newLibro(tit, ed, pr, an);
    }

    for (int j=0; j<n; j++){
        printf("%s %s %f %d\n", get_titolo(biblioteca[j]), get_editore(biblioteca[j]), get_prezzo(biblioteca[j]), get_anno(biblioteca[j]));
    }

    //realizzare le varie funzioni dell'esercizio
    printf("\n\nLIBRO PIU VECCHIO\n");
    libro elder=libropiuvecchio(biblioteca, n);
    printf("%s %s %f %d\n", get_titolo(elder), get_editore(elder), get_prezzo(elder), get_anno(elder));
    
    printf("\n\nLIBRO MENO COSTOSO\n");
    libro cheaper=libromenocostoso(biblioteca, n);
    printf("%s %s %f %d\n", get_titolo(cheaper), get_editore(cheaper), get_prezzo(cheaper), get_anno(cheaper));
    
    printf("\n\nRICERCA EDITORE\n");
    int num=0;
    fflush(stdin);
    printf("Chi editore vuoi ricercare:");
    fgets(ed, 50, stdin);
    if(ed[strlen(ed)-1]=='\n'){
        ed[strlen(ed)-1]='\0';
    }
    libro *lib_editore=ricercaeditore(ed,biblioteca, n, &num);
    for (int j=0; j<num; j++){
        printf("%s %s %f %d\n", get_titolo(lib_editore[j]), get_editore(lib_editore[j]), get_prezzo(lib_editore[j]), get_anno(lib_editore[j]));
    }
    

    printf("\n\nSCONTO LIBRI\n");
    float perc=0;
    printf("Inserisci percentuale sconto: ");
    scanf("%f", &perc);
    printf("Inserisci l`anno dei libri da scontare: ");
    scanf("%d", &an);
    scontalibri(biblioteca, n, an, perc);

    printf("\n\nLIBRO PREZZO SIMILE\n");
    libro *pr_simile=trovalibriprezzosimile(biblioteca, n);
    printf("%s %s %f %d\n", get_titolo(pr_simile[0]), get_editore(pr_simile[0]), get_prezzo(pr_simile[0]), get_anno(pr_simile[0]));
    printf("%s %s %f %d\n", get_titolo(pr_simile[1]), get_editore(pr_simile[1]), get_prezzo(pr_simile[1]), get_anno(pr_simile[1]));

    printf("\n\nCOSTO TOTALE\n");
    float tot=0;
    printf("Inserisci l`anno per calcolare il costo totale: ");
    scanf("%d", &an);
    tot=costototale(biblioteca, n, an);
    printf("Costo totale libri anno %d: %f",an, tot);

    return 0;
}


libro libropiuvecchio(libro* biblioteca, int n){
    libro old= biblioteca[0];
    for(int i=0; i<n; i++){
        if(get_anno(biblioteca[i])<get_anno(old)){
            old=biblioteca[i];
        }
    }
    return old;
}

libro libromenocostoso(libro* biblioteca, int n){
    libro cheap= biblioteca[0];
    for(int i=0; i<n; i++){
        if(get_prezzo(biblioteca[i])<get_prezzo(cheap)){
            cheap=biblioteca[i];
        }
    }
    return cheap;
}

libro* ricercaeditore(char* editore, libro* biblioteca, int n, int* num){
    int k=0;
    libro* lib=calloc(n,sizeof(libro));
    if(!lib){
        printf("Allocazione fallita\n");
        return NULL;
    }
    for(int i=0; i<n; i++){
        if(strcmp(editore, get_editore(biblioteca[i]))==0){
            lib[k]=biblioteca[i];
            k++;
        }
    }
    lib=realloc(lib, sizeof(libro)*k);
    *num=k;
    return lib;
}

void scontalibri(libro* biblioteca, int n, int anno, float percentuale){
    for(int i=0; i<n; i++){
        if (get_anno(biblioteca[i])==anno){
            sconto(biblioteca[i], percentuale);
        }
    }
}

libro* trovalibriprezzosimile(libro* biblioteca, int n){
    libro* l=calloc(2, sizeof(libro));
    float min=99999, p1, p2;
    int i, j;
    for (i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            p1=get_prezzo(biblioteca[i]);
            p2=get_prezzo(biblioteca[j]);
            if (p1 > p2){
                if((p1-p2)<min){
                    min=p1-p2;
                    l[0]=biblioteca[i];
                    l[1]=biblioteca[j];
                } 
            }
            else{
                if((p2-p1)<min){
                    min=p2-p1;
                    l[0]=biblioteca[j];
                    l[1]=biblioteca[i];
                }
            }
        }
    }
    return l;
}

float costototale(libro* biblioteca,int n, int anno){
    float tot=0;
    for (int i=0; i<n; i++){
        if(get_anno(biblioteca[i])==anno){
            tot=tot+get_prezzo(biblioteca[i]);
        }
    }
    return tot;
}
