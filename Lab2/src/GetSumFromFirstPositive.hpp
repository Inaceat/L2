#pragma once


double GetSumFromFirstPositive(std::vector<double>& vec)
{
	auto firstPositive = vec.begin();

	while (*firstPositive <= 0)
		++firstPositive;

	double sum = 0;

	for(auto i = firstPositive; i != vec.end(); ++i)
		sum += *i;

	return sum;
}