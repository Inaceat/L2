#pragma once

#include <string>


std::string SubstringBetweenSpaces(std::string input)
{
	auto firstSpaceIndex = input.find_first_of(' ');
	auto lastSpaceIndex = input.find_last_of(' ');

	if (firstSpaceIndex < lastSpaceIndex)
	{
		std::string result(input, firstSpaceIndex + 1, lastSpaceIndex - firstSpaceIndex - 1);

		return result;
	}

	return "";
}