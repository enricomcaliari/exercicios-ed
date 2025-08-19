#ifndef aluno_h
#define aluno_h

#define MAX_NOME 100

typedef struct aluno Aluno;

Aluno *criaAluno(char *nome, int presencas, int faltas);

void incrementaPresencasAluno(Aluno *aluno);

void incrementaFaltasAluno(Aluno *aluno);

char *retornaNomeAluno(Aluno *aluno);

void imprimeAluno(Aluno *aluno);

void liberaAluno(Aluno *aluno);

#endif