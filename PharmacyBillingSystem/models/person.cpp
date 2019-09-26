#include "models/person.hpp"

Person::Person(std::string firstName_, std::string lastName_, Address& address_)
	: firstName(firstName_), lastName(lastName_), address(address_)
{
	validateName();
}

Person::Person() { }

void Person::validateName()
{
	//if (firstName.empty() || lastName.empty())
	//	throw new std::invalid_argument("Empty names are not allowed");
}

void Person::setFirstName(std::string firstName_)
{
	firstName = firstName_;
	validateName();
}

void Person::setLastName(std::string lastName_)
{
	lastName = lastName_;
	validateName();
}

void Person::setAddress(Address& address_)
{
	address = address_;
}

std::string Person::getFirstName() const { return firstName; }

std::string Person::getLastName() const { return lastName; }

Address Person::getAddress() const { return address; }
