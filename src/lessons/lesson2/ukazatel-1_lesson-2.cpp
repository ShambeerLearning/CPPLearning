#include <iostream>

void outData(float a) {
    std::cout << a << std::endl;
}
void outData(double a) {
    std::cout << a << std::endl;
}
void outData(int a) {
    std::cout << a << std::endl;
}

int main() {
    int *uk = new int;
    *uk = 10;
    outData(*uk);

    double *a = new double[10];
    a[1] = 5;
    outData(a[1]);
    delete []a;


    a = new double;
    *a = 1.55;
    outData(*a);
    delete a;
    a = new double(1.55);
    outData(*a);
    delete a;
}