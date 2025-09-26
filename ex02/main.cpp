/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:23:32 by mohaben-          #+#    #+#             */
/*   Updated: 2025/09/26 20:28:27 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

bool parseInput(int ac, char **av, std::vector<int>& vec)
{
}

template<typename Container>
void printContainer(const Container& container, const std::string& prefix)
{
	std::cout << prefix;
	for (size_t i = 0; i < container.size(); i++)
	{
		std::cout << container[i];
		if (i != container.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " number1 number2 ..." << std::endl;
		return (1);
	}

	std::vector<int>	vector;
	std::deque<int>		deque;


}
