#include <iostream>
#include <cstring>
#include "Windows.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 100;
    char UserInp[N] = "";
    char CurrentWord[N] = "";
    char MaxWord[N] = "";

    std::cin.getline(UserInp, N);

    int wordIdx = 0;
    int currentCount = 0;
    int maxCount = -1;

    for (int i = 0; i <= strlen(UserInp); i++) {
        if (UserInp[i] == ' ' || UserInp[i] == '\0') {
            CurrentWord[wordIdx] = '\0';

            if (currentCount > maxCount) {
                maxCount = currentCount;
                strcpy_s(MaxWord, CurrentWord);
            }

            wordIdx = 0;
            currentCount = 0;
        }
        else {
            CurrentWord[wordIdx++] = UserInp[i];
            if (UserInp[i] == 'а' || UserInp[i] == 'А') {
                currentCount++;
            }
        }
    }

    std::cout << MaxWord << std::endl;
    return 0;
}
