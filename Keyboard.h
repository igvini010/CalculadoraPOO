#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "keyboardDigit.h"
#include "keyboardOperation.h"

class Keyboard: public KeyboardDigit, public KeyboardOperation{
public:
    Keyboard();
};

#endif