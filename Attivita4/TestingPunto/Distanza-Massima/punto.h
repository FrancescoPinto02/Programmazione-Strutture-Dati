typedef struct pto *punto;

punto creaPunto (float x, float y);
float ascissa (punto p);
float ordinata (punto p);
float distanza (punto p1, punto p2);
void stampa (punto p);
void finput_array(char *file_name, punto arr[], int n);
void foutput_array(char *file_name, punto arr[], int n);
