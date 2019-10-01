#include "models/city.hpp"
#include "exceptions/inappropriate_argument.hpp"

City::City(std::string name_)
{
	validateName(name_);
	name = name_;
}

City::City() { name = nullptr; }

City::City(const City& city)
{
	validateName(city.name);

	name = city.name;
}

City& City::operator=(const City& city)
{
	validateName(city.name);

	name = city.name;

	return *this;
}

std::string City::getName() const { return name; }

void City::setName(std::string name_)
{
	validateName(name_);

	name = name_;
}

void City::validateName(std::string name)
{
	if (name.empty())
		throw new inappropriate_argument("City name is can not be empty");
}