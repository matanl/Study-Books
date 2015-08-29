#pragma once
#include "drink.h"
class Bar
{
#define SHELF_SIZE 11
private:
	Drink* stock[SHELF_SIZE];
public:
	void Bartender();
	Bar();
	~Bar();
};

