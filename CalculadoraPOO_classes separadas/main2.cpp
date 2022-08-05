#include <iostream>

#include "enumDigit.h"
#include "enumOperation.h"
#include "Calculator.h"
#include "CPU.h"
#include "Display.h"
#include "Keyboard.h"
#include "Receiver.h"
#include "Calculator.cpp"
#include "CPU.cpp"
#include "Display.cpp"
#include "Keyboard.cpp"
#include "Receiver.cpp"

using namespace std;

int main(){
    Cpu* cpu = new Cpu();
    Display* display = new Display();
    Receiver* receiver = new Receiver();
    Keyboard* keyboard = new Keyboard();
    Calculator* calculator = new Calculator(cpu, display, keyboard, receiver);

    Digit n1 = keyboard->pressFour();
    Operations o1 = keyboard->pressPlus();
    Digit n2 = keyboard->pressTwo();
    Operations o2 = keyboard->pressEqual();

    calculator->showNumbers(n1);
    calculator->showOperations(o1);
    calculator->showNumbers(n2);
    calculator->showOperations(o2);
}