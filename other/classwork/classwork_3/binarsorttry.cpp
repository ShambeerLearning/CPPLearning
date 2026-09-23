#include <iostream>

void CompletionArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int arr[100], l = 1, r = 0, m = 0, inpp, y;
    std::cout << "Введите количество элементов в массиве - ";
    std::cin >> inpp;
    CompletionArray(arr, inpp);
    std::cout << "Введите искомое число - ";
    std::cin >> y;
    while (l < r)
    {
        if (arr[m] < y) {
            l = m + 1;
        }
        else {
            r = m;
        }
        if (arr[m] == y) {
            std::cout << "Элемент - " << arr[m] << std::endl;
            return 0;
        }
    }
    return 0;
}
