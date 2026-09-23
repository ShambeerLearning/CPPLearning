#include <iostream>
#include <ctime>
#include <iomanip>

// Ввод 
void InputArray(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        std::cout << "Введите элементы " << i + 1 << "-й строки (" << m << " шт.): ";
        for (int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
        }
    }
}

// Случайный ввод
void InputRandArray(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 201 - 100;
        }
    }
}

// Вывод двумерного массива
void OutputArray(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(5) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Вывод одномерного массива
void OutputOneArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Функция поиска и записи столбца в массив resultArr
void FindMinColumn(int arr[][100], int n, int m, int resultArr[]) {
    int minSum = 0;
    for (int i = 0; i < n; i++) {
        minSum += arr[i][0];
    }
    int minColIndex = 0;

    for (int j = 1; j < m; j++) {
        int currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum += arr[i][j];
        }

        if (currentSum < minSum) {
            minSum = currentSum;
            minColIndex = j;
        }
    }

    std::cout << "Минимальная сумма в столбце " << minColIndex << ": " << minSum << std::endl;

    // Записываем элементы найденного столбца в отдельный массив
    for (int i = 0; i < n; i++) {
        resultArr[i] = arr[i][minColIndex];
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    const int maxRows = 100;
    const int maxCols = 100;
    int arr[maxRows][maxCols];
    int result[maxRows];
    int n, m, choice;

    std::cout << "Случайный ввод - 0, пользовательский ввод - 1: ";
    std::cin >> choice;

    std::cout << "Введите количество строк: ";
    std::cin >> n;
    std::cout << "Введите количество колонок: ";
    std::cin >> m;

    if (choice == 0) {
        InputRandArray(arr, n, m);
    }
    else {
        InputArray(arr, n, m);
    }

    std::cout << std::endl << "Матрица:" << std::endl;
    OutputArray(arr, n, m);

    std::cout << std::endl << "Результат:" << std::endl;
    FindMinColumn(arr, n, m, result);

    std::cout << "Элементы этого столбца из нового массива: ";
    OutputOneArray(result, n);

    return 0;
}
