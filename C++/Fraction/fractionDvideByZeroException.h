#pragma once
#include "fractionException.h"
class FractionDvideByZeroException : public FractionException
{
public:
	FractionDvideByZeroException():FractionException("can't divide fraction by zero"){}
};