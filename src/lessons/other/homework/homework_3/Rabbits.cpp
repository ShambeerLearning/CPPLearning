#include <iostream>

int Rabbits(int a, int b, int count) {
	count++;
	if (count != 12) {
		b = a - b;
		std::cout << a << std::endl;
		Rabbits(a + b, b, count);
	}
	else {
		return a;
	}
}

int main() {
	std::cout << Rabbits(1, 1, 0) << std::endl;
	return 0;
}