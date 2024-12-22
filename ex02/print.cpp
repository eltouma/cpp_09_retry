/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:34:07 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/22 20:34:58 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
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

*/
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

/*
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
*/

/*
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
*/

/*
template <class T>
void	printSequence(T sequence)
{
	for (size_t i = 0; i < sequence.size(); i++)
		std::cout << sequence[i] << " ";
	std::cout << "\n\n";
}

*/
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
