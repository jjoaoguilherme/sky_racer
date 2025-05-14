#ifndef METEORO_H
#define METEORO_H

#include "nave.h"

typedef struct Meteoro {
    int x, y;
    struct Meteoro *prox;
} Meteoro;
typedef Meteoro ListaMeteoro;

ListaMeteoro* atualizar_meteoros(ListaMeteoro *lista);
int verificar_colisao_nave(Nave *n, ListaMeteoro *m);
void destruir_lista_meteoros(ListaMeteoro *lista);

#endif
