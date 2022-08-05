#ifndef DISPLAY_H
#define DISPLAY_H

#include "enumDigit.h"
#include "enumOperation.h"

class Display{
public:
    void addNum(Digit digit);
    void addOperation(Operations op);
    void show(float result);
};

#endif