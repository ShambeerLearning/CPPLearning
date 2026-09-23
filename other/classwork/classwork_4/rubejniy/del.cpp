#include <iostream>
#include <ctime>

void vvod(int arr[], int n) {
    std::cout << "Введите " << n << " элементов: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

void vvodRand(int m[], int n) {
    for (int i = 0; i < n; i++) {
        m[i] = rand() % 100;
    }
}

void vivodClear(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void vivod(int arr[], int n, int M, int L) {
    std::cout << "Числа с остатком " << L << " от деления на " << M << ": ";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (M != 0 && arr[i] % M == L) {
            std::cout << arr[i] << " ";
            found = true;
        }
    }
    if (!found) std::cout << "совпадений не найдено";
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0)));

    int arr[100], n, choise, M, L;

    std::cout << "Выберите метод ввода (0 - Случайный выбор, 1 - Пользовательский ввод): ";
    std::cin >> choise;

    if (choise != 0 && choise != 1) {
        std::cout << "Такого действия не существует" << std::endl;
        return 0;
    }

    std::cout << "Введите количество элементов (до 100): ";
    std::cin >> n;
    std::cout << "Введите делитель M: ";
    std::cin >> M;
    std::cout << "Введите остаток L: ";
    std::cin >> L;

    if (choise == 0) {
        vvodRand(arr, n);
        std::cout << "\nСгенерированный массив:\n";
    }
    else {
        vvod(arr, n);
        std::cout << "\nВведенный массив:\n";
    }

    vivodClear(arr, n);
    vivod(arr, n, M, L);

    return 0;
}