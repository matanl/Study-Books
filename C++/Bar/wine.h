#pragma once
#include "drink.h"
class Wine : public Drink 
{
protected:
	int year;
public:
	
	Wine(const std::string& name, int year) :Drink(name), year(year)
	{
	}
	virtual std::string getName(){ return Drink::getName() + " (year " + std::to_string(this->year) + ")"; }
};
class RedWine : public Wine
{
public:
	RedWine(const std::string& name, int year) : Wine(name, year)
	{
	}
	virtual std::string prepare()
	{
		return "Well, you need to make sure the wine is in room tempreture (16-18 degrees) and then pour it into a glass and serve.";
	}
};
class WhiteWine : public Wine
{
public:
	WhiteWine(const std::string& name, int year) : Wine(name, year)
	{
	}
	virtual std::string prepare()
	{
		return "Well, you need to make sure the wine is cold and then pour it into a glass and serve.";
	}
};


