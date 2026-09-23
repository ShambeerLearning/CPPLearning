#include <iostream>
#include <iomanip>

// Функция заполнения матрицы по спирали
void FillSpiral(int arr[][100], int n) {
    int num = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (num <= n * n) {
        // Вправо по верхней строке
        for (int i = left; i <= right; i++) {
            arr[top][i] = num++;
        }
        top++;

        // Вниз по правому столбцу
        for (int i = top; i <= bottom; i++) {
            arr[i][right] = num++;
        }
        right--;

        // Влево по нижней строке
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                arr[bottom][i] = num++;
            }
            bottom--;
        }

        // Вверх по левому столбцу
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                arr[i][left] = num++;
            }
            left++;
        }
    }
}

// Вывод матрицы
void OutputArray(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(5) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    const int maxRows = 100;
    const int maxCols = 100;
    int arr[maxRows][maxCols];
    int n;

    std::cout << "Введите размер квадратной матрицы n: ";
    std::cin >> n;

    if (n > 100) {
        std::cout << "Размер не может превышать 100" << std::endl;
        return 1;
    }

    FillSpiral(arr, n);

    std::cout << std::endl << "Спиральная матрица:" << std::endl;
    OutputArray(arr, n, n);

    return 0;
}
