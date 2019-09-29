#include "models/address.hpp"

Address::Address(Street& street_) : street(street_) { }

Address::Address(const Address& address) : street(address.street) { }

Address::Address() { }

Address& Address::operator=(const Address& address)
{
	street = address.street;

	return *this;
}

Street Address::getStreet() const { return street; }
 
void Address::setStreet(Street& street_) { street = street_; }