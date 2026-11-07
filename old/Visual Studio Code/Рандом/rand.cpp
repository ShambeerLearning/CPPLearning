#include <iostream>

int main(){
    srand(time(0));
    bool a;
    a = rand() % 2;
    std::cout << "1 - yes, 0 - no" << std::endl;
    std::cout << a << std::endl;
    system("pause");
}