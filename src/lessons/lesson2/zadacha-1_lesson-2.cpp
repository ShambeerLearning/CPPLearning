#include <iostream>
#include <ctime>

int main() {
    srand(time(0));
    int mass[100];
    int count = 0;
    for (int i = 0; i < 100; i++) {
        mass[i] = rand() % 100;
        if (mass[i] % 2 == 0) {
            count++;
        }
    }

    int *uk = new int[count];
    int j = 0;
    for (int i = 0; i < 100; i++) {
        if (mass[i] % 2 == 0) {
            uk[j] = mass[i];
            j++;
        }
    }

    for (int i = 0; i < 100; i++) {
        std::cout << mass[i] << " ";
    }
    std::cout << std::endl << std::endl;

    for (int i = 0; i < j; i++) {
        std::cout << uk[i] << " ";
    }
    std::cout << std::endl << std::endl;
}