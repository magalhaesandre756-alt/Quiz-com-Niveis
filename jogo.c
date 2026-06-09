#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void tela_inicial();
void pausa();
int questoes(void);
char lerRespostaComTempo(int segundos);

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

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        pausa();
        return 0;
    }

    char linha[300];
    char resposta;
    char respostaCorreta;

    int nivel = 1;
    int tempo = 30;
    int diminuirtempo = 2;
    int tempominimo = 8;

    printf("====================================\n");
    printf("              NIVEL %d              \n", nivel);
    printf("        Tempo: %d segundos\n", tempo);
    printf("====================================\n\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        if (strncmp(linha, "RESPOSTA:", 9) != 0) {
            printf("%s", linha);
        }

        if (strncmp(linha, "D)", 2) == 0) {
            resposta = lerRespostaComTempo(tempo);

            if (resposta == '\0') {
                printf("\nVoce perdeu! O tempo acabou no nivel %d.\n", nivel);

                fclose(arquivo);
                pausa();
                return 0;
            }
        }

        if (strncmp(linha, "RESPOSTA:", 9) == 0) {
            respostaCorreta = toupper(linha[9]);

            if (toupper(resposta) == respostaCorreta) {
                printf("\nAcertou! Voce avancou para o proximo nivel!\n");

                nivel++;

                tempo = tempo - diminuirtempo;

                if (tempo < tempominimo) {
                    tempo = tempominimo;
                }

                pausa();
                system("cls");

                printf("====================================\n");
                printf("              NIVEL %d              \n", nivel);
                printf("        Tempo: %d segundos\n", tempo);
                printf("====================================\n\n");

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

    printf("\nParabens! Voce completou o quiz!\n");
    pausa();
    return 1;
}

char lerRespostaComTempo(int segundos) {
    time_t inicio = time(NULL);
    int tempoespera = 3;
    int temporestante;
    int ultimotempo = -1;
    char resposta;

    printf("\nPrepare-se! O cronometro vai comecar em %d segundos...\n", tempoespera);
    Sleep(tempoespera * 1000);

    printf("\nVoce tem %d segundos para responder.\n", segundos);
    printf("Digite A, B, C ou D: ");

    while (1) {
        temporestante = segundos - (int) difftime(time(NULL), inicio);

        if (temporestante <=0 ) {
            printf("\nTEMPO ESGOTADO!\n");
            return '\0';
        }
        if (_kbhit()) {
            resposta = toupper(getch());

            if (resposta == 'A' || resposta == 'B' || resposta == 'C' || resposta == 'D') {
                printf("%c\n", resposta);
                return resposta;
            }
        }
        Sleep(100);

    }
}

