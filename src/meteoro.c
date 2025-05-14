#include <stdlib.h>
#include "screen.h"

#include "meteoro.h"
#include "nave.h"

ListaMeteoro* atualizar_meteoros(ListaMeteoro *lista) {
    if (rand() % 10 < 3) {
        Meteoro *novo = malloc(sizeof(Meteoro));
        novo->x = rand() % (screenGetWidth() - 2) + 1;
        novo->y = 1;
        novo->prox = lista;
        lista = novo;
    }
    Meteoro *ant = NULL, *atual = lista;
    while (atual) {
        atual->y++;
        if (atual->y > screenGetHeight()) {
            if (ant == NULL) lista = atual->prox;
            else ant->prox = atual->prox;
            Meteoro *temp = atual;
            atual = atual->prox;
            free(temp);
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }
    return lista;
}

int verificar_colisao_nave(Nave *n, ListaMeteoro *m) {
    while (m) {
        if (m->x == n->x && m->y == n->y) return 1;
        m = m->prox;
    }
    return 0;
}

void destruir_lista_meteoros(ListaMeteoro *lista) {
    while (lista) {
        Meteoro *temp = lista;
        lista = lista->prox;
        free(temp);
    }
}
