//
// Created by flipd on 08.03.2024.
//
#include "ProcessVector.h"
#include <vector>
#include <algorithm>
#include <numeric>

double FindPositiveMean(const std::vector<double>& vec) {
    // Используем std::accumulate для нахождения суммы положительных элементов
    double sum = std::accumulate(vec.begin(), vec.end(), 0.0, [](double acc, double val) {
        return val > 0 ? acc + val : acc;
    });

    // Используем std::count_if для подсчета положительных элементов
    size_t count = std::count_if(vec.begin(), vec.end(), [](double val) {
        return val > 0;
    });

    // Находим среднее арифметическое (если есть положительные элементы)
    return (count > 0) ? sum / count : 0.0;
}

// Функция для обработки вектора (прибавление среднего арифметического положительных элементов)
void ProcessVector(std::vector<double>& vec) {
    double positiveMean = FindPositiveMean(vec);

    // Прибавляем среднее арифметическое положительных элементов к каждому элементу вектора
    std::transform(vec.begin(), vec.end(), vec.begin(), [positiveMean](double val) {
        return val + positiveMean;
    });
}
