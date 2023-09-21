// file run_test_ins_array.c

# include <stdio.h>
# include <stdlib.h>
#include <string.h>
# include "vettore.h"

# define M 20
# define EXTRA 1    // spazio extra per consentire inserimento

int run_test_case(char *tc_id, int n, int elem, int pos)
{
    char input_fname[M], output_fname[M], oracle_fname[M];
    char* input="_input.txt";	
    char* output="_output.txt";
    char* oracle="_oracle.txt";

    // costruiamo i nomi dei file
    strcpy(input_fname, tc_id);
    strcpy(output_fname, tc_id);
    strcpy(oracle_fname, tc_id);

    strcat(input_fname, input);
    strcat(output_fname, output);
    strcat(oracle_fname, oracle);
    
    // allochiamo memoria per array di input
    // carica file di input
    int* arr_out=calloc(n+EXTRA, sizeof(int));
    if (!arr_out){
        printf("Allocazione fallita!\n");
        return 0;
    }
    finput_array(input_fname,arr_out,n);
    // inserimento in array
    // NB: n è stato incrementato nella funzione inserisci
    inserisci(arr_out, &n, elem, pos);
    // scrive file di outptut
    foutput_array(output_fname, arr_out, n);
    
    // allochiamo memoria per array oracolo
    int* arr_orac=calloc(n+EXTRA, sizeof(int));
    if (!arr_out){
        printf("Allocazione fallita!\n");
        return 0;
    }
    // carichiamo oracolo
    finput_array(oracle_fname,arr_orac,n);
    // confrontiamo array
    return confronta_array(arr_out, arr_orac, n);
}	



int main(int argc, char *argv[]) 
{ 	
    FILE *test_suite, *result;  
    char tc_id[M];// stringa contenente l'identificativo del test case
    int n,elem, pos, pass;
    if(argc < 3){
        printf("Nomi dei file mancanti \n");
        exit(1);
    }  
    test_suite = fopen(argv[1], "r");// apro file contenente test suite               
    result = fopen(argv[2], "w");// apro file contenente risultati test        
    if( test_suite==NULL || result == NULL ) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }
    
    
    /* Scansione del file di input nel ciclo while. 
    Ad ogni iterazione si leggono i quattro elementi di una riga:
    l’identificativo del test case tc_id, il numero n di elementi
    da ordinare, l’elemento elem da inserire e la posizione pos  */
    
    while(fscanf(test_suite, "%s%d%d%d", tc_id, &n, &elem, &pos) == 4){
        pass = run_test_case(tc_id, n, elem, pos);
    
        fprintf(result,"%s ", tc_id);
        if(pass == 1)
            fprintf(result, "PASS \n");
        else   
            fprintf(result, "FAIL \n");			
        }	
    
    
    
    fclose(test_suite);  // chiusura file di input
    fclose(result); // chiusura file di output
    return 0;
}