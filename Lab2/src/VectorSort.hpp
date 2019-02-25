#pragma once
#include <functional>


template<typename T, typename IterT>
void Sort(IterT begin, IterT end, std::function<bool(T, T)> comparer)
{

	//Insertion sort
	for(auto i = begin + 1, current = i; i < end; ++i, current = i)
	{
		while (current != begin
			&& comparer(*(current - 1), *current) == false)
		{
			std::swap(*(current - 1), *current);
			--current;
		}
	}
}