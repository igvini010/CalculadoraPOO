#include <iostream>

#include "Receiver.h"

using namespace std;

void Receiver::receive_Numbers(Digit digit){
    this->display->addNum(digit);
}

void Receiver::receive_Operations(Operations op){
    this->display->addOperation(op);
}