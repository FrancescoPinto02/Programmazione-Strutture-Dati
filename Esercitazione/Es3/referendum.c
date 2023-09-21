#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "referendum.h"

struct c_ref{
    char *comune;
    int n;
    list seggi;
};


/*
PROGETTAZIONE: creaRef

Ricevi comune (stringa), n (int) come parametri

crea e alloca una nuovo ref (new)

Se l`allocazione fallisce{
    restituisci NULL
}

copia stringa comune nel campo new->comune
assegna n al campo new->n
assegna una nuova lista a new->seggi

restituisci new
*/


ref creaRef(char *comune, int n){
    ref new;
    new = malloc (sizeof(*new));
    if(!new){
        return NULL;
    }

    strcpy(new->comune, comune);
    new->n = n;
    new->seggi=newList();
    return new;
}




/*
PROGETTAZIONE: inserSeggio

Ricevi R (ref), scheda (item) come parametri

Se R non esiste  OR  R->seggi non esiste{
    restituisci 0 //inserimento impossibile
}

Se scheda è gia presente in R->seggi  OR  item->ID < 1  OR  item->ID > n{
    restituisci 0 //inserimento fallito
}

Inserisci scheda nella lista R->seggi e restituisci l`esito dell`operazione
*/

int inserSeggio(ref R, item scheda){
    if(!R || !R->seggi){
        return -1;
    }

    if(posItem(R->seggi, scheda)!=-1  ||  get_ID(scheda) < 1  ||  get_ID(scheda) > R->n){
        return 0;
    }

    return consList(R->seggi, scheda);
}


/*
PROGETTAZIONE: completRef

Ricevi R (ref) come parametro

Se R non esiste  OR  R->seggi (list) non esiste{
    restituisci 0
}

Se sizeList(R->seggi) == R->n{
    restituisci 1
}

altrimenti restituisci 0

*/



int completRef(ref R){
    if(!R || !R->seggi){
        return 0;
    }

    if(sizeList(R->seggi) == R->n){
        return 1;
    }
    else{
        return 0;
    }
}


/*
PROGETTAZIONE: nosiRef

Ricevi R (ref) come parametro

Se R non esiste  OR  R->seggi (list) non esiste{
    termina funzione
}

dichiara e inizializza a 0 due totalizzatori (int y, n)
dichiara un contatore int e inizializzalo a 0 (i)
dichiara una variabile item di appoggio (val)
Se R è completo{
    mentre i != R->n{
        val = getItem(R->seggi, i)
        y += get_si(val)
        n += get_n(val)
        incrementa i
    }

    Se y > n{
        stampa vince si
    }
    Se n > y{
        stampa vince no
    }
    altrimenti{
        stampa pareggio
    }
}


*/



int nosiRef(ref R){
    if(!R || !R->seggi){
        return;
    }

    int y=0, n=0;
    item val;
    if(completRef(R)){
        for(int i=0; i < R->n; i++){
            val = getItem(R->seggi, i);
            y += get_si(val);
            n += get_no(val);
        }

        if(y>n){
            printf("Vince SI");
        }
        if(n>y){
            printf("Vince NO");
        }
        else{
            printf("Pareggio");
        }
    }
}