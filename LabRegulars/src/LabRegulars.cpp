#include "stdafx.h"

#include <iostream>
#include <string>
#include <regex>

int main()
{
	while (true)
	{
		std::string str;
		std::cin >> str;

		std::regex numberRegex("[1-9][0-9]{0,2}(?:,[0-9]{3})*");

		if (std::regex_match(str, numberRegex))
			std::cout << "Valid number!" << std::endl;
		else
			std::cout << "Number is invalid!" << std::endl;
	}

    return 0;
}
