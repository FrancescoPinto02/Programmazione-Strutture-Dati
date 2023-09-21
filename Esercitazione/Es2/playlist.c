#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "playlist.h"

struct c_playlist{
    char nome[20];
    list canzoni;
};

/* 
PROGETTAZIONE newPlaylist

Ricevi una stringa (nome) come parametro

Dichiara una nuova playlist (new)
alloca new
Se l`allocazione è fallita restituisci NULL

copia nome nel campo new->nome
crea una nuova lista e assegnala al campo new->canzoni (funzione newList)
restituisci new
*/

playlist newPlaylist(char *nome){
    playlist new;
    new = malloc(sizeof(*new));
    if(!new){
        printf("Allocazione fallita\n");
        return NULL;
    }

    strcpy(new->nome, nome);
    new->canzoni=newList();
    return new;
}


/* 
PROGETTAZIONE addSong

Ricevi una playlist (pl) ed un item (song) come parametri

Se pl non esiste {
    restituisci 0
}

dichiara una variabile int (pos)
assegna la lunghezza della lista pl->canzoni a pos
Inserisci song nella posizione pos di pl->canzoni e restituisci lo stato dell`inserimento (1=riuscito 0=fallito)
*/

int addSong(playlist pl, item song){
    if(!pl){
        return 0;
    }

    int pos=0;
    pos=sizeList(pl->canzoni);
    return insertList(pl->canzoni, pos, song);
}


/*PROGETTAZIONE playlistSize

Ricevi una playlist (pl) come parametro

Se pl non esiste {
    restituisci 0
}

restituisci la lunghezza della lista pl->canzoni
*/

int playlistSize(playlist pl){
    if(!pl){
        return 0;
    }
    return sizeList(pl->canzoni);
}


/*PROGETTAZIONE removeSong

Ricevi una playlist (pl) e un int (pos) come parametri

Se (pl non esiste) OR (pos < 0) OR (pos >= sizeList(pl->canzoni)){
    restituisci 0
}

rimuovi dalla lista pl->canzoni l`elemento in posizione pos e restituisci esito della rimozione
*/

int removeSong(playlist pl, int pos){
    if(!pl || pos<0 || pos>=sizeList(pl->canzoni)){
        return 0;
    }
    
    return removeList(pl->canzoni, pos);
}


/*PROGETTAZIONE forwardSong

Ricevi una playlist (pl) e un int (pos) come parametri

Se (pl non esiste) OR (pos < 0) OR (pos >= sizeList(pl->canzoni)-1){
    restituisci 0
}

dichiara una variabile item di appoggio (tmp)
assegna a tmp l`item in posizione pos della lista pl->canzoni
rimuovi l`item in posizione pos dalla lista pl->canzoni
inserisci tmp nella lista pl->canzoni in poszione pos+1 e restituisci l`esito dell`operazione
*/

int forwardSong(playlist pl, int pos){
    if(!pl || pos<0 || pos>=sizeList(pl->canzoni)-1){
        return 0;
    }
    
    item tmp;
    tmp=getItem(pl->canzoni, pos);
    removeList(pl->canzoni, pos);
    return insertList(pl->canzoni, pos+1, tmp);
}

/*PROGETTAZIONE backwardSong

Ricevi una playlist (pl) e un int (pos) come parametri

Se (pl non esiste) OR (pos < 1) OR (pos >= sizeList(pl->canzoni)){
    restituisci 0
}

dichiara una variabile item di appoggio (tmp)
assegna a tmp l`item in posizione pos della lista pl->canzoni
rimuovi l`item in posizione pos dalla lista pl->canzoni
inserisci tmp nella lista pl->canzoni in poszione pos-1 e restituisci l`esito dell`operazione
*/

int forwardSong(playlist pl, int pos){
    if(!pl || pos<1 || pos>=sizeList(pl->canzoni)){
        return 0;
    }
    
    item tmp;
    tmp=getItem(pl->canzoni, pos);
    removeList(pl->canzoni, pos);
    return insertList(pl->canzoni, pos-1, tmp);
}


/*PROGETTAZIONE subPlaylist

Ricevi una playlist (pl) e due stringhe (cant, nomesub) come parametri

se pl non esiste restituisci NULL

crea una nuova playlista chiamata "nomesub" (sub)
crea una variabile item di appoggio (song)
Crea e inizializza a 0 un int (i)
finche i < sizeList(pl->canzoni){
    assegna a song l`item in posizione i della lista pl->canzoni
    se song->cantante == cant{
        clona song
        aggiungi il clone alla playlist sub
    }
}

restituisci sub
*/

playlist subPlaylist(playlist pl, char *cant, char *nomesub){
    if(!pl){
        return NULL;
    }

    playlist sub = newPlaylist(nomesub);
    item song;
    int n=sizeList(pl->canzoni);
    for(int i=0; i<n; i++){
        song = getItem(pl->canzoni, i);
        if(strcmp(get_cantante(song), cant)==0){
            song = cloneItem(song);
            addSong(sub, song);
        }
    }
    return sub;
}


/*PROGETTAZIONE outputPlaylist

Ricevi una playlist (pl) come parametro

se pl non esiste{
    restituisci 0
}

stampa la lista pl->canzoni e restituisci esito

*/

int outputPlaylist(playlist pl){
    if(!pl){
        return 0;
    }

    return outputList(pl->canzoni);
}
