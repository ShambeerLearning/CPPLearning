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
            std::cout << std::setw(5) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Diagon(int arr[][100], int n, int m) {
    int max[100];
    int count = 0;
    for (int i = 0; i < n; i++) {
        max[i] = arr[i][0];
        for (int j = 0; j < m; j++) {
            if (max[i] < arr[i][j]) {
                max[i] = arr[i][j];
                count++;
            }
        }
    }
    std::cout << std::endl;
    for (int b = 0; b < count; b++) {
        std::cout << max[b] << " ";
    }
}

void Diagon1(int arr[][100], int n, int m) {
    int min[100];
    int count = 0;
    for (int j = 0; j < m; j++) {
        min[j] = arr[0][j];
        for (int i = 0; i < m; i++) {
            if (min[j] > arr[j][i]) {
                min[j] = arr[j][i];
                count++;
            }
        }
    }
    std::cout << std::endl;
    for (int b = 0; b < count; b++) {
        std::cout << min[b] << " ";
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    const int rows = 100;
    const int columns = 100;
    int arr[rows][columns];
    int n = 0, m = 0, choise = 0;

    std::cout << "Случайный ввод - 0, пользовательский ввод - 1: ";
    std::cin >> choise;
    if (choise == 0) {
        std::cout << "Введите количество строк - ";
        std::cin >> n;
        std::cout << "Введите количество строк - ";
        std::cin >> m;
        InputRandArray(arr, n, m);
        std::cout << std::endl << "Результат: " << std::endl;
        OutputArray(arr, n, m);
        std::cout << std::endl;
        Diagon(arr, n, m);
        Diagon1(arr, n, m);
    }
    else if (choise == 1) {
        std::cout << "Введите количество строк - ";
        std::cin >> n;
        std::cout << "Введите количество строк - ";
        std::cin >> m;
        InputArray(arr, n, m);
        std::cout << std::endl << "Результат: " << std::endl;
        OutputArray(arr, n, m);
        std::cout << std::endl;
        Diagon(arr, n, m);
        Diagon1(arr, n, m);
    }
    else {
        std::cout << std::endl << "Error!" << std::endl;
    }
    return 0;
}
