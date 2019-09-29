#include "models/person.hpp"
#include "exceptions/invalid_argument_exception.hpp"

Person::Person(std::string firstName_, std::string lastName_, Address& address_) : address(address_)
{
	validateName(firstName_);
	validateName(lastName_);

	firstName = firstName_;
	lastName = lastName_;
}

Person::Person()
{
	firstName = nullptr;
	lastName = nullptr;
}

void Person::setFirstName(std::string firstName_)
{
	validateName(firstName_);
	firstName = firstName_;
}

void Person::setLastName(std::string lastName_)
{
	validateName(lastName_);
	lastName = lastName_;
}

void Person::setAddress(Address& address_)
{
	address = address_;
}

std::string Person::getFirstName() const { return firstName; }

std::string Person::getLastName() const { return lastName; }

Address Person::getAddress() const { return address; }

void Person::validateName(std::string name)
{
	if (name.empty())
		throw new invalid_argument_exception("Empty first or last name");
}