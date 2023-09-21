typedef struct c_ref *ref;

/*
SPECIFICA SINTATTICA
- Tipo di riferimento: ref
- Tipi utilizzati: string, int, list, void, item


SPECIFICA SEMANTICA
- ref è composto dai campi:
    comune = stringa
    n = int (numero di seggi)
    seggi = list di item

- item è composto dai campi:
    ID = int
    votanti = int
    vot_effettivi = int
    nulli = int
    si = int
    no = int
*/



/*
creaRef(string, int) ---> ref

DATI DI INPUT: comune (string), n (int)
PRECONDIZIONI: comune non deve essere vuoto , n > 0

DATI DI OUTPUT: new (ref)
POSTCONDIZIONI: new = (comune, n, seggi) AND seggi=(Nil)
*/

ref creaRef(char *comune, int n);




/*
inserSeggio(ref, item) ---> ref'

DATI DI INPUT: R (ref), scheda (item)
PRECONDIZIONI: R deve esistere AND R->seggi (lista) deve esistere AND scheda non deve essere gia presente in R->seggi

DATI DI OUTPUT: R' (ref R modificato)
POSTCONDIZIONI: R = (comune, n, seggi) AND seggi=(s1, s2, ..., sk) 
                R' = (comune, n, seggi) AND seggi=(scheda, s1, s2, ..., sk)
                
NB: R->n è il numero massimo di seggi, quindi l`inserimento di un numero > n di seggi non è permessa
*/

int inserSeggio(ref R, item scheda);


/*
completRef(ref) ---> boolean

DATI DI INPUT: R (ref)
PRECONDIZIONI: R deve esistere AND R->seggi (lista) deve esistere 

DATI DI OUTPUT: b (int boolean)
POSTCONDIZIONI: R = (comune, n, seggi) AND seggi=(s1, s2, ..., sk) 
                b = 1 se sizeList(seggi) == R->n
                b = 0 se sizeList(seggi) < R->n              
*/

int completRef(ref R);

/*
nosiRef(ref) ---> void

DATI DI INPUT: R (ref)
PRECONDIZIONI: R deve esistere AND R->seggi (lista) deve esistere AND completeRef(R)==1

DATI DI OUTPUT: nessuno
POSTCONDIZIONI: Viene stampato a video chi ha vinto tra il si e il no            
*/

int nosiRef(ref R);