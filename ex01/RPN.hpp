/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:13:32 by mohaben-          #+#    #+#             */
/*   Updated: 2025/09/23 20:31:59 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class	RPN
{
	private:
		std::stack<int>	container;
	public:
		RPN();
		RPN(const RPN& copy);
		RPN&	operator=(const RPN& copy);
		~RPN();

		void	calculate(const std::string& input);
};

#endif