#include <iostream>
#include "conio.h"
#include "Windows.h"
#include "Adolf.h"
#include "string.h"
#include <string>
#include <ctime>

#pragma warning(disable : 4996) 

int main()
{
	setlocale(LC_ALL, "ru");
	std::string text1;
	int chas, min, sec, i = 0;
	int button = '1';
	int count = 0;

	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);

    chas = min = sec = 0;
	int index = 0;
	int nowTime[10][3];


	std::cout << "Введите s чтобы отсосать хуй, чтобы сбросить счётчик отсасываний нажмите f " << std::endl;

	while (true)
	{
		Sleep(1000);
		if (_kbhit())\
		{
			button = _getch();
		}

		switch (button)
		{
		case'f':
		case'F':
			count = 0;
			break;
		case 's':
		case 'S':
			setCursorPosition(0, 5);
			std::cout << "Я ОТСОСАЛ ХУЙ";
			count++;
			std::cout << " ";
			chas = min = sec = 0;

			t = std::time(nullptr);
			now = std::localtime(&t);

			/*for (int g = 5; g > 0; g--)
			{
				if (g <= 0) break;

				if (nowTime[g-1][0] != NULL) {
					int hourHolder, minHolder, secHolder;

					/*hourHolder = nowTime[g - 1][0];
					minHolder = nowTime[g-1][1];
					secHolder = nowTime[g-1][2];

					if (g - 1 >= 0) {
						nowTime[g][0] = hourHolder;
						nowTime[g][1] = minHolder;
						nowTime[g][2] = secHolder;
					}
				}
			}*/
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
		setCursorPosition(0, 2); std::cout << "                                                    ";
		setCursorPosition(0, 2); std::cout << "Время без насасывания " << chas << ':' << min << ':' << sec;
		setCursorPosition(0, 3); std::cout << "                                                    ";
		setCursorPosition(0, 3); std::cout << "Количество насасываний - " << count;

		for (int i = 0; i < index; i++)
		{
			if (index > 10) { index = 10; break; }
			setCursorPosition(0, 7+i);
		}
		
	}
	std::system("pause");
}