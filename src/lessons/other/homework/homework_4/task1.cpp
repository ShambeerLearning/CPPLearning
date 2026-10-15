#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    cout << "Введите количество учеников присутствующих на уроке: ";
    cin >> n;

    int rost[10000];
    for (int i = 0; i < n; i++) {
        cout << "Введите рост ученика " << i + 1 << ": ";
        cin >> rost[i];
        if (rost[i] > 200) {
            cout << "Введите другое число" << endl;
            return 0;
        }
        else if (rost[i] <= 0) {
            cout << "Рост не может быть отрицательным" << endl;
            return 0;
        }
    }

    int R;
    cout << "Введите рост Пети: " << endl;
    cin >> R;

    if (R > 200 || R <= 0) {
        cout << "Некорректный рост Пети" << endl;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (rost[j] < rost[j + 1]) {
                int temp = rost[j];
                rost[j] = rost[j + 1];
                rost[j + 1] = temp;
            }
        }
    }

    int position = n + 1;
    for (int i = 0; i < n; i++) {
        if (R > rost[i]) {
            position = i + 1;
            break;
        }
    }

    cout << " Шеренга учеников: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "-е место: " << rost[i] << endl;
    }

    cout << " Рост Пети: " << R << endl;
    cout << " Петя должен быть на " << position << "-м месте" << endl;

    return 0;
}