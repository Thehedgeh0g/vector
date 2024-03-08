#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "ProcessVector/ProcessVector.h"

std::vector<double> ReadVector()
{
    std::vector<double> vec;
    double num;
    std::cout << "Введите элементы вектора (разделяйте пробелами, для завершения введите нечисловой символ): ";

    while (std::cin >> num)
    {
        vec.push_back(num);
    }

    return vec;
}


void PrintVector(const std::vector<double>& vec)
{
    for (const auto &num: vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<double> vec = ReadVector();

    ProcessVector(vec);

    std::cout << "Результат обработки вектора: ";
    PrintVector(vec);

    return 0;
}
