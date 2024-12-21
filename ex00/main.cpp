/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:51:35 by ahayon            #+#    #+#             */
/*   Updated: 2024/12/21 19:21:41 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// bool	ft_check_txt(std::string str)
// {
// 	if (str.size() < 5)
// 		return false;
// 	if (!str.compare(str.size() - 4, 4, ".txt"))
// 		return true;
// 	return false;
// }



/*
bool	check_format(std::string date) {
	
	if (date.size() != 10)
        return false; 

    for (size_t i = 0; i < date.size(); ++i) {
        if ((i == 4 || i == 7)) {
            if (date[i] != '-')
                return false;
        } 
		else if (!std::isdigit(date[i]))
            return false; 
    }
	return true;
}

bool	check_date(std::string date) {

	if (!check_format(date))
		return false;
		
	int	year 	= atoi((date.substr(0, 4)).c_str());
	int	month 	= atoi((date.substr(5, 6)).c_str());
	int	day 	= atoi((date.substr(8, 9)).c_str());
	if ((year < 2009 || year > 2024) || (month < 1 || month > 12) 
	|| (day < 1 || ((month == 2 && day > 28) || (month % 2 == 0 && day > 30) || (month % 2 == 1 && day > 31))))
		return false;
	return true;
}
*/
#include <sstream>
#define MIN_YEAR 2009
#define MAX_YEAR 2024
#define JANUARY 1
#define DECEMBER 12
#define MIN_DAY 1
#define EVEN 30
#define ODD 31

int	isLeap(int year)
{
	if (!(year % 4) && (year % 100 || !(year % 400))) 
		return (1);
	return (0);
}

int	checkDate(std::string date)
{
//	std::string	str;
//	str.reserve(8);
	int	year;
	int	month;
	int	day;
	std::stringstream	sYear;
	std::stringstream	sMonth;
	std::stringstream	sDay;
	
	sYear << date.substr(0, 4).c_str();
	sYear >> year;
	sMonth << date.substr(5, 6).c_str();
	sMonth >> month;
	sDay << date.substr(8, 9).c_str();
	sDay >> day;
	if (year < MIN_YEAR || year > MAX_YEAR)
		return (std::cerr << "Error\nInvalid year" << std::endl, 0);
	if (month < JANUARY || month > DECEMBER)
		return (std::cerr << "Error\nInvalid month" << std::endl, 0);
	if (day < MIN_DAY || (month == 2 && !isLeap(year)))
		return (std::cerr << "Error\nNot a leap year" << std::endl, 0);
	if (day < MIN_DAY || (!(month % 2) && day > EVEN))
		return (std::cerr << "Error\nInvalid day" << std::endl, 0);
	if (day < MIN_DAY || (month % 2 && day > ODD))
		return (std::cerr << "Error\nInvalid day too" << std::endl, 0);
	std::cout << "year: " << year << " month: " << month << " day: " << day << "\n";
//	std::cout << "year: " << year ; //<< " month: " << month << "\n";
//	std::cout <<  " month: " << month << "\n";
	return 1;
}

void	loadDB(std::map<std::string, float> &btc, std::string filename)
{
	char	*end;
	std::string::size_type	pos;
	std::string	date;
	float	rate;
	std::string	line;
	std::ifstream	file(filename.c_str(), std::ios::in);

	if (!file.is_open())
		{ std::cerr << "Error: could not open file." << std::endl; return; }
	if (getline(file, line)) {};
	while (getline(file, line, '\n'))
	{
		pos = line.find(',');
		date = line.substr(0, pos);
		rate = std::strtof((line.substr(pos + 1)).c_str(), &end);
		if (*end != '\0')
			{ std::cerr << "Error\nParsing date: " << rate << std::endl; continue; }
		btc[date] = rate;
	}
}

/*
void	loadInput(std::map<std::string, float> &btc, std::string input)
{	
	(void)btc;
	std::ifstream	file(input.c_str());
	std::string		line;
	std::map<std::string, float>::iterator it;
	char	*end;
	std::string::size_type	pos; // = line.find('|');
	std::string	date; //= line.substr(0, pos - 1);
	
	if (!file.is_open())
		{ std::cerr << "Error: could not open " << file << " file." << std::endl; return; }
	if (getline(file, line)) {};
	while (getline(file, line, '\n'))
	{
		pos = line.find('|');
		if (pos == std::string::npos)
			std::cerr << "Error: Bad input => " << line << std::endl;
		else {
			date = line.substr(0, pos - 1);
			if (!check_date(date))
				std::cerr << "Error: Invalid date" << std::endl;
			else {
				float	value = std::strtof((line.substr(pos + 1)).c_str(), &end);
				if (*end != '\0')
					std::cerr << "Error: wrong value type" << std::endl;
				else {
					it = this->_dataBase.lower_bound(date);
					if (it == this->_dataBase.end() || it->first != date)
						--it;
					std::cout << date << " => " << value << " = " << value * it->second << std::endl;
				}
			}
		}
	}
}
*/

int	main(int argc, char **argv)
{
	(void)argv;
	std::map<std::string, float> btc;
//	std::string	input;

	if (argc != 2)
		return (std::cerr << "Error:\nPlease enter a valid file as parameter" << std::endl, 1);

	//	BitcoinExchange	btc;

	//	btc.loadDataBase("data.csv");
//	input = argv[1].c_str();
	loadDB(btc, "data.csv");
	checkDate("2014-14-24");
	checkDate("2024-12-24");
	checkDate("2024-04-31");
	checkDate("2024-05-31");
	checkDate("2024-05-30");
	checkDate("2024-05-32");
	checkDate("204-12-24");
	checkDate("2023-02-24");
	checkDate("2024-02-24");
//	loadInput(btc, argv[1]);
	// for (std::map<std::string, float>::const_iterator it = btc.get_cont().begin(); it != btc.get_cont().end(); ++it) {
	//     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	// }
	//	btc.loadInputFile(argv[1]);

	return (0);
}
