#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    char* newstr;
    int len;
    if (argc!=3){
        printf("Errore! Numero di parametri errato\n");
        exit(1);
    }
    len=strlen(argv[1])+strlen(argv[2]);
    newstr=(char *)calloc(len+1, sizeof(char));
    strcpy(newstr, argv[1]);
    strcat(newstr, argv[2]);
    printf("Nuova stringa: %s\n", newstr);
    return 0;
}