#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

void inputQueue(queue q);
void moveAll(queue dest, queue source);
void printQueue(queue q);
int quadrante(item it);
queue * subQueue(queue q);
float spezzata(queue q);
queue concatQueue(queue q1, queue q2);

int main(int argc, char argv[]){
    int i;
    queue coda = newQueue();
    inputQueue(coda);
    printQueue(coda);

    //FUNZIONE QUADRANTI
    printf("\n\nDIVISIONE QUADRANTI:\n");
    queue *quad = subQueue(coda);
    for(i=0; i<4; i++){
        printf("QUADRANTE %d:\n", i+1);
        printQueue(quad[i]);
        printf("\n\n");
    }

    //FUNZIONE SPEZZATA
    printf("\n\nSPEZZATE:\n");
    for(i=0; i<4; i++){
        float spz=spezzata(quad[i]);
        printf("spezzata quadrante %d: %f\n", i, spz);
    }

    //FUNZIONE CONCATENZIONE
    printf("\n\nCONCATENAZIONE:\n");
    queue coda_conc = newQueue();
    for(i=3; i>=0; i--){
        coda_conc = concatQueue(coda_conc, quad[i]);
    }
    printQueue(coda_conc);

    return 0;
}

void inputQueue(queue q){
    int i=1, flag=1;
    item val;

    while(flag==1){
        printf("Inserire punto %d:\n",i);
        val=inputItem();
        enQueue(q, val);
        printf("\n\n");
        i++;
        do{
            printf("1:CONTINUA  0:STOP\n");
            scanf("%d", &flag);
        }while(flag!=1 && flag!=0);
    }
}

void printQueue(queue q){
    queue tmp=newQueue();
    item val;
    int i=1;
    while(!emptyQueue(q)){
        printf("Elemento %d: ", i);
        val=deQueue(q);
        outputItem(val);
        printf("\n");
        enQueue(tmp, val);
        i++;
    }

    moveAll(q, tmp);
    free(tmp);
}

void moveAll(queue dest, queue source){
    int status=0;

    if (!dest || !source){
        printf("Errore!");
        return;
    }

    while(!emptyQueue(source)){
        status=enQueue(dest, deQueue(source));
    }
}

int quadrante(item it){
    float x = getX(it);
    float y = getY(it);

    if((x>=0) && (y>=0)){
        return 1;
    }

    if((x<0) && (y>=0)){
        return 2;
    }

    if((x<0) && (y<0)){
        return 3;
    }

    if((x>=0) && (y<0)){
        return 4;
    }
}

queue * subQueue(queue q){
    queue *sub = calloc(4, sizeof(queue));
    if(!sub){
        printf("Allocazione fallita\n");
        return NULL;
    }
    
    for(int i=0; i<4; i++){
        sub[i]=newQueue();
    }

    int quad=0;
    item val;
    while(!emptyQueue(q)){
        val = deQueue(q);
        switch (quadrante(val))
        {
        case 1:
            enQueue(sub[0], val);
            break;

        case 2:
            enQueue(sub[1], val);
            break;

        case 3:
            enQueue(sub[2], val);
            break;

        case 4:
            enQueue(sub[3], val);
            break;
        
        default:
            printf("Errore!\n");
            break;
        }
    }
    return sub;
}

float spezzata(queue q){
    queue tmp = newQueue();
    float dist=0;
    item p1, p2;

    if(!emptyQueue(q)){
        p1=deQueue(q);
        enQueue(tmp, p1);
    }
    
    
    while(!emptyQueue(q)){
        p2=deQueue(q);
        enQueue(tmp, p2);
        dist = dist + distance(p1, p2);
        p1 = p2;
    }

    moveAll(q, tmp);
    free(tmp);
    return dist; 
}

queue concatQueue(queue q1, queue q2){
    queue cq = newQueue();
    moveAll(cq, q1);
    moveAll(cq, q2);
    return cq;
}