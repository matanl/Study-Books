#pragma once
#include <string>
class SafeArrayOutOfBundsException
{

public:
	std::string getMessage()
	{
		return "You tried to access an item outside of the Safe Array's bounds";
	}
	
};

