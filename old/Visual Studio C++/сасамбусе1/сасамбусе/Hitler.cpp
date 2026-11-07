#include <iostream>
#include "Windows.h"
#include "Adolf.h"
#include <string>
#include <fstream>
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
void vivod(std::string text1)
{
	std::string path = "logs.txt";
	std::ofstream logs;
	logs.open(path, std::ofstream::app);
	logs << text1 << std::endl;
	logs.close();

}
