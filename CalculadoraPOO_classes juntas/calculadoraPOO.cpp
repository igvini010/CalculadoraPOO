#include <iostream>

using namespace std;

enum Digit{Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine};
enum Operations{Plus, Less, Multiplication, Division, Equal, Butn};

class KeyboardDigit{
public:
    Digit pressZero(){
    return Zero;
    };

    Digit pressOne(){
        return One;
    };

    Digit pressTwo(){
        return Two;
    };

    Digit pressThree(){
        return Three;
    };
        
    Digit pressFour(){
        return Four;
    };

    Digit pressFive(){
        return Five;
    };

    Digit pressSix(){
        return Six;
    };

    Digit pressSeven(){
        return Seven;
    };

    Digit pressEight(){
        return Eight;
    };

    Digit pressNine(){
        return Nine;
    };
};

class KeyboardOperation{
public:
    Operations pressPlus(){
    return Plus;
    };
        
    Operations pressDivision(){
        return Division;
    };
        
    Operations pressLess(){
        return Less;
    };
        
    Operations pressMultiplication(){
        return Multiplication;
    };
        
    Operations pressEqual(){
        return Equal;
    };
        
    Operations pressDigitSeparator(){
        return Butn;
    };
};

class Keyboard:public KeyboardDigit, public KeyboardOperation{
public:

};

class Cpu{
public:
    float plus(float n1, float n2){
        return (n1+n2);
    };

    float less(float n1, float n2){
        return (n1-n2);
    };
        
    float multiplication(float n1, float n2){
        return (n1*n2);
    };
        
    float division(float n1, float n2){
        return (n1/n2);
    };

    float operations(float n1, float n2, char op){
        switch(op){
            case Plus: this->plus(n1, n2); break;
            case Less: this->less(n1, n2); break;
            case Multiplication: this->multiplication(n1, n2); break;
            case Division: this->division(n1, n2); break;
            default: break;
        }
    };
};

class Display{
public:
    void addNum(Digit digit){
        switch(digit){
            case Zero: cout << "0"; break;
            case One: cout << "1"; break;
            case Two: cout << "2"; break;
            case Three: cout << "3"; break;
            case Four: cout << "4"; break;
            case Five: cout << "5"; break;
            case Six: cout << "6"; break;
            case Seven: cout << "7"; break;
            case Eight: cout << "8"; break;
            case Nine: cout << "9"; break;
            default: break;                
        }
    };

    void addOperation(Operations op){
        switch(op){
            case Plus: cout << " + "; break;
            case Less: cout << " - "; break;
            case Multiplication: cout << " * "; break;
            case Division: cout << " / "; break;
            case Equal: cout << " = "; break;
            case Butn: cout << "."; break;
            default: break;
        }
    };

    void show(float result){
        cout << result;
    };
};

class Receiver{
public:
    Display* display;
    void receive_Numbers(Digit digit){
        this->display->addNum(digit);
    }

    void receive_Operations(Operations op){
        this->display->addOperation(op);
    }
};

class Calculator{
public:
    Calculator(Cpu* cpu, Display* display, Keyboard* keyboard, Receiver* receiver){
        this->cpu = cpu;
        this->display = display;
        this->keyboard = keyboard;
        this->receiver = receiver;
    }
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

    void showNumbers(Digit n1){
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

    void showOperations(Operations op){
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

    void calculate(Operations op){
        if((verificationHaveOperation == 0) && (verificationHaveNumbers == 2)){
            result = this->cpu->operations(numbers[0], numbers[1], op);
            this->display->show(result);
            verificationCalc = 1;
        }
    }
};

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