/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayon <ahayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/20 16:52:48 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
   std::vector<int> generateJacobsthal(int maxValue) 
   {
   std::vector<int> jacobsthal;

   jacobsthal.push_back(0);
   jacobsthal.push_back(1);
   for (unsigned long i = 2; i < static_cast<unsigned long>(maxValue); ++i) 
   {
   int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
   if (next > maxValue) break;
   jacobsthal.push_back(next);
   }
   return jacobsthal;
   }

   std::vector<int> JacobOrder(unsigned long n)
   {
   std::vector<int> jacob = generateJacobsthal(static_cast<int>(n));
   std::vector<int> jacobOrder;

//std::cout << "jacob.begin() " << *jacob.begin() << "\n";
for (std::vector<int>::iterator it = jacob.begin() + 3; it < jacob.end(); it++)
{
int prevValue = *(it - 1);
//std::cout << "prevValue " << prevValue << "\n";
for (int currValue = *it; currValue > prevValue; currValue--)
{
//std::cout << "dans le if prevValue " << prevValue << "\n";
//std::cout << "dans le if currValue " << currValue << "\n";
jacobOrder.push_back(currValue);
}
}
for (std::vector<int>::iterator it = jacobOrder.begin(); it < jacobOrder.end(); it++)
std::cout << "jacob order : " << *it << std::endl;

return (jacobOrder);
}
 */

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
	std::cout << "mid " << mid << " *it " << *it << " start " << *start << " end " << *end << std::endl;

	if (valToFind <	*it)
	{
		if (it == start)
		{
			std::cout << "it: " << *it << " == start: " << *start << std::endl;
			return (start - (sizeElement - 1));
		}
		return binarySearch(start, it - sizeElement, sizeElement, valToFind);
	}
	else
	{
		if (it == end)
		{
			std::cout << "it: " << *it << " == end: " << *end << std::endl;
			return (end + 1);
		}
		return binarySearch(it + sizeElement, end, sizeElement, valToFind);
	}
}

void initPending(std::vector<int> &vect, int sizeElement, std::vector<std::pair<std::vector<int>, int> > &pending)
{
	int	nbElements;
	int	nbElementsToPush;
	std::vector<int>::iterator firstValGroup;
	std::vector<int>::iterator lastValGroup;

	std::cout << "\n\033[1;36mvect.size() \033[0m" << vect.size() << " sizeElement " << sizeElement << "\n";
	nbElements = vect.size() / sizeElement;
	nbElementsToPush = (nbElements / 2) - 1;
	if (nbElements & 1)
		nbElementsToPush += 1;
	std::cout << "nbElements " << nbElements << ", nbElementsToPush " << nbElementsToPush << "\n";
	firstValGroup = vect.begin() + sizeElement * 2;
	if (!nbElementsToPush)
		return ;
	std::cout << "firstValGroup " << *firstValGroup << "\n";
	for (int i = 0; i < nbElementsToPush; i++)
	{
		std::pair<std::vector<int>, int> tmpPair;
		lastValGroup = firstValGroup + sizeElement - 1;
		printVect(vect);
		std::cout << "lastValGroup " << *lastValGroup << " end " << *(vect.end() - 1) << "\n";
		tmpPair.first.insert(tmpPair.first.begin(), firstValGroup, lastValGroup + 1);
		if (vect.end() - 1 != lastValGroup)
			tmpPair.second = *(lastValGroup + 1);
		else
			tmpPair.second = -1;
		pending.push_back(tmpPair);
		firstValGroup = vect.erase(firstValGroup, lastValGroup + 1);
		std::cout << "\n\n";
		printVect(vect);
		std::cout << "\n\n";
		firstValGroup += sizeElement;
	}
}

void	printGroup(std::vector<int> vect, int sizeElement, int nbOfGroups)
{
	if (!nbOfGroups)
		return ;
	for (int i = 0; i < nbOfGroups; ++i) {
		std::cout << "{";
		for (int j = 0; j < sizeElement * 2; ++j) {
			std::cout << vect[i * sizeElement * 2 + j];
			if (j < sizeElement * 2 - 1)
				std::cout << ", ";
		}
		std::cout << "}";
		if (i < nbOfGroups - 1) std::cout << ", ";
	}
	std::cout << std::endl;
}

void	sortPairs(std::vector<int> &vect, int sizeElement)
{
	int	nbOfGroups;
	int	firstElement;
	int	lastElement;


	nbOfGroups = vect.size() / (sizeElement * 2);
	std::cout << "Number of groups " << nbOfGroups << std::endl;
	firstElement = sizeElement - 1;
	lastElement = sizeElement - 1 + sizeElement;
	//std::cout << "Element size: " << sizeElement << ". Amount of nbs in a group: " << sizeElement * 2 << std::endl;
	std::cout << "Original pairs" << std::endl;
	printGroup(vect, sizeElement, nbOfGroups);
	for (int i = 1; i <= nbOfGroups; i++)
	{
		if (vect[firstElement] > vect[lastElement])
			for (int j = 0; j < sizeElement; j++)
				std::swap(vect[firstElement - j], vect[lastElement - j]);
		firstElement += sizeElement * 2;
		lastElement += sizeElement * 2;
	}
	std::cout << "Sorted pairs" << std::endl;
	printGroup(vect, sizeElement, nbOfGroups);
	std::cout << std::endl;
}

void	printPending(std::vector<std::pair<std::vector<int>, int> > pending)
{
	for (size_t i = 0; i < pending.size(); i++)
	{
		std::cout << "first:\033[33m";
		for (size_t j = 0; j < pending[i].first.size(); j++)
		{
			std::cout << " " << pending[i].first.at(j);
		}
		std::cout << " \033[0msecond: " << pending[i].second << "\n";
	}

}

void	printVect(std::vector<int> vect)
{
	std::cout << "LE vect: " << std::endl;
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << "\n\n";

}

void	mergeInsert(std::vector<int> &vect, int sizeElement)
{
	int	jacobIn = 0;
	std::vector<std::pair<std::vector<int>, int> > pending;
	std::vector<int>::iterator end;
	std::vector<int>::iterator insertIt;

	sortPairs(vect, sizeElement);
	if (vect.size() / sizeElement >= 2)
		mergeInsert(vect, sizeElement * 2);
	else
		return ;
	std::cout << "vect.size() " << vect.size() << ", ";
	std::cout << vect.size() / sizeElement << " groups of " << sizeElement << " elements\n";
	//	std::vector<int> jacobOrder = JacobOrder(vect.size());
	//	unsigned long total_size = vect.size();
	printVect(vect);
	initPending(vect, sizeElement, pending);
	printPending(pending);
	int	prev_jacob = 1;
	int	next_jacob = jacobNumber(jacobIn);
	jacobIn++;
	size_t	insertIndex;
	std::cout << "\t\tVect AVANT bouble\n\n";
	printVect(vect);
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
		std::cout << "\n\033[1;32mvect.size() \033[0m" << vect.size() << "\n";
		end = find(vect.begin(), vect.end(), pending[insertIndex].second) - 1;
		if (pending[insertIndex].second == -1)
		{
			std::cout << "\033[1;31mend == -1; " << *end << " sizeElement = " << sizeElement << " \033[0m\n";
			printVect(vect);
		}
		insertIt = binarySearch(vect.begin() + sizeElement - 1, end, sizeElement, pending[insertIndex].first.back());
		std::cout << "insertIt " << *insertIt << " pending[insertIndex].first.begin() " << *pending[insertIndex].first.begin() << " pending[insertIndex].first.end() " << *(pending[insertIndex].first.end() - 1) << "\n";
		vect.insert(insertIt, pending[insertIndex].first.begin(), pending[insertIndex].first.end());
		pending.erase(pending.begin() + insertIndex);
		next_jacob -= 1;
		std::cout << "\t\tVect en fin de bouble\n\n";
		printVect(vect);
	}
	/*
	   std::vector<int>::iterator jacIt = jacobOrder.begin();

	   while (vect.size() != total_size)
	   {
	   std::cout << "\nect.size() \033[0m" << vect.size() << "\n";
	   std::cout << "\n\tdebut boucle insertion jacIt = " << *jacIt << " ett JacIt - 2 :" << *jacIt - 2 << " ok" << std::endl;
	   if (pending[*jacIt - 2].second) {

	   std::cout << "suite boucle insertion" << std::endl;
	   std::cout << "pending[*jacIt -2 ].second " << pending[*jacIt -2 ].second << " OK" << "\n";
	   end = find(vect.begin(), vect.end(), pending[*jacIt -2 ].second) - 1;
	   if (end == vect.end())
	   return ;
	   std::cout << "end " << *end << " ";
	   insertIt = binarySearch(vect.begin() + sizeElement - 1, end, sizeElement, pending[*jacIt - 2].first.back());
	   std::cout << "insertIt " << *insertIt << " pending[*jacIt - 2].first.begin() " << *pending[*jacIt - 2].first.begin() << " pending[*jacIt - 2].first.end() " << *(pending[*jacIt - 2].first.end() - 1) << "\n";
	   vect.insert(insertIt, pending[*jacIt - 2].first.begin(), pending[*jacIt - 2].first.end());
	//			pending.erase(pending.begin());
	std::cout << "\t\tVect en fin de bouble\n\n";
	printVect(vect);
	}
	std::cout << "*jacIt: " << *jacIt << "\n";
	if  (pending[*jacIt - 2].second == -1)
	{
	std::cout << "\033[1;31mon est -1\033[0m\n";
	jacIt -= 2;
	std::cout << "*jacIt: " << *jacIt << "\n";
	//		return ;
	}
	jacIt++;
	//	}
	}
	 */
std::cout << "PRINT VECT TEST\n";
printVect(vect);
pending.clear();
}

int	main(int argc, char **argv)
{
	char	*input;
	char	*buff;
	std::vector<int>	vect;
	std::vector<int>	main;
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
	std::cout << "\n";
	if (vect.size() == 1)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	mergeInsert(vect, 1);
	std::cout << "\nAfter sorting pairs:\n";
	for (it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	if (buff)
		delete [] buff;
}
