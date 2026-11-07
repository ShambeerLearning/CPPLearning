#include "iostream"
using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    bool arr[3][3] = {
            {0,0,0},
            {0,0,0},
            {0,0,0}
    };
    short int b = 0, a;

    srand(time(0));

    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 3; i++)
        {
            arr[j][i] = rand() % 2;
        }
    }

    cout << "Hello player, to complete the game you need to collect all 1" << endl << endl;

    while (true) {

        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 3; i++) {
                if (b % 3 == 0) { cout << endl; }
                b++;
                cout << arr[j][i];
            }
        }

        cout << endl << endl << "Enter the element you want to change from 1 to 9:" << endl;
        cin >> a;

        switch (a) {
            case 1:
                (arr[0][0] == 0) ? arr[0][0] = 1 : arr[0][0] = 0;
                (arr[0][1] == 0) ? arr[0][1] = 1 : arr[0][1] = 0;
                (arr[1][0] == 0) ? arr[1][0] = 1 : arr[1][0] = 0;
                break;
            case 2:
                (arr[0][0] == 0) ? arr[0][0] = 1 : arr[0][0] = 0;
                (arr[0][1] == 0) ? arr[0][1] = 1 : arr[0][1] = 0;
                (arr[0][2] == 0) ? arr[0][2] = 1 : arr[0][2] = 0;
                (arr[1][1] == 0) ? arr[1][1] = 1 : arr[1][1] = 0;
                break;
            case 3:
                (arr[0][2] == 0) ? arr[0][2] = 1 : arr[0][2] = 0;
                (arr[0][1] == 0) ? arr[0][1] = 1 : arr[0][1] = 0;
                (arr[1][2] == 0) ? arr[1][2] = 1 : arr[1][2] = 0;
        }
        system("cls");
        cout << endl;
    }
    system("pause");
}
