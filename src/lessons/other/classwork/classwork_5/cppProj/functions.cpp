#include "functions.h"

bool isAge(int age){
    if (age < 18) {
        return false;
    }
    else {
        return true;
    }
}

void message(int inpp){
    if(isAge(inpp)){
        std::cout << "Drink" << std::endl;
    }
    else {
        std::cout << "Not Drink" << std::endl;
    }
}