#include <iostream>

#include "keyboardOperation.h"

using namespace std;

Operations KeyboardOperation::pressPlus(){
    return Plus;
};
        
Operations KeyboardOperation::pressDivision(){
    return Division;
};
        
Operations KeyboardOperation::pressLess(){
    return Less;
};
        
Operations KeyboardOperation::pressMultiplication(){
    return Multiplication;
};
        
Operations KeyboardOperation::pressEqual(){
    return Equal;
};
        
Operations KeyboardOperation::pressDigitSeparator(){
    return Butn;
};