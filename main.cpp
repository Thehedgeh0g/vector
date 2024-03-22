#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include "ProcessVector/ProcessVector.h"

std::vector<double> ReadVector()
{
    std::vector<double> vec;
    std::string numString;
    std::cout << "Введите элементы вектора: ";
    while (std::getline(std::cin, numString, ' ')) {
        vec.push_back(std::stof(numString));
    }

    return vec;
}

void PrintVector(std::vector<double>& vec)
{
    std::sort(vec.begin(), vec.end());
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
