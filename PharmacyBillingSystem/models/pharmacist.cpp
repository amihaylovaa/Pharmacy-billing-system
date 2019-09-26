#include "models/pharmacist.hpp"

Pharmacist::Pharmacist(std::string firstName, std::string lastName, Address& address)
: Person(firstName, lastName, address) { }

Pharmacist::Pharmacist(const Pharmacist& pharmacist)
{
	firstName = pharmacist.firstName;
	lastName = pharmacist.lastName;
	address = pharmacist.address;
}