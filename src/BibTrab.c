#include "BibTrab.h"

int menu(){
    int op;
    printf("Digite a op��o desejada:\n");
    printf("1 - Para Gerar ABP\n");
    printf("2 - Calcular Fator de Balanceamento\n");
    printf("3 - Imprimir ABP\n");
    printf("0 - Para Sair\n");
    scanf("%d", &op);
    return op;
}

No* AbreArquivo(FILE *file){

    No* NovoNo = NULL;

    char buff[1024];
    char *Snumero;
    int numero;
    fgets(buff, 1024, file);
    Snumero = strtok(buff,",");
    while(Snumero != NULL){
        numero = atoi(Snumero);
        NovoNo = InstalaABP(NovoNo, numero);
        Snumero = strtok(NULL,",\n");
    }
    return NovoNo;

}

No* InstalaABP(No *NovoNo, int Chave){

    if(NovoNo != NULL){
        if(Chave < NovoNo->Chave)
            NovoNo->pEsq = InstalaABP(NovoNo->pEsq, Chave);
        else
            NovoNo->pDir = InstalaABP(NovoNo->pDir, Chave);
    }
    else{
        NovoNo = (No*) malloc (sizeof(No));
        NovoNo->Chave = Chave;
        NovoNo->pEsq = NULL;
        NovoNo->pDir = NULL;
    }
    return NovoNo;
}



void ArmazenaBal(No *A){

    A->FatBal = ((1 + CalculaBal(A->pDir)) - (1 + CalculaBal(A->pEsq)));
    if (A->pEsq!=NULL && A->pDir!=NULL){
        ArmazenaBal(A->pEsq);
        ArmazenaBal(A->pDir);
    } else if (A->pEsq!=NULL) {
        ArmazenaBal(A->pEsq);
    } else if (A->pDir!=NULL) {
        ArmazenaBal(A->pDir);
    }


}

int CalculaBal(No *A){

    if (A == NULL) {
        return 0;
    } else if ( A->pEsq!=NULL && A->pDir!=NULL ) {
        if (CalculaBal(A->pEsq)>=CalculaBal(A->pDir)){
            return 1 + CalculaBal(A->pEsq);
        } else {
            return 1 + CalculaBal(A->pDir);
        }
    } else if (A->pEsq!=NULL){
        return 1 + CalculaBal(A->pEsq);
    } else if (A->pDir!=NULL){
        return 1 + CalculaBal(A->pDir);
    } else {
        return 1;
    }

}

void destruirNo(No* no) {
	if (no == NULL)
		return;
	destruirNo(no->pEsq);
	destruirNo(no->pDir);
	free(no);
	no = NULL;
}

void destruirArvoreBinaria(No* arvoreBinaria) {
	if (arvoreBinaria == NULL)
		return;
	destruirNo(arvoreBinaria);
	arvoreBinaria = NULL;
}

void imprimir(No* root){
	if(root){
		printf("<");
		imprimir(root->pEsq);
		printf("([%d]-fb[%d])", root->Chave, root->FatBal);
		imprimir(root->pDir);
		printf(">");
	}
}