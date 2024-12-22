/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:37:20 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/22 23:59:29 by eltouma          ###   ########.fr       */
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
	draw_tab("Current vector");
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
	draw_tab("New vector");
	printGroup(vect, sizeElement, nbOfGroups);
	printOdd(vect, sizeElement);
	printLabel(sizeElement, nbOfGroups);
	std::cout << std::endl;
}

void	mergeInsertDeq(std::deque<int> &deq, int sizeElement)
{
	int nbOfGroups = deq.size() / (sizeElement * 2);
	int	jacobIn = 0;
	std::deque<std::pair<std::deque<int>, int> > pending;
	std::deque<int>::iterator end;
	std::deque<int>::iterator insertIt;

	sortPairs(deq, sizeElement);
	if (deq.size() / sizeElement >= 2)
		mergeInsertDeq(deq, sizeElement * 2);
	else
		return ;
	std::cout << "------------------------------------------------------------------------------------------------\n" << std::endl;
	draw_tab("Current deque");
	printGroup(deq, sizeElement, nbOfGroups);
	printOdd(deq, sizeElement);
	printLabel(sizeElement, nbOfGroups);
	initPending(deq, sizeElement, pending);
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
		end = find(deq.begin(), deq.end(), pending[insertIndex].second) - 1;
		insertIt = binarySearch<std::deque<int> >(deq.begin() + sizeElement - 1, end, sizeElement, pending[insertIndex].first.back());
		deq.insert(insertIt, pending[insertIndex].first.begin(), pending[insertIndex].first.end());
		pending.erase(pending.begin() + insertIndex);
		next_jacob -= 1;
	}
	std::cout << std::endl;
	draw_tab("New deque");
	printGroup(deq, sizeElement, nbOfGroups);
	printOdd(deq, sizeElement);
	printLabel(sizeElement, nbOfGroups);
	std::cout << std::endl;
}
