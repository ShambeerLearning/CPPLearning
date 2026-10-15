#include <iostream>
#include <ctime>
#include <iomanip>

// Ввод 
void InputArray(int arr[][100], int n, int m) {
    std::cout << "Введите " << n << " строк: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Введите " << m << " колонок: " << std::endl;
        for (int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
        }
    }
}

// Случайный ввод с отрицательными числами
void InputRandArray(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 201 - 100;
        }
    }
}

// Вывод массива
void OutputArray(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(4) << arr[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int MaxNumber(int arr[][100], int n, int m) {
    int max = arr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    const int rows = 100;
    const int columns = 100;
    int a[rows][columns];
    int n = 0, m = 0, choise = 0;

    std::cout << "Случайный ввод - 0, пользовательский ввод - 1: ";
    std::cin >> choise;
    if (choise == 0) {
        std::cout << "Введите количество строк - ";
        std::cin >> n;
        std::cout << "Введите количество строк - ";
        std::cin >> m;
        InputRandArray(a, n, m);
        std::cout << std::endl << "Результат: " << std::endl;
        OutputArray(a, n, m);
        std::cout << std::endl << "Максимальное число: " << MaxNumber(a, n, m) << std::endl;
    }
    else if (choise == 1) {
        std::cout << "Введите количество строк - ";
        std::cin >> n;
        std::cout << "Введите количество строк - ";
        std::cin >> m;
        InputArray(a, n, m);
        std::cout << std::endl << "Результат: " << std::endl;
        OutputArray(a, n, m);
        std::cout << std::endl << "Максимальное число: " << MaxNumber(a, n, m) << std::endl;
    }
    else {
        std::cout << std::endl << "Error!" << std::endl;
    }
    return 0;
}
