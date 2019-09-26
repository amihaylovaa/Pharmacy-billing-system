#pragma once
#include <iostream>
#include "models/city.hpp"

class Street
{
public:
	Street(std::string, unsigned short, City& city);
	Street(const Street&);
	Street& operator=(const Street&);
	Street();
	std::string getName() const;
	unsigned short getNumber() const;
	City getCity() const;
	void setName(std::string);
	void setNumber(char);

private: 
	void validateName(std::string);

private:
	std::string name;
    unsigned short number;
	City city;
};