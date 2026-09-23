#include <iostream>

int count = 0;

int Fib(int n) {
	count++;
	if (n == 1 || n == 0) {
		return 1;
	}
	else {
		return Fib(n - 1) + Fib(n - 2);
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int inp;
	std::cout << "Введите число - ";
	std::cin >> inp;
	std::cout << "Итог работы функции - " << Fib(inp - 1) << std::endl;
	std::cout << "Количество вызов - " << count << std::endl;
	return 0;
}