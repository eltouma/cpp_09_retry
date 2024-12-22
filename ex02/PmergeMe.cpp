/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:37:20 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/22 23:32:34 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	jacobNumber(int n)
{
	int jacob[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763};
	return jacob[n];
}

void	mergeInsertVect(std::vector<int> &vect, int sizeElement)
{
	int nbOfGroups = vect.size() / (sizeElement * 2);
	int	jacobIn = 0;
	std::vector<std::pair<std::vector<int>, int> > pending;
	std::vector<int>::iterator end;
	std::vector<int>::iterator insertIt;

	sortPairs(vect, sizeElement);
	if (vect.size() / sizeElement >= 2)
		mergeInsertVect(vect, sizeElement * 2);
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
		insertIt = binarySearch<std::vector<int> >(vect.begin() + sizeElement - 1, end, sizeElement, pending[insertIndex].first.back());
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
