#include "jogo.h"
#include "../cli-lib/screen.h"
#include "../cli-lib/keyboard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cli-lib/timer.h"

char nome_jogador[100] = "";

void inserir_nome_jogador() {
    if (nome_jogador[0] != '\0') {
        printf("\nNome já registrado: %s\n", nome_jogador);
        printf("Pressione ENTER para continuar...");
        while(getchar() != '\n');
        return;
    }
    printf("\nDigite seu nome: ");
    if (fgets(nome_jogador, sizeof(nome_jogador), stdin)) {
        nome_jogador[strcspn(nome_jogador, "\n")] = '\0';
    }
}

void exibir_menu_completo() {
    screenClear();
    printf("╔════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               SKY RACER                                      ║\n");
    printf("║──────────────────────────────────────────────────────────────────────────────║\n");
    printf("║                               [0] Inserir Nome                               ║\n");
    printf("║                               [1] Iniciar Jogo                               ║\n");
    printf("║                               [2] Ver Pontuações                             ║\n");
    printf("║                               [3] Sair                                       ║\n");
    printf("║                               [4] Trocar Jogador                             ║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════════╝\n");
    if (nome_jogador[0] != '\0') {
        printf("\nJogador atual: %s\n", nome_jogador);
    } else {
        printf("\nJogador atual: [NÃO REGISTRADO]\n");
    }
    printf("\nEscolha uma opção: ");
}

void mostrar_pontuacoes() {
    FILE *arquivo = fopen("assets/ranking.txt", "r");
    screenClear();
    if (arquivo == NULL) {
        printf("Erro ao abrir ranking.txt\n");
    } else {
        printf("╔════════════════════════════════════════════════════════╗\n");
        printf("║                    PONTUAÇÕES SALVAS                 ║\n");
        printf("╠════════════════════════════════════════════════════════╣\n");
        char linha[128];
        while (fgets(linha, sizeof(linha), arquivo)) {
            printf("║ %-54s ║\n", linha);
        }
        fclose(arquivo);
        printf("╚════════════════════════════════════════════════════════╝\n");
    }
    printf("\nPressione ENTER para voltar ao menu...");
    while(getchar() != '\n');
}

void menu_principal() {
    char entrada[10];
    int opcao = -1;
    while (1) {
        system("clear");
        screenClear();
        exibir_menu_completo();
        if (fgets(entrada, sizeof(entrada), stdin) != NULL) {
            opcao = atoi(entrada);
        } else {
            opcao = -1;
        }
        switch (opcao) {
            case 0:
                inserir_nome_jogador();
                break;
            case 1:
                if (nome_jogador[0] == '\0') {
                    printf("\nVocê precisa inserir o nome antes de jogar!\nPressione ENTER para continuar...");
                    while(getchar() != '\n');
                } else {
                    iniciar_jogo();
                }
                break;
            case 2:
                mostrar_pontuacoes();
                break;
            case 3:
                screenClear();
                printf("Obrigado por jogar Sky Racer!\n");
                exit(0);
            case 4:
                nome_jogador[0] = '\0';
                printf("\nJogador atual removido. Pressione ENTER...\n");
                while(getchar() != '\n');
                break;
            default:
                printf("Opção inválida! Pressione ENTER...\n");
                while(getchar() != '\n');
        }
    }
}

int main() {
    menu_principal();
    return 0;
}
