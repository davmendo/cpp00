/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:49:35 by davmendo          #+#    #+#             */
/*   Updated: 2026/04/13 15:50:20 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
** default constructor: automatically initializes empty strings
*/
Contact::Contact() {}

std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

void Contact::setFirstName(const std::string &str) { _firstName = str; }
void Contact::setLastName(const std::string &str) { _lastName = str; }
void Contact::setNickname(const std::string &str) { _nickname = str; }
void Contact::setPhoneNumber(const std::string &str) { _phoneNumber = str; }
void Contact::setDarkestSecret(const std::string &str) { _darkestSecret = str; }
