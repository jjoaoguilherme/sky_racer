#include <stdio.h>
#include <string.h>
#include "jogo.h"

int main() {
    int opcao;
    char nome[50] = "";

    while (1) {
        printf("\n=== SKY RACER ===\n");
        printf("1. Jogar\n");
        printf("2. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        if (opcao == 1) {
            if (strlen(nome) == 0) {
                printf("Digite seu nome: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0; 
            } else {
                printf("Nome já registrado: %s\n", nome);
            }
            iniciar_jogo(nome);
        } else if (opcao == 2) {
            printf("Saindo...\n");
            break;
        } else {
            printf("Opção inválida.\n");
        }
    }

    return 0;
}
