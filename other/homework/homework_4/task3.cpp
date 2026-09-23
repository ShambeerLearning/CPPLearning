#include <iostream>
using namespace std;

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    int Chis[1000];
    for (int i = 0; i < N; i++) {
        Chis[i] = i + 1;
    }

    int left = A - 1;
    int right = B - 1;
    while (left < right) {
        int itog = Chis[left];
        Chis[left] = Chis[right];
        Chis[right] = itog;
        left++;
        right--;
    }

    left = C - 1;
    right = D - 1;
    while (left < right) {
        int itog = Chis[left];
        Chis[left] = Chis[right];
        Chis[right] = itog;
        left++;
        right--;
    }

    for (int i = 0; i < N; i++) {
        cout << Chis[i] << " ";
    }

    return 0;
}