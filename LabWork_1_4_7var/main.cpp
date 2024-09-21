#include <iostream>

using namespace std;

int main()
{
	//1
	setlocale(0, "");
	int A, B, C;
	cout << "1) Введите натуральные числа A, B, C: ";
	cin >> A >> B >> C;
	if (A % B == 0)
	{
		if (B > C)
			cout << "Результат: " << A / B + C;
		else
		{
			if (B < C)
				cout << "Результат: " << A / B - C;
		}
	}
	else
		cout << "Результат: " << (A + B) * C;
    //2
    cout << endl << endl;
    int N;
    string result2;
    bool flag2 = true;
    cout << "2) Введите натуральное число N: ";
    cin >> N;
    switch (N)
    {
        case 1:
            result2 = "Понедельник";
            break;
        case 2:
            result2 = "Вторник";
            break;
        case 3:
            result2 = "Среда";
            break;
        case 4:
            result2 = "Четверг";
            break;
        case 5:
            result2 = "Пятница";
            break;
        case 6:
            result2 = "Суббота";
            break;
        case 7:
            result2 = "Воскресенье";
            break;
        default:
            result2 = "Введённое значение N не может быть номером дня недели!";
    }
    cout << result2 << endl << endl;
    //3
    int x;
    string result3;
    cout << "3) Введите число 1 или -1: ";
    cin >> x;
    switch (x)
    {
        case -1:
            result3 = "Negative number";
            break;
        case 1:
            result3 = "Positive number";
            break;
        default:
            result3 = "Введено некорректное значение!";
    }
    cout << result3;
}