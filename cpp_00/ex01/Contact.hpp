/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:00:30 by tgoossen          #+#    #+#             */
/*   Updated: 2025/03/10 13:28:19 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <cstdlib>

class Contact{
	private:
		std::string first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
	//setters
		void setfirstname		(std::string fname);
		void setlastname		(std::string lname);
		void setnickname		(std::string nname);
		void setphonenumber		(std::string pnumb);
		void setdarkestsecret	(std::string dsecr);
	//getters
		std::string getfirstname()		const;
		std::string getlastname()		const;
		std::string getnickname()		const;
		std::string getphonenumber()	const;
		std::string getdarkestsecret()	const;
};

#endif