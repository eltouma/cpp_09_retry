/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skiam <skiam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:51:48 by ahayon            #+#    #+#             */
/*   Updated: 2024/12/21 17:10:54 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>

void	loadInputFile(std::string filename);
void	loadDataBase(std::string filename);
void	error_msg(std::string line, int code);
bool	check_date(std::string date);
bool	check_format(std::string date);
