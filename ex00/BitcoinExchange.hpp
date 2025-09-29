/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:23:35 by mohaben-          #+#    #+#             */
/*   Updated: 2025/09/29 13:16:14 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class	BitcoinExchange
{
	private:
		std::map<std::string, float>	container;

		bool		isValidDate(const std::string& date) const;
		bool		isValidValue(const std::string& value) const;
		bool		isAllDigits(const std::string& str) const;
		std::string	trim(const std::string& str) const;
		float		findExchangeRate(const std::string& date) const;
		void		parseCsvLine(const std::string& line);
		void		processInputLine(const std::string& line);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange&	operator=(const BitcoinExchange& copy);
		~BitcoinExchange();

		void	loadCsv(const std::string& csv);
		void	processInput(const std::string& input);
};

#endif
