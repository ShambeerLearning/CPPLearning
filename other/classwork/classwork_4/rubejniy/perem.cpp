#include <iostream>
#include <ctime>

// Ввод 
void Input(int arr[], int n) {
    std::cout << "Введите " << n << " элементов: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

// Случайный ввод с отрицательными числами
void InputRand(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100;
    }
}

// Перестановка элементов: отрицательные в начало, порядок сохранен
void ReorderArray(int arr[], int n) {
    int pos = 0; // Индекс, куда будем ставить следующее отрицательное число
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            int temp = arr[i];
            // Сдвигаем все положительные элементы вправо
            for (int j = i; j > pos; j--) {
                arr[j] = arr[j - 1];
            }
            // Ставим отрицательный элемент на освободившееся место
            arr[pos] = temp;
            pos++;
        }
    }
}

// Вывод массива
void OutputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int arr[100];
    int n, choice;

    std::cout << "Выберите метод (0 - Случайный, 1 - Ручной): ";
    std::cin >> choice;

    if (choice != 0 && choice != 1) return 0;

    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    if (choice == 0) {
        InputRand(arr, n);
    }
    else {
        Input(arr, n);
    }

    std::cout << "\nИсходный массив:\n";
    OutputArray(arr, n);

    ReorderArray(arr, n);

    std::cout << "\nРезультат (отрицательные в начале):\n";
    OutputArray(arr, n);

    return 0;
}
