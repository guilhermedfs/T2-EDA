#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int chave;
	struct No *esq, *dir;
	int FatBal;
} ArvoreBinaria;

ArvoreBinaria* criarArvoreBinaria(int chave);

ArvoreBinaria* maiorNo(ArvoreBinaria *no);

int max(int a, int b);

int alturaArvoreBinaria(ArvoreBinaria *no);

ArvoreBinaria* buscaArvoreBinaria(ArvoreBinaria *no, int chave);

ArvoreBinaria* obterNoAnterior(ArvoreBinaria *no, int chave);

int inserirNo(ArvoreBinaria *no, int chave);

int excluirNo(ArvoreBinaria *no, int chave);

void preOrdem(ArvoreBinaria *no);

void posOrdem(ArvoreBinaria *no);

void emOrdem(ArvoreBinaria *no);

void destruirNo(struct No *no);

void destruirArvoreBinaria(ArvoreBinaria *arvoreBinaria);
