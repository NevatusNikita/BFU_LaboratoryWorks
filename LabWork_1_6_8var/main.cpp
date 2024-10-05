#include <iostream>
#include <vector>
#include <cmath>

bool check(int y)
{
    int last_numeral = y % 10;
    while (y > 0)
    {
        if (last_numeral != (y % 10))
            return false;
        else
        {
            last_numeral = y % 10;
            y /= 10;
        }
    }
    return true;
}

void Sort(int data[], int size)
{
    int j;
    for (int i = 1; i < size; ++i)
    {   
        for (int j = i; j > 0 && data[j - 1] < data[j]; --j)
            std::swap(data[j], data[j - 1]);
    }
}

int sum_of_numerals(int y)
{
    int sum = 0;
    while (y > 0)
    {
        sum += (y % 10);
        y /= 10;
    }
    return sum;
}

int min_numeral(int y)
{
    int res = 10;
    while (y > 0)
    {
        if ((y % 10) < res)
            res = y % 10;
        y /= 10;
    }
    return res;
}

bool same_digits(int c)
{
    while (c > 0)
    {
        int last_digit_1 = c % 10;
        int d = c / 10;
        while (d > 0)
        {
            int last_digit_2 = d % 10;
            if (last_digit_1 == last_digit_2)
                return true;
            d /= 10;
        }
        c /= 10;
    }
    return false;
}

int main()
{
    setlocale(0, "");
    //1
    int n, x, c = 0, data[10000];
    std::cout << "1) ¬ведите размер массива: ";
    std::cin >> n;
    std::cout << "¬ведтие элементы массива: ";
    for (int k = 0; k < n; ++k)
    {
        std::cin >> data[k];
        if (check(data[k]))
        {
            c += 1;
        }
    }
    if (c >= 3)
        Sort(data, n);
    for (int ind = 0; ind < n; ++ind)
        std::cout << data[ind] << " ";
    std::cout << std::endl << std::endl;
    //2
    int numbers[1000], sums[1000];
    std::cout << "2) ¬ведите размер массива: ";
    std::cin >> n;
    std::cout << "¬ведтие элементы массива: ";
    for (int k = 0; k < n; ++k)
    {
        std::cin >> numbers[k];
        sums[k] = sum_of_numerals(numbers[k]);
    }
    for (int i = 0; i + 1 < n; ++i)
    {   
        for (int j = i + 1; j < n; ++j)
        {
            if (sums[i] > sums[j])
            {
                std::swap(sums[i], sums[j]);
                std::swap(numbers[i], numbers[j]);
            }
        }
    }
    for (int i = 0; i + 1 < n; ++i)
    {   
        for (int j = i + 1; j < n; ++j)
        {
        if (sums[i] == sums[j])
            {
                if (min_numeral(numbers[i]) > min_numeral(numbers[j]))
                    std::swap(numbers[i], numbers[j]);
                else
                {
                    if (min_numeral(numbers[i]) == min_numeral(numbers[j]))
                    {
                        if (numbers[i] > numbers[j])
                            std::swap(numbers[i], numbers[j]);
                    }
                }
            }
        }
    }
    for (int k = 0; k < n; ++k)
        std::cout << numbers[k] << " ";
    std::cout << std::endl << std::endl;
    //3
    int m, ans_column = -1, ans_max = 0, matrix[100][100];
    std::cout << "3) ¬ведите размер мтарицы: ";
    std::cin >> n >> m;
    std::cout << "¬ведтие элементы матрицы: ";
    std::vector<int> products_of_column(m);
    for (int k = 0; k < m; ++k)
        products_of_column[k] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> matrix[i][j];
            products_of_column[j] *= matrix[i][j];
        }
    }
    for (int k = 0; k < m; ++k)
    {
        if (products_of_column[k] > ans_max)
        {
            ans_max = products_of_column[k];
            ans_column = k;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            {
                if (j == ans_column)
                    matrix[i][j] -= 3;
                std::cout << matrix[i][j] << " ";
            }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
    //4
    int A[10000], j = 0;
    std::cout << "4) ¬ведите количетсво элементов последовательноси: ";
    std::cin >> n;
    std::cout << "¬ведите элементы последовательноси: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x;
        if (sum_of_numerals(x) % 7 != 0)
        {
            A[j] = x;
            j += 1;
            if (same_digits(x) || (x < 10))
            {
                A[j] = x;
                j += 1;
            }
        }
    }
    for (int i = 0; i < j; ++i)
        std::cout << A[i] << " ";
}