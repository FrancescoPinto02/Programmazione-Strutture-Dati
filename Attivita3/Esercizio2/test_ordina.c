# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "vettore.h"
int run_test_case(char *tc_id, int n);

# define M 20

int main(int argc, char *argv[]) 
{ 	
    FILE *test_suite, *result;  
    char tc_id[M];  // stringa contenente l'identificativo del test case
    int n, pass;
    
    if(argc < 3){
        printf("Nomi dei file mancanti \n");
        exit(1);
    }    
    
    test_suite = fopen(argv[1], "r");  // apro file contenente test suite               
    result = fopen(argv[2], "w");   // apro file contenente risultati test        
    
    if( test_suite==NULL || result == NULL ) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }
    /* Scansione del file di input nel ciclo while. 
    Ad ogni iterazione si leggono i due elementi di una riga:
    l'identificativo del test case tc_id e il numero n di elementi
    da ordinare */
    
    while(fscanf(test_suite, "%s%d", tc_id, &n) == 2){
        pass = run_test_case(tc_id, n);
    
        fprintf(result,"%s ", tc_id);
        if(pass == 1)
            fprintf(result, "PASS \n");
        else   
            fprintf(result, "FAIL \n");			
        }	
    
    fclose(test_suite);  // chiusura file di input
    fclose(result);         // chiusura file di output
}

int run_test_case(char *tc_id, int n){
    char input_fname[M], output_fname[M], oracle_fname[M];
    char* input="_input.txt";	
    char* output="_output.txt";
    char* oracle="_oracle.txt";

    strcpy(input_fname, tc_id);
    strcpy(output_fname, tc_id);
    strcpy(oracle_fname, tc_id);

    strcat(input_fname, input);
    strcat(output_fname, output);
    strcat(oracle_fname, oracle);
    

    int* arr_out=calloc(n, sizeof(int));
    if (!arr_out){
        printf("Allocazione fallita!\n");
        return 0;
    }
    // carica file di input
    finput_array(input_fname,arr_out,n);

    // ordina array
    ordina(arr_out,n);
    //  scrive file di output
    foutput_array(output_fname, arr_out, n);

    // allochiamo memoria per array oracolo
    int* arr_orac=calloc(n, sizeof(int));
    if (!arr_out){
        printf("Allocazione fallita!\n");
        return 0;
    }
    // carichiamo oracolo
    finput_array(oracle_fname,arr_orac,n);
    return confronta_array(arr_out, arr_orac, n); 
}