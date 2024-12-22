/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:08:34 by eltouma           #+#    #+#             */
/*   Updated: 2024/12/22 18:38:50 by eltouma          ###   ########.fr       */
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
#include <deque>

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
void printPending(OuterContainer<std::pair<InnerContainer<T, std::allocator<T> >, int>, std::allocator<std::pair<InnerContainer<T, std::allocator<T> >, int> > > &pending);

int	ft_strlen(char *str);
char    *isString(int argc, char **argv, char *input, char *&buff);
void	printLabel(int sizeElement, int nbOfGroups);
void    draw_tab(const std::string& str);

int	isSorted(std::vector<int> vect);
void	mergeInsert(std::vector<int> &vect, int sizeElement);
void	sortPairs(std::vector<int> &vect, int sizeElement);
void	initPending(std::vector<int> &vect, int sizeElement, std::vector<std::pair<std::vector<int>, int> > &pending, int nbOfGroups);
std::vector<int>::iterator	binarySearch(std::vector<int>::iterator start, std::vector<int>::iterator end, int sizeElement, int valToFind);
int	jacobNumber(int n);

#include "checkParams.tpp"
#include "print.tpp"
