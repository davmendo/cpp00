/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:50:10 by davmendo          #+#    #+#             */
/*   Updated: 2026/04/13 15:50:19 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

/*
** PhoneBook class: phone book with a fixed array of 8 contacts (no dynamic allocation)
** _index: circular position for the next contact (0-7, wraps to 0 on the 9th)
** _count: total number of stored contacts (maximum 8)
** when _count == 8, new contacts overwrite the oldest one via _index
*/
class PhoneBook 
{
  private:
  Contact _contacts[8];
  int _index;
  int _count;
  
  std::string _truncate(const std::string &str) const;
  
  public:
  PhoneBook();

  void addContact();
  void searchContacts() const;
};

#endif
