/*Вариант 8

Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100.
Если суммы цифр минимального и максимального элементов матрицы
отличаются не более, чем на 2, упорядочить столбцы матрицы по неубыванию суммы элементов. 
*/

#include "funcs.hpp"
#include <iostream>

int main()
{
    int matrix[N][N], n, sum_of_columns[N];
    Read(matrix, n);
    int sum_max_digits = sumOfDigits(maxMatrixElem(matrix, n));
    int sum_min_digits = sumOfDigits(minMatrixElem(matrix, n));
    if (std::abs(sum_max_digits - sum_min_digits) <= 2)
    {
        matrixSort(matrix, n);
    }
    Write(matrix, n);
}