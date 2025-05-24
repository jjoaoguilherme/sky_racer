#include <stdlib.h>
#include <ncurses.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"

#include "nave.h"

Nave* criar_nave() {
    Nave *n = malloc(sizeof(Nave));
    n->x = screenGetWidth() / 2;
    n->y = screenGetHeight() - 4; 
    return n;
}


void mover_nave(Nave *n, int comando) {
    if (comando == KEY_LEFT  && n->x > 2)                  n->x--;
    if (comando == KEY_RIGHT && n->x < screenGetWidth() - 3) n->x++;
    if (comando == KEY_UP    && n->y > 3)                  n->y--;
    if (comando == KEY_DOWN  && n->y < screenGetHeight() - 1) n->y++;
}

void desenhar_nave(Nave *n) {
    screenSetCharXY(n->x,     n->y - 3, '^');
    screenSetStringXY(n->x - 1, n->y - 2, "/ \\");
    screenSetStringXY(n->x - 1, n->y - 1, "|O|");
    screenSetStringXY(n->x - 2, n->y,     "/| |\\");
}

void destruir_nave(Nave *n) {
    free(n);
}
