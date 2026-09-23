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

// Функция для вывода массива на экран
void vivod(int m[], int n) {
    for (int i = 0; i < n; i++) {
        cout << m[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0)); // Инициализация генератора случайных чисел
    
    int choise, n;
    int m[10000]; // Создаем массив с запасом
    
    cout << "Выберите метод ввода (0 - Случайный выбор, 1 - Пользовательский ввод): ";
    cin >> choise;
    
    if (choise == 0) {
        cout << "Введите количество элементов: ";
        cin >> n;
        
        vvodRand(m, n); // Передаем массив и размер
        
        cout << "\nСгенерированный массив:\n";
        vivod(m, n);
    }
    else if (choise == 1) {
        cout << "Введите количество элементов: ";
        cin >> n;
        
        vvod(m, n); // Передаем массив и размер
        
        cout << "\nВведенный массив:\n";
        vivod(m, n);
    }
    else {
        cout << "Такого действия не существует" << endl;
    }
    
    return 0;
}
