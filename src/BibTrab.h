#ifndef BIBTRAB_H_INCLUDED
#define BIBTRAB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct No {
    int Chave;
    int info;
    struct No *pEsq, *pDir;
    int FatBal;
}No;



int menu();

No* AbreArquivo(FILE*);

No* InstalaABP(No*, int);

void ArmazenaBal(No *A);

int CalculaBal(No *A);

void destruirNo(No *no);

void destruirArvoreBinaria(No* arvoreBinaria);

void imprimir(No* root);

#endif // BIBTRAB_H_INCLUDED
