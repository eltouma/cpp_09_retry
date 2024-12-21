/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:51:48 by ahayon            #+#    #+#             */
/*   Updated: 2024/12/05 21:53:25 by skiam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>

class	BitcoinExchange {
	
	private:
		std::map<std::string, float>	_dataBase;
		
	public:

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		const std::map<std::string, float>&	get_cont() const;
		void	loadInputFile(std::string filename);
		void	loadDataBase(std::string filename);
		void	error_msg(std::string line, int code);
		bool	check_date(std::string date);
		bool	check_format(std::string date);
};