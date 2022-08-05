#ifndef CPU_H
#define CPU_H

#include "enumOperation.h"

class Cpu{
public:
    //Cpu();
    //~Cpu();
    float plus(float n1, float n2);
    float less(float n1, float n2);    
    float multiplication(float n1, float n2);
    float division(float n1, float n2);
    float operations(float n1, float n2, char op);
};

#endif