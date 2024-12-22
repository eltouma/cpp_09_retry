/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:33:51 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/23 00:51:07 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printResult(std::vector<int> vect, std::vector<int> tmpV, std::deque<int> deq, std::deque<int> tmpD)
{
	std::cout << "\n\n------------------------------------------------------------------------------------------------\n" << std::endl;
	draw_tab("Final result");
	std::cout << "Original vector" << std::endl;
	printSequence(tmpV);
	std::cout << "\n\nCurrent vector" << std::endl;
	printSequence(vect);
	if (!isSorted(vect))
		std::cout << "\nVector is \033[32msuccessfully\033[0m sorted 🥳\n\n" << std::endl;
	std::cout << "Original deque" << std::endl;
	printSequence(tmpD);
	std::cout << "\n\nCurrent deque" << std::endl;
	printSequence(deq);
	if (!isSorted(deq))
		std::cout << "\nDeque is \033[32msuccessfully\033[0m sorted 🥳\n\n" << std::endl;
}

int	main(int argc, char **argv)
{
	char	*input;
	char	*buff;
	std::vector<int>	vect;
	std::vector<int>	pending;
	std::vector<int>::iterator	itV;
	std::vector<int>	tmpV;

	std::deque<int>		deq;
	std::deque<int>::iterator	itD;
	std::deque<int>	tmpD;

	input = NULL;
	buff = NULL;
	if (argc < 2)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	draw_tab("TEST VECTOR");
	input = isString(argc, argv, input, buff);
	parseInput(input, vect, buff);
	if (vect.size() == 1)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	if (handleDuplicate(vect, itV, buff))
		return (std::cerr << "Error\nWrong input: duplicate" << std::endl, 1);
	tmpV.insert(tmpV.begin(), vect.begin(), vect.end());
	mergeInsertVect(vect, 1);
	std::cout << "\n\n------------------------------------------------------------------------------------------------\n" << std::endl;
	if (buff)
		delete [] buff;
	draw_tab("TEST DEQUE");
	input = isString(argc, argv, input, buff);
	parseInput(input, deq, buff);
	if (deq.size() == 1)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	if (handleDuplicate(deq, itD, buff))
		return (std::cerr << "Error\nWrong input: duplicate" << std::endl, 1);
	tmpD.insert(tmpD.begin(), deq.begin(), deq.end());
	mergeInsertDeq(deq, 1);
	printResult(vect, tmpV, deq, tmpD);
	if (buff)
		delete [] buff;
}
