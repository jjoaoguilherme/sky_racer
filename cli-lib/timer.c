#include <time.h>

static struct timespec inicio;
static int tempo_frame;

void timerInit(int tempo) {
    tempo_frame = tempo;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
}

void timerDestroy() {
}

int timerTimeOver() {
    struct timespec agora;
    clock_gettime(CLOCK_MONOTONIC, &agora);

    long ms = (agora.tv_sec - inicio.tv_sec) * 1000 +
              (agora.tv_nsec - inicio.tv_nsec) / 1000000;

    if (ms >= tempo_frame) {
        clock_gettime(CLOCK_MONOTONIC, &inicio);
        return 1;
    }

    return 0;
}

long long current_timestamp() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)(ts.tv_sec * 1000LL + ts.tv_nsec / 1000000LL);
}
