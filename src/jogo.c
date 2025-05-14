#include <stdlib.h>
#include <unistd.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

#include "nave.h"
#include "meteoro.h"
#include "tiro.h"
#include "ranking.h"

void iniciar_jogo() {
    screenInit(0);              // modo sem buffer (0 = sem buffer, 1 = com buffer)
    keyboardInit();
    timerInit(50);              // 50 ms por frame (~20 FPS)

    Nave *nave = criar_nave();
    ListaMeteoro *meteoros = NULL;
    ListaTiro *tiros = NULL;
    int ch = 0, pontos = 0, tempo_tiro = 0;

    while (ch != 10) {          // tecla Enter encerra o jogo
        if (keyhit()) {
            ch = readch();
            if (ch == ' ') {
                if (tempo_tiro <= 0) {
                    tiros = inserir_tiro(tiros, nave->x, nave->y - 1);
                    tempo_tiro = 10; // recarga
                }
            } else {
                mover_nave(nave, ch);
            }
        }

        if (timerTimeOver()) {
            tempo_tiro--;
            meteoros = atualizar_meteoros(meteoros);
            tiros = atualizar_tiros(tiros);
            verificar_colisao(&meteoros, &tiros, &pontos);

            if (verificar_colisao_nave(nave, meteoros)) break;

            screenClear();
            desenhar_tela(nave, meteoros, tiros, pontos);
            screenUpdate(); // necessário mesmo no modo sem buffer
        }
    }

    salvar_pontuacao(pontos);
    destruir_nave(nave);
    destruir_lista_meteoros(meteoros);
    destruir_lista_tiros(tiros);

    screenClear();
    screenSetStringXY(2, 2, "Fim de jogo! Pressione uma tecla...");
    screenUpdate();
    readch();  // aguarda tecla final

    keyboardDestroy();
    screenDestroy();
    timerDestroy();
}
