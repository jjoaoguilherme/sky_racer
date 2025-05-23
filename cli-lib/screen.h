#ifndef CLI_LIB_SCREEN_H
#define CLI_LIB_SCREEN_H

int screenGetWidth();
int screenGetHeight();
void screenInit(int useBuffer);
void screenDestroy();
void screenClear();
void screenUpdate();
void screenSetCharXY(int x, int y, char ch);
void screenSetStringXY(int x, int y, const char *str);

#endif
