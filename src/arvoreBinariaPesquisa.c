#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinariaPesquisa.h"

ArvoreBinaria* criarArvoreBinaria(int chave) {
	ArvoreBinaria *arvoreBinaria = (ArvoreBinaria*) malloc(sizeof(ArvoreBinaria));
	arvoreBinaria->esq = NULL;
	arvoreBinaria->dir = NULL;
	arvoreBinaria->chave = chave;
	return arvoreBinaria;
}

ArvoreBinaria* maiorNo(ArvoreBinaria *no) {
	no = no->esq;
	while (no->dir != NULL)
		no = no->dir;
	return no;
}

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int alturaArvoreBinaria(ArvoreBinaria *no) {
	if (no == NULL)
		return 0;
	return 1 + max(alturaArvoreBinaria(no->esq), alturaArvoreBinaria(no->dir));
}

ArvoreBinaria* buscaArvoreBinaria(ArvoreBinaria *no, int chave) {
	if (no == NULL)
		return NULL;
	if (no->chave == chave)
		return no;
	if (no->chave < chave)
		buscaArvoreBinaria(no->dir, chave);
	else
		buscaArvoreBinaria(no->esq, chave);
	return no;
}

ArvoreBinaria* obterNoAnterior(ArvoreBinaria *no, int chave) {
	ArvoreBinaria *noAnterior = no;
	while (no != NULL) {
		if (no->chave == chave)
			return noAnterior;

		noAnterior = no;

		if (no->chave < chave)
			no = no->dir;
		else
			no = no->esq;
	}
	return noAnterior;
}

ArvoreBinaria* criarNo(int chave) {
	ArvoreBinaria *no = (ArvoreBinaria*) malloc(sizeof(ArvoreBinaria));
	no->esq = NULL;
	no->dir = NULL;
	no->chave = chave;
	return no;
}

int inserirNo(ArvoreBinaria *no, int chave) {
	ArvoreBinaria *noAux;

	while (no != NULL) {
		noAux = no;
		if (no->chave < chave)
			no = no->dir;
		else
			no = no->esq;
	}

	no = criarNo(chave);

	if (noAux->chave < chave)
		noAux->dir = no;
	else
		noAux->esq = no;
	return 1;
}

int excluirNo(ArvoreBinaria *no, int chave) {
	ArvoreBinaria *noAtual, *noAnterior, *noNovo = NULL;
	noAtual = buscaArvoreBinaria(no, chave);

	if (noAtual == NULL)
		return 0;

	noAnterior = obterNoAnterior(no, chave);

	if (noAtual->esq == NULL || noAtual->dir == NULL) {
		if (noAtual->esq == NULL)
			noNovo = noAtual->dir;
		else
			noNovo = noAtual->esq;
		if (noAnterior == NULL) {
			no = noNovo;
		} else {
			if (chave < noAnterior->chave)
				noAnterior->esq = noNovo;
			else
				noAnterior->dir = noNovo;
		}
		free(noAtual);
	} else {
		noNovo = maiorNo(noAtual);
		noAtual->chave = noNovo->chave;
		if (noNovo->esq != NULL)
			noAtual->esq = noNovo->esq;
		else
			noAtual->esq = NULL;
		free(noNovo);
	}
	return 1;
}

void preOrdem(ArvoreBinaria *no) {
	if (no != NULL)
		return;
	printf("%d, ", no->chave);
	preOrdem(no->esq);
	preOrdem(no->dir);
}

void posOrdem(ArvoreBinaria *no) {
	if (no != NULL)
		return;
	posOrdem(no->esq);
	posOrdem(no->dir);
	printf("%d, ", no->chave);
}

void emOrdem(ArvoreBinaria *no) {
	if (no != NULL)
		return;
	emOrdem(no->esq);
	printf("%d, ", no->chave);
	emOrdem(no->dir);
}
