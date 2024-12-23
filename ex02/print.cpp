/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:34:07 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/23 01:39:14 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printLabel(int sizeElement, int nbOfGroups)
{
	int	middle;
	int	last;
	int	a;
	int	b;

	a = 1;
	b = 1;
	for (int i = 0; i < nbOfGroups; i++)
	{
		for (int j = 0; j < sizeElement * 2; j++)
		{
			middle = sizeElement - 1;
			last = sizeElement * 2 - 1;
			if (j == middle)
			{
				for (int k = 0; k < (middle * nbOfGroups) * sizeElement / 2 -  1; k++)
					std::cout << " ";
				std::cout << "\033[94mb" << b << "\033[0m";
			}
			if (j == last)
			{
				for (int k = middle; k < (middle * nbOfGroups) * sizeElement / 2 + 2; k++)
					std::cout << " ";
				std::cout << "\033[94ma" << a << "\033[0m ";
			}
		}
		a += 1;
		b += 1;
	}
}

void	printTime(size_t parsingTime, size_t sortTime, std::string name)
{
	std::cout << "Parsing time for " << name << " " << parsingTime << " microseconds" << std::endl;
	std::cout << "Sorting time for " << name << " " << sortTime << " microseconds" << std::endl;
}

void	printResult(std::vector<int> vect, std::vector<int> tmpV, std::deque<int> deq, std::deque<int> tmpD, size_t parsingTime, size_t sortTime)
{
	std::cout << "\n\n------------------------------------------------------------------------------------------------\n" << std::endl;
	draw_tab("Final result");
	std::cout << "Original vector" << std::endl;
	printSequence(tmpV);
	std::cout << "\n\nCurrent vector" << std::endl;
	printSequence(vect);
	if (!isSorted(vect))
		std::cout << "\nVector is \033[32msuccessfully\033[0m sorted 🥳\n\n" << std::endl;
	printTime(parsingTime, sortTime, "vector:");
	std::cout << "\n\nOriginal deque" << std::endl;
	printSequence(tmpD);
	std::cout << "\n\nCurrent deque" << std::endl;
	printSequence(deq);
	if (!isSorted(deq))
		std::cout << "\nDeque is \033[32msuccessfully\033[0m sorted 🥳\n\n" << std::endl;
	printTime(parsingTime, sortTime, "deque:");
}
void	draw_tab(const std::string& str)
{
	const int frame_width = 25;
	int padding = frame_width - (static_cast<int>(str.length()));
	int left_padding = padding / 2;
	int right_padding = padding - left_padding;

	std::cout << "\u250c";
	for (int i = 0; i < frame_width; i++)
		std::cout << "\u2500";
	std::cout << "\u2510\n";
	std::cout << "\u2502";
	for (int i = 0; i < left_padding; i++)
		std::cout << " ";
	std::cout << str;
	for (int i = 0; i < right_padding; i++)
		std::cout << " ";
	std::cout << "\u2502\n";
	std::cout << "\u2514";
	for (int i = 0; i < frame_width; i++)
		std::cout << "\u2500";
	std::cout << "\u2518\n";
}
