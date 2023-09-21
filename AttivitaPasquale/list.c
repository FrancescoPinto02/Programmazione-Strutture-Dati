#include <stdio.h>
#include <stdlib.h>
#include "item.h" 
#include "list.h"


struct node {
    item value;
    struct node *next;
};

list newList(void){
    return NULL;
}

int emptyList(list l){
    if (l==NULL){
        return 1;
    }
    else{
        return 0;
    }
}


list consList(item val, list l){
    struct node *new = malloc(sizeof(struct node));
    if(new!=NULL){
        new->value=val;
        new->next=l;
        l=new;
    }
    return l;
}

list tailList(list l){
    list temp;
    if(l!=NULL){
        temp=l->next;
    }
    else{
        temp=NULL;
    }
    return temp;
}

item getFirst (list l)
{
    if(l!=NULL){
        return l->value;
    }
    else{
        return NULLITEM;
    }
}

int sizeList (list l)
{
    int count=0;
    while(!emptyList(l)){
        count++;
        l=tailList(l);
    }
    return count;
}

int posItem (list l, item val){
    int p=0, found=0;
    while(!emptyList(l) && !found){
        if(eq(getFirst(l), val)){
            found=1;
        }
        else{
            p++;
            l=tailList(l);
        }
    }
    if (!found){
        p=-1;
    }
    return p;
}

item getItem (list l, int pos)
{
    int i=0;
    if(pos>=0 && sizeList(l)>pos){
        while(i!=pos){
            l=tailList(l);
            i++;
        }
        return getFirst(l);
    }
    else{
        return NULLITEM;
    }
}

list reverseList (list l)
{   
    list rev;
    rev=newList();
    while(!emptyList(l)){
        rev=consList(getFirst(l),rev);
        l=tailList(l);
    }
    return rev;
}

list removeList(list l, int pos){
    list prec, tmp;
    int i;

    if(pos==0 && !emptyList(l)){
        tmp=l;
        l=tailList(l);
        free(tmp);
    }
    else{
        i=0;
        prec=l;
        while(i<pos-1 && !emptyList(prec)){
            prec=tailList(prec);
            i++;
        }

        if(!emptyList(prec) && prec->next!=NULL){
            tmp=prec->next;
            prec->next=tmp->next;
            free(tmp);
        }
    }

    return l;
}

void updateList(list l1, list l2){
    item tmp=l1->value;
    l1->value=l2->value;
    l2->value=tmp;
}