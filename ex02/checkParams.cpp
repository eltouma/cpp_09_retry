/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkParams.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:06:16 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/22 21:34:19 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 

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
