#include <stdlib.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"

#include "nave.h"

Nave* criar_nave() {
    Nave *n = malloc(sizeof(Nave));
    n->x = screenGetWidth() / 2;
    n->y = screenGetHeight() - 2;
    return n;
}

void mover_nave(Nave *n, int comando) {
    if (comando == KEY_LEFT && n->x > 1) n->x--;
    if (comando == KEY_RIGHT && n->x < screenGetWidth() - 2) n->x++;
}

void destruir_nave(Nave *n) {
    free(n);
}
