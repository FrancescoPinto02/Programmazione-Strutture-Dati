#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "item.h"

list string_to_list(char *str);

int main(void){
    char str[] = "Hello world!";
    list l=string_to_list(str);
    printf("%d", sizeList(l));
    outputList(l);
    return 0;
}

list string_to_list(char *str){
    int n=strlen(str);
    item val;

    list l=newList();

    for(int i=n-1; i>=0; i--){
        val=str[i];
        consList(l, val);
    }

    return l;
}


