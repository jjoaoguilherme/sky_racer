#ifndef METEORO_H
#define METEORO_H

#include "nave.h" 

typedef struct meteoro {
    int x, y;
    int tipo;
    struct meteoro *prox;
} Meteoro;

typedef Meteoro ListaMeteoro;

ListaMeteoro* atualizar_meteoros(ListaMeteoro *lista);
int verificar_colisao_nave(Nave *n, ListaMeteoro *m);
void destruir_lista_meteoros(ListaMeteoro *lista);

#endif
