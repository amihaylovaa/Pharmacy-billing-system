#pragma once
#include "street.hpp"

class Address
{
public:
	Address(Street&);
	Address(const Address&);
	Address& operator=(const Address&);
	Address();
	Street getStreet() const;
	void setStreet(Street&);

private:
	Street street;
};