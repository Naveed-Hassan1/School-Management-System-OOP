#pragma once
#include"contact_history.h"
#include"history.h"
#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

#include "Address.h"
class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address* address;
	int search_times;
public:
	bool equals(Contact contact);
	Contact* copy_contact();
	void set_first_name(std::string first_name);
	std::string get_first_name() const;
	void set_last_name(std::string last_name);
	std::string get_last_name() const;
	void set_mobile_number(std::string);
	std::string get_mobile_number() const;
	void set_email_address(std::string email_address);
	std::string get_email_address() const;
	void set_address(Address& address);
	Address* get_address() const;
	int get_search_times() const;
	void inc_search_count();
	Contact();
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address);
};
