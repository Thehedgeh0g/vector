//
// Created by flipd on 08.03.2024.
//
#include "ProcessVector.h"
#include <vector>
#include <algorithm>
#include <numeric>

double FindPositiveMean(const std::vector<double>& vec)
{
    double sum = std::accumulate(vec.begin(), vec.end(), 0.0, [](double acc, double val) {
        return val > 0 ? acc + val : acc;
    });

    size_t count = std::count_if(vec.begin(), vec.end(), [](double val) {
        return val > 0;
    });

    return (count > 0) ? sum / count : 0.0;
}

void ProcessVector(std::vector<double>& vec)
{
    double positiveMean = FindPositiveMean(vec);

    std::transform(vec.begin(), vec.end(), vec.begin(), [positiveMean](double val) {
        return val + positiveMean;
    });
}
