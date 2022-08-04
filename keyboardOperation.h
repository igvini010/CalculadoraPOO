#ifndef KEYBOARDOPERATION_H
#define KEYBOARDOPERATION_H

#include "enumOperation.h"

class KeyboardOperation{
public:
    Operations pressPlus();  
    Operations pressDivision();    
    Operations pressLess();     
    Operations pressMultiplication();    
    Operations pressEqual();
    Operations pressDigitSeparator();
};

#endif