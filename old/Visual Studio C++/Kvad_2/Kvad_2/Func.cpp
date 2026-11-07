#include "Kvad.h"

int* arr = new int[50];

int view_main(int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "Число [" << i + 1 << "]: ";
		std::cin >> arr[i];
	}
	system("cls");
	return view_second(n);
}

int view_second(int n) {
	std::cout << std::endl;
	std::cout << "\tТаблица квадратных чисел\n";
	std::cout << std::endl;
	std::cout << "Числа \t\t\tКвадрат числа\n";
	std::cout << "------\t\t\t-------------\n";
	std::cout << std::endl;
	return funckvad(n);
}

int funckvad(int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << "\t\t\t" << arr[i] * arr[i] << std::endl;
	}
	return 0;
}