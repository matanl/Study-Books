#pragma once
#include "calculatorOperation.h"
#include "Operations.h"
#include <vector>
class Calculator
{
private:
	double _register;

	std::vector<CalculatorOperation*> operations;
public:
	void start();
	Calculator();
	~Calculator();
};

