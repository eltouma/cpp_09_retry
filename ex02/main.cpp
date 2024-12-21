/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayon <ahayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/21 05:21:57 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
//	std::cout << "mid " << mid << " *it " << *it << " start " << *start << " end " << *end << std::endl;

	if (valToFind <	*it)
	{
		if (it == start)
		{
//			std::cout << "it: " << *it << " == start: " << *start << std::endl;
			return (start - (sizeElement - 1));
		}
		return binarySearch(start, it - sizeElement, sizeElement, valToFind);
	}
	else
	{
		if (it == end)
		{
//			std::cout << "it: " << *it << " == end: " << *end << std::endl;
			return (end + 1);
		}
		return binarySearch(it + sizeElement, end, sizeElement, valToFind);
	}
}

void	initPending(std::vector<int> &vect, int sizeElement, std::vector<std::pair<std::vector<int>, int> > &pending, int nbOfGroups)
{
	(void)nbOfGroups;
	int	nbElements;
	int	nbElementsToPush;
	std::vector<int>::iterator firstValGroup;
	std::vector<int>::iterator lastValGroup;

	nbElements = vect.size() / sizeElement;
	nbElementsToPush = (nbElements / 2) - 1;
	if (nbElements & 1)
		nbElementsToPush += 1;
//	std::cout << "\n\t" << __func__ << "\n";
//	std::cout << "\n\033[1;36mVVVVVVvect.size() \033[0m" << vect.size() << " sizeElement " << sizeElement << "\n";
//	std::cout << "nbElements " << nbElements << ", nbElementsToPush " << nbElementsToPush << "\n";
	firstValGroup = vect.begin() + sizeElement * 2;
	if (!nbElementsToPush)
		return ;
//	std::cout << "firstValGroup " << *firstValGroup << "\n";
	//printPending(pending);
	for (int i = 0; i < nbElementsToPush; i++)
	{
		std::pair<std::vector<int>, int> tmpPair;
		lastValGroup = firstValGroup + sizeElement - 1;
//		std::cout << "lastValGroup " << *lastValGroup << " end " << *(vect.end() - 1) << "\n";
//		std::cout << "ATTENTION TOUT LE MONDE JE FAIL\n";
//		printGroup(vect, sizeElement, nbOfGroups);
//		printOdd(vect, sizeElement);
//		std::cout << "lastValGroup " << *lastValGroup << " end " << *(vect.end() - 1) << "\n";
		tmpPair.first.insert(tmpPair.first.begin(), firstValGroup, lastValGroup + 1);
		if (vect.end() - 1 != lastValGroup)
			tmpPair.second = *(lastValGroup + 1);
		else
			tmpPair.second = -1;
		pending.push_back(tmpPair);
		firstValGroup = vect.erase(firstValGroup, lastValGroup + 1);
		//std::cout << "\n\n";
	//	printGroup(vect, sizeElement, nbOfGroups / 2);
	//	std::cout << "\n\n";
		firstValGroup += sizeElement;
	}
//	std::cout << "LE PENDING MESSIEURS DAMES" << "\n";
//	printPending(pending);
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
		std::cout << "Number of groups " << nbOfGroups << std::endl;
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
	std::cout << "------------------------------------------------------------------------------------------------\n\n";

	//std::cout << "\tvect.size() " << vect.size() << ", ";
//	std::cout << nbOfGroups << " groups of " << sizeElement * 2 << " elements\n";

	draw_tab("Current vector");
	printGroup(vect, sizeElement, nbOfGroups);
	printOdd(vect, sizeElement);
	initPending(vect, sizeElement, pending, nbOfGroups);
	if (!pending.size())
		std::cout << "No pend - no insertions. Move on" << std::endl;
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
//		std::cout << "\n\033[1;32mvect.size() \033[0m" << vect.size() << "\n";
		end = find(vect.begin(), vect.end(), pending[insertIndex].second) - 1;
		if (pending[insertIndex].second == -1)
		{
//			std::cout << "\033[1;31mend == -1; " << *end << " sizeElement = " << sizeElement << " \033[0m\n";
			//			printGroup(vect, sizeElement, nbOfGroups);
		}
		insertIt = binarySearch(vect.begin() + sizeElement - 1, end, sizeElement, pending[insertIndex].first.back());
//		std::cout << "insertIt " << *insertIt << " pending[insertIndex].first.begin() " << *pending[insertIndex].first.begin() << " pending[insertIndex].first.end() " << *(pending[insertIndex].first.end() - 1) << "\n";
		vect.insert(insertIt, pending[insertIndex].first.begin(), pending[insertIndex].first.end());
		pending.erase(pending.begin() + insertIndex);
		next_jacob -= 1;
//		std::cout << "\t\tVect en fin de bouble\n\n";
		//		printGroup(vect, sizeElement, nbOfGroups);
	}
	std::cout << std::endl;
	draw_tab("New vector");
	printGroup(vect, sizeElement, nbOfGroups);
	printOdd(vect, sizeElement);
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	char	*input;
	char	*buff;
	std::vector<int>	vect;

	std::vector<int>	pending;
	std::vector<int>::iterator	it;

	input = NULL;
	buff = NULL;
	if (argc < 2)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	input = isString(argc, argv, input, buff);
	std::cout << "input = ";
	while (input != NULL)
	{
		std::cout << input << " ";
		if (checkInput(input, vect))
		{
			if (buff)
				delete [] buff;
			return (std::cerr << "Error\nWrong input" << std::endl, 1);
		}
		input = strtok(NULL, " ");
	}
	std::cout << "\n\n";
	if (vect.size() == 1)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	if (handleDuplicate(vect, it, buff))
		return (std::cerr << "Error\nWrong input: duplicate" << std::endl, 1);
	mergeInsert(vect, 1);
	std::cout << "\nSorted list:\n";
	for (it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	if (buff)
		delete [] buff;
}
