/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:49:57 by davmendo          #+#    #+#             */
/*   Updated: 2026/04/13 15:50:18 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

/*
** contact class: represents a phone book contact
** all attributes are private (encapsulation)
** data access only through getters and setters
** fields: first name, last name, nickname, phone number, and darkest secret
*/
class Contact 
{
  private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickname;
  std::string _phoneNumber;
  std::string _darkestSecret;
  
  public:
  Contact();

  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getNickname() const;
  std::string getPhoneNumber() const;
  std::string getDarkestSecret() const;

  void setFirstName(const std::string &str);
  void setLastName(const std::string &str);
  void setNickname(const std::string &str);
  void setPhoneNumber(const std::string &str);
  void setDarkestSecret(const std::string &str);
};

#endif
