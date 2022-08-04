#include <iostream>

#include "CPU.h"

using namespace std;

//Cpu::Cpu(){}

//Cpu::~Cpu(){}

float Cpu::plus(float n1, float n2){
    return (n1+n2);
};

float Cpu::less(float n1, float n2){
    return (n1-n2);
};
        
float Cpu::multiplication(float n1, float n2){
    return (n1*n2);
};
        
float Cpu::division(float n1, float n2){
    return (n1/n2);
};

float Cpu::operations(float n1, float n2, char op){
    switch(op){
        case Plus: this->plus(n1, n2); break;
        case Less: this->less(n1, n2); break;
        case Multiplication: this->multiplication(n1, n2); break;
        case Division: this->division(n1, n2); break;
        default: break;
    }
};