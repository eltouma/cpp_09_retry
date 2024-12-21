/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:16:03 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/21 22:16:07 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


/*
void	loadDataBase(std::string filename) {
	std::ifstream	file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error opening the .csv file" << std::endl;
		return ;
	}
	std::string	line;
	while (getline(file, line, '\n')) {
		char	*end;
		std::string::size_type 	pos = line.find(',');
		std::string 			date = line.substr(0, pos);
		float					rate = std::strtof((line.substr(pos + 1)).c_str(), &end);
		this->_dataBase[date] = rate;
	}
}

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

void	loadInputFile(std::string filename) {
	
	std::ifstream	file(filename.c_str());
	std::string		line;
	std::map<std::string, float>::iterator it;
	
	if (!file.is_open()) {
		std::cerr << "Error opening the .txt file" << std::endl;
		return ;
	}
	
	while (getline(file, line, '\n')) {
		char	*end;
		std::string::size_type 	pos = line.find('|');
		if (pos == std::string::npos)
			std::cerr << "Error: Bad input => " << line << std::endl;
		else {
			std::string	date = line.substr(0, pos - 1);
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
