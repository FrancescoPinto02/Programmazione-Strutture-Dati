typedef struct c_playlist *playlist;

/* 
    SPECIFICA SINTATTICA
    -Tipo di riferimento: playlist
    -Tipi utilizzati: string, list, item, int, void

    SPECIFICA SEMANTICA ITEM
    -item è composto da:
        titolo = stringa
        cantante = stringa
        durata = intero

    SPECIFICA SEMANTICA PLAYLIST
    -playlist è composto da:
        nome = stringa
        canzoni = lista di item
*/


/* 
newPlaylist(string) ---> playlist

ANALISI E SPECIFICA
    
DATI IN INPUT: nome (stringa)
PRECONDIZIONI: nome non deve essere nullo

DATI IN OUTPUT: new (playlist)
POSTCONDIZIONI: new = (nome, l) l = nil
*/

playlist newPlaylist(char *nome);


/* 
addSong(playlist, item) ---> playlist

ANALISI E SPECIFICA
    
DATI IN INPUT: pl (playlist), song (item)
PRECONDIZIONI: pl deve esistere, song deve esistere e non deve essere un NULLITEM

DATI IN OUTPUT: pl' (playlist pl modificata)
POSTCONDIZIONI: pl=(nome, l)  pl'=(nome, l')    l=(c1, c2, ..., cn)  l'=(c1, c2, ..., cn, song)

NB: l`output in realtà può essere considerato un side-effect perchè viene modificata direttamente la playlist presa in input,
    perciò la funzione può essere void oppure potrebbe restituire l`esito dell`operazione (1=riuscita 0=fallita)
*/

int addSong(playlist pl, item song);

/* 
playlistSize(playlist) ---> int

ANALISI E SPECIFICA
    
DATI IN INPUT: pl (playlist)
PRECONDIZIONI: pl deve esistere

DATI IN OUTPUT: dim (int)
POSTCONDIZIONI: pl=(nome, l) AND dim=sizeList(l)
*/

int playlistSize(playlist pl);


/* 
removeSong(playlist, int) ---> playlist

ANALISI E SPECIFICA
    
DATI IN INPUT: pl (playlist), pos (int)
PRECONDIZIONI: pl deve esistere, pos>=0, pos < sizeList(pl->canzoni)

DATI IN OUTPUT: pl' (playlist pl modificata)
POSTCONDIZIONI: pl=(nome, l) AND pl'=(nome, l')    
                AND l=(c1, c2, ..., cpos-1, cpos, cpos+1, ..., cn) AND l'=(c1, c2, ..., cpos-1, cpos+1, ..., cn)

NB: l`output in realtà può essere considerato un side-effect perchè viene modificata direttamente la playlist presa in input,
    perciò la funzione può essere void oppure potrebbe restituire l`esito dell`operazione (1=riuscita 0=fallita)
*/

int removeSong(playlist pl, int pos);


/* 
forwardSong(playlist, int) ---> playlist

ANALISI E SPECIFICA
    
DATI IN INPUT: pl (playlist), pos (int)
PRECONDIZIONI: pl deve esistere, pos>=0, pos < sizeList(pl->canzoni)-1

DATI IN OUTPUT: pl' (playlist pl modificata)
POSTCONDIZIONI: pl=(nome, l) AND pl'=(nome, l')    
                AND l=(c1, c2, ..., cpos, cpos+1, ..., cn) AND l'=(c1, c2, ..., cpos+1, cpos, ..., cn)

NB: l`output in realtà può essere considerato un side-effect perchè viene modificata direttamente la playlist presa in input,
    perciò la funzione può essere void oppure potrebbe restituire l`esito dell`operazione (1=riuscita 0=fallita)
*/

int forwardSong(playlist pl, int pos);


/* 
backwardSong(playlist, int) ---> playlist

ANALISI E SPECIFICA
    
DATI IN INPUT: pl (playlist), pos (int)
PRECONDIZIONI: pl deve esistere, pos>=1, pos < sizeList(pl->canzoni)

DATI IN OUTPUT: pl' (playlist pl modificata)
POSTCONDIZIONI: pl=(nome, l) AND pl'=(nome, l')    
                AND l=(c1, c2, ..., cpos-1, cpos, ..., cn) AND l'=(c1, c2, ..., cpos, cpos-1, ..., cn)

NB: l`output in realtà può essere considerato un side-effect perchè viene modificata direttamente la playlist presa in input,
    perciò la funzione può essere void oppure potrebbe restituire l`esito dell`operazione (1=riuscita 0=fallita)
*/

int backwardSong(playlist pl, int pos);


/* 
subPlaylist(playlist, string, string) ---> playlist

ANALISI E SPECIFICA
    
DATI IN INPUT: pl (playlist), cant (string), nomesub (string)
PRECONDIZIONI: pl deve esistere

DATI IN OUTPUT: sub (playlist)
POSTCONDIZIONI: sub=(nomesub, l)  AND l=(c1, c2, ..., cn) AND ck->cantante == cant  
                (ck sono tutte le canzoni in l)
*/

playlist subPlaylist(playlist pl, char *cant, char *nomesub);


/* 
outputPlaylist(playlist) ---> void

ANALISI E SPECIFICA
    
DATI IN INPUT: pl (playlist)
PRECONDIZIONI: pl deve esistere

DATI IN OUTPUT: Nessuno
POSTCONDIZIONI: Viene stampata la lista di canzoni senza restituire nulla
*/

int outputPlaylist(playlist pl);