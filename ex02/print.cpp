/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayon <ahayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/21 05:25:50 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printGroup(std::vector<int> vect, int sizeElement, int nbOfGroups)
{
	int	middle;
	int	last;
//	std::cout << "sizeElement: " << sizeElement << " nbOfGroups: " << nbOfGroups << "\n";
	for (int i = 0; i < nbOfGroups; i++)
	{
		std::cout << "{";
		for (int j = 0; j < sizeElement * 2; j++)
		{
			middle = sizeElement - 1;
			last = sizeElement * 2 - 1;
			if (sizeElement > 1 && (j == middle || j == last))
//			if (j == middle || j == last)
				std::cout << "\033[96m" << vect[i * sizeElement * 2 + j] << "\033[0m";
//			else if (sizeElement == 1)
//				std::cout << "\033[96m" << vect[i * sizeElement * 2] << "\033[0m";
			else
				std::cout << vect[i * sizeElement * 2 + j];
			if (j < sizeElement * 2 - 1)
				std::cout << ", ";
		}
		std::cout << "} ";
	}
}

void	printPending(std::vector<std::pair<std::vector<int>, int> > pending)
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

void	printOdd(std::vector<int> vect, int sizeElement)
{ 
	int	remainingSize;

	remainingSize = vect.size() % (sizeElement * 2);
	if (remainingSize > 0)
	{
		for (size_t i = vect.size() - remainingSize; i < vect.size(); ++i)
		{
			std::cout << "\033[1;90m" << vect[i];
			if (i < vect.size() - 1)
				std::cout << ", ";
			std::cout << "\033[0m";
		}
	}
	std::cout << std::endl;
}

void	printVect(std::vector<int> vect)
{
	std::cout << "LE vect: " << std::endl;
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << "\n\n";

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
