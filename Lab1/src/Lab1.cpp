#include "stdafx.h"

#include "SubstringBetweenSpaces.hpp"
#include "MoveZeroesToEnd.hpp"


//Strings

void Task1()
{
	//std::string x1 = "qw e r ty";
	//
	//std::cout << "Test string 1: [" << x1 << "]" << std::endl;
	//std::cout << "Result:        [" << SubstringBetweenSpaces(x1) << "]" << std::endl;
	//
	//
	//std::string x2 = "";
	//
	//std::cout << "Test string 2: [" << x2 << "]" << std::endl;
	//std::cout << "Result:        [" << SubstringBetweenSpaces(x2) << "]" << std::endl;
	//
	//
	//std::string x3 = "qwerty ";
	//
	//std::cout << "Test string 1: [" << x3 << "]" << std::endl;
	//std::cout << "Result:        [" << SubstringBetweenSpaces(x3) << "]" << std::endl;


	std::string userInput;
	std::cout << std::endl << "Enter your string:" << std::endl;
	std::getline(std::cin, userInput);

	std::cout << "User string : [" << userInput << "]" << std::endl;
	std::cout << "Result:       [" << SubstringBetweenSpaces(userInput) << "]" << std::endl;
}


//Vectors

void PrintVector(std::vector<double> v)
{
	for (auto value : v)
		std::cout << std::setw(6) << value << " ";

	std::cout << std::endl;
}

std::vector<double> ReadVector()
{
	std::string read;
	std::getline(std::cin, read);

	std::stringstream sstream(read);

	std::vector<double> result;

	while (!sstream.eof())
	{
		double value;
		sstream >> value;

		result.push_back(value);
	}

	return result;
}

void Task2()	
{
	//std::vector<double> x1{ 12.5, 0, 0.2, 0, 42};
	//
	//std::cout << "Vector 1:" << std::endl;
	//PrintVector(x1);
	//
	//std::cout << "\"Sorted\" vector 1:" << std::endl;
	//PrintVector(MoveZeroesToEnd(x1));
	//
	//std::cout << std::endl;
	//
	//
	//std::vector<double> x2{ 0, 0, 0 };
	//
	//std::cout << "Vector 2:" << std::endl;
	//PrintVector(x2);
	//
	//std::cout << "\"Sorted\" vector 2:" << std::endl;
	//PrintVector(MoveZeroesToEnd(x2));
	//
	//std::cout << std::endl;


	std::cout << "Enter your numbers, with space as delimiter:" << std::endl;
	std::vector<double> userInput = ReadVector();


	std::cout << "User vector:" << std::endl;
	PrintVector(userInput);

	std::cout << "\"Sorted\" user vector:" << std::endl;
	PrintVector(MoveZeroesToEnd(userInput));

	std::cout << std::endl;

}


int main()
{
	Task1();
	std::cout << std::endl << std::endl;

	Task2();
	std::cout << std::endl << std::endl;

    return 0;
}