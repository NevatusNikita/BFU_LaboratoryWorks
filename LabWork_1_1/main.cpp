#include <iostream>
#include <cmath>

/*
									Лабораторная работа №1
										“Типы данных”

1. Дать определение переменной, понять, что это такое.
2. Перечислить основные типы данных в С++: целочисленные (знаковые и беззнаковые), 
			вещественные, символьные, логические.
3. Указать для каждого типа размер в байтах.
4. Указать минимальное и максимальное значение для каждого типа.
5. Составить программу, которая выводит название типа, размер, мин. и макс. значения.
6. Привести пример выполнения арифметической операции с каждым типом данных.
7. Программу желательно оформить с использованием CMake и загрузить на удаленное 
			хранилище репозиториев*.
*/

/*
1. Переменная - это именованая или адресованная область памяти для хранения данных.
2. 
Целочисленные: int, short, long, long long
Целочисленные беззнаковые: unsigned int, unsigned short, unsigned long, unsigned long long
Вещественные: float, double, long double
Символьные: char, unsigned char
Логический: bool

3, 4.                   
Название			Размер (байты)			Минимум 			Максимум
int 				4                		-1 * 2^31			2^31 - 1
unsigned int  		4       				0					2^32 - 1
short 				2              			-1 * 2^15			2^15 - 1
unsigned short 		2      					0					2^16 - 1
long  				4            			-1 * 2^31			2^31 - 1 
					8						-1 * 2^63			2^63 - 1
unsigned long  		4  						0					2^32 - 1			
					8						0					2^64 - 1
long long  			8           			-1 * 2^63			2^63 - 1
unsigned long long  8  						0					2^64 - 1

char				1                		-1 * 2^7			2^7 - 1
unsigned char   	1       				0					2^8 - 1

float 				4              			-3.4E+38			3.4E+38
double  			8              			-1.7E+308			1.7E+308
long double 		8						-1.7E+308			1.7E+308
					16     				  	-1.1E+4932			1.1E+4932
					
bool				1                       0 					1
*/

int main()
{
	//5
	std::cout << "Type" << '\t' << '\t' << '\t' <<  "Size" << '\t'
		<< '\t' << "Max" << '\t' << '\t' << '\t' << "Min" << std::endl;
	std::cout << std::endl << "Integer data types:" << std::endl;
	short size_int = sizeof(int);
	int n1 = pow(2, (size_int * 8) - 1) - 1;
	std::cout << std::endl << "int" << '\t'  << '\t' << '\t' << size_int <<
		 '\t' << '\t' << -1 * n1 - 1 << '\t' << '\t' << n1 << std::endl;
	short un_size_int = sizeof(unsigned int);
	unsigned int n2 = pow(2, un_size_int * 8) - 1;
	std::cout << "unsigned int" << '\t' << '\t' << un_size_int <<
		 '\t' << '\t' << 0 << '\t' << '\t' << '\t' << n2 << std::endl;
	short short_int = sizeof(short);
	short n3 = pow(2, (short_int * 8) - 1) - 1;
	std::cout << "short" << '\t' << '\t' << '\t' << short_int <<
		 '\t' << '\t' <<  -1 * n3 - 1 << '\t' << '\t' << '\t' << n3 << std::endl;
	short un_short_int = sizeof(unsigned short);
	unsigned short n4 = pow(2, un_short_int * 8) - 1;
	std::cout << "unsigned short" << '\t' << '\t' << un_short_int <<
		 '\t' << '\t' << 0 << '\t' << '\t' << '\t' << n4 << std::endl;
	short long_int = sizeof(long);
	long n5 = pow(2, (long_int * 8) - 1) - 1;
	std::cout << "long" << '\t' << '\t' << '\t' << long_int <<
		 '\t' << '\t' << -1 * n5 - 1 << '\t' << '\t' << n5 << std::endl;
	short un_long_int = sizeof(unsigned long);
	unsigned long n6 = pow(2, un_long_int * 8) - 1;
	std::cout << "unsigned long" << '\t' << '\t' << un_long_int <<
		 '\t' << '\t' << 0 << '\t' << '\t' << '\t' << n6 << std::endl;
	short long_long_int = sizeof(long long);
	long long n7 = pow(2, (long_long_int * 8) - 1) - 1;
	std::cout << "long long" << '\t' << '\t' << long_long_int <<
		 '\t' << '\t' << -1 * n7 - 1 << '\t' << n7 << std::endl;
	short un_long_long_int = sizeof(unsigned long long);
	unsigned long long n8 = pow(2, un_long_long_int * 8) - 1;
	std::cout << "unsigned long long" << '\t' << un_long_long_int <<
		 '\t' << '\t' << 0 << '\t' << '\t' << '\t' << n8 * 2 - 1 << std::endl;
	std::cout << std::endl << "Symbolic data types:" << std::endl;
	short size_char = sizeof(char);
	short n9 = pow(2, (size_char * 8) - 1) - 1;
	std::cout << std::endl << "char" << '\t' << '\t' << '\t' << size_char <<
		 '\t' << '\t' << -1 * n9 - 1 << '\t' << '\t' << '\t' << n9 << std::endl;
	short size_un_char = sizeof(unsigned char);
	short n10 = pow(2, size_un_char * 8) - 1;
	std::cout << "unsigned char" << '\t' << '\t' << size_un_char <<
		 '\t' << '\t' << 0 << '\t' << '\t' << '\t' << n10 << std::endl;
	std::cout << std::endl << "Real data types:" << std::endl;
	std::cout << std::endl << "float" << '\t' << '\t' << '\t' << sizeof(float) << '\t' << 
	     '\t' << 3.4E-38 << '\t' << '\t' << '\t' << 3.4E+38 << std::endl;
	std::cout << "double" << '\t' << '\t' << '\t' << sizeof(double) << '\t' << 
	     '\t' << 1.7E-308 << '\t' << '\t' << 1.7E+308 << std::endl;
	std::cout << "long double" << '\t' << '\t' << sizeof(long double) << '\t' << 
	     '\t' << "1.7E-4932" << '\t' << '\t' << "1.7E-4932" << std::endl;
	std::cout << std::endl << "Logical data type:" << std::endl;
	std::cout << std::endl << "bool" << '\t' << '\t' << '\t' << sizeof(bool) << '\t' <<
		 '\t' << "false (0)" << '\t' << '\t' << "true (1)" << std::endl;
	std::cout << std::endl;
	//6
	int a_int = 1, b_int = 2;
    std::cout << "int: " << a_int << " + " << b_int << " = " << (a_int + b_int) << std::endl;
	std::cout << '\t' << a_int << " - " << b_int << " = " << (a_int - b_int) << std::endl;
	std::cout << '\t' << a_int << " * " << b_int << " = " << (a_int * b_int) << std::endl;
	std::cout << '\t' << a_int << " / " << b_int << " = " << (a_int / b_int) << std::endl;
	unsigned int a_un_int = 1, b_un_int = 2;
    std::cout << "unsigned int: " << a_un_int << " + " << b_un_int << " = " <<
	 (a_un_int + b_un_int) << std::endl;
	std::cout << '\t' << a_un_int << " - " << b_un_int << " = " << (a_un_int - b_un_int) << std::endl;
	std::cout << '\t' << a_un_int << " * " << b_un_int << " = " << (a_un_int * b_un_int) << std::endl;
	std::cout << '\t' << a_un_int << " / " << b_un_int << " = " << (a_un_int / b_un_int) << std::endl;
	short a_short = 1, b_short = 2;
    std::cout << "short: " << a_short << " + " << b_short << " = " <<
	 (a_short + b_short) << std::endl;
	std::cout << '\t' << a_short << " - " << b_short << " = " << (a_short - b_short) << std::endl;
	std::cout << '\t' << a_short << " * " << b_short << " = " << (a_short * b_short) << std::endl;
	std::cout << '\t' << a_short << " / " << b_short << " = " << (a_short / b_short) << std::endl;
	unsigned short a_un_short = 1, b_un_short = 2;
    std::cout << "unsigned short: " << a_un_short << " + " << b_un_short << " = " <<
	 (a_un_short + b_un_short) << std::endl;
	std::cout << '\t' << a_un_short << " - " << b_un_short << " = " << (a_un_short - b_un_short) << std::endl;
	std::cout << '\t' << a_un_short << " * " << b_un_short << " = " << (a_un_short * b_un_short) << std::endl;
	std::cout << '\t' << a_un_short << " / " << b_un_short << " = " << (a_un_short / b_un_short) << std::endl;
    long a_long = 1, b_long = 2;
    std::cout << "long: " << a_long << " + " << b_long << " = " <<
	 (a_long + b_long) << std::endl;
	std::cout << '\t' << a_long << " - " << b_long << " = " << (a_long - b_long) << std::endl;
	std::cout << '\t' << a_long << " * " << b_long << " = " << (a_long * b_long) << std::endl;
	std::cout << '\t' << a_long << " / " << b_long << " = " << (a_long / b_long) << std::endl;
	unsigned long a_un_long = 1, b_un_long = 2;
    std::cout << "unsigned long: " << a_un_long << " + " << b_un_long << " = " <<
	 (a_un_long + b_un_long) << std::endl;
	std::cout << '\t' << a_un_long << " - " << b_un_long << " = " << (a_un_long - b_un_long) << std::endl;
	std::cout << '\t' << a_un_long << " * " << b_un_long << " = " << (a_un_long * b_un_long) << std::endl;
	std::cout << '\t' << a_un_long << " / " << b_un_long << " = " << (a_un_long / b_un_long) << std::endl;
    long long a_long_long = 1, b_long_long = 2;
    std::cout << "long long: " << a_long_long << " + " << b_long_long << " = " <<
	 (a_long_long + b_long_long) << std::endl;
	std::cout << '\t' << a_long_long << " - " << b_long_long << " = " << (a_long_long - b_long_long) << std::endl;
	std::cout << '\t' << a_long_long << " * " << b_long_long << " = " << (a_long_long * b_long_long) << std::endl;
	std::cout << '\t' << a_long_long << " / " << b_long_long << " = " << (a_long_long / b_long_long) << std::endl;
	unsigned long long a_un_long_long = 1, b_un_long_long = 2;
    std::cout << "unsigned long long: " << a_un_long_long << " + " << b_un_long_long << " = " <<
	 (a_un_long_long + b_un_long_long) << std::endl;
	std::cout << '\t' << a_un_long_long << " - " << b_un_long_long << " = " << (a_un_long_long - b_un_long_long) << std::endl;
	std::cout << '\t' << a_un_long_long << " * " << b_un_long_long << " = " << (a_un_long_long * b_un_long_long) << std::endl;
	std::cout << '\t' << a_un_long_long << " / " << b_un_long_long << " = " << (a_un_long_long / b_un_long_long) << std::endl;

	char a_char = 1, b_char = 2;
    std::cout << std::endl << "char: " << a_char << " + " << b_char << " = " <<
	 (a_char + b_char) << std::endl;
	std::cout << '\t' << a_char << " - " << b_char << " = " << (a_char - b_char) << std::endl;
	std::cout << '\t' << a_char << " * " << b_char << " = " << (a_char * b_char) << std::endl;
	std::cout << '\t' << a_char << " / " << b_char << " = " << (a_char / b_char) << std::endl;
	unsigned char a_un_char = 1, b_un_char = 2;
    std::cout << "unsigned char: " << a_un_char << " + " << b_un_char << " = " <<
	 (a_un_char + b_un_char) << std::endl;
	std::cout << '\t' << a_un_char << " - " << b_un_char << " = " << (a_un_char - b_un_char) << std::endl;
	std::cout << '\t' << a_un_char << " * " << b_un_char << " = " << (a_un_char * b_un_char) << std::endl;
	std::cout << '\t' << a_un_char << " / " << b_un_char << " = " << (a_un_char / b_un_char) << std::endl;

    float a_float = 1.0f, b_float = 2.0f;
    std::cout << std::endl << "float: " << a_float << " + " << b_float << " = " <<
	 (a_float + b_float) << std::endl;
	std::cout << '\t' << a_float << " - " << b_float << " = " << (a_float - b_float) << std::endl;
	std::cout << '\t' << a_float << " * " << b_float << " = " << (a_float * b_float) << std::endl;
	std::cout << '\t' << a_float << " / " << b_float << " = " << (a_float / b_float) << std::endl;
    double a_doudble = 1.0, b_doudble = 2.0;
    std::cout << "double: " << a_doudble << " + " << b_doudble << " = " <<
	 (a_doudble + b_doudble) << std::endl;
	std::cout << '\t' << a_doudble << " - " << b_doudble << " = " << (a_doudble - b_doudble) << std::endl;
	std::cout << '\t' << a_doudble << " * " << b_doudble << " = " << (a_doudble * b_doudble) << std::endl;
	std::cout << '\t' << a_doudble << " / " << b_doudble << " = " << (a_doudble / b_doudble) << std::endl;
    long double a_long_doudble = 1.0, b_long_doudble = 2.0;
    std::cout << "long double: " << a_long_doudble << " + " << b_long_doudble << " = " <<
	 (a_long_doudble + b_long_doudble) << std::endl;
	std::cout << '\t' << a_long_doudble << " - " << b_long_doudble << " = " << (a_long_doudble - b_long_doudble) << std::endl;
	std::cout << '\t' << a_long_doudble << " * " << b_long_doudble << " = " << (a_long_doudble * b_long_doudble) << std::endl;
	std::cout << '\t' << a_long_doudble << " / " << b_long_doudble << " = " << (a_long_doudble / b_long_doudble) << std::endl;

	bool a_bool = 1, b_bool = 2;
	std::cout << std::endl << "bool: " << a_bool << " + " << b_bool << " = " <<
	 (a_bool + b_bool) << std::endl;
	std::cout << '\t' << a_bool << " - " << b_bool << " = " << (a_bool - b_bool) << std::endl;
	std::cout << '\t' << a_bool << " * " << b_bool << " = " << (a_bool * b_bool) << std::endl;
	std::cout << '\t' << a_bool << " / " << b_bool << " = " << (a_bool / b_bool) << std::endl;
	return 0;
}