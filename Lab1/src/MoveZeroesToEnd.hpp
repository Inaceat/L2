#pragma once
#include <vector>


std::vector<double> MoveZeroesToEnd(std::vector<double> input)
{
	std::vector<double> result(input.size(), 0);

	for (size_t i = 0, r = 0; i < input.size(); i++)
	{
		if (input[i] != 0)
			result[r++] = input[i];
	}

	return result;
}