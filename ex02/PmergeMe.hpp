/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:24:10 by mohaben-          #+#    #+#             */
/*   Updated: 2025/09/29 13:03:22 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <vector>

class	PmergeMe
{
	private:
		std::vector<int>	generate_sequence(int total);
		template<typename Container>
		void	merge_insert_impl(Container& container);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe&	operator=(const PmergeMe& copy);
		~PmergeMe();

		void	sort(std::vector<int>& container);
		void	sort(std::deque<int>& container);
};

#endif
