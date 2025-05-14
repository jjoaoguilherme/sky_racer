#include <stdio.h>
#include "ranking.h"

void salvar_pontuacao(int pontos) {
    FILE *f = fopen("assets/ranking.txt", "a");
    if (f) {
        fprintf(f, "%d\n", pontos);
        fclose(f);
    }
}
