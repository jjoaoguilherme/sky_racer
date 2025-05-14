#ifndef CLI_LIB_KEYBOARD_H
#define CLI_LIB_KEYBOARD_H

#define KEY_LEFT 68
#define KEY_RIGHT 67

void keyboardInit();
void keyboardDestroy();
int keyhit();
int readch();

#endif
