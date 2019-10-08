// Represents implementation to all methods from Street class

#include "models/street.hpp"
#include "exceptions/inappropriate_argument.hpp"

Street::Street(std::string name_, unsigned short number_, City& city_) : city(city_)
{
	number = number_;

	validateStreet(name_);

	name = name_;
}

Street::Street()
{
	name = nullptr;
	number = 0;
}

Street::Street(const Street& street) : city(street.city)
{
	number = street.number;

	validateStreet(street.name);

	name = street.name;
}

Street& Street::operator=(const Street& street)
{
	city = street.city;
	number = street.number;

	validateStreet(street.name);

	name = street.name;

	return *this;
}

std::string Street::getName() const { return name; }

unsigned short Street::getNumber() const { return number; }

City Street::getCity() const { return city; }

void Street::setName(std::string name_)
{
	validateStreet(name_);
	name = name_;
}

void Street::validateStreet(std::string name)
{
	if (name.empty())
		throw new inappropriate_argument("Street name can not be empty");

	if (number == 0)
		throw new inappropriate_argument("Street number can not be zero");
}