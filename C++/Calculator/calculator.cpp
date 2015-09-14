#include "calculator.h"
#include <iostream>
#include <sstream>
Calculator::Calculator()
{
	_register = 0;

	operations.push_back(new SetOperation());
	operations.push_back(new AddOperation());
	operations.push_back(new SubstracrtOperation());
	operations.push_back(new MultiplyOperation());
	operations.push_back(new DivideOperation());
	operations.push_back(new PowerOperation());
	operations.push_back(new SquareRootOperation());
	operations.push_back(new Average3Operation());
	operations.push_back(new AverageOperation());
}

Calculator::~Calculator()
{
	for (CalculatorOperation* o : operations)
	{
		delete o;
	}
	operations.clear();
}

void Calculator::start()
{
	std::cout << "Welcome to the modular calculator." << std::endl;
	while (true){ 
		std::cout << ">";
		//get line input
		std::string temp;
		std::getline(std::cin, temp);
		std::stringstream line_stream(temp);
		//extract the command
		line_stream >> temp;
		//check if  the command is to exit the calculator
		if (temp == "exit")
		{
			break;
		}
		//check if the command exists and find operaton
		CalculatorOperation* operation_input = nullptr;
		for (CalculatorOperation* o : operations)
		{
			if (o->supportsOperation(temp))
			{
				operation_input = o;
			}
		}
		//if command not found skip it and wait for a new one
		if (operation_input == nullptr)
		{
			std::cout << "Command : \"" << temp <<"\" is not a supported operation."  << std::endl;
			continue;
		}
		//handle paramters
		int number_of_paramters = operation_input->requiredParameters();
		std::vector<std::string> paramters;
		for (int i = 0; i < number_of_paramters; i++)
		{
			line_stream >> temp;
			paramters.push_back(temp);
		}
		//perform operation and update register
		_register = operation_input->calcResult(_register, paramters);
		//display register
		std::cout << "Current value is: " << _register << std::endl;

	}
}