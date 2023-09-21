#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

void inputStack(stack s);
void outputStack(stack s);
stack reverseStack(stack s);
stack mergeStack(stack s1, stack s2);
void appendStack(stack dest, stack src);
int extractStack(stack s, int n);

int main(int argc, char argv[]){
    //CARICAMENTO STACK
    stack s=newStack();
    inputStack(s);
    printf("\nSTAMPA S\n");
    outputStack(s);

    //FUNZIONE INVERSIONE STACK
    stack rev=reverseStack(s);
    printf("\nSTAMPA REV\n");
    outputStack(rev);

    //FUNZIONE MERGE STACK
    stack merge=mergeStack(s, rev);
    printf("\nSTAMPA MERGE\n");
    outputStack(merge);

    //FUNZIONE MERGE STACK (VERSIONE APPEND)
    appendStack(s, rev);
    printf("\nSTAMPA S DOPO APPEND CON REV\n");
    outputStack(s);

    //FUNZIONE ESTRAZIONE
    int n=0;
    printf("Inserisci indice elemento da estrarre: ");
    scanf("%d", &n);
    if(extractStack(merge, n)==0){
        printf("Estrazione Fallita\n");
    }
    else{
        printf("Estrazione riuscita\n");
        printf("STAMPA MERGE DOPO ESTRAZIONE\n");
        outputStack(merge);
    }

    return 0;   
}

void inputStack(stack s){
    item val;
    int i=0, stop=0;
    printf("CARICAMENTO STACK\n");
    while(stop==0){
        printf("Elemento numero %d: ", i);
        val=inputItem();
        printf("\n");
        i++;
        if(get_data(val)==-1){
            stop=1;
        }
        else{
            push(s, val);
        }
    }
    printf("CARICAMENTO COMPLETATO\n");
}

void outputStack(stack s){
    int i=0;
    stack tmp=cloneStack(s);
    while(!emptyStack(tmp)){
        printf("|");
        outputItem(top(tmp));
        printf("|\n");
        pop(tmp);
    }
    freeStack(tmp);
}

stack reverseStack(stack s){
    stack tmp=newStack();
    stack rev=newStack();
    while(!emptyStack(s)){
        push(rev, top(s));
        push(tmp, top(s));
        pop(s);
    }
    while(!emptyStack(tmp)){
        push(s, top(tmp));
        pop(tmp);
    }
    freeStack(tmp);
    return rev;
}

stack mergeStack(stack s1, stack s2){
    stack merge=newStack();
    stack tmp=reverseStack(s2);
    while(!emptyStack(tmp)){
        push(merge, top(tmp));
        pop(tmp);
    }
    free(tmp);
    tmp=reverseStack(s1);
    while(!emptyStack(tmp)){
        push(merge, top(tmp));
        pop(tmp);
    }
    free(tmp);
    return merge;
}

void appendStack(stack dest, stack src){
    stack tmp1=reverseStack(dest);
    stack tmp2=reverseStack(src);
    clearStack(dest);

    while(!emptyStack(tmp2)){
        push(dest, top(tmp2));
        pop(tmp2);
    }
    while(!emptyStack(tmp1)){
        push(dest, top(tmp1));
        pop(tmp1);
    }

    freeStack(tmp1);
    freeStack(tmp2);
}

int extractStack(stack s, int n){
    int i=0, found=0;
    stack tmp=reverseStack(s);
    clearStack(s);
    
    while(!emptyStack(tmp)){
        if(i!=n){
            push(s ,top(tmp));
        }
        else{
            found=1;
        }
        pop(tmp);
        i++;
    }
    
    freeStack(tmp);
    
    if(!found){
        return 0;
    }
    else{
        return 1;
    }
}

