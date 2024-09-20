#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(0, "");
	int A, B, C;
	cout << "Введите значения сторон A, B, C (от 0 до 3*10^4): ";
	cin >> A >> B >> C;
	if (A <= 0 || A > 3 * pow(10, 4))
	{
		cout << "Значение A выходит за рамки промежутка!";
		return 0;
	}
	else 
	{
		if (B <= 0 || B > 3 * pow(10, 4))
		{
			cout << "Значение B выходит за рамки промежутка!";
			return 0;
		}
		else
		{
			if (C <= 0 || C > 3 * pow(10, 4))
			{
				cout << "Значение C выходит за рамки промежутка!";
				return 0;
			}
		}
	}
	cout << "Значение главной диагонали: " << sqrt(A * A + B * B + C * C);
}