#include <iostream>
#include "safeArray.h"
#include "safePointer.h"
#include "safeArrayOutOfBundsException.h"

int main()
{
	try{
		SafeArray<int> a(5);
		a[1] = 3;
		a[6] = 7; //throw
	}
	catch (SafeArrayOutOfBundsException& e)
	{
		std::cout << e.getMessage() <<std::endl;
	}

	try{
		SafeArray<int> b(2);
		b[0] = 3;
		b[1] = 7;
		SafePointer<int> s(b, &b[0]);
		std::cout <<*s << std::endl;
		s++;
		std::cout << *s << std::endl;
		s++; //throw
	}
	catch (SafeArrayOutOfBundsException& e)
	{
		std::cout << e.getMessage() << std::endl;
	}



	getc(stdin);
	return 0;
}