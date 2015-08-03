#include <iostream>
#include "fraction.h"
#include "fractionException.h"
#include "fractionDvideByZeroException.h"
#include <string>

int main()
{
	try
	{

	Fraction f1(1);
	Fraction f2(1 , 2);
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f1/f2 << std::endl;
	f1 /= 5;
	std::cout << f1 << std::endl;
	f1 /= 5;
	std::cout << f1 << std::endl;
	f1 *= 100;
	std::cout << f1 << std::endl;
	f1 += (float)1 / 20;
	Fraction f3 = f1;
	std::cout << f1 << std::endl;
	std::cout << (f3 != f1) << std::endl;
	f1 = Fraction(2 , 5);
	std::cout << f1 << std::endl;
	f1++;
	std::cout << f1 << std::endl;
	int a = f1;
	std::cout << a << std::endl;
	f1 /= 0;
	
		
	}
	catch (FractionException& e)
	{
		std::cout << e.getMessage() << std::endl;
	}


	system("pause");
}