/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:24:10 by mohaben-          #+#    #+#             */
/*   Updated: 2025/09/26 19:41:57 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <vector>

class	PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe&	operator=(const PmergeMe& copy);
		~PmergeMe();

	template<typename T>
	void	fordJohnsonAlgo(T& container);
};

#endif