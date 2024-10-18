#include <iostream>

int sum_of_digits(int x)
{
    short s = 0;
    while (x > 0)
    {
        s += (x % 10);
        x /= 10;
    }
    return s;
}

int main()
{
    int c = 0;
    for (int i = 100000; i < 1000000; ++i)
    {
        if (sum_of_digits(i % 1000) == sum_of_digits(i / 1000))
            c += 1;
    }
    std::cout << c;
}