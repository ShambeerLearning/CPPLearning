#include <iostream>

void fun(int n, int m, int **matr)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matr[i][j] = k++;
        }
    }
}

int main()
{
    int **pa;
    int n1 = 5, m1 = 6;
    fun(n1, m1, pa);
}