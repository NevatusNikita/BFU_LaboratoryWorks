#include <iostream>

int main()
{
    setlocale(0, "");
    long long x;
    std::cout << "¬ведите число: ";
    std::cin >> x;
    long long* p = &x;
    unsigned char* c_p = reinterpret_cast<unsigned char*>(p);
    for (int i = 0; i < 8; ++i)
    {
        std::cout << static_cast<long long>(*c_p) << std::endl;
        ++c_p;
    }
}