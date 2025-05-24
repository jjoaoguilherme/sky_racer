#ifndef NAVE_H
#define NAVE_H

typedef struct {
    int x, y;
} Nave;

Nave* criar_nave();
void mover_nave(Nave *n, int comando);
void desenhar_nave(Nave *n);  
void destruir_nave(Nave *n);

#endif
