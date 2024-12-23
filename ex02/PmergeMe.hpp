/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:08:34 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/23 01:37:08 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <limits.h>
#include <cerrno>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sys/time.h>
#include <deque>

template <class T>
int	parseInput(char *input, T &sequence, char *buff);

template <class T>
int	checkInput(char *s, T &sequence);

template <class T, class I>
int	handleDuplicate(T &sequence, I it, char *buff);

template <class T>
void	printSequence(T sequence);

template <class T>
void	printGroup(T sequence, int sizeElement, int nbOfGroups);

template <class T>
void	printOdd(T sequence, int sizeElement);

template <
	template <class, class> class OuterContainer,
	template <class, class> class InnerContainer,
	class T
>
void	printPending(OuterContainer<std::pair<InnerContainer<T, std::allocator<T> >, int>, std::allocator<std::pair<InnerContainer<T, std::allocator<T> >, int> > > &pending);

template <class T>
int	isSorted(T sequence);

template <class T>
void	sortPairs(T &sequence, int sizeElement);

template <
	class S,
	template <class, class> class OuterContainer,
	template <class, class> class InnerContainer,
	class T
>
void	initPending(S &sequence, int sizeElement, OuterContainer<std::pair<InnerContainer<T, std::allocator<T> >, int>, std::allocator<std::pair<InnerContainer<T, std::allocator<T> >, int> > > &pending);

template <typename T>
typename T::iterator	binarySearch(typename T::iterator start, typename T::iterator end, int sizeElement, int valToFind);

int	ft_strlen(char *str);
char    *isString(int argc, char **argv, char *input, char *&buff);
void	printLabel(int sizeElement, int nbOfGroups);
void	printTime(size_t parsingTime, size_t sortTime, std::string name);
void	printResult(std::vector<int> vect, std::vector<int> tmpV, std::deque<int> deq, std::deque<int> tmpD, size_t parsingTime, size_t sortTime);
void    draw_tab(const std::string& str);
int	jacobNumber(int n);
void	mergeInsertVect(std::vector<int> &sequence, int sizeElement);
void	mergeInsertDeq(std::deque<int> &deq, int sizeElement);

#include "checkParams.tpp"
#include "print.tpp"
#include "PmergeMe.tpp"
