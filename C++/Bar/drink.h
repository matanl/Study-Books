#pragma once
#include <string>
class Drink
{
protected:
	std::string name;
public:
	Drink(const std::string& name):name(name){}
	virtual std::string getName(){ return name; }
	virtual std::string prepare() = 0;
};

