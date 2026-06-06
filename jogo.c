#include <stdio.h>
#include <stdlib.h>

void tela_inicial();
void pausa();

int opcao;

int main()
{

    do { 

        tela_inicial();

        switch(opcao)
        {
            case 1:
                printf("Iniciando...\n");
                break;

            case 2:
                printf("Sao 18 perguntas no total e a cada resposta certa voce avanca 1 nivel\n"
                       "ao responder todas de forma correta, voce vence o QUIZ Com Niveis!\n");
                pausa();
                break;

            case 3:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida\n");
                pausa();
        }
    }    
    while(opcao != 3);    

    return 0;

}

void tela_inicial() {
    printf("====================================\n");
    printf("           QUIZ COM NIVEIS          \n");
    printf("====================================\n");

    printf("1 - Jogar\n");
    printf("2 - Objetivo do QUIZ\n");
    printf("3 - Sair\n");

    printf("\nEscolha uma opcao: ");
    scanf("%i", &opcao);
    while (getchar () != '\n');
    system("cls");
}    

void pausa() {
    printf("\nPressione enter para continuar...\n");
    while (getchar () != '\n');
}