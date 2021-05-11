#ifndef BIBTRAB_H_INCLUDED
#define BIBTRAB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct No {
    int Chave;
    struct No *pEsq, *pDir;
    int FatBal;
}No;



int menu();

No* AbreArquivo(FILE*);

No* InstalaABP(No*, int);

void ArmazenaBal(No *A);

int CalculaBal(No *A);



#endif // BIBTRAB_H_INCLUDED
