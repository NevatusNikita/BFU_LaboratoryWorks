#include "funcs.hpp"
#include <iostream>
#include <cmath>
#include <limits>

void Read(int matrix[N][N], int& n)
{
    std::cout << "Введите размер квадратной матрицы n: ";
    std::cin >> n;
    std::cout << "Введите элементы матрицы: " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void Write(int matrix[N][N], int& n)
{
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << matrix[i][j] << '\t';
        std::cout << std::endl;
    }
}

int sumOfDigits(int x)
{
    int sum = 0;
    x = std::abs(x);
    while (x > 0)
    {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

int maxMatrixElem(int matrix[N][N], int& n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (max < matrix[i][j])
                max = matrix[i][j];
        }
    }
    return max;
}

int minMatrixElem(int matrix[N][N], int& n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (min > matrix[i][j])
                min = matrix[i][j];
        }
    }
    return min;
}

void matrixSort(int matrix[N][N], int& n)
{
    int sumOfColumns[N];
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
            sumOfColumns[j] += matrix[i][j];
    }
    for (int i = 0; i + 1 < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sumOfColumns[i] > sumOfColumns[j])
            {
                std::swap(sumOfColumns[i], sumOfColumns[j]);
                for (int k = 0; k < n; k++)
                    std::swap(matrix[k][i], matrix[k][j]);
            }
        }
    }
}