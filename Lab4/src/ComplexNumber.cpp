#include "ComplexNumber.hpp"

#include <sstream>


template< typename T_To, typename T_From>
T_To MagicCastTo(T_From value)
{
	std::stringstream sstr;
	sstr << value;

	T_To result;
	sstr >> result;

	if (!sstr.eof() && sstr.fail())
		throw InvalidArgumentException("Cast failed, invalid input!");
	
	return result;
}


ComplexNumber::ComplexNumber()
	:
	_real(0),
	_imaginary(0)
{}

ComplexNumber::ComplexNumber(double re, double im)
	:
	_real(re),
	_imaginary(im)
{}

ComplexNumber::ComplexNumber(char* re, size_t reLength, char* im, size_t imLength)
	:
	ComplexNumber(std::string(re, reLength), std::string(im, reLength))
{}

ComplexNumber::ComplexNumber(std::string re, std::string im)
{
	try
	{
		_real = MagicCastTo<double>(re);
		_imaginary = MagicCastTo<double>(im);
	}
	catch (const InvalidArgumentException& e)
	{
		throw;
	}
}


ComplexNumber ComplexNumber::operator*(ComplexNumber other) const
{
	//(x + iy) * (u + iv) =
	//= (xu - yv) + i(xv + yu)
	return
	{
		this->_real * other._real - this->_imaginary * other._imaginary,
		this->_real * other._imaginary + this->_imaginary * other._real
	};
}

ComplexNumber ComplexNumber::operator/(ComplexNumber other) const
{
	//(u + iv) / (x + iy)

	//m = 1 / (x*x + y*y)
	double multiplier = 1. / (other._real * other._real + other._imaginary * other._imaginary);

	//m * ((ux + vy) + i(vx - uy))
	return
	{
		multiplier * (this->_real * other._real + this->_imaginary * other._imaginary),
		multiplier * (this->_imaginary * other._real - this->_real * other._imaginary)
	};
}


std::string ComplexNumber::RealToString() const
{
	return MagicCastTo<std::string>(_real);
}

std::string ComplexNumber::ImaginaryToString() const
{
	return MagicCastTo<std::string>(_imaginary);
}
