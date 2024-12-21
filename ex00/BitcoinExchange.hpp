/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:58:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/22 00:17:27 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits.h>

#define MIN_YEAR 2009
#define MAX_YEAR 2024
#define JANUARY 1
#define LEAP 29
#define DECEMBER 12
#define MIN_DAY 1
#define EVEN 30
#define ODD 31

int	checkDateFormat(std::string date);
int	isLeap(int year);
void	printError(int n, std::string date);
int	checkDate(std::string date);
void	loadDB(std::map<std::string, float> &btc, std::string filename);
void	loadInput(std::map<std::string, float> &btc, std::string input);
