#pragma once

#include "PmergeMe.hpp"

template <class T>
int	checkInput(char *s, T &sequence)
{
	std::string	str;
	long	nb;
	char	*endptr;

	str = s;
	errno = 0;
	nb = strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str() || *endptr != '\0')
		return (1);
	if (errno == ERANGE || nb < 0 || nb > INT_MAX)
		return (1);
	sequence.push_back(nb);
	return (0);
}

