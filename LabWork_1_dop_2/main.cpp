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
    /*for (int i = 100000; i < 1000000; ++i)
    {
        if (sum_of_digits(i % 1000) == sum_of_digits(i / 1000))
            c += 1;
    }
    for (int i = 10000; i < 100000; ++i)
    {
        if (sum_of_digits(i % 1000) == sum_of_digits(i / 1000))
            c += 1;
    }
    for (int i = 1000; i < 10000; ++i)
    {
        if (sum_of_digits(i % 1000) == sum_of_digits(i / 1000))
            c += 1;
    }
    std::cout << c;*/


    for (int q=0; q<10; q++)
        for (int w=0; w<10; w++)
            for (int e=0; e<10; e++)
                for (int r=0; r<10; r++)
                    for (int t=0; t<10; t++)
                        for (int y=0; y<10; y++)
                            if (q+w+e==r+t+y) 
                                c++;
    std::cout << c-1;
}