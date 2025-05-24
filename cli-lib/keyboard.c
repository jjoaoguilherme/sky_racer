#include <ncurses.h>

void keyboardInit() {
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    scrollok(stdscr, FALSE);
}

void keyboardDestroy() {
}

int keyhit() {
    int ch = getch();
    if (ch != ERR) {
        ungetch(ch);
        return 1;
    }
    return 0;
}

int readch() {
    return getch();
}
