/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/06 13:54:25 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstring>
#include <cstdlib>
#include <limits.h>
#include <cerrno>
#include <list>

double	doOp(double first, double second, char op)
{
	switch (op)
	{
		case '+':
			return (first + second);
		case '-':
			return (second - first);
		case '*':
			return (first * second);
		case '/':
			if (first == 0)
				throw std::invalid_argument("ZeroDivisionError (divided by 0)");
			return (second / first);
	}
	return (0);
}

int	checkInput(char *s, std::list<double> &lst)
{
	std::string	str;
	size_t	size;
	long	nb;
	double	result;
	double	first;
	double	second;
	char	*endptr;

	str = s;
	size = str.length();
	if ((str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*') && size == 1)
	{
		if (lst.size() < 2)
			return (1);
		first = lst.back();
		lst.pop_back();
		second = lst.back();
		lst.pop_back();
		result  = doOp(first, second, str[0]);
		lst.push_back(result);
		return (0);
	}
	errno = 0;
	nb = strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str() || *endptr != '\0')
		return (1);
	if (errno == ERANGE || nb < INT_MIN || nb > 9)
		return (1);
	lst.push_back(nb);
	return (0);
}

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
				return (std::cerr << "Error" << std::endl, 1);
			input = strtok(NULL, " ");
		}
		if (lst.size() != 1)
			return (std::cerr << "Error: stack size is greater than 1 at the end" << std::endl, 1);
		std::cout << lst.back() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
