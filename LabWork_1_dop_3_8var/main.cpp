#include <iostream>

bool isDigitInFib(int x, int digit)
{
    while (x > 0)
    {
        if (x % 10 == digit)
            return true;
        x /= 10;
    }
    return false;
}

bool isSquare(int x)
{
    int a = (int)sqrt(x);
    if (a * a == x)
        return true;
    return false;
}

int main()
{
    setlocale(0, "");
    int A[20000], j = 0, n;
    std::cout << "¬ведите количество элементов массива: ";
    std::cin >> n;
    std::cout << "¬ведите элементы массива: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> A[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if ((isDigitInFib(A[i], 0)) && (!isDigitInFib(A[i], 1)))
            continue;
        A[j] = A[i];
        j++;
    }
    n = j;
    for (int i = 0; i < n; ++i)
    {
        if (isSquare(A[i]))
        {
            for (int j = n; j > i; --j)
               A[j] = A[j - 1];
            n++;
            i++;
        }
    }
    for (int i = 0; i < n; ++i)
        std::cout << A[i] << " ";
}