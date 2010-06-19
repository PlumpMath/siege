#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

Uint8* keyStates;
int keyNumStates;

SGuint keySDLtoSIEGE(int key);
int keySIEGEtoSDL(SGuint key);

void keyboardKey(int key, int down);
void keyboardChar(int chr, int down);

#endif // __KEYBOARD_H__