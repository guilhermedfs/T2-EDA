#include "BibTrab.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    FILE *file;
    char nomeArquivo[256];
    int op = 0;
    No* PNo;

    do{
    op = menu();
        switch (op){
        case 1:
            printf("\n----------------------- GERA ABP -----------------------\n\n");
            printf("Digite o nome do arquivo que deseja abrir\n");
            scanf(“ %[^\n]s”, nomeArquivo);
            file = fopen(nomeArquivo, "r");
            if(file)
                PNo = AbreArquivo(file);
            else
                printf("Erro ao abrir arquivo!\n");
            break;

        case 2:
            printf("Calcula Fator de Balanceamento\n");
            if (PNo!=NULL){
                ArmazenaBal(PNo);
                printf("O Calculo do Fator de Balanceamento foi realizado com sucesso!\n");
            } else {
                printf("Erro!! A arvore esta vazia!\n");
            }            
            break;
        case 3:
            printf("Imprime ABP\n");
            imprimir(PNo);
            break;
        case 0:
            fclose(file);
            destruirArvoreBinaria(PNo);
            printf("\n\n-------------------- Programa Encerrado --------------------\n\n");
            break;

        default:
            printf("Opção Inválida!\n");
            break;
        }
    }while (op != 0);

    return 0;
}
