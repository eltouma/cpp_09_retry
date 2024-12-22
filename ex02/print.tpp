#pragma once

#include "PmergeMe.hpp"

template <class T>
void	printSequence(T sequence)
{
	for (size_t i = 0; i < sequence.size(); i++)
		std::cout << sequence[i] << " ";
}

template <class T>
void	printGroup(T sequence, int sizeElement, int nbOfGroups)
{
	int	middle;
	int	last;
	for (int i = 0; i < nbOfGroups; i++)
	{
		std::cout << "{";
		for (int j = 0; j < sizeElement * 2; j++)
		{
			middle = sizeElement - 1;
			last = sizeElement * 2 - 1;
			if (sizeElement  > 1 && (j == middle || j == last))
				std::cout << "\033[96m" << sequence[i * sizeElement * 2 + j] << "\033[0m";
			else
				std::cout << sequence[i * sizeElement * 2 + j];
			if (j < sizeElement * 2 - 1)
				std::cout << ", ";
		}
		std::cout << "} ";
	}
}

template <class T>
void	printOdd(T sequence, int sizeElement)
{
	int	remainingSize;

	remainingSize = sequence.size() % (sizeElement * 2);
	if (remainingSize > 0)
	{
		for (size_t i = sequence.size() - remainingSize; i < sequence.size(); ++i)
		{
			std::cout << "\033[1;90m" << sequence[i];
			if (i < sequence.size() - 1)
				std::cout << ", ";
			std::cout << "\033[0m";
		}
	}
	std::cout << std::endl;
}

template <
    template <class, class> class OuterContainer,
    template <class, class> class InnerContainer,
    class T
>
void	printPending(OuterContainer<std::pair<InnerContainer<T, std::allocator<T> >, int>, std::allocator<std::pair<InnerContainer<T, std::allocator<T> >, int> > > &pending)
{
	for (size_t i = 0; i < pending.size(); i++)
	{
		std::cout << "{\033[33m";
		for (size_t j = 0; j < pending[i].first.size(); j++)
		{
			std::cout << pending[i].first.at(j);
			if (j < pending[i].first.size() - 1) std::cout << ", ";
		}
		std::cout << "\033[0m} ";
	}
}
