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

template <class T, class I>
int	handleDuplicate(T &sequence, I it, char *buff)
{
	T tmp;
	tmp.insert(tmp.begin(), sequence.begin(), sequence.end());
	sort(tmp.begin(), tmp.end());
	it = adjacent_find(tmp.begin(), tmp.end());
	if (it != tmp.end())
	{
		if (buff)
			delete [] buff;
		return (1);
	}
	return (0);
}

template <class T>
int	isSorted(T sequence)
{
	int	min;

	min = sequence.at(0);
	for (size_t it = 1; it != sequence.size(); it++)
	{
		if (min > sequence.at(it))
			return (std::cerr << "Error\nUnsorted list" << std::endl, 1);
		min = it;
	}
	return (0);
}
