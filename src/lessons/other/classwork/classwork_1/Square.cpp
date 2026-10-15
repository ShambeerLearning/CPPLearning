#include <iostream>
#include <cmath>
using namespace std;

int SearchSquare(int, int, int);
bool isTriangle(int, int, int);

int main() {
	setlocale(LC_ALL, "ru");
	int a, b, c, d;
	cout << "Вводите стороны: " << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;


}

bool isTriangle(int a, int b, int c) {
	if (a < b + c) {
		return true;
	}
	else if (b < a + c) {
		return true;
	} 
	else if (c < a + b) {
		return true;
	}
	else {
		return false;
	}
}

int SearchSquare(int a, int b, int c) {
	int p = (a + b + c) / 2;
	int S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}