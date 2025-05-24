#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "screen.h"
#include "keyboard.h"
#include "../cli-lib/timer.h"

#include "nave.h"
#include "meteoro.h"
#include "tiro.h"
#include "ranking.h"

extern char nome_jogador[100];

void iniciar_jogo() {
    screenInit(0);
    keyboardInit();
    timerInit(50);

    Nave *nave = criar_nave();
    ListaMeteoro *meteoros = NULL;
    ListaTiro *tiros = NULL;
    int ch = 0, pontos = 0;
    int jogador_morreu = 0;
    long long ultimo_tiro = 0;

    while (ch != 10) {
        if (keyhit()) {
            ch = readch();
            if (ch == ' ') {
                long long agora = current_timestamp();
                if (agora - ultimo_tiro >= INTERVALO_TIRO) {
                    tiros = inserir_tiro(tiros, nave->x, nave->y - 1);
                    ultimo_tiro = agora;
                }
            } else {
                mover_nave(nave, ch);
            }
        }

        if (timerTimeOver()) {
            meteoros = atualizar_meteoros(meteoros);
            tiros = atualizar_tiros(tiros);
            verificar_colisao(&meteoros, &tiros, &pontos);

            if (verificar_colisao_nave(nave, meteoros)) {
                jogador_morreu = 1;
                break;
            }

            screenClear();
            desenhar_tela(nave, meteoros, tiros, pontos);
            screenUpdate();
        }
    }

    if (jogador_morreu) {
        if (nome_jogador[0] == '\0') {
            screenClear();
            screenSetStringXY(2, 2, "Digite seu nome para salvar no ranking:");
            screenUpdate();
            echo();
            mvgetnstr(3, 2, nome_jogador, 99);
            noecho();
        }
        salvar_pontuacao(nome_jogador, pontos);
    }

    destruir_nave(nave);
    destruir_lista_meteoros(meteoros);
    destruir_lista_tiros(tiros);

    screenClear();
    screenSetStringXY(2, 2, "Fim de jogo! Pressione uma tecla...");
    screenUpdate();
    readch();

    keyboardDestroy();
    screenDestroy();
    timerDestroy();
}
