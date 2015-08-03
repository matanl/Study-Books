#include "fraction.h"
#include "fractionDvideByZeroException.h"
#include <algorithm>


Fraction::Fraction() :numerator(0), denominator(1){}
Fraction::Fraction(float num)
{
	int power = 0;
	while (num != std::floor(num))
	{
		num *= 10;
		power++;
	}
	this->numerator = num;
	this->denominator = std::pow(10, power);
	this->reduce();
}

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator){
	/*cosmetic changes if denominator is negative for consistency*/
	if (denominator < 0)
	{
		this->denominator = -this->denominator;
		this->numerator = -this->numerator;
	}

	/*reduce*/
	this->reduce();
}

int Fraction::gcd(int a, int b)
{
	/*Euclid's algorithm*/
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}
void Fraction::reduce()
{
	/*if the number is 0, make the denominator 1 for consistency*/
	if (this->numerator == 0)
	{
		this->denominator = 1;
		return;
	}

	int divisor = gcd(std::abs(this->numerator), this->denominator);
	this->numerator /= divisor;
	this->denominator /= divisor;
}

Fraction Fraction::operator-()
{
	return Fraction(-this->numerator / this->denominator);
}
Fraction Fraction::operator+(const Fraction& f) const
{
	int new_num = this->numerator*f.denominator + f.numerator * this->denominator;
	int new_denom = this->denominator * f.denominator;
	return Fraction(new_num, new_denom);
}
Fraction Fraction::operator-(const Fraction& f) const
{
	int new_num = this->numerator*f.denominator - f.numerator * this->denominator;
	int new_denom = this->denominator * f.denominator;
	return Fraction(new_num, new_denom);
}
Fraction Fraction::operator*(const Fraction& f) const
{
	int new_num = this->numerator*f.numerator;
	int new_denom = this->denominator * f.denominator;
	return Fraction(new_num, new_denom);
}
Fraction Fraction::operator/(const Fraction& f) const
{
	if (f==Fraction(0,1))
	{
		throw FractionDvideByZeroException();
	}
	int new_num = this->numerator*f.denominator;
	int new_denom = this->denominator * f.numerator;
	return Fraction(new_num, new_denom);
}
Fraction& Fraction::operator+=(const Fraction& f)
{
	this->numerator *= f.denominator;
	this->numerator += f.numerator * this->denominator;
	this->denominator *= f.denominator;
	this->reduce();
	return *this;
}
Fraction& Fraction::operator -= (const Fraction& f)
{
	this->numerator *= f.denominator;
	this->numerator -= f.numerator * this->denominator;
	this->denominator *= f.denominator;
	this->reduce();
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& f)
{
	this->numerator *= f.numerator;
	this->denominator *= f.denominator;
	this->reduce();
	return *this;
}
Fraction& Fraction::operator/=(const Fraction& f)
{
	if (f == Fraction(0, 1))
	{
		throw FractionDvideByZeroException();
	}
	this->numerator *= f.denominator;
	this->denominator *= f.numerator;
	this->reduce();
	return *this;
}
Fraction& Fraction::operator++()
{
	this->numerator += this->denominator;
	return *this;
}
Fraction& Fraction::operator--()
{
	this->numerator -= this->denominator;
	return *this; 
}

bool Fraction::operator==(const Fraction& f)const
{
	return this->numerator == f.numerator && this->denominator == f.denominator;
}
bool Fraction::operator!= (const Fraction& f)const
{
	return !((*this) == f);
}
bool Fraction::operator>(const Fraction& f)const
{
	return this->numerator*f.denominator > f.numerator *this->denominator;
}
bool Fraction::operator<(const Fraction& f)const
{
	return this->numerator*f.denominator < f.numerator *this->denominator;
}
bool Fraction::operator>=(const Fraction& f)const
{
	return !((*this) < f);
}
bool Fraction::operator<=(const Fraction& f)const
{
	return !((*this) > f);
}

Fraction::operator float() const
{
	return (float)this->numerator / (float)this->denominator;
}
Fraction::operator int() const
{
	return this->numerator / this->denominator;
}

Fraction::~Fraction()
{
}
