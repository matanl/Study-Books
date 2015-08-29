#pragma once
#include "drink.h"
class Beer : public Drink
{
public:

	Beer(const std::string& name):Drink(name)
	{
	}

	~Beer()
	{
	}
	virtual std::string prepare()
	{
		return "Well, all you need to do is pour it into a glass and serve.";
	}
};

