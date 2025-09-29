/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:46:38 by mohaben-          #+#    #+#             */
/*   Updated: 2025/09/29 16:01:57 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : container(copy.container) {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
		container = copy.container;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	std::string	yearStr = date.substr(0, 4);
	std::string	monthStr = date.substr(5, 2);
	std::string	dayStr = date.substr(8, 2);

	if (!isAllDigits(yearStr) || !isAllDigits(monthStr) || !isAllDigits(dayStr))
		return (false);

	int	year = std::atoi(yearStr.c_str());
	int	month = std::atoi(monthStr.c_str());
	int	day = std::atoi(dayStr.c_str());


	if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	
	int	monthDays[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int	maxDay = monthDays[month];

	if (month == 2)
	{
		bool	isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

		if (isLeap)
			maxDay = 29;
		else
			maxDay = 28;
	}
	return (day <= maxDay);
}

bool	BitcoinExchange::isValidValue(const std::string& value) const
{
	if (value.empty())
	{
		std::cerr << "Error: bad input." << std::endl;
		return (false);
	}

	std::istringstream	iss(value);
	float				val;
	char				leftover;

	if (!(iss >> val) || (iss >> leftover))
	{
		std::cerr << "Error: bad input." << std::endl;
		return (false);
	}
	if (val < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (val > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

bool		BitcoinExchange::isAllDigits(const std::string& str) const
{
	if (str.empty())
		return (false);
	for (int i = 0; i < static_cast<int>(str.size()); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

std::string	BitcoinExchange::trim(const std::string& str) const
{
	size_t	start = str.find_first_not_of(" \t\r\n");

	if (start == std::string::npos)
		return ("");

	size_t	end = str.find_last_not_of(" \t\r\n");

	return (str.substr(start, end - start + 1));
}

float		BitcoinExchange::findExchangeRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator	it = container.find(date);

	if (it != container.end())
		return (it->second);

	std::map<std::string, float>::const_iterator	upper = container.upper_bound(date);

	if (upper != container.begin())
	{
		--upper;
		return (upper->second);
	}
	return (-1.0f);
}

void		BitcoinExchange::parseCsvLine(const std::string& line)
{
	size_t	pos = line.find(',');

	if (pos == std::string::npos)
		return ;

	std::string			date = line.substr(0, pos);
	std::string			rateStr = line.substr(pos + 1);
	std::istringstream	iss(rateStr);
	float				rate;

	iss >> rate;
	if (!iss.fail())
		container[date] = rate;
}

void		BitcoinExchange::processInputLine(const std::string& line)
{
	if (line.empty())
		return ;

	size_t	pos = line.find('|');

	if (pos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}

	std::string	date = trim(line.substr(0, pos));
	std::string	valueStr = trim(line.substr(pos + 1));

	if (!isValidDate(date))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (!isValidValue(valueStr))
		return ;

	float				rate = findExchangeRate(date);
	std::istringstream	iss(valueStr);
	float				value;

	iss >> value;
	if (rate < 0)
	{
		std::cerr << "Error: no exchange rate data available." << std::endl;
		return;
	}
	std::cout << date << " => " << value << " = " << value * rate << std::endl;
}

void	BitcoinExchange::loadCsv(const std::string& csv)
{
	std::ifstream	file(csv);

	if (!file)
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return ;
	}

	std::string	line;

	std::getline(file, line);
	while (getline(file, line))
		parseCsvLine(line);
	file.close();
}

void	BitcoinExchange::processInput(const std::string& input)
{
	std::ifstream	file(input);

	if (!file)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string	line;

	if (!getline(file, line))
	{
		std::cerr << "Error: empty file." << std::endl;
		return ;
	}
	if (line.find("date") == std::string::npos || line.find("|") == std::string::npos || line.find("value") == std::string::npos)
	{
		std::cerr << "Error: invalid header. Expected format with 'date' and 'value'" << std::endl;
		return ;
	}
	while (getline(file, line))
		processInputLine(line);
	file.close();
}
