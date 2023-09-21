#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list inputList (int n);
int dist_minore(list punti, float dist);
item *max_dist(list punti);
list sottolista(list l, int M, int N);
list ins_lista(list L, list K, int M);
list inputListFILE (char *fname);
list orderList(list l, char coord, char mode);
void zigzag(list l);

int main (int argc, char *argv[]){
    int n=0;
    list punti=newList();

    //CARICAMENTO LISTA
    printf("CARICAMENTO LISTA\n");
    if (argc==2){
        punti=inputListFILE(argv[1]);
    }
    else{
        printf("Quanti punti vuoi inserire? ");
        scanf("%d", &n);
        punti=inputList(n);
    }
    
    //STAMPA LISTA
    outputList(punti);


    //ZIG ZAG
    printf("\n\nORDINAMENTO ZIGZAG\n");
    zigzag(punti);
    outputList(punti);


    //FUNZIONE dist_minore
    float d=0;
    printf("\nInserisci distanza: ");
    scanf("%f", &d);
    printf("Numero di punti a distanza minore di %f: %d\n", d, dist_minore(punti, d));

    //FUNZIONE max_dist
    item *pmax=max_dist(punti);
    printf("\nCoppia di punti a distanza massima:\n");
    output_item(pmax[0]);
    output_item(pmax[1]);
    printf("\n\n");

    //FUNZIONE riordina
    char c, m;
    printf("Inserisci coordinata ordinamento: ");
    scanf("\n%c", &c);
    printf("Inserisci modalita ordinamento: ");
    scanf("\n%c", &m);
    list ord=newList();
    ord=orderList(punti, c, m);
    outputList(ord);

    //FUNZIONE sottolista
    int M, N;
    list punti_copia=copiaLista(punti);
    list subL=newList();
    printf("Inserisci posizione M: ");
    scanf("%d", &M);
    printf("Inserisci posizione N: ");
    scanf("%d", &N);
    subL=sottolista(punti_copia,M,N);
    printf("Sottolista:\n");
    outputList(subL);
    printf("\nLista originale:\n");
    outputList(punti_copia);

    //FUNZIONE ins_list
    list K=newList();
    list nuova=newList();
    printf("Quanti punti vuoi inserire nella lista K? ");
    scanf("%d", &n);
    K=inputList(n);
    printf("Da che posizione vuoi inserire K? ");
    scanf("%d", &M);
    nuova=ins_lista(punti, K, M);
    printf("\nLista L:\n");
    outputList(punti);
    printf("\nLista K:\n");
    outputList(K);
    printf("\nLista NL:\n");
    outputList(nuova);

	return 0;
}

list inputList (int n){
    item val;
    list l=newList();
    for(int i=0; i<n; i++){
        printf("Punto %d:\n",i);
        val=input_item();
        l=consList(val, l);
        printf("\n");
    }
    return reverseList(l);
}

int dist_minore(list punti, float dist){
    int count=0;
    int n=sizeList(punti);
    list l;
    for(int i=0; i<n-1; i++){
        l=punti;
        for(int j=i+1; j<n; j++){
            l=tailList(l);
            if(distanza(getFirst(punti), getFirst(l))<dist){
                count++;
            }
        }
        punti=tailList(punti);
    }
    return count;
}

item *max_dist(list punti){
    item *max=calloc(2,sizeof(item));
    if(!max){
        printf("Errore di allocazione!\n");
        return NULL;
    }
    float maxd=0;
    int n=sizeList(punti);
    list l;
    for(int i=0; i<n-1; i++){
        l=punti;
        for(int j=i+1; j<n; j++){
            l=tailList(l);
            if(distanza(getFirst(punti), getFirst(l))>maxd){
                maxd=distanza(getFirst(punti), getFirst(l));
                max[0]=getFirst(punti);
                max[1]=getFirst(l);
            }
        }
        punti=tailList(punti);
    }
    return max;
}

/*list sottolista(list *l, int M, int N){
    list subl=newList();
    list newl=newList();
    int n=sizeList(*l);
    int i;
    for(i=0; i<n; i++){
        if(i>=M && i<=N){
            subl=consList(getItem(*l,i), subl);
        }
        else{
            newl=consList(getItem(*l,i), newl);
        }
    }
    *l=reverseList(newl);
    subl=reverseList(subl);
    return subl;
}*/

list sottolista(list l, int M, int N){
    list subl=newList();
    int n=sizeList(l);

    if(N<M || N>=n){
        printf("Indici errati\n");
        return NULL;
    }

    int i=0;
    while(i<n){
        if(i>=M && i<=N){
            subl=consList(getItem(l,i),subl);
            l=removeList(l,i);
            n--;
            N--;
        }
        else{
            i++;
        }
    }
    return reverseList(subl);
}

list ins_lista(list L, list K, int M){
    if(M>=sizeList(L)){
        printf("posizione M non valida\n");
        return L;
    }

    int nk=sizeList(K);
    for(int i=0; i<nk; i++){
        L=insertList(L, getItem(K,i), M+1);
        M++;
    }

    return L;
}

list inputListFILE (char *fname){
    list l=newList();
    float x, y;
    FILE *fp=fopen(fname, "r");
    if(!fp){
        printf("Errore apertura file\n");
        return NULL;
    }
    while(fscanf(fp,"%f%f",&x ,&y)==2){
        l=consList(creaItem(x,y),l);
    }
    fclose(fp);
    return reverseList(l);
}

list orderList(list l, char coord, char mode){
    item swap;
    int n=sizeList(l);
    list prec, suc;
    prec=l;
    if(coord=='a'){
        for(int i=0; i<n-1; i++){
            suc=tailList(prec);
            for(int j=i+1; j<n; j++){
                if(get_x(getFirst(suc))<get_x(getFirst(prec))){
                    updateList(suc,prec);
                }
                suc=tailList(suc);
            }
            prec=tailList(prec);
        }
    }
    else if(coord=='o'){
        for(int i=0; i<n-1; i++){
            suc=tailList(prec);
            for(int j=i+1; j<n; j++){
                if(get_y(getFirst(suc))<get_y(getFirst(prec))){
                    updateList(suc,prec);
                }
                suc=tailList(suc);
            }
            prec=tailList(prec);
        }
    }

    if(mode=='d'){
        l=reverseList(l);
    }

    return l;
}

void zigzag(list l){
    int n=sizeList(l);
    l=orderList(l, 'o', 'a');
    list tmp;
    for(int i=0; i<n; i+=2){
        tmp=tailList(l);
        updateList(l,tmp);
        l=tailList(tmp);
    }
}