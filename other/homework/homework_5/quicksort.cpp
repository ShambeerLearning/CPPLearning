#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    // Базовый случай рекурсии: если в отрезке 1 элемент или меньше, выходим
    if (low >= high) return; 
    
    int pivot = arr[(low + high) / 2]; // Выбор опорного элемента (середина)
    int i = low; 
    int j = high; 
    
    // Главный цикл разделения массива
    while (i <= j) { 
        while (arr[i] < pivot) i++; // Ищем элемент слева, который нужно перекинуть вправо
        while (arr[j] > pivot) j--; // Ищем элемент справа, который нужно перекинуть влево
        
        // Если нашли два "заблудившихся" элемента, меняем их местами
        if (i <= j) { 
            swap(arr[i], arr[j]); 
            i++; 
            j--; 
        }
    }
    
    // Рекурсивный вызов для левой и правой частей
    if (low < j) quickSort(arr, low, j); 
    if (i < high) quickSort(arr, i, high); 
}

int main() {
    const int MAX = 100; // Лимит массива
    int arr[MAX];
    int n = 0; // Счетчик реального количества чисел
    int input;
    
    cout << "Вводите числа (0 для завершения ввода):\n";
    
    // Цикл ввода данных
    while (true) {
        cin >> input;
        if (input == 0) break;    // 0 — сигнал к остановке ввода
        arr[n] = input;           // Сохраняем число
        n++;
        
        if (n >= MAX) {           // Защита от переполнения
            cout << "Достигнут максимум (" << MAX << " элементов)\n";
            break;
        }
    }
    
    if (n == 0) {
        cout << "Массив пуст.\n";
        return 0;
    }
    
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    // Вызов функции сортировки для всего массива (от 0 до n-1)
    quickSort(arr, 0, n - 1);
    
    cout << "Отсортированный: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}