#pragma once

#include "PmergeMe.hpp"

template <typename T>
typename T::iterator	binarySearch(typename T::iterator start, typename T::iterator end, int sizeElement, int valToFind)
{
	std::vector<int>::iterator	it;
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
	std::vector<int>::iterator firstValGroup;
	std::vector<int>::iterator lastValGroup;

	nbElements = sequence.size() / sizeElement;
	nbElementsToPush = (nbElements / 2) - 1;
	if (nbElements & 1)
		nbElementsToPush += 1;
	firstValGroup = sequence.begin() + sizeElement * 2;
	if (!nbElementsToPush)
		return ;
	for (int i = 0; i < nbElementsToPush; i++)
	{
		std::pair<std::vector<int>, int> tmpPair;
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

template <class T>
void	mergeInsert(T &sequence, int sizeElement)
{
	int nbOfGroups = sequence.size() / (sizeElement * 2);
	int	jacobIn = 0;
	std::vector<std::pair<std::vector<int>, int> > pending;
	std::vector<int>::iterator end;
	std::vector<int>::iterator insertIt;

	sortPairs(sequence, sizeElement);
	if (sequence.size() / sizeElement >= 2)
		mergeInsert(sequence, sizeElement * 2);
	else
		return ;
	std::cout << "------------------------------------------------------------------------------------------------\n" << std::endl;
	draw_tab("Current sequence");
	printGroup(sequence, sizeElement, nbOfGroups);
	printOdd(sequence, sizeElement);
	printLabel(sizeElement, nbOfGroups);
	initPending(sequence, sizeElement, pending);
	if (!pending.size())
		std::cout << "\nNo pend - no insertions. Move on" << std::endl;
	else
	{
		std::cout << std::endl;
		draw_tab("Pending");
	}
	printPending(pending);
	std::cout << std::endl;
	int	prev_jacob = 1;
	int	next_jacob = jacobNumber(jacobIn);
	jacobIn++;
	size_t	insertIndex;
	while (pending.size())
	{
		if (next_jacob <= prev_jacob) 
		{
			prev_jacob = next_jacob;
			next_jacob = jacobNumber(jacobIn);
			jacobIn++;
		}
		insertIndex = next_jacob - prev_jacob;
		if (insertIndex > pending.size())
			insertIndex = pending.size();
		insertIndex -= 1;
		end = find(sequence.begin(), sequence.end(), pending[insertIndex].second) - 1;
		insertIt = binarySearch<T>(sequence.begin() + sizeElement - 1, end, sizeElement, pending[insertIndex].first.back());
		sequence.insert(insertIt, pending[insertIndex].first.begin(), pending[insertIndex].first.end());
		pending.erase(pending.begin() + insertIndex);
		next_jacob -= 1;
	}
	std::cout << std::endl;
	draw_tab("New sequence");
	printGroup(sequence, sizeElement, nbOfGroups);
	printOdd(sequence, sizeElement);
	printLabel(sizeElement, nbOfGroups);
	std::cout << std::endl;
}
