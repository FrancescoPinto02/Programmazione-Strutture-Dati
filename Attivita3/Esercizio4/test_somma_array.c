// file run_test_ins_array.c

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "vettore.h"

# define M 20

int run_test_case(char *tc_id, int n)
{  
    char input1_fname[M], input2_fname[M], output_fname[M], oracle_fname[M];
    char* input1="_input1.txt";	
    char* input2="_input2.txt";	
    char* output="_output.txt";
    char* oracle="_oracle.txt";

    // costruiamo i nomi dei file
    strcpy(input1_fname, tc_id);
    strcpy(input2_fname, tc_id);
    strcpy(output_fname, tc_id);
    strcpy(oracle_fname, tc_id);

    strcat(input1_fname, input1);
    strcat(input2_fname, input2);
    strcat(output_fname, output);
    strcat(oracle_fname, oracle);

    int * in_arr1=calloc(n,sizeof(int));
    int * in_arr2=calloc(n,sizeof(int));
    int * out_arr=calloc(n,sizeof(int));
    if(!in_arr1 || !in_arr2 || !out_arr){
        printf("Allocazione fallita!\n");
        return 0;
    }
    
    finput_array(input1_fname,in_arr1,n);
    finput_array(input2_fname,in_arr2,n);

    somma_array(in_arr1, in_arr2, out_arr, n);

    foutput_array(output_fname, out_arr, n);

    int * orac_arr=calloc(n,sizeof(int));
    if(!orac_arr){
        printf("Allocazione fallita!\n");
        return 0;
    }
    finput_array(oracle_fname, orac_arr, n);

    return confronta_array(out_arr, orac_arr, n);
}	



int main(int argc, char *argv[]) 
{ 	
    FILE *test_suite, *result;  
    char tc_id[M];// stringa contenente l'identificativo del test case
    int n,pass;
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
    
    while(fscanf(test_suite, "%s%d", tc_id, &n) == 2){
        pass = run_test_case(tc_id, n);
    
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

