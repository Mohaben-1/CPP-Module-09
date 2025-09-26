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

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::vector<int>	vector;
	std::deque<int>		deque;

	for (int i = 1; i < ac; i++)
	{
		if (isdigit(av[i]))
	}
}
