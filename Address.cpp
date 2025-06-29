#include "Address.h"
//constructors
Address::Address() :house(""), street(""), city(""), country(""){}//default constructor
Address::Address(std::string house, std::string street, std::string city, std::string country)//parameterized constructor
{
	this->house = house;
	this->street = street;
	this->city = city;
	this->country = country;
}
//setter And getters
std::string Address::get_house() const
{
	return house;
}
void Address::set_house(std::string house)
{
	this->house = house;
}
std::string Address::get_street() const
{
	return street;
}
void Address::set_street(std::string street)
{
	this->street = street;
}
std::string Address::get_city() const
{
	return city;
}
void Address::set_city(std::string city)
{
	this->city = city;
}
std::string Address::get_country() const
{
	return country;
}
void Address::set_country(std::string country)
{
	this->country = country;
}
//equals function
bool Address::equals(const Address& address)
{
	if (this->house == address.house)
	{
		if (this->street == address.street)
		{
			if (this->city == address.city)
			{
				if (this->country == address.country)
				{
					return true;
				}
			}
		}
	}
	return false;
}
//print function
void Address::print_address()
{
	std::cout << "Address: " << house << ", " << street << ", " << city << ", " << country;
}
//copy of this
Address Address::copy_address()
{
	Address copy_this_address(this->house, this->street, this->city, this->country);
	return copy_this_address;
}
