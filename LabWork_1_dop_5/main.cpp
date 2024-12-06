#include <iostream>
#include <cmath>

int main()
{
    setlocale(0, "");
    std::cout << "¬ведите радуис r1 и координаты центра x1, y1 первого круга: ";
    int r1, x1, y1;
    std::cin >> r1 >> x1 >> y1;
    std::cout << "¬ведите радуис r2 и координаты центра x2, y2 второго круга: ";
    int r2, x2, y2;
    std::cin >> r2 >> x2 >> y2;
    double d = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2)); //рассто€ние между центрами окружностей
    double s, s1, s2;
    const double pi = 2 * acos(0.0);
    if (d >= (r1 + r2))
    {
        s1 = pi * r1 * r1;
        s2 = pi * r2 * r2;
        s = s1 + s2;
    }
    else if (d <= fabs(r1 - r2))
    {
        s1 = pi * r1 * r1;
        s2 = pi * r2 * r2;
        if (s1 > s2)
            s = s1;
        s = s2;
    }
    else
    {
        double s_inter, s1_inter, s2_inter, angle_1, angle_2;
        angle_1 = acos((r2 * r2 - r1 * r1 + d * d) / (2 * r2 * d));
        angle_2 = acos((r1 * r1 - r2 * r2 + d * d) / (2 * r1 * d));
        s1 = 0.5 * r1 * r1 * (angle_2 - sin(angle_2));
        s2 = 0.5 * r2 * r2 * (angle_1 - sin(angle_1));
        s = pi * r1 * r1 + pi * r2 * r2 - s1 - s2;
    }
    std::cout << s;
}