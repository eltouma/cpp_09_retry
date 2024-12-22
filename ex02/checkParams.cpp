/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkParams.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:06:16 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/22 20:33:36 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 

/*
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
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

char    *isString(int argc, char **argv, char *input, char *&buff)
{
        std::string str;
        char    *dup;

        if (argc > 2)
        {
                for (int i = 1; i < argc; i++)
                {
                        str.reserve(ft_strlen(argv[i]));
                        str += argv[i];
                        str.reserve(1);
                        str += " ";
                }
                buff = new char[str.size() + 1];
                dup = strcpy(buff, str.c_str());
                input = strtok(dup, " ");
        }
        else
                input = strtok(argv[1], " ");
        return (input);
}

/*
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
*/
