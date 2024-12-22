/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:15:48 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/22 00:47:39 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	checkDateFormat(std::string date)
{
	if (!date.length() || date.length() != 10)
		return (0);
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return (0);
		}
		else if (!isdigit(date[i]))
			return (0);
	}
	return (1);
}

int	isLeap(int year)
{
	if (!(year % 4) && (year % 100 || !(year % 400)))
		return (1);
	return (0);
}

void	printError(int n, std::string date)
{
	switch (n)
	{
		case 1:
			std::cerr << "Error: Invalid format => " << date << std::endl;
			break ;
		case 2:
			std::cerr << "Error: Invalid year => " << date << std::endl;
			break ;
		case 3:
			std::cerr << "Error: Invalid month => " << date << std::endl;
			break ;
		case 4:
			std::cerr << "Error: Not a leap year => " << date << std::endl;
			break ;
		case 5:
			std::cerr << "Error: Invalid day. Less than 30 days in this month => " << date << std::endl;
			break ;
		case 6:
			std::cerr << "Error: Invalid day => " << date << std::endl;
	}
}

int	checkDate(std::string date)
{
	int	year;
	int	month;
	int	day;
	std::stringstream	sYear;
	std::stringstream	sMonth;
	std::stringstream	sDay;

	if (!checkDateFormat(date))
		return (1);
	sYear << date.substr(0, 4).c_str();
	sYear >> year;
	sMonth << date.substr(5, 6).c_str();
	sMonth >> month;
	sDay << date.substr(8, 9).c_str();
	sDay >> day;
	if (year < MIN_YEAR || year > MAX_YEAR)
		return (2);
	if (month < JANUARY || month > DECEMBER)
		return (3);
	if (month == 2)
	{
		if (day == LEAP && !isLeap(year))
			return (4);
		if (day > LEAP)
			return (6);
		return (0);
	}
	if (day < MIN_DAY || (!(month % 2) && day > EVEN))
		return (5);
	if (day < MIN_DAY || (month % 2 && day > ODD))
		return (6);
	return (0);
}

int	handleFileError(std::ifstream *file)
{
	if (!file->is_open())
		return (std::cerr << "Error: could not open file." << std::endl, 1);
	return (0); 
}
