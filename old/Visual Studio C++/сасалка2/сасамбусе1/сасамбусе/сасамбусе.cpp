#include <iostream>
#include "conio.h"
#include "Windows.h"
#include "Adolf.h"
#include "string.h"
#include <string>
#include <ctime>
#include <stdlib.h>

#pragma warning(disable : 4996) 

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "ru");
	std::string text1;
	int chas, min, sec, i = 0;
	int button = '1';
	int count = 0;
	char d;

	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);

    chas = min = sec = 0;
	int index = 0;
	int nowTime[10][3];

	vvod();

	ClearText(0, 0, 115);


	while (true)
	{
	DisplayText(0, 0, "Введите s чтобы отсосать хуй, чтобы сбросить счётчик отсасываний нажмите f, e для выхода из программы");
		if (Pashalka(count) == true) count++;
		Sleep(1000);
		if (_kbhit())
		{
			button = _getch();
		}

		switch (button)
		{
		case 'f':
		case 'F':
			count = 0;
			break;
		case 'e':
		case 'E':
			setCursorPosition(0, 9); std::cout << "Нажмите d + Enter если хотите удалить файл при выходе из кликера - ";
			std::cin >> d;
			if (d == 'd')
			{
				Delete();
				DisplayText(0, 11, 1000, "Файл успешно удалён");
				return 0;
				break;
			}
			else
			{
				DisplayText(0, 11, 1000, "Файл успешно сохранён");
				return 0;
				break;
			}
		case 's':
		case 'S':
			ClearText(0, 5, 50);
			DisplayText(0, 5, RandomMessage());
			count++;
			std::cout << " ";
			chas = min = sec = 0;

			t = std::time(nullptr);
			now = std::localtime(&t);

			nowTime[0][0] = now->tm_hour;
			nowTime[0][1] = now->tm_min;
			nowTime[0][2] = now->tm_sec;

			index++;

			text1 = std::to_string(i + 1) + ") Я отсосал хуй в " + std::to_string(nowTime[0][0]) + ':' + std::to_string(nowTime[0][1]) + ':' + std::to_string(nowTime[0][2]) + " .";
			i++;
			vivod(text1);

			setCursorPosition(0, 5);

			button = '1';
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

		std::string timeText = "Время без насасывания " + std::to_string(chas) + ':' + std::to_string(min) + ':' + std::to_string(sec);
		std::string countText = "Количество насасываний - " + std::to_string(count);
		DisplayText(0, 2, timeText);
		DisplayText(0, 3, countText);		

	}
	std::system("pause");
}