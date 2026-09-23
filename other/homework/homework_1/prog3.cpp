#include <iostream>
#include <cmath>
using namespace std;

double SearchSquare(double, double, double);
bool isTriangle(double, double, double);
void SearchAndCheck(double, double, double);

int main() {
	system("chcp 65001 > nul");
	setlocale(LC_ALL, "ru_RU.UTF-8");
	double a, b, c, d;
	cout << "Вводите стороны: " << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	SearchAndCheck(a, b, c);
	SearchAndCheck(a, b, d);
	SearchAndCheck(a, c, d);
	SearchAndCheck(b, c, d);

	cout << endl;
	system("pause");
	return 0;
}

bool isTriangle(double a, double b, double c) {
	if ((a < b + c) && (b < a + c) && (c < a + b)) {
		return true;
	}
	else {
		return false;
	}
}

double SearchSquare(double a, double b, double c) {
	double p = (a + b + c) / 2.0;
	double S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}

void SearchAndCheck(double a, double b, double c) {
	if (isTriangle(a, b, c)) {
		cout << endl << "Площадь треугольника со сторонами: " << a << "; " << b << "; " << c << "; равняется: " << SearchSquare(a, b, c) << endl;
	}
	else {
		cout << endl << "Треугольник со сторонами: " << a << " " << b << " " << c << " не существует" << endl;
	}
}