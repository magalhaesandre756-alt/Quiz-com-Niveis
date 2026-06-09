#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
void tela_inicial();
void pausa();
int questoes(void);

int opcao;

int main() {
setlocale(LC_ALL, "Portuguese");
    do { 
        tela_inicial();

        switch(opcao)
        {
            case 1:
                printf("Iniciando QUIZ...\n");
                questoes();
                break;

            case 2:
                printf("Sao 18 perguntas no total e a cada resposta certa voce avanca 1 nivel.\n"
                       "Ao responder todas de forma correta, voce vence o QUIZ Com Niveis!\n");
                pausa();
                break;

            case 3:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
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

    printf("1 - Jogar.\n");
    printf("2 - Objetivo do QUIZ.\n");
    printf("3 - Sair.\n");

    printf("\nEscolha uma opcao: ");
    scanf("%i", &opcao);
    while (getchar () != '\n');
    system("cls");
}    

void pausa() {
    printf("\nPressione enter para continuar...\n");
    while (getchar () != '\n');
}

int questoes(void) {
    FILE *arquivo = fopen("perguntas.txt", "r");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit (1);
    }

    char linha[300];
    char resposta;
    char respostaCorreta;
    char respostaCorreta = ' ';

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strncmp(linha, "RESP:", 5) == 0)
        {
            respostaCorreta = toupper(linha[5]);
            continue;
        }

        if (strncmp(linha, "RESPOSTA:", 9) != 0) {
            printf("%s", linha);
        }

        if (strncmp(linha, "D)", 2) == 0) {
            printf("Digite sua resposta (A, B, C ou D): ");
            scanf(" %c", &resposta);

            while (getchar() != '\n');

            if (toupper(resposta) == respostaCorreta)
            {
                printf("\nAcertou!\n");
            }
            else
            {
                printf("\nErrou!\n");
            }

            pausa();
        }

        if (strncmp(linha, "RESPOSTA:", 9) == 0) {

            respostaCorreta = linha[9];

            if (toupper(resposta) == toupper(respostaCorreta)) {

                printf("\nAcertou! Proxima pergunta.\n");
                pausa();

            } else {

                printf("\nErrou! Fim de jogo.\n");
                printf("Resposta correta: %c\n", respostaCorreta);

                fclose(arquivo);
                pausa();
                return 0;
            }

        }
    }
    fclose(arquivo);

    printf("Parabens! Voce completou o quiz!\n");
    pausa();
    return 1;

}
