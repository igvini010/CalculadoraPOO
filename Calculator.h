#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "CPU.h"
#include "Display.h"
#include "Keyboard.h"
#include "Receiver.h"

class Calculator{
public:
    Cpu* cpu;
    Keyboard* keyboard;
    Display* display;
    Receiver* receiver;

    int numbers[2] = {0, 0};
    Operations operations[2];
    int verificationHaveNumbers = 0;
    int verificationHaveOperation = 0;
    int verificationCalc = 0;
    float result;

    Calculator(Cpu* cpu, Display* display, Keyboard* keyboard, Receiver* receiver){
        this->cpu = cpu;
        this->display = display;
        this->keyboard = keyboard;
        this->receiver = receiver;
    };

    void showNumbers(Digit n1);
    void showOperations(Operations op);
    void calculate(Operations op);
};

#endif