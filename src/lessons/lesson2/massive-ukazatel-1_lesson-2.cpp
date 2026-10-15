#include <iostream>

int main() {
    int m[4];
    int *ukm;
    ukm = &m[0];
    // umk + 1 = m[1];

    double *ukz;
    ukz = new double[50]; //выделили в куче память для хранения для 50 double элементов
    for (int i = 0; i < 50; i++) {
        ukz[i] = rand() % 100;
    }
    delete []ukz;
}