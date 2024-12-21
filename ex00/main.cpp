/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:15:48 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/21 22:58:42 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::map<std::string, float> btc;

	if (argc != 2)
		return (std::cerr << "Error:\nPlease enter a valid file as parameter" << std::endl, 1);
	loadDB(btc, "data.csv");
	loadInput(btc, argv[1]);
	return (0);
}
