#pragma once

#include "PmergeMe.hpp"

template <class T>
void	printSequence(T &sequence)
{
	for (size_t i = 0; i < sequence.size(); i++)
		std::cout << sequence[i] << " ";
	std::cout << "\n\n";
}
