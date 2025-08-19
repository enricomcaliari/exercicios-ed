#ifndef pais_h
#define pais_h

typedef struct pais Pais;

Pais *criaPais(char *nome, int ouro, int prata, int bronze, int total);

void incrementaOuroPais(Pais *pais, int ouro);

void incrementaPrataPais(Pais *pais, int prata);

void incrementaBronzePais(Pais *pais, int bronze);

char *retornaNomePais(Pais *pais);

int retornaOuroPais(Pais *pais);

int retornaPrataPais(Pais *pais);

int retornaBronzePais(Pais *pais);

void imprimePais(Pais *pais);

void liberaPais(Pais *pais);

#endif