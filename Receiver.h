#ifndef RECEIVER_H
#define RECEIVER_H

#include "enumDigit.h"
#include "enumOperation.h"
#include "Display.cpp"

class Receiver{
public:
    Display* display;
    void receive_Numbers(Digit digit);
    void receive_Operations(Operations op);
};

#endif