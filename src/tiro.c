#include <stdio.h>
#include <stdlib.h>

#include "screen.h"

#include "tiro.h"
#include "meteoro.h"
#include "nave.h"

ListaTiro* inserir_tiro(ListaTiro *lista, int x, int y) {
    Tiro *novo = malloc(sizeof(Tiro));
    novo->x = x;
    novo->y = y;
    novo->prox = lista;
    return novo;
}

ListaTiro* atualizar_tiros(ListaTiro *lista) {
    Tiro *ant = NULL, *atual = lista;
    while (atual) {
        atual->y--;
        if (atual->y < 1) {
            if (ant == NULL) lista = atual->prox;
            else ant->prox = atual->prox;
            Tiro *temp = atual;
            atual = atual->prox;
            free(temp);
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }
    return lista;
}

void verificar_colisao(ListaMeteoro **meteoros, ListaTiro **tiros, int *pontos) {
    Tiro *t = *tiros, *t_ant = NULL;
    while (t) {
        Meteoro *m = *meteoros, *m_ant = NULL;
        while (m) {
            if (t->x == m->x && t->y == m->y) {
                (*pontos)++;
                if (m_ant == NULL) *meteoros = m->prox;
                else m_ant->prox = m->prox;
                free(m);
                if (t_ant == NULL) *tiros = t->prox;
                else t_ant->prox = t->prox;
                free(t);
                return;
            }
            m_ant = m;
            m = m->prox;
        }
        t_ant = t;
        t = t->prox;
    }
}

void destruir_lista_tiros(ListaTiro *lista) {
    while (lista) {
        Tiro *temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

void desenhar_tela(Nave *n, ListaMeteoro *m, ListaTiro *t, int pontos) {
    screenSetCharXY(n->x, n->y, '^'); 
    while (m) {
        screenSetCharXY(m->x, m->y, '*'); 
        m = m->prox;
    }
    while (t) {
        screenSetCharXY(t->x, t->y, '|'); 
        t = t->prox;
    }
    char score[30];
    sprintf(score, "Pontos: %d", pontos);
    screenSetStringXY(2, 1, score);
}
