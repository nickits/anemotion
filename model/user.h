/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef USER_H
#define USER_H

#include "defines.h"

class User
{
public:
	std::string userName;
	std::string password;
	std::string name;
	std::string country;
	std::string town;
	std::string zipCode;
	std::string address;
	std::string phone;
	std::string email;
	
  template<class Action> 
  void persist(Action& a)
  {
	dbo::field(a, userName, "userName");
	dbo::field(a, password, "password");
	dbo::field(a, name, "name");
	dbo::field(a, country, "country");
	dbo::field(a, town, "town");
	dbo::field(a, zipCode, "zipCode");
	dbo::field(a, address, "address");
	dbo::field(a, phone, "phone");
	dbo::field(a, email, "email");
  }
};

DBO_EXTERN_TEMPLATES(User);

#endif // USER_H
