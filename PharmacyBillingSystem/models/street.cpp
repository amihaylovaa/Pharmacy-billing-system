#include "street.hpp"

Street::Street(std::string name_, unsigned short number_, City& city_) : name(name_), city(city_)
{
	number = number_;
}

Street::Street() {}

Street::Street(const Street& street) : name(street.name), city(street.city)
{
	number = street.number;
}

Street& Street::operator=(const Street& street)
{
	name = street.name;
	city = street.city;

	return *this;
}

std::string Street::getName() const { return name; }

unsigned short Street::getNumber() const { return number; }

City Street::getCity() const { return city; }

void Street::setNumber(char number_)
{
	number = number_;
}

void Street::setName(std::string name_)
{
	validateName(name_);
	name = name_;
}

void Street::validateName(std::string name)
{
	if (name.empty())
		throw new std::invalid_argument("The name is now allowed to be null");
}