#include <stdio.h>

int main()
{
    int opcao;

    printf("====================================\n");
    printf("           QUIZ COM NIVEIS          \n");
    printf("====================================\n");

    printf("1 - Jogar\n");
    printf("2 - Objetivo\n");
    printf("3 - Sair\n");

    printf("\nEscolha uma opcao: ");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            printf("\nIniciando...\n");
            break;

        case 2:
            printf("\nResponda corretamente para avancar\n");
            break;

        case 3:
            printf("\nEncerrando...\n");
            break;

        default:
            printf("\nOpcao invalida\n");
    }

    return 0;
}
