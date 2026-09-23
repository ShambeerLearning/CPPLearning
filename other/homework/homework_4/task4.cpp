#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Глобальный массив, чтобы вместить до 100000 элементов
int a[100005];

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
    srand(time(0)); // Инициализация генератора случайных чисел

    int choise, n, k;

    cout << "Выберите метод ввода (0 - Случайный выбор, 1 - Пользовательский ввод): ";
    if (!(cin >> choise)) return 0;

    cout << "Введите количество элементов: ";
    cin >> n;

    if (n <= 0) {
        cout << "Массив пуст или введено неверное количество элементов." << endl;
        return 0;
    }

    // Заполнение массива в зависимости от выбора пользователя
    if (choise == 0) {
        vvodRand(a, n);
        cout << "Исходный массив:\n";
        vivod(a, n);
    }
    else if (choise == 1) {
        vvod(a, n);
        cout << "Исходный массив:\n";
        vivod(a, n);
    }
    else {
        cout << "Такого действия не существует" << endl;
        return 0;
    }

    // Ввод величины сдвига
    cout << "Введите величину сдвига (K): ";
    cin >> k;

    // Приводим K к положительному сдвигу вправо в пределах от 0 до N-1.
    int actual_k = (k % n + n) % n;

    if (actual_k > 0) {
        // 1. Переворачиваем весь массив
        reverseArray(a, 0, n - 1);
        // 2. Переворачиваем первые K элементов
        reverseArray(a, 0, actual_k - 1);
        // 3. Переворачиваем оставшиеся N - K элементов
        reverseArray(a, actual_k, n - 1);
    }

    // Выводим результат с помощью нашей функции
    cout << "Массив после сдвига на " << k << " позиций:\n";
    vivod(a, n);

    return 0;
}
