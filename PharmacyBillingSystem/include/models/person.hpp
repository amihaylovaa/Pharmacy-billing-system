#pragma once
#include <iostream>
#include "models/address.hpp"

class Person
{
public:
	Person(std::string, std::string, Address&);
	Person();
	void validateName();
   std::string getFirstName() const;
	std::string getLastName() const;
	Address getAddress() const;
	void setFirstName(std::string);
	void setLastName(std::string);
	void setAddress(Address&);

protected:
    std::string firstName;
	std::string lastName;
	Address address;
};