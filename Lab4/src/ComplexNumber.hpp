#pragma once

#include <string>



class InvalidArgumentException
	:
	public std::runtime_error
{
public:
	explicit InvalidArgumentException(const std::string& message)
		: runtime_error(message)
	{}

	explicit InvalidArgumentException(const char* message)
		: runtime_error(message)
	{}
};


class ComplexNumber
{
public:
	ComplexNumber();

	ComplexNumber(double re, double im);
	
	ComplexNumber(char* re, size_t reLength, char* im, size_t imLength);

	ComplexNumber(std::string re, std::string im);


	ComplexNumber operator*(ComplexNumber other) const;

	ComplexNumber operator/(ComplexNumber other) const;


	std::string RealToString() const;

	std::string ImaginaryToString() const;

private:
	double _real;
	double _imaginary;
};
