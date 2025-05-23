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
    screenInit(0);             
    keyboardInit();
    timerInit(50);            

    Nave *nave = criar_nave();
    ListaMeteoro *meteoros = NULL;
    ListaTiro *tiros = NULL;
    int ch = 0, pontos = 0, tempo_tiro = 0;

    while (ch != 10) {         
        if (keyhit()) {
            ch = readch();
            if (ch == ' ') {
                if (tempo_tiro <= 0) {
                    tiros = inserir_tiro(tiros, nave->x, nave->y - 1);
                    tempo_tiro = 10; 
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
            screenUpdate(); 
        }
    }

    salvar_pontuacao(pontos);
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
