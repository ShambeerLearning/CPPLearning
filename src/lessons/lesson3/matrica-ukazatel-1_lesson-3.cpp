#include <iostream>

int main()
{
    int n, m, i;
    int** mas; //указатель на указатель типа int
    std::cin >> n; //Кол-во строк
    std::cin >> m;
    mas = new int*[n]; // выделяем память под n указателей на строки
    for (i = 0; i < n; i++){
        mas[i] = new int[m]; //Выделяется память для каждой строки
    }
    for (i = 0; i < n; i ++)
    {
        delete []mas[i];
    }
    delete []mas;

}