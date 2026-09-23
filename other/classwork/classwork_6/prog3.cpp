#include <iostream>
#include <cstring>

int main()
{
    const int N = 10;
    char s[N];
    while (std::cin.getline(s, N)) {
        for (int i = 0; i < N - 1; i++) {
            s[i] = s[i + 1];
        }
        std::cout << s << std::endl;
    }
}
