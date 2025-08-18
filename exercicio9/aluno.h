#ifndef aluno_h
#define aluno_h

#define MAX_NOME 100

typedef struct aluno Aluno;

Aluno *criaAluno(char *nome, int matricula, float media);

void imprimeAluno(Aluno *aluno);

void liberaAluno(Aluno *aluno);

#endif // aluno_h