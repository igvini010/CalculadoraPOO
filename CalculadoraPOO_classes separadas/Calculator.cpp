#include <iostream>

#include "Calculator.h"

using namespace std;

void Calculator::showNumbers(Digit n1){
    if(verificationHaveNumbers == 0){
        verificationHaveNumbers++;
        this->receiver->receive_Numbers(n1);
        numbers[0] = n1;
    }else if(verificationHaveNumbers == 1){
        verificationHaveNumbers++;
        this->receiver->receive_Numbers(n1);
        numbers[1] = n1;
    }
};

void Calculator::showOperations(Operations op){
    this->receiver->receive_Operations(op);
    operations[verificationHaveOperation] = op;
    verificationHaveOperation++;
    if((verificationHaveNumbers == 1) && (verificationCalc == 0)){
            
    }
    if((op == Equal) && (verificationHaveOperation == 2)){
        verificationHaveOperation = 0;
        calculate(operations[verificationHaveOperation]);
    }
};

void Calculator::calculate(Operations op){
    if((verificationHaveOperation == 0) && (verificationHaveNumbers == 2)){
        result = this->cpu->operations(numbers[0], numbers[1], op);
        this->display->show(result);
        verificationCalc = 1;
    }
}