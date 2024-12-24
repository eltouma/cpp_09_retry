/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:33:51 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/23 01:36:14 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	char	*input;
	char	*buff;
	std::vector<int>	vect;
	std::vector<int>::iterator	itV;
	std::vector<int>	tmpV;

	std::deque<int>		deq;
	std::deque<int>::iterator	itD;
	std::deque<int>	tmpD;

	timeval startTime;
	timeval endTime;
	size_t	parsingTime;
	size_t	sortTime;

	input = NULL;
	buff = NULL;
	if (argc < 2)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	draw_tab("TEST VECTOR");
	gettimeofday(&startTime, NULL);
	input = isString(argc, argv, input, buff);
	if (parseInput(input, vect, buff))
		return (1);
	if (vect.size() == 1)
		return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
	if (handleDuplicate(vect, itV, buff))
		return (std::cerr << "Error\nWrong input: duplicate" << std::endl, 1);
	tmpV.insert(tmpV.begin(), vect.begin(), vect.end());
	gettimeofday(&endTime, NULL);
	parsingTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + (endTime.tv_usec - startTime.tv_usec);
	gettimeofday(&startTime, NULL);
	mergeInsertVect(vect, 1);
	gettimeofday(&endTime, NULL);
	sortTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + (endTime.tv_usec - startTime.tv_usec);
	if (buff)
		delete [] buff;
	std::cout << "\n\n------------------------------------------------------------------------------------------------\n" << std::endl;
	draw_tab("TEST DEQUE");
	gettimeofday(&startTime, NULL);
	input = isString(argc, argv, input, buff);
	parseInput(input, deq, buff);
	tmpD.insert(tmpD.begin(), deq.begin(), deq.end());
	gettimeofday(&endTime, NULL);
	parsingTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + (endTime.tv_usec - startTime.tv_usec);
	gettimeofday(&startTime, NULL);
	mergeInsertDeq(deq, 1);
	gettimeofday(&endTime, NULL);
	sortTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + (endTime.tv_usec - startTime.tv_usec);
	printResult(vect, tmpV, deq, tmpD, parsingTime, sortTime);
	if (buff)
		delete [] buff;
}
