#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main()
{
	setlocale(0, "");
	int x;
	int y;
	short i;
	cout << "Введите число x (от 0 до 10^9): ";
	cin >> x;
	if (x < 0 || x > pow(10, 9))
	{
		cout << "Число не принадлежит заданному отрезку!";
		return 0;
	}
	cout << "Введите номер бита i: ";
	cin >> i;
	short size_x = ceil(log2(x));
	y = x | (1 << (size_x - i));
	cout << "Двоичное 32 разрядное представление исходного числа:" << '\t' 
	<< '\t' << bitset<32>(x) << endl;
	cout << "Двоичное 32 разрядное представление числа, с измененным битом:  " << bitset<32>(y) << endl;
	cout << "Исходное число: " << x << endl;
	cout << "Результат: " << y;
}