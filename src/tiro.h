#ifndef TIRO_H
#define TIRO_H

#include "nave.h"
#include "meteoro.h"

typedef struct Tiro {
    int x, y;
    struct Tiro *prox;
} Tiro;
typedef Tiro ListaTiro;

ListaTiro* inserir_tiro(ListaTiro *lista, int x, int y);
ListaTiro* atualizar_tiros(ListaTiro *lista);
void verificar_colisao(ListaMeteoro **meteoros, ListaTiro **tiros, int *pontos);
void destruir_lista_tiros(ListaTiro *lista);
void desenhar_tela(Nave *n, ListaMeteoro *m, ListaTiro *t, int pontos);

#endif
