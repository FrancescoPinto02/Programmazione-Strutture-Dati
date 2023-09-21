#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "punto.h"

#define M 20

int run_test(char *tc_id, int n);

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

    while (fscanf(test_suite,"%s%d",tc_id,&n)==2){
        pass=run_test(tc_id, n);
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

int run_test(char *tc_id, int n){
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

    if(n<2){
        fp=fopen(output_fname,"w");
        fclose(fp);
        return 1;
    }

    punto *arr_input=calloc(n, sizeof(punto));
    if(!arr_input){
        printf("Errore allocazione!\n");
        return 0;
    }

    finput_array(input_fname, arr_input, n);

    punto out_p1, out_p2;
    float out_dmax=-1;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(distanza(arr_input[i],arr_input[j])>out_dmax){
                out_p1=arr_input[i];
                out_p2=arr_input[j];
                out_dmax=distanza(arr_input[i],arr_input[j]);
            }
        }
    }


    fp=fopen(output_fname,"w");
    if(!fp){
        printf("Errore apertura file!\n");
        exit (1);
    }
    fprintf(fp,"%f %f\n",ascissa(out_p1),ordinata(out_p1));
    fprintf(fp,"%f %f\n",ascissa(out_p2),ordinata(out_p2));
    fprintf(fp,"%f\n",out_dmax);
    fclose(fp);
    
    punto orac_p1, orac_p2;
    float x, y, orac_dmax;
    fp=fopen(oracle_fname,"r");
    if(!fp){
        printf("Errore apertura file!\n");
        exit (1);
    }
    fscanf(fp,"%f%f", &x, &y);
    orac_p1=creaPunto(x, y);
    fscanf(fp,"%f%f", &x, &y);
    orac_p2=creaPunto(x, y);
    fscanf(fp,"%f", &orac_dmax);
    fclose(fp);
    
    //PRINTF PER CONTROLLI
    /*printf("Ascissa P1 %f=%f\n",ascissa(out_p1),ascissa(orac_p1));
    printf("Ordinata P1 %f=%f\n",ordinata(out_p1),ordinata(orac_p1));
    printf("Ascissa P2 %f=%f\n",ascissa(out_p2),ascissa(orac_p2));
    printf("Ordinata P2 %f=%f\n",ordinata(out_p2),ordinata(orac_p2));
    printf("Dmax %f=%f\n",out_dmax,orac_dmax);*/

    if(ascissa(out_p1)==ascissa(orac_p1) && ordinata(out_p1)==ordinata(orac_p1) && ascissa(out_p2)==ascissa(orac_p2) && ordinata(out_p2)==ordinata(orac_p2) && out_dmax==orac_dmax){
        free(arr_input);
        return 1;
    }
    else{
        free(arr_input);
        return 0;
    }
}