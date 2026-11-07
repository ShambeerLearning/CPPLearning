#include <iostream>
using namespace std;

int main() {
	int i = 0;
	setlocale(LC_ALL, "ru");
metod:
	cout << "daun" << endl;
	if (i > 10) {
		goto daun;
	}
	i++;
	goto metod;
daun:
	system("pause");
}