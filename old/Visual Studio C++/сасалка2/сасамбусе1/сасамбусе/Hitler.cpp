#include <iostream>
#include "Windows.h"
#include "Adolf.h"
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

void setCursorPosition(int x, int y)
{
	COORD position = { x,y }; //позиция x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

int Chas(int a)
{
	return a % 24;
}
int Min(int a)
{
	return a % 60;
}
int Sec(int a)
{
	return a % 60;
}
int MinChas(int a)
{
	return a / 60;
}
int SecMin(int a)
{
	return a / 60;
}

void vvod()
{
	char l;

	DisplayText(0, 0, "Если хотите удалить старый файл нажмите x + Enter, если же его нет или нет желания удалять, то нажмите любую кнопку");
	DisplayText(0, 1, "Сюда вводить - "); std::cin >> l;
	ClearText(0, 1, 12);

	switch (l)
	{
	case 'x':
	case 'X':
		Delete();
		DisplayText(0, 2, 1000, "Файл успешно удалён");
		exit(0);
		break;
	}
}
void vivod(std::string text1)
{
	std::string path = "logs.txt";
	std::ofstream logs;
	logs.open(path, std::ofstream::app);
	if (!logs.is_open())
	{
		DisplayText(0, 7, "Ошибка файл не открывается!!!!");
	}
	else
	{
		DisplayText(0, 7, text1);
		logs << text1 << std::endl;
	}
	logs.close();
}
void Delete()
{
	std::string path = "logs.txt";
	std::ofstream logs;
	logs.open(path, std::ofstream::app);
	logs.close();
	std::remove("logs.txt");
}

void DisplayText(int x, int y, int pause, std::string text) // Если нужно сделать паузу перед удалением текста
{
	setCursorPosition(x, y); std::cout << text; 
	Sleep(pause);
	std::cout.width(text.size() + 4);
	setCursorPosition(x, y); std::cout.fill(' '); std::cout << "";
}
void DisplayText(int x, int y, std::string text) // Если нужно просто выводить текст
{
	std::cout.width(text.size() + 4);
	setCursorPosition(x, y); std::cout.fill(' '); std::cout << "";
	setCursorPosition(x, y); std::cout << text;
}
void ClearText(int x, int y, int textSize) // Стереть текст
{
	std::cout.width(textSize + 4);
	setCursorPosition(x, y); std::cout.fill(' '); std::cout << "";
}

std::string RandomMessage()
{
	int randNum;
	std::string Message[] =
	{
		"Я ОТСОСАЛ ХУЙ!!!",
		"О ДА! Я ХУЕГЛОТ!",
		"ОН ТАКОЙ ВКУСНЫЙ!",
		"ПРЯМО КАК У ТВОЕГО ОТЦА",
		"ВКУСНЫЙ МАЙОНЕЗ",
		"У МОЕЙ СОБАКИ БОЛЬШЕ",
		"ТЫ НЕ ТЫ, КОГДА ГОЛОДЕН",
		"ФУ БЛЯ, ВОЛОС",
		"АМ НЯМ НЯМ, КАКАЯ ВКУСНОТИЩА",
		"КТО ХУЙ СУЁТ МНЕ В ГОРЛО?",
		"СКОЛЬКО ХУЙ СМ",
		"МОЖЕТ В ЖОПУ?",
		"У МЕНЯ ГОРЛО ПЕРЕСОХЛО"
	};
	int size = end(Message) - begin(Message);
	int num = 0 + rand() % ((size-1) - 0 + 1);
	return Message[num];
}

bool Pashalka(int a)
{
	switch (a)
	{
	case 1000:
		system("cls");
		for (int i = 0; i < 20; i++)
		{
		Sleep(10);
		DisplayText(5 + i, 5 + i, "ПОЗДРАВЛЯЮ ВЫ ОТСОСАЛИ 1000 РАЗ!!!!!");
		}
		Sleep(3000);
		system("cls");
		return true;
	case 2000:
		system("cls");
		for (int i = 0; i < 20; i++)
		{
			Sleep(10);
			DisplayText(20 - i, 20 - i, "ПОЗДРАВЛЯЮ ВЫ ОТСОСАЛИ 1000 РАЗ!!!!!");
		}
		Sleep(3000);
		system("cls");
		return true;
	case 3000:
		system("cls");
		for (int i = 0; i < 20; i++)
		{
			Sleep(10);
			DisplayText(5 + i, 5 + i, "ПОЗДРАВЛЯЮ ВЫ ОТСОСАЛИ 1000 РАЗ!!!!!");
		}
		Sleep(3000);
		system("cls");
		return true;
	case 4000:
		system("cls");
		for (int i = 0; i < 20; i++)
		{
			Sleep(10);
			DisplayText(20 - i, 20 - i, "ПОЗДРАВЛЯЮ ВЫ ОТСОСАЛИ 1000 РАЗ!!!!!");
		}
		Sleep(3000);
		system("cls");
		return true;
	case 5000:
		system("cls");
		for (int i = 0; i < 20; i++)
		{
			Sleep(10);
			DisplayText(5 + i, 5 + i, "ПОЗДРАВЛЯЮ ВЫ ОТСОСАЛИ 1000 РАЗ!!!!!");
		}
		Sleep(3000);
		system("cls");
		return true;
	}
}

