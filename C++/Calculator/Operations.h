#pragma once
#include "calculatorOperation.h"
#include <algorithm>
class SetOperation : public CalculatorOperation
{
	virtual bool supportsOperation(std::string op_string)
	{
		if (op_string == "set")
		{
			return true;
		}
		return false;
	}
	virtual int requiredParameters(){ return 1; }
	virtual double calcResult(double currVal, std::vector<std::string> parameters){ return stoi(parameters[0]); }
};
class AddOperation : public CalculatorOperation
{
	virtual bool supportsOperation(std::string op_string)
	{
		if (op_string == "add")
		{
			return true;
		}
		if (op_string=="+")
		{
			return true;
		}
		return false;
	}
	virtual int requiredParameters(){ return 1; }
	virtual double calcResult(double currVal, std::vector<std::string> parameters){ return currVal + stoi(parameters[0]); }
};
class SubstracrtOperation : public CalculatorOperation
{
	virtual bool supportsOperation(std::string op_string)
	{
		if (op_string == "substract")
		{
			return true;
		}
		if (op_string == "sub")
		{
			return true;
		}
		if (op_string == "-")
		{
			return true;
		}
		return false;
	}
	virtual int requiredParameters(){ return 1; }
	virtual double calcResult(double currVal, std::vector<std::string> parameters){ return currVal - stoi(parameters[0]); }
};
class MultiplyOperation : public CalculatorOperation
{
	virtual bool supportsOperation(std::string op_string)
	{
		if (op_string == "multiply")
		{
			return true;
		}
			if (op_string == "mul")
		{
			return true;
		}
		if (op_string == "*")
		{
			return true;
		}
		return false;
	}
	virtual int requiredParameters(){ return 1; }
	virtual double calcResult(double currVal, std::vector<std::string> parameters){ return currVal * stoi(parameters[0]); }
};
class DivideOperation : public CalculatorOperation
{
	virtual bool supportsOperation(std::string op_string)
	{
		if (op_string == "divide")
		{
			return true;
		}
		if (op_string == "div")
		{
			return true;
		}
		if (op_string == "/")
		{
			return true;
		}
		if (op_string == "\\")
		{
			return true;
		}
		return false;
	}
	virtual int requiredParameters(){ return 1; }
	virtual double calcResult(double currVal, std::vector<std::string> parameters){ return currVal / stoi(parameters[0]); }
};
class PowerOperation : public CalculatorOperation
{
	virtual bool supportsOperation(std::string op_string)
	{
		if (op_string == "pow")
		{
			return true;
		}
		if (op_string == "power")
		{
			return true;
		}
		if (op_string == "^")
		{
			return true;
		}
		return false;
	}
	virtual int requiredParameters(){ return 1; }
	virtual double calcResult(double currVal, std::vector<std::string> parameters){ return std::pow(currVal, stoi(parameters[0])); }
};
class SquareRootOperation : public CalculatorOperation
{
	virtual bool supportsOperation(std::string op_string)
	{
		if (op_string == "sqrt")
		{
			return true;
		}
		if (op_string == "SquareRoot")
		{
			return true;
		}
		return false;
	}
	virtual int requiredParameters(){ return 0; }
	virtual double calcResult(double currVal, std::vector<std::string> parameters){ return std::sqrt(currVal); }
};
class AverageOperation : public CalculatorOperation
{
	virtual bool supportsOperation(std::string op_string)
	{
		if (op_string == "avg")
		{
			return true;
		}
		if (op_string == "average")
		{
			return true;
		}
		return false;
	}
	virtual int requiredParameters(){ return 1; }
	virtual double calcResult(double currVal, std::vector<std::string> parameters){ return (currVal + stoi(parameters[0]) ) / 2; }
};
class Average3Operation : public CalculatorOperation
{
	virtual bool supportsOperation(std::string op_string)
	{
		if (op_string == "avg3")
		{
			return true;
		}
		if (op_string == "average3")
		{
			return true;
		}
		return false;
	}
	virtual int requiredParameters(){ return 2; }
	virtual double calcResult(double currVal, std::vector<std::string> parameters){ return (currVal + stoi(parameters[0]) + stoi(parameters[1]))/3; }
};