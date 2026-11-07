#include "stdafx.h"
#include "iostream"
#include "Windows.h"
#include "MyHeader.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Enter size of array: ";
	int size;
	std::cin >> size;

	int *inputArr = new int[size];
	int *squareArr = new int[size];

	std::cout << "Fill arr for square." << std::endl;

	for (int i = 0; i < size; i++)
	{
		int number;
		std::cin >> number;
		inputArr[i] = number;
		squareArr[i] = Square(number);
	}

	std::cout << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << i << ") " << inputArr[i] << " -> " << squareArr[i] << std::endl;
	}


	system("pause");
}

