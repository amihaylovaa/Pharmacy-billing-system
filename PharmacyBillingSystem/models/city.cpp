#include "models/city.hpp"

City::City(std::string name_) : name(name_)
{
	validateName();
}

City::City() { }

City::City(const City& city) : name(city.name)
{
	validateName();
}

City& City::operator=(const City& city)
{
	name = city.name;

	return *this;
}

void City::validateName()
{
	//if (name.empty())
		//throw new std::invalid_argument("City is not allowed to be empty");
}

std::string City::getName() const { return name; }

void City::setName(std::string name_) { name = name_; }