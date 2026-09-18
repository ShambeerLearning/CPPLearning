#include <iostream>
#include <ctime>

void randGen(int &a) {
    a = rand() % 100;
}

int main() {
    srand(time(0));
    int size;
    randGen(size);
    int *uk = new int[size];

    for (int i = 0; i < (size + 1) / 2; ++i) {
        uk[i] = i + 1;
        uk[size - 1 - i] = i + 1;
    }

    std::cout << "Size: " << size << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << uk[i] << " ";
    }
    std::cout << std::endl;

    delete[] uk;
    return 0;
}
