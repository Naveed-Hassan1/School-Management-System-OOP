#include "Contact.h"
#include "Address.h"
#include <string>
/*
*	Implement a constructor that initializes all the Contact parts, including address. Call the setter to set values
*	as they have the logic to check correct input
*	Declaration is given in Contact.h
*/
Contact::Contact() :first_name(""), last_name(""), mobile_number(""), email_address("")
{
	address = nullptr;
	search_times = 0;
}
int Contact::get_search_times() const
{
	return search_times;
}
Contact::Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address)
{
	set_first_name(first_name);
	set_last_name(last_name);
	set_mobile_number(mobile_number);
	set_email_address(email_address);
	set_address(*address);
}
void Contact::inc_search_count()
{
	search_times++;
}
/*
*	Implement getter/setters for all the member variables of Contact. Also declare them in the Contact.h header file
*	In each setter, do not set value if string is empty ("" 0 size).
*   Check in phone number setter, Phone number must be 11 digits
*/
void Contact::set_first_name(std::string first_name)
{
	int length = first_name.length();
	if (length != 0)
	{
		this->first_name = first_name;
	}
}
std::string Contact::get_first_name() const
{
	return first_name;
}
void Contact::set_last_name(std::string last_name)
{
	int length = last_name.length();
	if (length != 0)
	{
		this->last_name = last_name;
	}
}
std::string Contact::get_last_name() const
{
	return last_name;
}
void Contact::set_email_address(std::string email_address)
{
	int length = last_name.length();
	if (length != 0)
	{
		this->email_address = email_address;
	}
}
std::string Contact::get_email_address() const
{
	return email_address;
}
void Contact::set_mobile_number(std::string mobile_number)
{
	int length = mobile_number.length();
	if (length == 11)
	{
		this->mobile_number = mobile_number;
	}
}
std::string Contact::get_mobile_number() const
{
	return mobile_number;
}
void Contact::set_address(Address& address)
{
	this->address = new Address;
	int length = address.get_house().length();
	if (length != 0)
	{
		this->address->set_house(address.get_house());
	}
	length = address.get_street().length();
	if (length != 0)
	{
		this->address->set_street(address.get_street());
	}
	length = address.get_city().length();
	if (length != 0)
	{
		this->address->set_city(address.get_city());
	}
	length = address.get_country().length();
	if (length != 0)
	{
		this->address->set_country(address.get_country());
	}
}
Address* Contact::get_address() const
{
	return address;
}
/*
*	Implement the equals function(as declared in header file) that takes a
*   Contact object and checks if it is equal to current object refered by (this pointer).
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/
bool Contact::equals(Contact contact)
{
	if (this->first_name == contact.first_name)
	{
		if (this->last_name == contact.last_name)
		{
			if (this->mobile_number == contact.mobile_number)
			{
				if (this->email_address == contact.email_address)
				{
					if (this->address->equals(*address) == contact.address->equals(*address))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
Contact* Contact::copy_contact()
{
	Contact* new_ptr;
	new_ptr = new Contact;
	new_ptr->set_first_name(first_name);
	new_ptr->set_last_name(last_name);
	new_ptr->set_mobile_number(mobile_number);
	new_ptr->set_email_address(email_address);
	Address* new_address;
	new_address = new Address(*address);
	new_ptr->set_address(*new_address);
	return new_ptr;
}
