#include <ncurses.h>
#include <string.h>

static int buffer = 0;

void screenInit(int useBuffer) {
    initscr();
    noecho();
    curs_set(0);
    timeout(0);
    keypad(stdscr, TRUE);
    buffer = useBuffer;
}

void screenDestroy() {
    endwin();
}

void screenClear() {
    clear();
}

void screenUpdate() {
    refresh();
}

void screenSetCharXY(int x, int y, char ch) {
    mvaddch(y, x, ch);
}

void screenSetStringXY(int x, int y, const char *str) {
    mvaddstr(y, x, str);
}

int screenGetWidth() {
    int x, y;
    getmaxyx(stdscr, y, x);
    return x;
}

int screenGetHeight() {
    int x, y;
    getmaxyx(stdscr, y, x);
    return y;
}
void clearScreen() {
    printf("\033[2J\033[H");
}
