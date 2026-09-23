#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для ручного ввода
void vvod(int m[], int n) {
    cout << "Введите " << n << " элементов: ";
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
}

// Функция для случайного заполнения
void vvodRand(int m[], int n) {
    for (int i = 0; i < n; i++) {
        m[i] = rand() % 100; // Случайные числа от 0 до 99
    }
}

// Функция для заполнения по порядку (1, 2, 3... N)
void vvodSeq(int m[], int n) {
    for (int i = 0; i < n; i++) {
        m[i] = i + 1;
    }
}

// Функция для вывода массива на экран
void vivod(int m[], int n) {
    for (int i = 0; i < n; i++) {
        cout << m[i] << " ";
    }
    cout << endl;
}

// Функция для переворота части массива на отрезке [start, end]
void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0)); 

    int choise, N, A, B, C, D;
    int Chis[10000]; // Массив с запасом

    cout << "Выберите метод ввода (0 - Случайный выбор, 1 - Ручной ввод, 2 - По порядку (1..N)): ";
    if (!(cin >> choise)) return 0;

    cout << "Введите количество элементов (N): ";
    cin >> N;

    if (N <= 0) {
        cout << "Массив пуст или введено неверное количество элементов." << endl;
        return 0;
    }

    // Заполнение массива
    if (choise == 0) {
        vvodRand(Chis, N);
    }
    else if (choise == 1) {
        vvod(Chis, N);
    }
    else if (choise == 2) {
        vvodSeq(Chis, N);
    }
    else {
        cout << "Такого действия не существует" << endl;
        return 0;
    }

    cout << "\nИсходный массив:\n";
    vivod(Chis, N);

    // Запрос границ отрезков
    cout << "\nВведите границы первого отрезка (A B): ";
    cin >> A >> B;
    
    cout << "Введите границы второго отрезка (C D): ";
    cin >> C >> D;

    // Выполняем переворот отрезков (сдвигаем индексы на -1, так как они нумеруются с 0)
    // Проверяем, чтобы индексы не вышли за границы массива
    if (A >= 1 && B <= N && A <= B) {
        reverseArray(Chis, A - 1, B - 1);
    }
    
    if (C >= 1 && D <= N && C <= D) {
        reverseArray(Chis, C - 1, D - 1);
    }

    cout << "\nМассив после переворота отрезков:\n";
    vivod(Chis, N);

    return 0;
}
