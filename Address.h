#pragma once
#include <iostream>
#include <string>

class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;
public:
	//equals function
	bool equals(const Address& address);
	//print function
	void print_address();
	//copy function
	Address copy_address();
	//setters and getters
	std::string get_house() const;
	void set_house(std::string house);
	std::string get_street() const;
	void set_street(std::string street);
	std::string get_city() const;
	void set_city(std::string city);
	std::string get_country() const;
	void set_country(std::string country);
	//constructors
	Address(std::string house, std::string street, std::string city, std::string country);
	Address();
};
