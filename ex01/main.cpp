/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/22 01:06:13 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try {
		char	*input;
		std::list<double>	lst;

		if (argc != 2)
			return (std::cerr << "Error\nWrong amount of arguments" << std::endl, 1);
		input = strtok(argv[1], " ");
		while (input != NULL)
		{
			if (checkInput(input, lst))
				return (std::cerr << "Error\nInvalid RPN format" << std::endl, 1);
			input = strtok(NULL, " ");
		}
		if (!lst.size())
			return (std::cerr << "Error\nEmpty string" << std::endl, 1);
		if (lst.size() != 1)
			return (std::cerr << "Error\nStack size is greater than 1 at the end" << std::endl, 1);
		std::cout << lst.back() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
