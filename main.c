#include "BibTrab.h"
#include "arvoreBinariaPesquisa.h"

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
            printf("Digite o nome do arquivo que deseja abrir\n");
            scanf("%s", nomeArquivo);
            file = fopen(nomeArquivo, "r");
            if(file)
                PNo = AbreArquivo(file);
            else
                printf("Erro ao abrir arquivo!\n");
            break;

        case 2:
            printf("Calcula Fator de Balanceamento\n");
            break;

        case 3:
            printf("Imprime ABP\n");
            break;

        case 0:
            fclose(file);
            destruirArvoreBinaria(PNo);
            printf("\n\n-------------------- Programa Encerrado --------------------\n\n");
            break;

        default:
            printf("Op��o Inv�lida!\n");
            break;
        }
    }while (op != 0);

    return 0;
}
