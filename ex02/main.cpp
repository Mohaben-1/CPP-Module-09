/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:23:32 by mohaben-          #+#    #+#             */
/*   Updated: 2025/09/29 14:47:06 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <sys/time.h>

bool parseInput(int ac, char **av, std::vector<int>& vec)
{
	for (int i = 1; i < ac; i++)
	{
		std::istringstream	iss(av[i]);
		int					num;

		iss >> num;
		if (iss.fail() || !iss.eof() || num < 0)
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
		vec.push_back(num);
	}
	return (true);
}

template<typename Container>
double	measureTime(PmergeMe& sorter, Container& container)
{
	timeval	start, end;
	double	time;

	gettimeofday(&start, NULL);
	sorter.sort(container);
	gettimeofday(&end, NULL);
	time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	return (time);
}

template<typename Container>
void	printContainer(const Container& container, const std::string& prefix)
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

void	printTiming(int size, const std::string& containerType, double time)
{
	std::cout << "Time to process a range of " << size << " elements with " << containerType << " : " << time << " us" << std::endl;
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

	if (!parseInput(ac, av, vector))
		return (1);
	deque.insert(deque.end(), vector.begin(), vector.end());

	printContainer(vector, "Before: ");

	PmergeMe	sorter;
	double		timeV = measureTime(sorter, vector);
	double		timeD = measureTime(sorter, deque);

	printContainer(vector, "After: ");
	printTiming(ac - 1, "std::vector", timeV);
	printTiming(ac - 1, "std::deque", timeD);
	return (0);
}
