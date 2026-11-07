#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	short int b = 0, vvod, f = 0;
	bool arr[9]{};

	srand(time(0));

	for (short int g = 0; g < 9; g++) {
		arr[g] = rand() % 2;
	}

	cout << "Привет игрок, цель игры превратить все 0 в 1, управление цифрами, удачи" << endl;

	while (true)
	{
		for (short int a = 0; a < 9; a++) {
			if (b % 3 == 0) cout << endl;
			b++;
			cout << arr[a];
		}

		cout << endl << endl << "Введите элемент, который хотите изменить от 0 до 8:" << endl;
		cin >> vvod;

		if (vvod > -1 && vvod < 9)
		{
			(arr[vvod] == 0) ? arr[vvod] = 1 : arr[vvod] = 0;

			switch (vvod)
			{
			case 0:
				(arr[1] == 0) ? arr[1] = 1 : arr[1] = 0;
				(arr[3] == 0) ? arr[3] = 1 : arr[3] = 0;
				break;
			case 1:
				(arr[0] == 0) ? arr[0] = 1 : arr[0] = 0;
				(arr[2] == 0) ? arr[2] = 1 : arr[2] = 0;
				(arr[4] == 0) ? arr[4] = 1 : arr[4] = 0;
				break;
			case 2:
				(arr[1] == 0) ? arr[1] = 1 : arr[1] = 0;
				(arr[5] == 0) ? arr[5] = 1 : arr[5] = 0;
				break;
			case 3:
				(arr[0] == 0) ? arr[0] = 1 : arr[0] = 0;
				(arr[4] == 0) ? arr[4] = 1 : arr[4] = 0;
				(arr[6] == 0) ? arr[6] = 1 : arr[6] = 0;
				break;
			case 4:
				(arr[1] == 0) ? arr[1] = 1 : arr[1] = 0;
				(arr[3] == 0) ? arr[3] = 1 : arr[3] = 0;
				(arr[5] == 0) ? arr[5] = 1 : arr[5] = 0;
				(arr[7] == 0) ? arr[7] = 1 : arr[7] = 0;
				break;
			case 5:
				(arr[2] == 0) ? arr[2] = 1 : arr[2] = 0;
				(arr[4] == 0) ? arr[4] = 1 : arr[4] = 0;
				(arr[8] == 0) ? arr[8] = 1 : arr[8] = 0;
				break;
			case 6:
				(arr[3] == 0) ? arr[3] = 1 : arr[3] = 0;
				(arr[7] == 0) ? arr[7] = 1 : arr[7] = 0;
				break;
			case 7:
				(arr[4] == 0) ? arr[4] = 1 : arr[4] = 0;
				(arr[6] == 0) ? arr[6] = 1 : arr[6] = 0;
				(arr[8] == 0) ? arr[8] = 1 : arr[8] = 0;
				break;
			case 8:
				(arr[7] == 0) ? arr[7] = 1 : arr[7] = 0;
				(arr[5] == 0) ? arr[5] = 1 : arr[5] = 0;
				break;
			}
			system("cls");

			if (arr[0] == 1 && arr[1] == 1 && arr[2] == 1 && arr[3] == 1 && arr[4] == 1 && arr[5] == 1 && arr[6] == 1 && arr[7] == 1 && arr[8] == 1)
			{
				cout << endl << "ПОЗДРАВЛЯЮ С ПОБЕДОЙ!!!!" << endl << endl;
				break;
			}
		}
		else
		{
			cout << endl << "Я СКАЗАЛ ОТ 0 ДО 8, ДАВАЙ ТЕПЕРЬ ПО НОВОЙ))))))" << endl << endl;
			return 0;
		}
	}
	system("pause");
}