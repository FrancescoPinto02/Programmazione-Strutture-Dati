#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordina(int * array, int dim);

int main(int argc, char* argv[]){
    int* numeri=(int *)calloc(argc-1, sizeof(int));
    int i;
    for (i=1; i<argc; i++){
        numeri[i-1]=atoi(argv[i]);
    }
    ordina(numeri, argc-1);
    for (i=0; i<argc-1; i++){
        printf("n[%d]:%d\n",i,numeri[i]);
    }
    return 0;
}

void ordina(int * array, int dim){
    int swap, i, j;
    for (i=0; i<dim-1; i++){
        for (j=i+1; j<dim; j++){
            if (array[j]<array[i]){
                swap=array[i];
                array[i]=array[j];
                array[j]=swap;
            }
        }
    }
}
