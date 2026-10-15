#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Сколько элементов в массиве: ";
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) {
        cout << "Вводите числа массива: ";
        cin >> a[i];
    }

    int x;
    cout << "Введите искомое число: ";
    cin >> x;
    int mesto = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            mesto = i;
            break;
        }
    }

    cout << "Число находится на " << mesto << " месте";
}
