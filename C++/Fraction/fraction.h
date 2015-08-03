#pragma once
#include <string>
class Fraction
{
private:
	int numerator;
	int denominator;

	/*functions to rduce the fraction*/
	static int gcd(int a, int b);
	void reduce();

public:
	Fraction();
	Fraction(int numerator, int denominator);
	Fraction(float num);

	void setNumerator(int numerator){ this->numerator = numerator; }
	void setDenominator(int denominator){ this->denominator = denominator; }
	int getNumerator() const { return this->numerator; }
	int getDenominator() const { return this->denominator; }

	Fraction operator-();
	Fraction operator+(const Fraction& f) const;
	Fraction operator-(const Fraction& f) const;
	Fraction operator*(const Fraction& f) const;
	Fraction operator/(const Fraction& f) const;
	Fraction& operator+=(const Fraction& f);
	Fraction& operator-=(const Fraction& f);
	Fraction& operator*=(const Fraction& f);
	Fraction& operator/=(const Fraction& f);
	Fraction& operator++();
	Fraction& operator--();
	bool operator==(const Fraction& f)const;
	bool operator!=(const Fraction& f)const;
	bool operator>(const Fraction& f)const;
	bool operator<(const Fraction& f)const;
	bool operator>=(const Fraction& f)const;
	bool operator<=(const Fraction& f)const;

	
	operator float() const;
	operator int() const;

	inline friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
		if (f.numerator == 0)
		{
			out << "0";
		}
		else if (f.denominator == 1)
		{
			out << f.numerator;
		}
		else{
			out << f.numerator << "/" << f.denominator;
		}
		return out;
	}
	~Fraction();
};

