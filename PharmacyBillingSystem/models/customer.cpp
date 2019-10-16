// Represents implementation to all methods from Customer class

#include "models/customer.hpp"

Customer::Customer(std::string firstName, std::string lastName, Address& address)
: Person(firstName, lastName, address) { }

Customer::Customer(const Customer& customer)
{
	firstName = customer.firstName;
	lastName = customer.lastName;
	address = customer.address;
}

void Customer::addItem(std::string item)
{
	items.push_back(item);
}
