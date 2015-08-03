#pragma once
#include <string>
class FractionException
{
private:
	std::string msg;
public:
	std::string getMessage()const{ return msg; }
	std::string setMessage(std::string msg){ this->msg = msg; }
	FractionException(std::string msg):msg(msg){}
};

