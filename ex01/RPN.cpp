/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:29:24 by mohaben-          #+#    #+#             */
/*   Updated: 2025/09/23 20:56:27 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) : container(copy.container) {}

RPN&	RPN::operator=(const RPN& copy)
{
	if (this != &copy)
		container = copy.container;
	return (*this);
}

RPN::~RPN() {}

void	RPN::calculate(const std::string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
			continue ;
		else if (isdigit(str[i]))
			container.push(str[i] - 48);
		else if 
		{
			
		}
	}
}
