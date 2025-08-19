#ifndef palavra_h
#define palavra_h

typedef struct palavra Palavra;

Palavra *criaPalavra(char *texto);

void liberaPalavra(Palavra *p);

void incrementaFrequencia(Palavra *p);

int getFrequencia(Palavra *p);

char *getTexto(Palavra *p);

int comparaPalavras(Palavra *p1, Palavra *p2);

#endif