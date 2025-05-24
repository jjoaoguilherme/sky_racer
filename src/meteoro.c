#include <stdlib.h>
#include "screen.h"
#include "meteoro.h"
#include "nave.h"

const char *cometas[][5] = {
    {
        " .-\"```\"-.",
        "/  ()  o   \\",
        "|  o  --    |",
        "\\   \\/   o/",
        " '-.___.-'"
    },
    {
        " .-\"```\"-.",
        "/   .  o   \\",
        "| o (____) o |",
        "\\    o o   /",
        " '-.___.-'"
    },
    {
        " .-\"```\"-.",
        "/   o  ()  \\",
        "|  (______)  |",
        "\\    o o   /",
        " '-.___.-'"
    },
    {
        "     .-\"\"-.",
        "   /  o () \\",
        "  |   ___   |",
        "   \\ (___) /",
        "    '-..-'"
    },
    {
        "     .---.",
        "   / (o o) \\",
        "  |   \\/    |",
        "   \\ ____  /",
        "    '---'"
    }
};

const int largura_cometa[] = {
    11, 
    11, 
    13, 
    11, 
    11  
};

void desenhar_cometa(Meteoro *m) {
    for (int i = 0; i < 5; i++) {
        screenSetStringXY(m->x, m->y + i, cometas[m->tipo % 5][i]);
    }
}

ListaMeteoro* atualizar_meteoros(ListaMeteoro *lista) {
    if (rand() % 10 < 2) {
        int tentativas = 0;
        int novo_x;
        int colisao;
        do {
            colisao = 0;
            novo_x = rand() % (screenGetWidth() - 14) + 1;
            Meteoro *ver = lista;
            while (ver) {
                if (abs(ver->x - novo_x) < 12) {
                    colisao = 1;
                    break;
                }
                ver = ver->prox;
            }
            tentativas++;
        } while (colisao && tentativas < 10);

        Meteoro *novo = malloc(sizeof(Meteoro));
        novo->x = novo_x;
        novo->y = 1;

        int r = rand() % 100;
        if (r < 20) novo->tipo = 0;
        else if (r < 40) novo->tipo = 1;
        else if (r < 60) novo->tipo = 2;
        else if (r < 80) novo->tipo = 3;
        else novo->tipo = 4;

        novo->prox = lista;
        lista = novo;
    }

    Meteoro *ant = NULL, *atual = lista;
    static int contador_vel = 0;
    contador_vel++;
    while (atual) {
        if (contador_vel % 2 == 0) {
            atual->y += 1;
        }
        if (atual->y > screenGetHeight() - 5) {
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
        int largura = largura_cometa[m->tipo % 5];
        if (n->x >= m->x && n->x <= m->x + largura &&
            n->y >= m->y && n->y <= m->y + 4) {
            return 1;
        }
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
