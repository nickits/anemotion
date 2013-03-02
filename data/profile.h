#ifndef DATA_PROFILE_H
#define DATA_PROFILE_H
#include "master.h"

namespace data {
	
	enum ClientType{
		Person,
		Organization
	};
	
	struct profile_form : public cppcms::form{
		cppcms::widgets::select clientType;
		cppcms::widgets::text username;
		cppcms::widgets::text password;
		cppcms::widgets::text repassword;
		cppcms::widgets::text fname;
		cppcms::widgets::text lastName;
		cppcms::widgets::text identityNumber;
		cppcms::widgets::text country;
		cppcms::widgets::text town;
		cppcms::widgets::text zipCode;
		cppcms::widgets::text address;
		cppcms::widgets::text phone;
		cppcms::widgets::text fax;
		cppcms::widgets::email mail;
		cppcms::widgets::text webSite;
		cppcms::widgets::text contactPerson;

		profile_form(){
// 			clientType.id("clientType");
// 			username.id("username");
// 			password.id("password");
// 			repassword.id("repassword");
// 			fname.id("fname");
// 			lastName.id("lastName");
// 			identityNumber.id("identityNumber");
// 			country.id("country");
// 			town.id("town");
// 			zipCode.id("zipCode");
// 			address.id("address");
// 			phone.id("phone");
// 			fax.id("fax");
// 			mail.id("mail");
// 			webSite.id("webSite");
// 			contactPerson.id("contactPerson");
			
			clientType.name("clientType");
			username.name("username");
			password.name("password");
			repassword.name("repassword");
			fname.name("fname");
			lastName.name("lastName");
			identityNumber.name("identityNumber");
			country.name("country");
			town.name("town");
			zipCode.name("zipCode");
			address.name("address");
			phone.name("phone");
			fax.name("fax");
			mail.name("mail");
			webSite.name("webSite");
			contactPerson.name("contactPerson");

			clientType.message("Client Type");
			clientType.add("Person", "person");
			clientType.add("Organization", "organization");
			username.message("Username");
			password.message("Password");
			repassword.message("Retype Password");
			fname.message("First Name");
			lastName.message("Last Name");
			identityNumber.message("Identity Number");
			country.message("Country");
			town.message("Town");
			zipCode.message("Zip Code");
			address.message("Address");
			phone.message("Phone");
			fax.message("Fax");
			mail.message("Mail");
			webSite.message("Web Site");
			contactPerson.message("Contact Person");

			add(clientType);
			add(username);
			add(password);
			add(repassword);
			add(fname);
			add(lastName);
			add(identityNumber);
			add(country);
			add(town);
			add(zipCode);
			add(address);
			add(phone);
			add(fax);
			add(mail);
			add(webSite);
			add(contactPerson);
			
			username.limits(1, 50);
			password.limits(1, 50);
			repassword.limits(1, 50);
			fname.limits(1, 50);
			lastName.limits(1, 50);
			identityNumber.limits(1, 50);
			country.limits(1, 50);
			town.limits(1, 50);
			zipCode.limits(1, 50);
			address.limits(1, 100);
			phone.limits(1, 100);
			fax.limits(1, 100);
			mail.limits(1, 100);
			webSite.limits(1, 250);
			contactPerson.limits(1, 50);
		}
	};

	class profile : public master{
	public:
		profile_form fProfile;
		
		profile() : id(0) {}
		profile(const profile& i){
			id = i.id;
		}
		int id;
		ClientType clientType;
		std::string username;
		std::string password;
		std::string repassword;
		std::string fname;
		std::string lastName;
		std::string identityNumber;
		std::string country;
		std::string town;
		std::string zipCode;
		std::string address;
		std::string phone;
		std::string fax;
		std::string webSite;
		std::string mail;
		std::string contactPerson;

	};

}

#endif
