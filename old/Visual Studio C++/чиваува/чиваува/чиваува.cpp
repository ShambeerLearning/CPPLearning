#include <iostream>
using namespace std;
int random() {
	int start = 0;
	int end = 1;
	int x = rand() % (end - start + 1) + start;
	return x;
}
int main() {
	setlocale(LC_ALL, "ru");
	int arr[] = { 0,0,0,0,0,0,0,0,0 };
	int b = 0;
	int vvod;
	for (int g = 0; g < 9; g++) {
		arr[g] = random();
	}
	cout << endl;
	cout << "Привет игрок, цель игры превратить все 0 в 1, управление цифрами, удачи" << endl;
	cout << endl;
	while (true)
	{
		cout << "Введите элемент, который хотите изменить от 0 до 8:" << endl;
		cin >> vvod;
		if (arr[vvod] == 0)
		{
			arr[vvod] = 1;
		}
		else if (arr[vvod] == 1)
		{
			arr[vvod] = 0;
		}
		if (vvod == 0)
		{
			if (arr[1] == 0)
			{
				arr[1] = 1;
			}
			else if (arr[1] == 1)
			{
				arr[1] = 0;
			}
			if (arr[3] == 0)
			{
				arr[3] = 1;
			}
			else if (arr[3] == 1)
			{
				arr[3] = 0;
			}
		}
		else if (vvod == 1)
		{
			if (arr[0] == 0)
			{
				arr[0] = 1;
			}
			else if (arr[0] == 1)
			{
				arr[0] = 0;
			}
			if (arr[2] == 0)
			{
				arr[2] = 1;
			}
			else if (arr[2] == 1)
			{
				arr[2] = 0;
			}
			if (arr[4] == 0)
			{
				arr[4] = 1;
			}
			else if (arr[4] == 1)
			{
				arr[4] = 0;
			}
		}
		else if (vvod == 2)
		{
			if (arr[1] == 0)
			{
				arr[1] = 1;
			}
			else if (arr[1] == 1)
			{
				arr[1] = 0;
			}
			if (arr[5] == 0)
			{
				arr[5] = 1;
			}
			else if (arr[5] == 1)
			{
				arr[5] = 0;
			}
		}
		else if (vvod == 3)
		{
			if (arr[0] == 0)
			{
				arr[0] = 1;
			}
			else if (arr[0] == 1)
			{
				arr[0] = 0;
			}
			if (arr[4] == 0)
			{
				arr[4] = 1;
			}
			else if (arr[4] == 1)
			{
				arr[4] = 0;
			}
			if (arr[6] == 0)
			{
				arr[6] = 1;
			}
			else if (arr[6] == 1)
			{
				arr[6] = 0;
			}
		}
		else if (vvod == 4)
		{
			if (arr[1] == 0)
			{
				arr[1] = 1;
			}
			else if (arr[1] == 1)
			{
				arr[1] = 0;
			}
			if (arr[3] == 0)
			{
				arr[3] = 1;
			}
			else if (arr[3] == 1)
			{
				arr[3] = 0;
			}
			if (arr[5] == 0)
			{
				arr[5] = 1;
			}
			else if (arr[5] == 1)
			{
				arr[5] = 0;
			}
			if (arr[7] == 0)
			{
				arr[7] = 1;
			}
			else if (arr[7] == 1)
			{
				arr[7] = 0;
			}
		}
		else if (vvod == 5)
		{
			if (arr[2] == 0)
			{
				arr[2] = 1;
			}
			else if (arr[2] == 1)
			{
				arr[2] = 0;
			}
			if (arr[4] == 0)
			{
				arr[4] = 1;
			}
			else if (arr[4] == 1)
			{
				arr[4] = 0;
			}
			if (arr[8] == 0)
			{
				arr[8] = 1;
			}
			else if (arr[8] == 1)
			{
				arr[8] = 0;
			}
		}
		else if (vvod == 6)
		{
			if (arr[3] == 0)
			{
				arr[3] = 1;
			}
			else if (arr[3] == 1)
			{
				arr[3] = 0;
			}
			if (arr[7] == 0)
			{
				arr[7] = 1;
			}
			else if (arr[7] == 1)
			{
				arr[7] = 0;
			}
		}
		else if (vvod == 7)
		{
			if (arr[6] == 0)
			{
				arr[6] = 1;
			}
			else if (arr[6] == 1)
			{
				arr[6] = 0;
			}
			if (arr[4] == 0)
			{
				arr[4] = 1;
			}
			else if (arr[4] == 1)
			{
				arr[4] = 0;
			}
			if (arr[8] == 0)
			{
				arr[8] = 1;
			}
			else if (arr[8] == 1)
			{
				arr[8] = 0;
			}
		}
		else if (vvod == 8)
		{
			if (arr[7] == 0)
			{
				arr[7] = 1;
			}
			else if (arr[7] == 1)
			{
				arr[7] = 0;
			}
			if (arr[5] == 0)
			{
				arr[5] = 1;
			}
			else if (arr[5] == 1)
			{
				arr[5] = 0;
			}
		}
		for (int a = 0; a < 9; a++) {
			if (b % 3 == 0) cout << endl;
			b++;
			cout << arr[a];
		}
		cout << endl;
		cout << endl;
		if (arr[0] == 1 && arr[1] == 1 && arr[2] == 1 && arr[3] == 1 && arr[4] == 1 && arr[5] == 1 && arr[6] == 1 && arr[7] == 1 && arr[8] == 1)
		{
			cout << endl;
			cout << "ПОЗДРАВЛЯЮ С ПОБЕДОЙ!!!!, А ТЕПЕРЬ ИДИ НАХУУУУУУУУУУУЙ" << endl;
			cout << endl;
			break;
		}
	}
}