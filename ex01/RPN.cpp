/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:29:24 by mohaben-          #+#    #+#             */
/*   Updated: 2025/09/23 20:31:19 by mohaben-         ###   ########.fr       */
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

void	RPN::calculate(const std::string& input)
{
	
}
