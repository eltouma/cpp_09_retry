/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:16:03 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/21 23:17:15 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int	handleFileError(std::ifstream *file)
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

static void	parseLine(std::map<std::string, float> &btc, std::string line)
{
	std::map<std::string, float>::iterator it;
	char	*end;
	std::string::size_type	pipe;
	std::string	date;
	float	val;
	int	n;

	pipe = line.find('|');
	if (pipe == std::string::npos)
		{ std::cerr << "Error: Bad input => '" << line << "'" << std::endl; return; }
	date = line.substr(0, pipe - 1);
	n = checkDate(date);
	if (n)
		{ printError(n, date); return; }
	val = strtof((line.substr(pipe + 1)).c_str(), &end);
	if (*end != '\0')
		{ std::cerr << "Error: wrong type" << std::endl; return; }
	if (val < 0)
		{ std::cerr << "Error: not a positive number." << std::endl; return; }
	if (static_cast<long>(val) > INT_MAX)
		{ std::cerr << "Error: too large number." << std::endl; return; }
	it = btc.lower_bound(date);
	if (it == btc.end() || it->first != date)
		--it;
	std::cout << date << " => " << val << " = " << val * it->second << std::endl;
}

void	loadInput(std::map<std::string, float> &btc, std::string input)
{	
	std::ifstream	file(input.c_str());
	std::string		line;

	if (handleFileError(&file))
		return ;
	if (getline(file, line))
		if (line != "date | value")
			parseLine(btc, line);
	while (getline(file, line, '\n'))
		parseLine(btc, line);
}
