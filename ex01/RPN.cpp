/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/23 02:03:01 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
	nb = strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str() || *endptr != '\0')
		throw std::invalid_argument("Error\nBad input");
	if (nb < INT_MIN)
		throw std::invalid_argument("Error\nOut of range");
	if (nb > 9)
		throw std::invalid_argument("Error\nGreater than or equal to 10");
	lst.push_back(nb);
	return (0);
}
