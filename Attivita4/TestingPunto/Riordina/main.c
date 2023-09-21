#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "punto.h"
#define M 20

void riordina(punto *p, int n, char coordinata, char criterio);
int run_test(char *tc_id, int n, char coordinata, char criterio);

int main(int argc, char *argv[]){
    FILE *test_suite, *result;
    char tc_id[M];
    int n=0, pass=0;
    char coord, crit;

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

    while (fscanf(test_suite,"%s%d %c %c",tc_id,&n,&coord,&crit)==4){
        pass=run_test(tc_id, n, coord, crit);
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

void riordina(punto *p, int n, char coordinata, char criterio){
    int i,j;
    punto swap;
    switch (coordinata)
    {
    case 'a':
        switch (criterio)
        {
        case 'a':
            for (i=0; i<n-1; i++){
                for(j=i+1; j<n; j++){
                    if(ascissa(p[j])<ascissa(p[i])){
                        swap=p[j];
                        p[j]=p[i];
                        p[i]=swap;
                    }
                }
            }
            break;
        case 'd':
            for (i=0; i<n-1; i++){
                for(j=i+1; j<n; j++){
                    if(ascissa(p[j])>ascissa(p[i])){
                        swap=p[j];
                        p[j]=p[i];
                        p[i]=swap;
                    }
                }
            }
            break; 
        default:
            printf("Parametri Errati!\n");
            return;
            break;
        }
        break;
    
    case 'o':
        switch (criterio)
        {
        case 'a':
            for (i=0; i<n-1; i++){
                for(j=i+1; j<n; j++){
                    if(ordinata(p[j])<ordinata(p[i])){
                        swap=p[j];
                        p[j]=p[i];
                        p[i]=swap;
                    }
                }
            }
            break;
        case 'd':
            for (i=0; i<n-1; i++){
                for(j=i+1; j<n; j++){
                    if(ordinata(p[j])>ordinata(p[i])){
                        swap=p[j];
                        p[j]=p[i];
                        p[i]=swap;
                    }
                }
            }
            break;
        default:
            printf("Parametri Errati!\n");
            return;
            break;
        }
        break;

    default:
        printf("Parametri Errati!\n");
        return;
        break;
    }
}

int run_test(char *tc_id, int n, char coordinata, char criterio){
    FILE *fp;
    char input_fname[M], output_fname[M], oracle_fname[M];
    char* input="_input.txt";	
    char* output="_output.txt";
    char* oracle="_oracle.txt";
    int i, j;

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

    riordina(arr_input, n, coordinata, criterio);

    foutput_array(output_fname, arr_input, n);

    punto *arr_oracle=calloc(n, sizeof(punto));
    if(!arr_oracle){
        printf("Errore allocazione!\n");
        return 0;
    }

    finput_array(oracle_fname, arr_oracle, n);

    return (confronta_array(arr_input, arr_oracle, n));
}