/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:33:51 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/22 23:33:27 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	char	*input;
	char	*buff;
	std::vector<int>	vect;
	std::vector<int>	pending;
	std::vector<int>::iterator	itV;
	std::vector<int>	tmp;

	std::deque<int>		deq;
	std::deque<int>::iterator	itD;

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
			return (std::cerr << "\n\nError\nWrong input" << std::endl, 1);
		}
		input = strtok(NULL, " ");
	}
	std::cout << std::endl << std::endl;
	if (vect.size() == 1)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	if (handleDuplicate(vect, itV, buff))
		return (std::cerr << "Error\nWrong input: duplicate" << std::endl, 1);
	tmp.insert(tmp.begin(), vect.begin(), vect.end());
	mergeInsertVect(vect, 1);
	std::cout << "\n\n------------------------------------------------------------------------------------------------\n" << std::endl;
	draw_tab("Final result");
	std::cout << "Original sequence" << std::endl;
	printSequence(tmp);
	std::cout << "Current sequence" << std::endl;
	printSequence(vect);
	if (!isSorted(vect))
		std::cout << "Sequence is successfully sorted 🥳\n";
	if (buff)
		delete [] buff;


	std::cout << "\n\n------------------------------------------------------------------------------------------------\n" << std::endl;
	for (int i = 1; i <= 5; i++)
		deq.push_back(i);
	if (handleDuplicate(deq, itD, NULL))
		return (std::cerr << "Error\nWrong input: duplicate" << std::endl, 1);
	else
	{
		printSequence(deq);
		std::cerr << "Deque est triee" << std::endl;
	}
}
