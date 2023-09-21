#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "punto.h"

#define M 20

int run_test(char *tc_id, int n, float dist);

int main(int argc, char *argv[]){
    FILE *test_suite, *result;
    char tc_id[M];
    int n=0,pass=0;
    float dist=0;

    if (argc!=3){
        printf("Numero argomenti non valido!\n");
        exit(1);
    }
    
    test_suite=fopen(argv[1],"r");
    result=fopen(argv[2],"w");

    if(!test_suite || !result){
        printf("Apertura file fallita!\n");
        exit(1);
    }

    while (fscanf(test_suite,"%s%d%f",tc_id,&n,&dist)==3){
        pass=run_test(tc_id, n, dist);
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

int run_test(char *tc_id, int n, float dist){
    FILE *fp;
    char input_fname[M], output_fname[M], oracle_fname[M];
    char* input="_input.txt";	
    char* output="_output.txt";
    char* oracle="_oracle.txt";
    int i, j, out_cont=0, orac_cont=0;

    strcpy(input_fname, tc_id);
    strcpy(output_fname, tc_id);
    strcpy(oracle_fname, tc_id);

    strcat(input_fname, input);
    strcat(output_fname, output);
    strcat(oracle_fname, oracle);

    punto *arr_input=calloc(n, sizeof(punto));
    if(!arr_input){
        printf("Errore allocazione!\n");
        return 0;
    }

    finput_array(input_fname, arr_input, n);

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(distanza(arr_input[i],arr_input[j])<dist){
                out_cont++;
            }
        }
    }


    fp=fopen(output_fname,"w");
    if(!fp){
        printf("Errore apertura file!\n");
        exit (1);
    }
    fprintf(fp,"%d",out_cont);
    fclose(fp);
    
    fp=fopen(oracle_fname,"r");
    if(!fp){
        printf("Errore apertura file!\n");
        exit (1);
    }
    fscanf(fp,"%d", &orac_cont);
    fclose(fp);
    
    if(orac_cont==out_cont){
        free(arr_input);
        return 1;
    }
    else{
        free(arr_input);
        return 0;
    }
}