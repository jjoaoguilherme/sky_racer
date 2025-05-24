#include <stdio.h>
#include "ranking.h"

void salvar_pontuacao(const char *nome, int pontos) {
    FILE *f = fopen("assets/ranking.txt", "a");
    if (f) {
        fprintf(f, "%s - %d pontos\n", nome, pontos);
        fclose(f);
    }
}
