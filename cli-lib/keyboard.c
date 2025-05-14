#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

static struct termios oldt;

void keyboardInit() {
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void keyboardDestroy() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int keyhit() {
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int readch() {
    unsigned char ch;
    if (read(STDIN_FILENO, &ch, 1) < 0) return 0;
    return ch;
}
