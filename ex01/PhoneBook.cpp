/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:50:03 by davmendo          #+#    #+#             */
/*   Updated: 2026/04/14 14:07:46 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cctype>
#include <iomanip>
#include <iostream>

/*
** main constructor: initializer list sets _index and _count to 0
*/
PhoneBook::PhoneBook() : _index(0), _count(0) {}

/*
** truncates string to a 10 character column
** if longer than 10, cuts at 9 and appends '.' at the end
*/
std::string PhoneBook::_truncate(const std::string &str) const 
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

/*
** repeats the prompt until the user enters a non empty input
** rejects strings that are empty or contain only whitespace characters
** find_first_not_of returns npos if the string has only whitespace
** returns an empty string if EOF (ctrl+D) is detected
*/
static	std::string getInput(const std::string &prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return "";
		if (input.find_first_not_of(" \t\n\v\f\r") != std::string::npos)
			return input;
	}
}

/*
** prompts the user for all 5 fields and stores them at position _index
** _index advances circularly using modulo 8 (overwrites the oldest entry)
** if any field returns empty (EOF), the addition is cancelled.
*/
void	PhoneBook::addContact() 
{
	std::string fields[5];
	std::string prompts[5] = {"First name: ", "Last name: ", "Nickname: ",
		"Phone number: ", "Darkest secret: "};
	
	for (int i = 0; i < 5; i++) 
	{
		fields[i] = getInput(prompts[i]);
		if (fields[i].empty())
			return;
	}
	_contacts[_index].setFirstName(fields[0]);
	_contacts[_index].setLastName(fields[1]);
	_contacts[_index].setNickname(fields[2]);
	_contacts[_index].setPhoneNumber(fields[3]);
	_contacts[_index].setDarkestSecret(fields[4]);
	_index = (_index + 1) % 8;
	if (_count < 8)
		_count++;
}

/*
** displays a table with 10-char right-aligned columns (std::setw)
** columns separated by '|'. Text longer than 10 chars is truncated
** after the table, prompts for an index to display contact details
** validates whether the input is a single digit and within range
*/
void	PhoneBook::searchContacts() const
{
	if (_count == 0) 
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}
	std::cout << std::right << std::setw(10) << "Index" << "|" << std::setw(10)
		<< "First Name" << "|" << std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << std::right << std::setw(10) << i << "|" << std::setw(10)
			<< _truncate(_contacts[i].getFirstName()) << "|" << std::setw(10)
			<< _truncate(_contacts[i].getLastName()) << "|" << std::setw(10)
			<< _truncate(_contacts[i].getNickname()) << std::endl;
	}
	std::cout << "Enter index: ";
	std::string input;
	if (!std::getline(std::cin, input))
		return;
	if (input.length() != 1 || !std::isdigit(input[0]))
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	int idx = input[0] - '0';
	if (idx >= _count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	std::cout << "First name: " << _contacts[idx].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[idx].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[idx].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[idx].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[idx].getDarkestSecret() << std::endl;
}
