#include "stdafx.h"


#include "VectorSort.hpp"

#include "GetSumFromFirstPositive.hpp"


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



	std::vector<double> result;


	std::stringstream sstream(read);

	while (!sstream.eof())
	{
		double value;
		sstream >> value;

		if (sstream.fail())
			break;

		result.push_back(value);
	}

	return result;
}


int main()
{
	std::cout << "Enter your double sequence, or leave empty for default:" << std::endl;
	auto testVector = ReadVector();

	if (testVector.size() == 0)
		testVector = { -13, -42, 2, 3, 1, 0, -21, 2.5};

	PrintVector(testVector);


	auto sumFromFirstPositive = GetSumFromFirstPositive(testVector);

	std::cout << std::endl << "Sum of all elements from first positive = " << sumFromFirstPositive << std::endl << std::endl;


	std::function<bool(double, double)> doubleAscendingComparer = [](double left, double right)
	{
		return left < right;
	};
	std::function<bool(double, double)> doubleDescendingComparer = [](double left, double right)
	{
		return left > right;
	};

	//Ascending
	std::cout << "Ascending sorted :" << std::endl;
	Sort(testVector.begin(), testVector.end(), doubleAscendingComparer);
	PrintVector(testVector);

	//Descending
	std::cout << "Descending sorted :" << std::endl;
	Sort(testVector.begin(), testVector.end(), doubleDescendingComparer);
	PrintVector(testVector);

    return 0;
}