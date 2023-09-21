#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char ** vocali_consonanti(char * string, int * vowels, int * consonants);

int main(int argc, char* argv[]){
    char** voc_con;
    int vocali=0, consonanti=0, i=0;
    if (argc!=2){
        printf("Errore! Numero di argomenti non valido\n");
        exit(1);
    }
    voc_con=vocali_consonanti(argv[1], &vocali, &consonanti);
    printf("VOCALI: ");
    for(i=0; i<vocali; i++){
        printf("%c ", voc_con[0][i]);
    }
    printf("\nCONSONANTI: ");
    for(i=0; i<consonanti; i++){
        printf("%c ", voc_con[1][i]);
    }
    return 0;
}

char ** vocali_consonanti(char * string, int * vowels, int * consonants){
    int voc=0, con=0, i=0;
    char c;
    int dimstr=strlen(string);
    char** vc=calloc(2,sizeof(char*));
    vc[0]=calloc(dimstr,sizeof(char));
    vc[1]=calloc(dimstr,sizeof(char));
    if(!vc[0] || !vc[1]){
        printf("Allocazione Fallita\n");
        return NULL;
    }
    for(i=0; i<dimstr; i++){
        c=tolower(string[i]);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            vc[0][voc]=string[i];
            voc++;
        }
        else{
            vc[1][con]=string[i];
            con++;
        }
    }
    *vowels=voc;
    *consonants=con;
    return vc;
}