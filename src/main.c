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
            printf("Digite o nome do arquivo que deseja abrir\n");
            scanf("%s", nomeArquivo);
            file = fopen(nomeArquivo, "r");
<<<<<<< HEAD:main.c
            if(file)
                PNo = AbreArquivo(file);
=======
            if(file){
                //No* PNo = AbreArquivo(file);
                PNo = AbreArquivo(file);
            }
>>>>>>> 771ecc4cb660c171635608198df23564a3d8396d:src/main.c
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
            printf("\n\n-------------------- Programa Encerrado --------------------\n\n");
            break;

        default:
            printf("Op��o Inv�lida!\n");
            break;
        }
    }while (op != 0);

    return 0;
}
