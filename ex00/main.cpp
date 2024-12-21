/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:51:35 by ahayon            #+#    #+#             */
/*   Updated: 2024/12/21 20:36:40 by eltouma          ###   ########.fr       */
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
			std::cerr << "Error: Invalid day. Only 30 days in this month => " << date << std::endl;
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
	if (day < MIN_DAY || (month == 2 && !isLeap(year)))
		return (4);
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

void	loadDB(std::map<std::string, float> &btc, std::string filename)
{
	char	*end;
	std::string::size_type	pos;
	std::string	date;
	float	rate;
	std::string	line;
	std::ifstream	file(filename.c_str(), std::ios::in);

	if (handleFileError(&file))
		return ;
	if (getline(file, line)) {};
	while (getline(file, line, '\n'))
	{
		pos = line.find(',');
		date = line.substr(0, pos);
		rate = strtof((line.substr(pos + 1)).c_str(), &end);
		if (*end != '\0')
		{ std::cerr << "Error\nParsing date: " << rate << std::endl; continue; }
		btc[date] = rate;
	}
}

void	loadInput(std::map<std::string, float> &btc, std::string input)
{	
	std::ifstream	file(input.c_str());
	std::string		line;
	std::map<std::string, float>::iterator it;
	char	*end;
	std::string::size_type	pipe;
	std::string	date;
	float	val;
	int	n;

	if (handleFileError(&file))
		return ;
	if (getline(file, line)) {};
	while (getline(file, line, '\n'))
	{
		pipe = line.find('|');
		if (pipe == std::string::npos)
		{ std::cerr << "Error: Bad input => '" << line << "'" << std::endl; continue; }
		date = line.substr(0, pipe - 1);
		n = checkDate(date);
		if (n)
		{ printError(n, date); continue; }
		val = strtof((line.substr(pipe + 1)).c_str(), &end);
		if (*end != '\0')
		{ std::cerr << "Error: wrong type" << std::endl; continue; }
		it = btc.lower_bound(date);
		if (it == btc.end() || it->first != date)
			--it;
		std::cout << date << " => " << val << " = " << val * it->second << std::endl;
	}
}

int	main(int argc, char **argv)
{
	std::map<std::string, float> btc;

	if (argc != 2)
		return (std::cerr << "Error:\nPlease enter a valid file as parameter" << std::endl, 1);
	loadDB(btc, "data.csv");
	loadInput(btc, argv[1]);
	return (0);
}
