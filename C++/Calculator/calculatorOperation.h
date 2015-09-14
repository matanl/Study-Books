#pragma once
#include <string>
#include <vector>
class CalculatorOperation
{
public:
	virtual bool supportsOperation(std::string op_string)=0;
	virtual int requiredParameters()=0;
	virtual double calcResult(double currVal, std::vector<std::string> parameters)=0;
};

