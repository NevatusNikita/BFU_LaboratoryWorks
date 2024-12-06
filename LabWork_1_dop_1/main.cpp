#include <iostream>
#include <cmath>

void choose(short& q1, short& p1, short& q2, short& p2, short& a, short& cost)
{
    if (q1 > a && q2 > a)
    {
        if (p1 < p2)
        {
            a -= q1;
            cost += p1;
            return;
        }
        else
        {
            a -= q2;
            cost += p2;
            return;
        }
    }
    if (q1 <= a && q2 <= a)
    {
        double cof1 = q1 / (double) p1;
        double cof2 = q2 / (double) p2;
        if (cof1 > cof2)
        {
            a -= q1;
            cost += p1;
            return;
        }
        else 
        {
            a -= q2;
            cost += p2;
            return;
        }
    }
    if ((a < q1) && (p1 < (p2 * ceil(a / (double) q2))))
    {
        a -= q1;
        cost += p1;
        return;
    }
    else
    {
        a -= q2;
        cost += p2;
        return;
    }
}

int main()
{
    short P1, Q1, P2, Q2, A, Cost=0;
    std::cin >> Q1 >> P1 >> Q2 >> P2 >> A;
    while (A > 0)
    {
        choose(Q1, P1, Q2, P2, A, Cost);
    }
    std::cout << Cost;
}