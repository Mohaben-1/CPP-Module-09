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
	for (int i = 0; i < static_cast<int>(str.size()); i++)
	{
		if (str[i] == ' ')
			continue ;
		else if (isdigit(str[i]))
			container.push(str[i] - 48);
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (container.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			int	num1 = container.top();
			container.pop();
			int	num2 = container.top();
			container.pop();
			switch (str[i])
			{
				case '+':
					container.push(num1 + num2);
					break ;
				case '-':
					container.push(num2 - num1);
					break ;
				case '*':
					container.push(num1 * num2);
					break ;
				case '/':
					if (num1 == 0)
					{
						std::cerr << "Error" << std::endl;
						return ;
					}
					container.push(num2 / num1);
					break ;
				default:
					break ;
			}
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
	}
	if (container.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	std::cout << container.top() << std::endl;
}
