#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int arr[3][3] = {
		{0,0,0},
		{0,0,0},
		{0,0,0}
	};
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[j][i] << endl;
		}
	}
	return 0;
}