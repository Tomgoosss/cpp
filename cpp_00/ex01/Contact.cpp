/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:02:16 by tgoossen          #+#    #+#             */
/*   Updated: 2024/12/13 14:44:57 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

// Setters
void Contact::setfirstname(std::string fname) { first_name = fname; }
void Contact::setlastname(std::string lname) { last_name = lname; }
void Contact::setnickname(std::string nname) { nickname = nname; }
void Contact::setphonenumber(std::string pnumb) { phone_number = pnumb; }
void Contact::setdarkestsecret(std::string dsecr) { darkest_secret = dsecr; }

// Getters
std::string Contact::getfirstname() const { return first_name; }
std::string Contact::getlastname() const { return last_name; }
std::string Contact::getnickname() const { return nickname; }
std::string Contact::getphonenumber() const { return phone_number; }
std::string Contact::getdarkestsecret() const { return darkest_secret; }