

typedef struct c_lib * lib;

lib newLib(void);

char * get_cognome(lib l);

char * get_nome(lib l);

int get_matricola(lib l);

list get_esami(lib l);

int addExam(lib l, item ex);

int findExam(lib l, item ex);
