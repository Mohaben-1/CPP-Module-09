/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:26:55 by mohaben-          #+#    #+#             */
/*   Updated: 2025/09/29 14:13:09 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	static_cast<void>(copy);
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& copy)
{
	static_cast<void>(copy);
	return (*this);
}

PmergeMe::~PmergeMe() {}

std::vector<int>	PmergeMe::generate_sequence(int size)
{
	std::vector<int>	sequence;
	std::vector<int>	jacob;

	jacob.push_back(0);
	jacob.push_back(1);

	for (int i = 2; jacob.back() <= size; i++)
		jacob.push_back(jacob[i-1] + 2 * jacob[i-2]);

	for (size_t i = 2; i < jacob.size(); i++)
	{
		if (jacob[i] <= size)
			sequence.push_back(jacob[i]);
	}

	for (int k = 1; k <= size; k++)
	{
		if (!std::binary_search(sequence.begin(), sequence.end(), k))
			sequence.push_back(k);
	}

	return (sequence);
}

template<typename Container>
void	PmergeMe::merge_insert_impl(Container& container)
{
	if (container.size() < 2)
		return ;
	
	Container	winner, loser;

	for (size_t i = 0; i < container.size(); i += 2)
	{
		if (i + 1 >= container.size())
		{
			winner.push_back(container[i]);
			break ;
		}
		if (container[i] > container[i + 1])
		{
			winner.push_back(container[i]);
			loser.push_back(container[i + 1]);
		}
		else
		{
			winner.push_back(container[i + 1]);
			loser.push_back(container[i]);
		}
	}
	merge_insert_impl(winner);

	std::vector<int>	sequence = generate_sequence(loser.size());

	for (size_t i = 0; i < loser.size(); i++)
	{
		int	index = sequence[i] - 1;

		if (index < static_cast<int>(loser.size()))
		{
			typename Container::iterator	it = std::upper_bound(winner.begin(), winner.end(), loser[index]);

			winner.insert(it, loser[index]);
		}
	}
	container = winner;
}

void	PmergeMe::sort(std::vector<int>& container)
{
	merge_insert_impl(container);
}

void	PmergeMe::sort(std::deque<int>& container)
{
	merge_insert_impl(container);
}
