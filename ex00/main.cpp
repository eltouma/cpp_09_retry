/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:51:35 by ahayon            #+#    #+#             */
/*   Updated: 2024/12/08 15:11:04 by skiam            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Error: Please enter a valid file as parameter" << std::endl;
		return (1);
	}
	
	BitcoinExchange	btc;

	btc.loadDataBase("data.csv");
	// for (std::map<std::string, float>::const_iterator it = btc.get_cont().begin(); it != btc.get_cont().end(); ++it) {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    // }
	btc.loadInputFile(argv[1]);

	return (0);
}
