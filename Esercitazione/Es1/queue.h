
typedef struct c_queue *queue;

queue newQueue(void);

int emptyQueue(queue q);

int enQueue(queue q, item val);

item deQueue(queue q);

/*    
    -cancFinoItem (queue, item) ---> queue

    DATI IN INPUT: queue Q, item el
    PRECONDIZIONI: Q deve esistere, el deve esistere e non deve essere un NULLITEM (potrebbero essere effettuati appositi controlli)

    DATI IN OUTPUT: queue Q'
    POSTCONDIZIONI: Q' sarà ottenuta da Q eliminando tutti gli item che precedono l`item el, 
                    quindi se el non è presente Q' sarà vuota.

    
    NB: Siccome le operazioni sulle code vengono effettuate con passaggio per riferimento, Q' non è un vero e proprio output
        ma può essere considerato come un side-effect, quindi un`idea potrebbe essere quella di restituire un int booleano (0 o 1) per 
        indicare se l`operazione è andata a buon fine oppure no.
*/

int cancFinoItem (queue q, item el);

/*    
    -fondiDaItem (queue, queue, item) ---> queue

    DATI IN INPUT: queue Q1, queue Q2, item el
    PRECONDIZIONI: Q1 e Q2 devono esistere, el deve esistere e non deve essere un NULLITEM (potrebbero essere effettuati appositi controlli)

    DATI IN OUTPUT: queue newQ
    POSTCONDIZIONI: newQ sarà vuota se l`item el non è presente sia in Q1 che in Q2, altrimenti conterrà tutti gli elementi contenuti 
                    sia in Q1 che in Q2 a partire da el (se non hanno elementi comuni a partire da el newQ sarà comunque vuota)

    
    NB: Siccome Non è specificato se Q1 e Q2 devono continuare ad esistere, per praticità sarebbe meglio creare delle copie delle due code su 
        cui lavorare, così da poter sfruttare anche la funzione realizzata in precedenza
*/

queue fondiDaItem (queue Q1, queue Q2, item el);