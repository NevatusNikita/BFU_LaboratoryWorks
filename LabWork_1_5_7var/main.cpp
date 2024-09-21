#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
	//1
    int j;
    int x;
    int min_x = INT32_MAX;
    int min_ind = -1;
    int sum_of_els = 0;
    cout << "1) Введите количетсво элементов последовательности j: ";
    cin >> j;
    cout << "Введите значения элементов полседовательности: ";
    for (int i = 0; i < j; ++i)
    {
        cin >> x;
        if ((x % 3 == 0) || (x % 7 == 0))
        {
            sum_of_els += x;
            if (x < min_x)
            {
                min_x = x;
                min_ind = i + 1;
            }
        }
    }
    if (min_ind != -1)
    {
        cout << "Сумма элементов, делящихся на 3 или на 7: " << sum_of_els << endl;
        cout << "Минимальный элемент последовательности, делящийся на 3 или на 7: " << min_x << endl;
        cout << "Номер минимального элемента, делящегося на 3 или на 7, в последовательности: " << min_ind << endl << endl;
    }
    else
        cout << "Чисел, удовлетворяющих условию, нет в последовательности" << endl << endl;
    //2
    int p = 1;
    int N;
    int numeral;
    cout << "2) Введите натуральное число N: ";
    cin >> N;
    while (N != 0)
    {
        numeral = N % 10;
        if (numeral % 2 == 0)
            p *= numeral;
        N /= 10;
    }
    if (p == 1)
        p = 0;
    cout << "Произведение чётных цифр числа: " << p;
}