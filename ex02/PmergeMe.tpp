#pragma once

#include "PmergeMe.hpp"

template <typename T>
typename T::iterator	binarySearch(typename T::iterator start, typename T::iterator end, int sizeElement, int valToFind)
{
	typename T::iterator	it;
	size_t	mid;

	mid  = std::distance(start, end) / sizeElement / 2;
	it = start + mid * sizeElement;

	if (valToFind <	*it)
	{
		if (it == start)
			return (start - (sizeElement - 1));
		return binarySearch<T>(start, it - sizeElement, sizeElement, valToFind);
	}
	else
	{
		if (it == end)
			return (end + 1);
		return binarySearch<T>(it + sizeElement, end, sizeElement, valToFind);
	}
}

template <
	class S,
	template <class, class> class OuterContainer,
	template <class, class> class InnerContainer,
	class T
>
void	initPending(S &sequence, int sizeElement, OuterContainer<std::pair<InnerContainer<T, std::allocator<T> >, int>, std::allocator<std::pair<InnerContainer<T, std::allocator<T> >, int> > > &pending)
{
	int	nbElements;
	int	nbElementsToPush;
	typename S::iterator firstValGroup;
	typename S::iterator lastValGroup;

	nbElements = sequence.size() / sizeElement;
	nbElementsToPush = (nbElements / 2) - 1;
	if (nbElements & 1)
		nbElementsToPush += 1;
	firstValGroup = sequence.begin() + sizeElement * 2;
	if (!nbElementsToPush)
		return ;
	for (int i = 0; i < nbElementsToPush; i++)
	{
		typename OuterContainer<std::pair<InnerContainer<T, std::allocator<T> >, int>, std::allocator<std::pair<InnerContainer<T, std::allocator<T> >, int> > >::value_type tmpPair;
//		std::pair<std::vector<int>, int> tmpPair;
		lastValGroup = firstValGroup + sizeElement - 1;
		tmpPair.first.insert(tmpPair.first.begin(), firstValGroup, lastValGroup + 1);
		if (sequence.end() - 1 != lastValGroup)
			tmpPair.second = *(lastValGroup + 1);
		else
			tmpPair.second = -1;
		pending.push_back(tmpPair);
		firstValGroup = sequence.erase(firstValGroup, lastValGroup + 1);
		firstValGroup += sizeElement;
	}
	std::cout << std::endl;
}

template <class T>
void	sortPairs(T &sequence, int sizeElement)
{
	int	nbOfGroups;
	int	firstElement;
	int	lastElement;


	nbOfGroups = sequence.size() / (sizeElement * 2);
	firstElement = sizeElement - 1;
	lastElement = sizeElement - 1 + sizeElement;
	if (nbOfGroups)
	{
		std::cout << "Number of pairs " << nbOfGroups << std::endl;
		std::cout << "Original pairs" << std::endl;
		printGroup(sequence, sizeElement, nbOfGroups);
		std::cout << std::endl;
	}
	for (int i = 1; i <= nbOfGroups; i++)
	{
		if (sequence[firstElement] < sequence[lastElement])
			std::cout << "{" << sequence[firstElement] << ", " << sequence[lastElement] << "} ";
		if (sequence[firstElement] > sequence[lastElement])
		{
			for (int j = 0; j < sizeElement; j++)
			{
				std::swap(sequence[firstElement - j], sequence[lastElement - j]);
				std::cout << "{\033[1;36m" << sequence[firstElement - j];
				if (j < sizeElement * 2 - 1)
					std::cout << ", " << sequence[lastElement - j] << "\033[0m} ";
			}
		}
		firstElement += sizeElement * 2;
		lastElement += sizeElement * 2;
	}
	if (nbOfGroups)
	{
		std::cout << "\nSorted pairs" << std::endl;
		printGroup(sequence, sizeElement, nbOfGroups);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
