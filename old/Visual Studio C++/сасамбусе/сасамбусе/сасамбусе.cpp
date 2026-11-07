#include <iostream>
#include "conio.h"
#include "Windows.h"
#include "Adolf.h"
int main()
{
	setlocale(LC_ALL, "ru");
	int chas, min, sec;
	int botton = '1';
	int count = 0;

	chas = min = sec = 0;


	std::cout << "Введите s чтобы отсосать хуй " << std::endl;

	while (true)
	{
		Sleep(1000);
		if (_kbhit())\
		{
			botton = _getch();
		}

		switch (botton)
		{
		case 's':
		case 'S':
			setCursorPosition(0, 5);
			std::cout << "Я ОТСОСАЛ ХУЙ";
			count++;
			std::cout << " ";
			chas = min = sec = 0;
			botton = '1';
			break;
		default:
			setCursorPosition(0, 5); std::cout << "                                                    ";
		}
		sec++;

		while (min > 60 || sec > 60 || chas > 24)
		{
			min += SecMin(sec);
			sec = Sec(sec);

			chas += MinChas(min);
			min = Min(min);
		}
		setCursorPosition(0, 2); std::cout << "                                                    ";
		setCursorPosition(0, 2); std::cout << "Время без насасывания " << chas << ':' << min << ':' << sec;
		setCursorPosition(0, 3); std::cout << "                                                    ";
		setCursorPosition(0, 3); std::cout << "Количество насасываний - " << count;
	}
	std::system("pause");
}