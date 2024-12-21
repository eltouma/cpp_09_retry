/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkParams.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayon <ahayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:03:22 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/21 01:04:53 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 

int	checkInput(char *s, std::vector<int> &vect)
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
	vect.push_back(nb);
	return (0);
}

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
                input = strtok(buff, " ");
        }
        else
                input = strtok(argv[1], " ");
        return (input);
}

int	handleDuplicate(std::vector<int> vect, std::vector<int>::iterator it, char *buff)
{
	std::vector<int>	tmp;
	tmp.insert(tmp.begin(), vect.begin(), vect.end());
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

