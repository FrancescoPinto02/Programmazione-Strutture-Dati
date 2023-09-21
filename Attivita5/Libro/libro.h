typedef struct miolibro *libro;

libro newLibro(char *titolo, char* editore, float prezzo, int anno);
char* get_titolo(libro l);
char* get_editore(libro l);
int get_anno(libro l);
float get_prezzo(libro l);
float sconto(libro l, float percentuale);
void aggiorna(libro l, int anno);