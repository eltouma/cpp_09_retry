/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:33:51 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/22 18:43:48 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "checkParams.tpp"
#include "print.tpp"

int	jacobNumber(int n)
{
	int jacob[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763};
	// TO DO: a proteger si n est hors du tableau. throw out_of_range()
	return jacob[n];
}

std::vector<int>::iterator	binarySearch(std::vector<int>::iterator start, std::vector<int>::iterator end, int sizeElement, int valToFind)
{
	std::vector<int>::iterator	it;
	size_t	mid;

	mid  = std::distance(start, end) / sizeElement / 2;
	it = start + mid * sizeElement;

	if (valToFind <	*it)
	{
		if (it == start)
			return (start - (sizeElement - 1));
		return binarySearch(start, it - sizeElement, sizeElement, valToFind);
	}
	else
	{
		if (it == end)
			return (end + 1);
		return binarySearch(it + sizeElement, end, sizeElement, valToFind);
	}
}

void	initPending(std::vector<int> &vect, int sizeElement, std::vector<std::pair<std::vector<int>, int> > &pending)
{
	int	nbElements;
	int	nbElementsToPush;
	std::vector<int>::iterator firstValGroup;
	std::vector<int>::iterator lastValGroup;

	nbElements = vect.size() / sizeElement;
	nbElementsToPush = (nbElements / 2) - 1;
	if (nbElements & 1)
		nbElementsToPush += 1;
	firstValGroup = vect.begin() + sizeElement * 2;
	if (!nbElementsToPush)
		return ;
	for (int i = 0; i < nbElementsToPush; i++)
	{
		std::pair<std::vector<int>, int> tmpPair;
		lastValGroup = firstValGroup + sizeElement - 1;
		tmpPair.first.insert(tmpPair.first.begin(), firstValGroup, lastValGroup + 1);
		if (vect.end() - 1 != lastValGroup)
			tmpPair.second = *(lastValGroup + 1);
		else
			tmpPair.second = -1;
		pending.push_back(tmpPair);
		firstValGroup = vect.erase(firstValGroup, lastValGroup + 1);
		firstValGroup += sizeElement;
	}
	std::cout << std::endl;
}

void	sortPairs(std::vector<int> &vect, int sizeElement)
{
	int	nbOfGroups;
	int	firstElement;
	int	lastElement;


	nbOfGroups = vect.size() / (sizeElement * 2);
	firstElement = sizeElement - 1;
	lastElement = sizeElement - 1 + sizeElement;
	if (nbOfGroups)
	{
		std::cout << "Number of pairs " << nbOfGroups << std::endl;
		std::cout << "Original pairs" << std::endl;
		printGroup(vect, sizeElement, nbOfGroups);
		std::cout << std::endl;
	}
	for (int i = 1; i <= nbOfGroups; i++)
	{
		if (vect[firstElement] < vect[lastElement])
			std::cout << "{" << vect[firstElement] << ", " << vect[lastElement] << "} ";
		if (vect[firstElement] > vect[lastElement])
		{
			for (int j = 0; j < sizeElement; j++)
			{
				std::swap(vect[firstElement - j], vect[lastElement - j]);
				std::cout << "{\033[1;36m" << vect[firstElement - j];
				if (j < sizeElement * 2 - 1)
					std::cout << ", " << vect[lastElement - j] << "\033[0m} ";
			}
		}
		firstElement += sizeElement * 2;
		lastElement += sizeElement * 2;
	}
	if (nbOfGroups)
	{
		std::cout << "\nSorted pairs" << std::endl;
		printGroup(vect, sizeElement, nbOfGroups);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void	mergeInsert(std::vector<int> &vect, int sizeElement)
{
	int nbOfGroups = vect.size() / (sizeElement * 2);
	int	jacobIn = 0;
	std::vector<std::pair<std::vector<int>, int> > pending;
	std::vector<int>::iterator end;
	std::vector<int>::iterator insertIt;

	sortPairs(vect, sizeElement);
	if (vect.size() / sizeElement >= 2)
		mergeInsert(vect, sizeElement * 2);
	else
		return ;
	std::cout << "------------------------------------------------------------------------------------------------\n" << std::endl;
	draw_tab("Current sequence");
	printGroup(vect, sizeElement, nbOfGroups);
	printOdd(vect, sizeElement);
	printLabel(sizeElement, nbOfGroups);
	initPending(vect, sizeElement, pending);
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
		end = find(vect.begin(), vect.end(), pending[insertIndex].second) - 1;
		insertIt = binarySearch(vect.begin() + sizeElement - 1, end, sizeElement, pending[insertIndex].first.back());
		vect.insert(insertIt, pending[insertIndex].first.begin(), pending[insertIndex].first.end());
		pending.erase(pending.begin() + insertIndex);
		next_jacob -= 1;
	}
	std::cout << std::endl;
	draw_tab("New sequence");
	printGroup(vect, sizeElement, nbOfGroups);
	printOdd(vect, sizeElement);
	printLabel(sizeElement, nbOfGroups);
	std::cout << std::endl;
}

int	isSorted(std::vector<int> vect)
{
	int	min;

	min = vect.at(0);
	for (size_t it = 1; it != vect.size(); it++)
	{
		if (min > vect.at(it))
			return (std::cerr << "Error\nUnsorted list" << std::endl, 1);
		min = it;
	}
	return (0);
}
