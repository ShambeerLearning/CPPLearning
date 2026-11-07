#include <iostream>
#include <string>
#include "windows.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	string fraza = "И мы захватим серый Питер, надрочим ему пиписьки, я на члене извините, подрочите, отососите мнеееееее, каким бы не был большой хуй, знаю куда его сувать и куда ногу пихнуть. Гей гей я на члене и выебал, который гей я не заметил, на неграх двух и мне навстречу большой, мне кончил пидор, хоть и говорили все тут, что я не буду в сперме ";
	for (int i = 0; i < fraza.size(); i++)
	{
		for (int gamas = 0; gamas < i; gamas++)
		{
			cout << fraza[gamas];
			Sleep(2);
		}
		cout << endl;
	}
	system("pause");
}