#include <iostream>
#include <ctime>

void Input(int arr[], int n) {
    std::cout << "Введите " << n << " элементов: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

void InputRand(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;
    }
}

int createFilteredArray(int source[], int n, int target[], int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (source[i] % 10 == k) {
            target[count] = source[i];
            count++;
        }
    }
    return count;
}

void OutputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int arr[100], resultArr[100];
    int n, choice, k;

    std::cout << "Выберите метод (0 - Случайный, 1 - Ручной): ";
    std::cin >> choice;

    if (choice != 0 && choice != 1) return 0;

    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    std::cout << "Введите цифру k (0-9): ";
    std::cin >> k;

    if (choice == 0) {
        InputRand(arr, n);
    }
    else {
        Input(arr, n);
    }

    int newSize = createFilteredArray(arr, n, resultArr, k);

    std::cout << "\nИсходный массив:\n";
    OutputArray(arr, n);

    std::cout << "\nНовый массив (числа на " << k << "):\n";
    if (newSize > 0) {
        OutputArray(resultArr, newSize);
    }
    else {
        std::cout << "Элементы не найдены." << std::endl;
    }

    return 0;
}
