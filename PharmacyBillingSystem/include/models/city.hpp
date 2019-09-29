#pragma once

#include <iostream>

class City
{
public:
	City(std::string);
	City(const City&);
	City& operator=(const City&);
	City();
	std::string getName() const;
	void setName(std::string);

private:
	void validateName(std::string);

private:
	std::string name;
};