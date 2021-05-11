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

    No *NovoNo = NULL;

    char buff[1024];
    char *Snumero;
    int numero;
    fgets(buff, 1024, file);
    Snumero = strtok(buff,",");
    while(Snumero != NULL){
        numero = atoi(Snumero);
        InstalaABP(NovoNo, numero);
        Snumero = strtok(NULL,",\n");
    }
    return NovoNo;
}

void InstalaABP(No* NovoNo, int Chave){
    if(NovoNo != NULL)
        if(Chave < NovoNo->Chave)
            InstalaABP(NovoNo->pEsq, Chave);
        else
            InstalaABP(NovoNo->pDir, Chave);
    else{
        NovoNo = (No*) malloc (sizeof(No));
        NovoNo->Chave = Chave;
        NovoNo->pEsq = NULL;
        NovoNo->pDir = NULL;
    }
}
