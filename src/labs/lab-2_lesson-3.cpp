#include <iostream>
#include <ctime>

int** createArray(int n, int m) {
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    return arr;
}

void fillArray(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void printArray(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

int** deleteRowAndColumn(int** mas, int n, int m, int del_row, int del_col) {
    int new_n = n - 1;
    int new_m = m - 1;

    int** new_mas = createArray(new_n, new_m);

    int new_i = 0;
    for (int i = 0; i < n; i++) {
        if (i == del_row) {
            continue;
        }
        int new_j = 0;
        for (int j = 0; j < m; j++) {
            if (j == del_col) {
                continue;
            }
            new_mas[new_i][new_j] = mas[i][j];
            new_j++;
        }
        new_i++;
    }
    return new_mas;
}

void freeArray(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int n, m;
    std::cout << "Enter the number of rows and columns (separated by space): ";
    std::cin >> n >> m;

    int** mas = createArray(n, m);

    srand(time(0));
    fillArray(mas, n, m);

    std::cout << "Generated original array:\n";
    printArray(mas, n, m);

    int del_row, del_col;
    std::cout << "Enter the number of the row to delete (starting from 0): ";
    std::cin >> del_row;
    std::cout << "Enter the number of the column to delete (starting from 0): ";
    std::cin >> del_col;

    int** new_mas = deleteRowAndColumn(mas, n, m, del_row, del_col);

    std::cout << "Final array after deletion:\n";
    printArray(new_mas, n - 1, m - 1);

    freeArray(mas, n);
    freeArray(new_mas, n - 1);

    return 0;
}